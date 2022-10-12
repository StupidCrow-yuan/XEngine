//
// Created by yuan on 9/5/22.
//

#include "xepch.h"
#include "Scene.h"

#include "Components.h"
#include "Renderer/Renderer2D.h"

#include <glm/glm.hpp>
#include "Entity.h"

namespace XEngine {

    Scene::Scene()
    {
    }

    Scene::~Scene()
    {
    }

    Entity Scene::CreateEntity(const std::string& name)
    {
        Entity entity = { m_Registry.create(), this };
        entity.AdddComponent<TransformComponent>();
        auto& tag = entity.AdddComponent<TagComponent>();
        tag.Tag = name.empty() ? "Entity" : name;
        return entity;
    }

    void Scene::DestroyEntity(Entity entity)
    {
        m_Registry.destroy(entity);
    }

    void Scene::OnUpdate(Timestep ts)
    {
        //update scripts
        {
            m_Registry.view<NativeScriptComponent>().each([=] (auto entity, auto& nsc)
           {
                //todo: move to Scene::OnScenePlay
                if (!nsc.Instance)
                {
                    nsc.Instance = nsc.InstantiateScript();
                    nsc.Instance->m_Entity = Entity{ entity, this };

                    nsc.Instance->OnCreate();
                }

                nsc.Instance->OnUpdate(ts);
           });
        }

        //Render2D
        Camera* mainCamera = nullptr;
        glm::mat4 cameraTransform;
        {
            auto view = m_Registry.view<TransformComponent, CameraComponent>();
            for (auto entity : view)
            {
                const auto [transform, camera] = view.get<TransformComponent, CameraComponent>(entity);
                if (camera.Primary)
                {
                    mainCamera = &camera.Camera;
                    cameraTransform = transform.GetTransform();
                    break;
                }
            }
        }

        if (mainCamera)
        {
            Renderer2D::BeginScene(mainCamera->GetProjection(), cameraTransform);

            auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
            for (auto entity : group)
            {
                const auto [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);

                Renderer2D::DrawQuad(transform.GetTransform(), sprite.Color);
            }
            Renderer2D::EndScene();
        }
    }

    void Scene::OnViewportResize(uint32_t width, uint32_t height)
    {
        m_ViewportWidth = width;
        m_ViewportHeight = height;

        //resize our non-FixedAspectRatio camera
        auto view = m_Registry.view<CameraComponent>();
        for (auto entity : view)
        {
            auto& cameraComponent = view.get<CameraComponent>(entity);
            if (!cameraComponent.FixedAspectRatio)
            {
                cameraComponent.Camera.SetViewportSize(width, height);
            }
        }
    }

    template<typename T>
    void Scene::OnComponentAdded(Entity entity, T &component)
    {
        static_assert(9 < 10, "error");//???????
    }

    template<>
    void Scene::OnComponentAdded(Entity entity, TransformComponent &component)
    {
    }

    template<>
    void Scene::OnComponentAdded(Entity entity, CameraComponent &component)
    {
        component.Camera.SetViewportSize(m_ViewportWidth, m_ViewportHeight);
    }

    template<>
    void Scene::OnComponentAdded(Entity entity, SpriteRendererComponent &component)
    {
    }

    template<>
    void Scene::OnComponentAdded(Entity entity, TagComponent &component)
    {
    }

    template<>
    void Scene::OnComponentAdded(Entity entity, NativeScriptComponent &component)
    {
    }
}
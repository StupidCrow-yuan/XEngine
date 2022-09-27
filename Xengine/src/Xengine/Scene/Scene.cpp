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

    static void DoMath(const glm::mat4& transform)
    {

    }

    static void OnTransformConstruct(entt::registry& registry, entt::entity entity)
    {

    }

    Scene::Scene()
    {
#if ENTT_EXAMPLE_CODE
        entt::entity entity = m_Registry.create();
        m_Registry.emplace<TransformComponent>(entity, glm::mat4(1.0f));

        m_Registry.on_construct<TransformComponent>().connect<&OnTransformConstruct>();

        if (m_Registry.has<TransformComponent>(entity))
        {
            TransformComponent& transform = m_Registry.get<TransformComponent>(entity);
        }

        auto view = m_Registry.view<TransformComponent>();
        for (auto entity : view)
        {
            TransformComponent& transform = view.get<TransformComponent>(entity);
        }

//        auto group = m_Registry.group<TransformComponent>(entt::get<MeshComponent>);
//        for (auto entity : group)
//        {
//            auto& [transform, mesh] = group.get<TransformComponent, MeshComponent>(entity);
//        }
#endif
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

    void Scene::OnUpdate(Timestep ts)
    {
        //update scripts
        {
            m_Registry.view<NativeScriptComponent>().each([=] (auto entity, auto& nsc)
           {
                if (!nsc.Instance)
                {
                    nsc.InstantiateFunction();
                    nsc.Instance->m_Entity = Entity{ entity, this };

                    if (nsc.OnCreateFunction)
                        nsc.OnCreateFunction(nsc.Instance);
                }

                if (nsc.OnUpdateFunction)
                    nsc.OnUpdateFunction(nsc.Instance, ts);
           });
        }

        //Render2D
        Camera* mainCamera = nullptr;
        glm::mat4* cameraTransform = nullptr;
        {
            auto view = m_Registry.view<TransformComponent, CameraComponent>();
            for (auto entity : view)
            {
                const auto& [transform, camera] = view.get<TransformComponent, CameraComponent>(entity);
                if (camera.Primary)
                {
                    mainCamera = &camera.Camera;
                    cameraTransform = &transform.Transform;
                    break;
                }
            }
        }

        if (mainCamera)
        {
            Renderer2D::BeginScene(mainCamera->GetProjection(), *cameraTransform);

            auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
            for (auto entity : group)
            {
                const auto& [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);

                Renderer2D::DrawQuad(transform.Transform, sprite.Color);
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
}
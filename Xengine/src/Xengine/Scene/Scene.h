//
// Created by yuan on 9/5/22.
//

#ifndef XENGINEMAIN_SCENE_H
#define XENGINEMAIN_SCENE_H

#include "entt.hpp"
#include "Xengine/Core/Timestep.h"
#include "Xengine/Core/UUID.h"
#include "Xengine/Renderer/EditorCamera.h"
#include "entt.hpp"

class b2World;

namespace XEngine {

    class Entity;

    class Scene
    {
    public:
        Scene();
        ~Scene();

        static Ref<Scene> Copy(Ref<Scene> other);

        Entity CreateEntity(const std::string& name = std::string());
        Entity CreateEntityWithUUID(UUID uuid, const std::string& name = std::string());
        void DestroyEntity(Entity entity);

        void OnRuntimeStart();
        void OnRuntimeStop();

        void OnSimulationStart();
        void OnSimulationStop();

        void OnUpdateRuntime(Timestep ts);
        void OnUpdateEditor(Timestep ts, EditorCamera& camera);
        void OnUpdateSimulation(Timestep ts, EditorCamera& camera);

        void OnViewportResize(uint32_t width, uint32_t height);

        void DuplicateEntity(Entity entity);
        Entity GetEntityByUUID(UUID uuid);
        Entity FindEntityByName(std::string_view name);

        Entity GetPrimaryCameraEntity();

        bool IsPaused() { return m_IsPaused; }
        void SetPaused(bool paused) { m_IsPaused = paused; }

        void Step(int frames = 1);

        template<typename... Components>
        auto GetAllEntitiesWith()
        {
            return m_Registry.view<Components...>();
        }

    private:
        template<typename T>
        void OnComponentAdded(Entity entity, T& component);

        void OnPhysics2DStart();
        void OnPhysics2DStop();

        void RenderScene(EditorCamera& camera);
    private:
        //创建一个registry,可以把它理解为vector<entity>,也就是包含所有entity的容器
        entt::registry m_Registry;
        uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;
        bool m_IsPaused = false;
        int m_StepFrames = 0;

        b2World* m_PhysicsWorld = nullptr;

        std::unordered_map<UUID, entt::entity> m_EntityMap;
        friend class Entity;
        friend class SceneSerializer;
        friend class SceneHierarchyPanel;
    };
}

#endif //XENGINEMAIN_SCENE_H

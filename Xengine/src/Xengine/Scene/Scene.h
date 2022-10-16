//
// Created by yuan on 9/5/22.
//

#ifndef XENGINEMAIN_SCENE_H
#define XENGINEMAIN_SCENE_H

#include "entt.hpp"
#include "Xengine/Core/Timestep.h"

namespace XEngine {

    class Entity;

    class Scene
    {
    public:
        Scene();
        ~Scene();

        Entity CreateEntity(const std::string& name = std::string());
        void DestroyEntity(Entity entity);

        void OnUpdate(Timestep ts);

        void OnViewportResize(uint32_t width, uint32_t height);

    private:
        template<typename T>
        void OnComponentAdded(Entity entity, T& component);
    private:
        entt::registry m_Registry;
        uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;

        friend class Entity;
        friend class SceneSerializer;
        friend class SceneHierarchyPanel;
    };
}

#endif //XENGINEMAIN_SCENE_H

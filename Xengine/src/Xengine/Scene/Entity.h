//
// Created by yuan on 9/15/22.
//

#ifndef XENGINEMAIN_ENTITY_H
#define XENGINEMAIN_ENTITY_H

#include "Scene.h"
#include "entt.hpp"

namespace XEngine {
    class Entity
    {
    public:
        Entity() = default;
        Entity(entt::entity handle, Scene* scene);
        Entity(const Entity& other) = default;

        template<typename T, typename... Args>
        T& AdddComponent(Args&&... args)
        {
            XE_CORE_ASSERT(!HasComponent<T>(), "Entity already has component!");
            return m_Scene->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
        }

        template<typename T>
        T& GetComponent()
        {
            XE_CORE_ASSERT(HasComponent<T>(), "Entity does not have component!");
            return m_Scene->m_Registry.get<T>(m_EntityHandle);
        }

        template<typename T>
        bool HasComponent()
        {
            return m_Scene->m_Registry.has<T>(m_EntityHandle);
        }

        template<typename T>
        void RevomeComponent()
        {
            XE_CORE_ASSERT(HasComponent<T>(), "Entity does not have component!");
            m_Scene->m_Registry.remove<T>(m_EntityHandle);
        }

        operator bool() const { return static_cast<int>(m_EntityHandle) != 0; }

    private:
        entt::entity m_EntityHandle{0};
        Scene* m_Scene = nullptr;
    };
}

#endif //XENGINEMAIN_ENTITY_H

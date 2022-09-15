//
// Created by yuan on 9/15/22.
//

#include "xepch.h"
#include "Entity.h"

namespace XEngine {
    Entity::Entity(entt::entity handle, Scene* scene) : m_EntityHandle(handle), m_Scene(scene)
    {
    }
}
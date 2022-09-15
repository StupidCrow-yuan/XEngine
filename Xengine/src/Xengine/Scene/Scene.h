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

        void OnUpdate(Timestep ts);
    private:
        entt::registry m_Registry;

        friend class Entity;
    };
}

#endif //XENGINEMAIN_SCENE_H

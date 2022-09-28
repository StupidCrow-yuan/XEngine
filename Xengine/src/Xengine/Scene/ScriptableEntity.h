//
// Created by yuan on 9/26/22.
//

#ifndef XENGINEMAIN_SCRIPTABLEENTITY_H
#define XENGINEMAIN_SCRIPTABLEENTITY_H

#include "Entity.h"

namespace XEngine {
    class ScriptableEntity
    {
    public:
        virtual ~ScriptableEntity() {}

        template<typename T>
        T& GetComponent()
        {
            return m_Entity.GetComponent<T>();
        }

    protected:
        virtual void OnCreate() {}
        virtual void OnDestroy() {}
        virtual void OnUpdate(Timestep ts) {}

    private:
        Entity m_Entity;
        friend class Scene;
    };
}

#endif //XENGINEMAIN_SCRIPTABLEENTITY_H

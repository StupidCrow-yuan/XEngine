//
// Created by yuan on 4/14/22.
//

#ifndef XENGINEMAIN_LAYER_H
#define XENGINEMAIN_LAYER_H

#include "Xengine/Core/Core.h"
#include "Xengine/Events/Event.h"
#include "Xengine/Core/Timestep.h"

namespace XEngine {
    class Layer {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate(Timestep ts) {}
        virtual void OnImGuiRender() {}
        virtual void OnEvent(Event& event) {}

        const std::string& GetName() const { return m_DebugName; }

    protected:
        std::string  m_DebugName;
    };
}

#endif //XENGINEMAIN_LAYER_H

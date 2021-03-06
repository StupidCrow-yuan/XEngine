//
// Created by yuan on 4/14/22.
//

#ifndef XENGINEMAIN_IMGUILAYER_H
#define XENGINEMAIN_IMGUILAYER_H

#include "Xengine/Core/Layer.h"
#include "Xengine/Events/ApplicationEvent.h"
#include "Xengine/Events/KeyEvent.h"
#include "Xengine/Events/MouseEvent.h"

namespace XEngine {
    class ImGuiLayer : public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer() = default;

        virtual void OnAttach() override;
        virtual void OnDetach() override;

        void Begin();
        void End();

    private:
        float m_Time = 0.0f;
    };
}

#endif //XENGINEMAIN_IMGUILAYER_H

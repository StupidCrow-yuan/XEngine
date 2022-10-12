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
        virtual void OnEvent(Event& e) override;

        void Begin();
        void End();

        void BlockEvents(bool block) { m_BlockEvents = block; }

        void SetDarkThemeColors();

    private:
        bool m_BlockEvents = true;
        float m_Time = 0.0f;
    };
}

#endif //XENGINEMAIN_IMGUILAYER_H

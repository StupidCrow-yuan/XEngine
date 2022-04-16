//
// Created by yuan on 4/14/22.
//

#ifndef XENGINEMAIN_IMGUILAYER_H
#define XENGINEMAIN_IMGUILAYER_H

#include "Xengine/Layer.h"
#include "Xengine/Events/ApplicationEvent.h"
#include "Xengine/Events/KeyEvent.h"
#include "Xengine/Events/MouseEvent.h"

namespace XEngine {
    class ImGuiLayer : public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event &event);

    private:
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
        bool OnMouseMovedEvent(MouseMovedEvent& e);
        bool OnMouseScrolledEvent(MouseScrolledEvent& e);
        bool OnKeyPressedEvent(KeyPressedEvent& e);
        bool OnKeyReleasedEvent(KeyReleasedEvent& e);
        bool OnKeyTypedEvent(KeyTypedEvent& e);
        bool OnWindowResizeEvent(WindowResizeEvent& e);
    private:
        float m_Time = 0.0f;
    };
}

#endif //XENGINEMAIN_IMGUILAYER_H

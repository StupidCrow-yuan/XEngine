//
// Created by yuan on 4/9/22.
//

#include "XEngine.h"

class ExampleLayer : public XEngine::Layer
{
public:
    ExampleLayer() : Layer("Example")
    {
    }

    void OnUpdate() override
    {
        if (XEngine::Input::IsKeyPressed(XE_KEY_TAB))
        {
            XE_TRACE("Tab Key is pressed(poll)!");
        }
    }

    void OnEvent(XEngine::Event& event) override
    {
        if (event.GetEventType() == XEngine::EventType::KeyPressed)
        {
            XEngine::KeyPressedEvent& e = (XEngine::KeyPressedEvent&)event;
            if (e.GetKeyCode() == XE_KEY_TAB)
            {
                XE_TRACE("Tab Key is pressed (event)!");
                XE_TRACE("{0}", (char)e.GetKeyCode());
            }
        }
    }
};

class Sandbox : public XEngine::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer);
        PushOverlay(new XEngine::ImGuiLayer());
    }

    ~Sandbox()
    {
    }
};

XEngine::Application* XEngine::CreateApplication()
{
    return new Sandbox();
}
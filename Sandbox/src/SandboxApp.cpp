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
        XE_INFO("ExampleLayer::Update");
    }

    void OnEvent(XEngine::Event& event) override
    {
        XE_TRACE("{0}", event);
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
//
// Created by yuan on 4/9/22.
//

#include "Application.h"
#include "xepch.h"
#include <glad/glad.h>
#include "Xengine/Core/Input.h"
#include "Renderer/Renderer.h"
#include <glfw/glfw3.h>

namespace XEngine {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        XE_PROFILE_FUNCTION();
        XE_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;
        m_Window = Window::Create();
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

        Renderer::Init();

        m_ImGuiLayer = new ImGuiLayer();
        PushOverlay(m_ImGuiLayer);
    }

    Application::~Application()
    {
        XE_PROFILE_FUNCTION();
        Renderer::ShutDown();
    }

    void Application::PushLayer(Layer *layer)
    {
        XE_PROFILE_FUNCTION();
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *layer)
    {
        XE_PROFILE_FUNCTION();
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }

    void Application::OnEvent(Event &e)
    {
        XE_PROFILE_FUNCTION();
        EventDispatcher dispatcher(e);
        dispatcher.DisPatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
        dispatcher.DisPatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));

        for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
        {
            (*it)->OnEvent(e);
            if (e.Handled)
            {
                break;
            }
        }
    }

    void Application::Run()
    {
        XE_PROFILE_FUNCTION();
        WindowResizeEvent e(1280, 720);
        while (m_Running)
        {
            XE_PROFILE_SCOPE("RunLoop");
            float time = (float)glfwGetTime();
            Timestep timestep = time - m_LastFrameTime;
            m_LastFrameTime = time;

            if (!m_Minimized)
            {
                for (Layer* layer : m_LayerStack)
                {
                    XE_PROFILE_SCOPE("LayerStack OnUpdate");
                    layer->OnUpdate(timestep);
                }
            }

            m_ImGuiLayer->Begin();
            {
                XE_PROFILE_SCOPE("LayerStack OnImGuiRender");
                for (Layer* layer : m_LayerStack)
                    layer->OnImGuiRender();
            }
            m_ImGuiLayer->End();

            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        m_Running = false;
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent &e)
    {
        XE_PROFILE_FUNCTION();
        if (e.GetWidth() == 0 || e.GetHeight() == 0)
        {
            m_Minimized = true;
            return false;
        }
        
        m_Minimized = false;
        Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());
        
        return false;
    }

}

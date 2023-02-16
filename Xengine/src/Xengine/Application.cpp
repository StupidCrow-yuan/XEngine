//
// Created by yuan on 4/9/22.
//

#include "Application.h"
#include "xepch.h"
#include <glad/glad.h>
#include "Xengine/Core/Input.h"
#include "Renderer/Renderer.h"
#include <GLFW/glfw3.h>

namespace XEngine {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application* Application::s_Instance = nullptr;

    Application::Application(const ApplicationSpecification& specification) : m_Specification(specification)
    {
        XE_PROFILE_FUNCTION();
        XE_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        //Set working directory here
        if (!m_Specification.WorkingDirectory.empty())
        {
            std::filesystem::current_path(m_Specification.WorkingDirectory);
        }
        m_Window = Window::Create(WindowProps(m_Specification.Name));//创建窗口
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));//绑定一个事件函数作为glfw的通用回调

        Renderer::Init(m_Window.get()->GetWidth(), m_Window.get()->GetHeight());

        m_ImGuiLayer = new ImGuiLayer();
        PushOverlay(m_ImGuiLayer);//UI层
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

    void Application::Close()
    {
        m_Running = false;
    }

    void Application::OnEvent(Event &e)
    {
        XE_PROFILE_FUNCTION();
        EventDispatcher dispatcher(e);//EventDispatcher里面村里处理event的函数，在event类型跟模板T匹配时，才响应事件
        dispatcher.DisPatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
        dispatcher.DisPatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));

        //layer来处理事件，逆序遍历是为了让ImGuiLayer最先收到Event
        //反向遍历LayerStack，依次查看事件是否被这个layer响应，然后如果这个过程中，事件被handle了，那么就停止往下层layer传递，否则继续遍历
        for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
        {
            if (e.Handled)
            {
                break;
            }
            (*it)->OnEvent(e);
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

            //Render Logic
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

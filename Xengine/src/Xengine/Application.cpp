//
// Created by yuan on 4/9/22.
//

#include "Application.h"
#include "xepch.h"
#include "Xengine/Events/ApplicationEvent.h"
#include <GLFW/glfw3.h>

namespace XEngine {
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        while (m_Running)
        {
            XE_TRACE(e);
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }

}
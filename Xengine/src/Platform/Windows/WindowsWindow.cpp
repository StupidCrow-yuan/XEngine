//
// Created by yuan on 4/13/22.
//

#include "Platform/OpenGL/OpenGLContext.h"
#include "xepch.h"
#include "WindowsWindow.h"
#include "Xengine/Core/Input.h"
#include "Xengine/Events/ApplicationEvent.h"
#include "Xengine/Events/MouseEvent.h"
#include "Xengine/Events/KeyEvent.h"

#include "Renderer/Renderer.h"

namespace XEngine {
    static uint8_t s_GLFWWindowCount = 0;

    static void GLFWErrorCallback(int error, const char* description)
    {
        XE_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    WindowsWindow::WindowsWindow(const WindowProps &props)
    {
        XE_PROFILE_FUNCTION();
        Init(props);
    }

    WindowsWindow::~WindowsWindow()
    {
        XE_PROFILE_FUNCTION();
        Shutdown();
    }

    void WindowsWindow::Init(const WindowProps &props)
    {
        XE_PROFILE_FUNCTION();
        m_data.Title = props.Title;
        m_data.Width = props.Width;
        m_data.Height = props.Height;

        XE_CORE_INFO("Create Window {0}, {1}, {2}", props.Title, props.Width, props.Height);

        if (s_GLFWWindowCount == 0)
        {
            XE_PROFILE_SCOPE("glfwInit");
            XE_CORE_INFO("Initalizing GLFW");
            int success = glfwInit();
            XE_CORE_ASSERT(success, "Could not initialize GLFW!");
            glfwSetErrorCallback(GLFWErrorCallback);
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        XE_CORE_INFO("I'm apple machine");
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        {
            XE_PROFILE_SCOPE("glfwCreateWindow");
#if defined(XE_DEBUG)
            if (Renderer::GetAPI() == RendererAPI::API::OpenGL)
                            glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif
            m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_data.Title.c_str(), nullptr, nullptr);
            ++s_GLFWWindowCount;
        }

        //将glfwWindow设置为当前上下文，一个thread同时只能拥有一个上下文；这里省去了一些函数每次都指定window的麻烦，像glfwSwapInterval()这样的函数只操作当前Context
        m_context = GraphicsContext::Create(m_Window);
        m_context->Init();

        glfwSetWindowUserPointer(m_Window, &m_data);
        SetVSync(true);

        //set glfw callbacks
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
        {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;

            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
        {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
            switch (action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, true);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned  int keycode)
        {
            WindowData& data = *(WindowData*)
            glfwGetWindowUserPointer(window);

            KeyTypedEvent event(keycode);
            data.EventCallback(event);
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
        {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            data.EventCallback(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            MouseMovedEvent event((float)xPos, (float)yPos);
            data.EventCallback(event);
        });
    }

    void WindowsWindow::Shutdown()
    {
        XE_PROFILE_FUNCTION();
        glfwDestroyWindow(m_Window);
        --s_GLFWWindowCount;
        if (s_GLFWWindowCount == 0)
        {
            XE_CORE_INFO("Terminating GLFW");
            glfwTerminate();
        }
    }

    void WindowsWindow::OnUpdate()
    {
        XE_PROFILE_FUNCTION();
        glfwPollEvents();
        m_context->SwapBuffers();//交换缓冲区
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        XE_PROFILE_FUNCTION();
        if (enabled)
        {
            glfwSwapInterval(1);//交换间隔表示交换缓冲区之前等待的帧数，通常称为vsync，即每帧更新一次
        }
        else
        {
            glfwSwapInterval(0);
        }
        m_data.VSnc = enabled;
    }

    bool WindowsWindow::IsVSync() const
    {
        return m_data.VSnc;
    }
}

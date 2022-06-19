//
// Created by yuan on 4/13/22.
//

#include "Platform/OpenGL/OpenGLContext.h"
#include "xepch.h"
#include "WindowsWindow.h"
#include "Xengine/Events/ApplicationEvent.h"
#include "Xengine/Events/MouseEvent.h"
#include "Xengine/Events/KeyEvent.h"

namespace XEngine {
    static uint8_t s_GLFWWindowCount = 0;

    static void GLFWErrorCallback(int error, const char* description)
    {
        XE_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    Scope<Window> Window::Create(const WindowProps &props)
    {
        return CreateScope<WindowsWindow>(props);
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

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        XE_CORE_INFO("I'm apple machine");
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        {
            XE_PROFILE_SCOPE("glfwCreateWindow");
            m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_data.Title.c_str(), nullptr, nullptr);
            ++s_GLFWWindowCount;
        }

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
                    KeyPressedEvent event(key, 1);
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
        m_context->SwapBuffers();
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        XE_PROFILE_FUNCTION();
        if (enabled)
        {
            glfwSwapInterval(1);
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

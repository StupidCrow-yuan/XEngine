//
// Created by yuan on 5/1/22.
//

#include "xepch.h"
#include "OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace XEngine {

    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle) : m_WindowHandle(windowHandle)
    {
        XE_CORE_ASSERT(windowHandle, "Window handle is null!");
    }

    void OpenGLContext::Init()
    {
        XE_PROFILE_FUNCTION();
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        XE_CORE_ASSERT(status, "Failed to initialize glad!");

        XE_CORE_INFO("OpenGL Info:");
        XE_CORE_INFO("  Vendor {0}", glGetString(GL_VENDOR));
        XE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
        XE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

        XE_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Hazel requires at least OpenGL version 4.5!");
    }

    void OpenGLContext::SwapBuffers()
    {
        XE_PROFILE_FUNCTION();
        glfwSwapBuffers(m_WindowHandle);
    }
}
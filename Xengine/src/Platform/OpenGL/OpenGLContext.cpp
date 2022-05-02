//
// Created by yuan on 5/1/22.
//

#include "xepch.h"
#include "OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
//#include <GL/GL.h>

namespace XEngine {

    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle) : m_WindowHandle(windowHandle)
    {
        XE_CORE_ASSERT(windowHandle, "Window handle is null!");
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        XE_CORE_ASSERT(status, "Failed to initialize glad!");

        XE_CORE_INFO("OpenGL Info:");
        XE_CORE_INFO("  Vendor {0}", glGetString(GL_VENDOR));
        XE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
        XE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }
}
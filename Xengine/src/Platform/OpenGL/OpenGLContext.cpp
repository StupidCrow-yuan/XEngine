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

        #ifdef XE_ENABLE_ASSERTS
            int versionMajor;
            int versionMinor;
            glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
            glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

            XE_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Hazel requires at least OpenGL version 4.5!");
        #endif
    }

    void OpenGLContext::SwapBuffers()
    {
        XE_PROFILE_FUNCTION();
        glfwSwapBuffers(m_WindowHandle);
    }
}
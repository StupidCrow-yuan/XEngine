//
// Created by yuan on 6/5/22.
//

#include "xepch.h"
#include "Renderer/GraphicsContext.h"
#include "Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace XEngine {
    Scope<GraphicsContext> GraphicsContext::Create(void *window)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:    XE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
        }

        XE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}

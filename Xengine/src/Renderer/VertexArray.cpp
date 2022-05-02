//
// Created by yuan on 5/2/22.
//

#include "VertexArray.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace XEngine {
    VertexArray* VertexArray::Create()
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:    XE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::API::OpenGL:  return new OpenGLVertexArray();
        }

        XE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}
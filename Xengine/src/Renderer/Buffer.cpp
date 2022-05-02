//
// Created by yuan on 5/2/22.
//

#include "Buffer.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace XEngine {
    VertexBuffer* VertexBuffer::Create(float *vertices, uint32_t size)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
                XE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
                return nullptr;
            case RendererAPI::API::OpenGL:
                return new OpenGLVertexBuffer(vertices, size);
        }
        XE_CORE_ASSERT(false, "Unknow RendererAPI!");
        return nullptr;
    }

    IndexBuffer* IndexBuffer::Create(uint32_t *indices, uint32_t size)
    {
        switch (Renderer::GetAPI()) {
            case RendererAPI::API::None:
                XE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
                return nullptr;
            case RendererAPI::API::OpenGL:
                return new OpenGLIndexBuffer(indices, size);
        }
        XE_CORE_ASSERT(false, "Unknow RendererAPI!");
        return nullptr;
    }
}
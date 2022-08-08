//
// Created by yuan on 8/4/22.
//

#include "xepch.h"
#include "Framebuffer.h"

#include "Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLFramebuffer.h"

namespace XEngine
{
    Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification &spec)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
                XE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::API::OpenGL: return CreateRef<OpenGLFramebuffer>(spec);
        }
        XE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}
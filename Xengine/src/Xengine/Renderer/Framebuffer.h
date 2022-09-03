//
// Created by yuan on 8/4/22.
//

#ifndef XENGINEMAIN_FRAMEBUFFER_H
#define XENGINEMAIN_FRAMEBUFFER_H

#include "Xengine/Core/Base.h"

namespace XEngine
{
    struct FramebufferSpecification
    {
        uint32_t Width, Height;
        //FramebufferFormat
        uint32_t Samples = 1;

        bool SwapChainTarget = false;
    };

    class Framebuffer
    {
    public:
        virtual void Bind() = 0;
        virtual void Unbind() = 0;

        virtual uint32_t GetColorAttachmentRendererID() const = 0;

        virtual const FramebufferSpecification& GetSpecification() const = 0;

        static Ref<Framebuffer> Create(const FramebufferSpecification& spec);

        virtual void ReadPixel(const std::string& path) {};
    };
}

#endif //XENGINEMAIN_FRAMEBUFFER_H

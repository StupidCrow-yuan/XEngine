//
// Created by yuan on 8/4/22.
//

#ifndef XENGINEMAIN_OPENGLFRAMEBUFFER_H
#define XENGINEMAIN_OPENGLFRAMEBUFFER_H

#include "Xengine/Renderer/Framebuffer.h"

namespace XEngine
{
    class OpenGLFramebuffer : public Framebuffer
    {
    public:
        OpenGLFramebuffer(const FramebufferSpecification& spec);
        virtual ~OpenGLFramebuffer();

        void Invalidate();

        virtual void Bind() override;
        virtual void Unbind() override;

        virtual void ReadPixel(const std::string& path) override;

        virtual uint32_t GetColorAttachmentRendererID() const override { return m_ColorAttachment; };

        virtual const FramebufferSpecification& GetSpecification() const override { return m_Specification; }
    private:
        uint32_t m_RendererID;
        uint32_t m_ColorAttachment, m_DepthAttachment;
        FramebufferSpecification m_Specification;
    };
}

#endif //XENGINEMAIN_OPENGLFRAMEBUFFER_H

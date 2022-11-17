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

        virtual void Resize(uint32_t width, uint32_t height) override;
        virtual int ReadPixel(uint32_t attachmentIndex, int x, int y) override;

        virtual void ReadPixel(const std::string& path) override;

        virtual uint32_t GetColorAttachmentRendererID(uint32_t index = 0) const override { XE_CORE_ASSERT(index < m_ColorAttachments.size()); return m_ColorAttachments.size() > 0 ? m_ColorAttachments[index] : 0; };

        virtual const FramebufferSpecification& GetSpecification() const override { return m_Specification; }
    private:
        uint32_t m_RendererID = 0;
        std::vector<uint32_t> m_ColorAttachments;
        uint32_t m_DepthAttachment = 0;
        FramebufferSpecification m_Specification;

        std::vector<FramebufferTextureSpecification> m_ColorAttachmentSpecifications;
        FramebufferTextureSpecification m_DepthAttachmentSpecification = FramebufferTextureFormat::None;
    };
}

#endif //XENGINEMAIN_OPENGLFRAMEBUFFER_H

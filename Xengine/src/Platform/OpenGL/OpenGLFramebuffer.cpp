//
// Created by yuan on 8/4/22.
//

#include "xepch.h"
#include "OpenGLFramebuffer.h"

#include <glad/glad.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

namespace XEngine
{
    OpenGLFramebuffer::OpenGLFramebuffer(const FramebufferSpecification &spec)
            : m_Specification(spec)
    {
        Invalidate();
    }

    OpenGLFramebuffer::~OpenGLFramebuffer()
    {
        glDeleteFramebuffers(1, &m_RendererID);
        glDeleteTextures(1, &m_ColorAttachment);
//        glDeleteTextures(1, &m_DepthAttachment);
    }

    void OpenGLFramebuffer::Invalidate()
    {
        if (m_RendererID)
        {
            glDeleteFramebuffers(1, &m_RendererID);
            glDeleteTextures(1, &m_ColorAttachment);
//            glDeleteTextures(1, &m_DepthAttachment);
        }

        glGenFramebuffers(1, &m_RendererID);
        glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID);

        glGenTextures(1, &m_ColorAttachment);
        glBindTexture(GL_TEXTURE_2D, m_ColorAttachment);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Specification.Width, m_Specification.Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //将当前颜色附加到当前绑定的帧缓冲对象
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_ColorAttachment, 0);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);

//        //深度缓冲
//        glGenRenderbuffers(1, &m_DepthAttachment);
//        glBindRenderbuffer(GL_RENDERBUFFER, m_DepthAttachment);
//        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, m_Specification.Width, m_Specification.Height);
//
//        //将渲染缓冲对象附加到帧缓冲的深度和模板附件上
//        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_DepthAttachment);
//        glBindRenderbuffer(GL_RENDERBUFFER, 0);

        XE_CORE_ASSERT(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE, "Framebuffer is incomplete!");

    }

    void OpenGLFramebuffer::Bind()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID);
        glViewport(0, 0, m_Specification.Width, m_Specification.Height);
    }

    void OpenGLFramebuffer::Unbind()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void OpenGLFramebuffer::Resize(uint32_t width, uint32_t height)
    {
        m_Specification.Width = width;
        m_Specification.Height = height;

        Invalidate();//宽高发生变化得重新生成framebuffer
    }

    void OpenGLFramebuffer::ReadPixel(const std::string& path) {
        this->Bind();//readPixels之前重新绑定一下当前缓冲纹理
        unsigned char* data = new unsigned char[m_Specification.Width * m_Specification.Height * 4];
        memset(data, 0, m_Specification.Width * m_Specification.Height * 4);
        glReadPixels(0, 0,m_Specification.Width, m_Specification.Height, GL_RGBA, GL_UNSIGNED_BYTE,  data);
        stbi_write_png(path.c_str(), m_Specification.Width, m_Specification.Height, 4, data, m_Specification.Width * 4);

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        delete[] data;
    }
}
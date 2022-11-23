//
// Created by yuan on 11/22/22.
//

#include "xepch.h"
#include "OpenGLUniformBuffer.h"

#include <glad/glad.h>

namespace XEngine {

    OpenGLUniformBuffer::OpenGLUniformBuffer(uint32_t size, uint32_t binding)
    {
//        glCreateBuffers(1, &m_RendererID);
//        glNamedBufferData(m_RendererID, size, nullptr, GL_DYNAMIC_DRAW);// todo: investigate usage hint
//        glBindBufferBase(GL_UNIFORM_BUFFER, binding, m_RendererID);
        glGenBuffers(1, &m_RendererID);
        glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID);
    }

    OpenGLUniformBuffer::~OpenGLUniformBuffer()
    {
        glDeleteBuffers(1, &m_RendererID);
    }

    void OpenGLUniformBuffer::SetData(const void *data, uint32_t size, uint32_t offset)
    {
//        glNamedBufferSubData(m_RendererID, offset, size, data);
        glBufferStorage(GL_FRAMEBUFFER, sizeof(data), data, 0);
    }
}
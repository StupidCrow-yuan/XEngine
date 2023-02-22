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
//        glGenBuffers(1, &m_RendererID);
//        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
        glGenBuffers(1, &m_RendererID);
        glBindBuffer(GL_UNIFORM_BUFFER, m_RendererID);
        glBufferData(GL_UNIFORM_BUFFER, size, NULL, GL_STATIC_DRAW); // 分配size个字节的内存空间
        glBindBuffer(GL_UNIFORM_BUFFER, 0);
    }

    OpenGLUniformBuffer::~OpenGLUniformBuffer()
    {
        glDeleteBuffers(1, &m_RendererID);
    }

    void OpenGLUniformBuffer::SetData(const void *data, uint32_t size, uint32_t offset)
    {
//        glNamedBufferSubData(m_RendererID, offset, size, data);//opengl4.5开始支持
        glBufferStorage(GL_UNIFORM_BUFFER, sizeof(data), data, 0);
//        GLint b = true;
//        glBufferSubData(GL_UNIFORM_BUFFER, size, 4, &b);
    }
}
//
// Created by yuan on 5/2/22.
//

#include "xepch.h"
#include "OpenGLVertexArray.h"
#include <glad/glad.h>

namespace XEngine {

    static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
    {
        switch (type)
        {
            case XEngine::ShaderDataType::Float:    return GL_FLOAT;
            case XEngine::ShaderDataType::Float2:   return GL_FLOAT;
            case XEngine::ShaderDataType::Float3:   return GL_FLOAT;
            case XEngine::ShaderDataType::Float4:   return GL_FLOAT;
            case XEngine::ShaderDataType::Mat3:     return GL_FLOAT;
            case XEngine::ShaderDataType::Mat4:     return GL_FLOAT;
            case XEngine::ShaderDataType::Int:      return GL_INT;
            case XEngine::ShaderDataType::Int2:     return GL_INT;
            case XEngine::ShaderDataType::Int3:     return GL_INT;
            case XEngine::ShaderDataType::Int4:     return GL_INT;
            case XEngine::ShaderDataType::Bool:     return GL_BOOL;
        }

        XE_CORE_ASSERT(false, "Unknown ShaderDataType!");
        return 0;
    }

    OpenGLVertexArray::OpenGLVertexArray()
    {
        glGenVertexArrays(1, &m_RendererID);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &m_RendererID);
    }

    void OpenGLVertexArray::Bind() const
    {
        glBindVertexArray(m_RendererID);
    }

    void OpenGLVertexArray::UnBind() const
    {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer)
    {
        XE_CORE_ASSERT(vertexBuffer->GetLayout().GetLayout().GetElements().size(), "VertexBuffer Buffer has no layout!");

        glBindVertexArray(m_RendererID);
        vertexBuffer->Bind();

        uint32_t index = 0;
        const auto& layout = vertexBuffer->GetLayout();
        for (const auto& element : layout)
        {
            glEnableVertexAttribArray(index + m_VertexBufferIndexOffset);
            glVertexAttribPointer(index + m_VertexBufferIndexOffset, element.GetComponentCount(),
                                  ShaderDataTypeToOpenGLBaseType(element.Type),
                                  element.Normalized ? GL_TRUE : GL_FALSE,
                                  layout.GetStride(),
                                  (const void*)(intptr_t)element.Offset);
            index++;
        }
        m_VertexBuffers.push_back(vertexBuffer);
        m_VertexBufferIndexOffset += layout.GetElements().size();
    }

    void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer)
    {
        glBindVertexArray(m_RendererID);
        indexBuffer->Bind();
        m_IndexBuffer = indexBuffer;
    }
}
//
// Created by yuan on 5/2/22.
//

#ifndef XENGINEMAIN_OPENGLVERTEXARRAY_H
#define XENGINEMAIN_OPENGLVERTEXARRAY_H

#include "Renderer/VertexArray.h"

namespace XEngine {
    class OpenGLVertexArray : public VertexArray
    {
    public:
        OpenGLVertexArray();
        virtual ~OpenGLVertexArray();

        virtual void Bind() const override;
        virtual void UnBind() const override;

        virtual void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) override;
        virtual void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer) override;

        virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const { return m_VertexBuffers; }
        virtual const Ref<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }

    private:
        uint32_t m_RendererID;
        std::vector<Ref<VertexBuffer>> m_VertexBuffers;
        Ref<IndexBuffer> m_IndexBuffer;
        uint32_t m_VertexBufferIndex = 0;
    };
}

#endif //XENGINEMAIN_OPENGLVERTEXARRAY_H

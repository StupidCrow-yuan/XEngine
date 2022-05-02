//
// Created by yuan on 5/2/22.
//

#ifndef XENGINEMAIN_OPENGLBUFFER_H
#define XENGINEMAIN_OPENGLBUFFER_H

#include "Renderer/Buffer.h"

namespace XEngine {
    class OpenGLVertexBuffer : public VertexBuffer {
    public:
        OpenGLVertexBuffer(float* vertices, uint32_t size);
        virtual ~OpenGLVertexBuffer();

        virtual void Bind() const;
        virtual void UnBind() const;

    private:
        uint32_t m_RendererID;
    };

    class OpenGLIndexBuffer : public IndexBuffer {
    public:
        OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
        virtual ~OpenGLIndexBuffer();

        virtual void Bind() const;
        virtual void UnBind() const;

        virtual uint32_t GetCount() const { return m_Count; }

    private:
        uint32_t m_RendererID;
        uint32_t m_Count;
    };
}

#endif //XENGINEMAIN_OPENGLBUFFER_H

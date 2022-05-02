//
// Created by yuan on 5/2/22.
//

#ifndef XENGINEMAIN_BUFFER_H
#define XENGINEMAIN_BUFFER_H

#include "xepch.h"

namespace XEngine {
    class VertexBuffer
    {
    public:
        virtual ~VertexBuffer() {}

        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;

        static VertexBuffer* Create(float* vertices, uint32_t size);
    };

    class IndexBuffer
    {
    public:
        virtual ~IndexBuffer() {}

        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;

        virtual uint32_t GetCount() const = 0;

        static IndexBuffer* Create(uint32_t* indices, uint32_t size);
    };
}

#endif //XENGINEMAIN_BUFFER_H

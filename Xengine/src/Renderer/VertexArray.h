//
// Created by yuan on 5/2/22.
//

#ifndef XENGINEMAIN_VERTEXARRAY_H
#define XENGINEMAIN_VERTEXARRAY_H

#include <memory>
#include "Renderer/Buffer.h"

namespace XEngine {
    class VertexArray {
    public:
        virtual ~VertexArray() {}

        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;

        virtual void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) = 0;
        virtual void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer) = 0;

        virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const = 0;
        virtual const Ref<IndexBuffer>& GetIndexBuffer() const = 0;

        static Ref<VertexArray> Create();
    };
}

#endif //XENGINEMAIN_VERTEXARRAY_H

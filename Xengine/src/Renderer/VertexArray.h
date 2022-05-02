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

        virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;
        virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) = 0;

        virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const = 0;
        virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const = 0;

        static VertexArray* Create();
    };
}

#endif //XENGINEMAIN_VERTEXARRAY_H

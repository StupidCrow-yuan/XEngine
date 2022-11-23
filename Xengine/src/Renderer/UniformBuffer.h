//
// Created by yuan on 11/22/22.
//

#ifndef XENGINEMAIN_UNIFORMBUFFER_H
#define XENGINEMAIN_UNIFORMBUFFER_H

#include "Xengine/Core/Base.h"

namespace XEngine {
    class UniformBuffer
    {
    public:
        virtual ~UniformBuffer() {}
        virtual void SetData(const void* data, uint32_t size, uint32_t offset = 0) = 0;

        static Ref<UniformBuffer> Create(uint32_t size, uint32_t binding);
    };
}

#endif //XENGINEMAIN_UNIFORMBUFFER_H

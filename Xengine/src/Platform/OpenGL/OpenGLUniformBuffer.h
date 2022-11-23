//
// Created by yuan on 11/22/22.
//

#ifndef XENGINEMAIN_OPENGLUNIFORMBUFFER_H
#define XENGINEMAIN_OPENGLUNIFORMBUFFER_H

#include "Renderer/UniformBuffer.h"

namespace XEngine {
    class OpenGLUniformBuffer : public UniformBuffer
    {
    public:
        OpenGLUniformBuffer(uint32_t size, uint32_t binding);
        virtual ~OpenGLUniformBuffer();

        virtual void SetData(const void* data, uint32_t size, uint32_t offset = 0) override;

    private:
        uint32_t m_RendererID = 0;
    };
}

#endif //XENGINEMAIN_OPENGLUNIFORMBUFFER_H

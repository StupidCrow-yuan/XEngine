//
// Created by yuan on 5/2/22.
//

#ifndef XENGINEMAIN_OPENGLRENDERERAPI_H
#define XENGINEMAIN_OPENGLRENDERERAPI_H

#include "Renderer/RendererAPI.h"

namespace XEngine {
    class OpenGLRendererAPI : public RendererAPI
    {
    public:
        virtual void Init() override;
        
        virtual void SetViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;

        virtual void SetClearColor(const glm::vec4& color) override;
        virtual void Clear() override;

        virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
    };
}

#endif //XENGINEMAIN_OPENGLRENDERERAPI_H

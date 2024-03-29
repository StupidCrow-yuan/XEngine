//
// Created by yuan on 5/2/22.
//

#ifndef XENGINEMAIN_RENDERCOMMAND_H
#define XENGINEMAIN_RENDERCOMMAND_H

#include "RendererAPI.h"

namespace XEngine {
    class RenderCommand
    {
    public:
        static void Init()
        {
            s_RendererAPI->Init();
        }

        static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
        {
            s_RendererAPI->SetViewPort(x, y, width, height);
        }
        
        static void SetClearColor(const glm::vec4& color)
        {
            s_RendererAPI->SetClearColor(color);
        }

        static void Clear()
        {
            s_RendererAPI->Clear();
        }

        static void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexcount = 0)
        {
            s_RendererAPI->DrawIndexed(vertexArray, indexcount);
        }

        static void DrawLines(const Ref<VertexArray>& vertexArray, uint32_t vertexCount)
        {
            s_RendererAPI->DrawLines(vertexArray, vertexCount);
        }

        static void SetLineWidth(float width)
        {
            s_RendererAPI->SetLineWidth(width);
        }

    private:
        static  Scope<RendererAPI> s_RendererAPI;
    };
}

#endif //XENGINEMAIN_RENDERCOMMAND_H

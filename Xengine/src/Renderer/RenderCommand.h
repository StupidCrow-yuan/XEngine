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
        inline static void SetClearColor(const glm::vec4& color)
        {
            s_RendererAPI->SetClearColor(color);
        }

        inline static void Clear()
        {
            s_RendererAPI->Clear();
        }

        inline static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
        {
            s_RendererAPI->DrawIndexed(vertexArray);
        }
    private:
        static  RendererAPI* s_RendererAPI;
    };
}

#endif //XENGINEMAIN_RENDERCOMMAND_H
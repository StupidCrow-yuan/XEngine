//
// Created by yuan on 5/2/22.
//

#include "xepch.h"
#include "Renderer.h"

namespace XEngine {
    void Renderer::BeginScene()
    {
    }

    void Renderer::EndScene()
    {
    }

    void Renderer::Submit(const std::shared_ptr<VertexArray> &vertexArray)
    {
        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray);
    }
}
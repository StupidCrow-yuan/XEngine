//
// Created by yuan on 5/2/22.
//

#ifndef XENGINEMAIN_RENDERER_H
#define XENGINEMAIN_RENDERER_H

#include "RenderCommand.h"

namespace XEngine {

    class Renderer {
    public:
     static void BeginScene();
     static void EndScene();

     static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

     inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
    };
}


#endif //XENGINEMAIN_RENDERER_H

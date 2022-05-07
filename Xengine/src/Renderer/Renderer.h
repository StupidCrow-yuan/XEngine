//
// Created by yuan on 5/2/22.
//

#ifndef XENGINEMAIN_RENDERER_H
#define XENGINEMAIN_RENDERER_H

#include "RenderCommand.h"

#include "OrthographicCamera.h"
#include "Shader.h"

namespace XEngine {

    class Renderer
    {
    public:
     static  void Init();
     static void BeginScene(OrthographicCamera& camera);
     static void EndScene();

     static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

     inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

    private:
        struct SceneData
        {
            glm::mat4 ViewProjectionMatrix;
        };

        static SceneData* s_SceneData;
    };
}


#endif //XENGINEMAIN_RENDERER_H

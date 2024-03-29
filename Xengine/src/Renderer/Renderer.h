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
      static void Init(uint32_t width, uint32_t height);
     static void ShutDown();

     static void OnWindowResize(uint32_t width, uint32_t height);
     static void BeginScene(OrthographicCamera& camera);
     static void EndScene();

     static void Submit(const Ref<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

     static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

    private:
        struct SceneData
        {
            glm::mat4 ViewProjectionMatrix;
        };

        static Scope<SceneData> s_SceneData;
    };
}


#endif //XENGINEMAIN_RENDERER_H

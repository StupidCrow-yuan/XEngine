//
// Created by yuan on 5/30/22.
//

#ifndef XENGINEMAIN_RENDERER2D_H
#define XENGINEMAIN_RENDERER2D_H

#include "OrthographicCamera.h"

namespace XEngine {

    class Renderer2D
    {
    public:
        static void Init();
        static void ShutDown();

        static void BeginScene(const OrthographicCamera& camera);
        static void EndScene();

        //privatives
        static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
        static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
    };
}

#endif //XENGINEMAIN_RENDERER2D_H

//
// Created by yuan on 5/30/22.
//

#ifndef XENGINEMAIN_RENDERER2D_H
#define XENGINEMAIN_RENDERER2D_H

#include "OrthographicCamera.h"
#include "Texture.h"

namespace XEngine {

    class Renderer2D
    {
    public:
        static void Init(uint32_t width, uint32_t height);
        static void ShutDown();

        static void BeginScene(const OrthographicCamera& camera);
        static void EndScene();
        static void Flush();

        //privatives
        static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
        static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);

        static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
        static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));

        static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const glm::vec4& color);
        static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& color);
        static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
        static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
        
        //stats
        struct Statistics
        {
            uint32_t DrawCalls = 0;
            uint32_t QuadCount = 0;
            
            uint32_t GetTotalVertexCount() { return  QuadCount * 4; }
            uint32_t GetTotalIndexCount()  { return  QuadCount * 6; }
        };
        
        static void ResetStats();
        static Statistics GetStats();

        static uint32_t Width;
        static uint32_t Height;
        
    private:
        static void FlushAndReset();
    };
}

#endif //XENGINEMAIN_RENDERER2D_H

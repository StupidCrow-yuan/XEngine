//
// Created by yuan on 5/2/22.
//

#include "xepch.h"
#include "OpenGLRendererAPI.h"
#include <glad/glad.h>

namespace XEngine {

    void OpenGLMessageCallbcak(
                               unsigned source,
                               unsigned type,
                               unsigned id,
                               unsigned severity,
                               int length,
                               const char* message,
                               const void* userParam)
    {
        switch (severity)
        {
            case GL_DEBUG_SEVERITY_HIGH:
                XE_CORE_CRITICAL(message);
                return;
                
            case GL_DEBUG_SEVERITY_MEDIUM:
                XE_CORE_ERROR(message);
                return;
                
            case GL_DEBUG_SEVERITY_LOW:
                XE_CORE_WARN(message);
                return;
                
            case GL_DEBUG_SEVERITY_NOTIFICATION:
                XE_CORE_TRACE(message);
                return;
        }
        
        XE_CORE_ASSERT(false, "Unknown severity level!");
    }

    void OpenGLRendererAPI::Init()
    {
        XE_PROFILE_FUNCTION();
        
#ifdef XE_DEBUG
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(OpenglMessageCallback, nullptr);
        glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE,GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
#endif

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glDisable(GL_DEPTH_TEST);//关闭深度测试，确保绘制方式是按画家算法即先画不透明物体，且由近到远开始绘制；在画透明物体，又远到近绘制
        glEnable(GL_LINE_SMOOTH);//启用线抗锯齿
    }

    void OpenGLRendererAPI::SetViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
    {
        glViewport(x, y, width, height);
    }

    void OpenGLRendererAPI::SetClearColor(const glm::vec4 &color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void OpenGLRendererAPI::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLRendererAPI::DrawIndexed(const Ref<VertexArray> &vertexArray, uint32_t indexCount)
    {
        vertexArray->Bind();
        uint32_t count = indexCount ? indexCount : vertexArray->GetIndexBuffer()->GetCount();
        glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
    }

    void OpenGLRendererAPI::DrawLines(const Ref<VertexArray> &vertexArray, uint32_t vertexCount)
    {
        vertexArray->Bind();
        glDrawArrays(GL_LINE_STRIP, 0, vertexCount);//绘制线，需要设置为GL_LINE_STRIP, GL_LINE模式无效
    }

    void OpenGLRendererAPI::SetLineWidth(float width)
    {
        GLfloat lineWidthRange[2] = {0.0f, 0.0f};
        glGetFloatv(GL_ALIASED_LINE_WIDTH_RANGE, lineWidthRange);
        glLineWidth(width);//line 宽度设置范围为0.0~1.0
    }
}

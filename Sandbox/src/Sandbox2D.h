//
// Created by yuan on 5/28/22.
//

#ifndef XENGINEMAIN_SANDBOX2D_H
#define XENGINEMAIN_SANDBOX2D_H

#include "XEngine.h"

class Sandbox2D : public XEngine::Layer
{
public:
    Sandbox2D();
    virtual ~Sandbox2D() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void OnUpdate(XEngine::Timestep ts) override;
    virtual void OnImGuiRender() override;
    void OnEvent(XEngine::Event& e) override;

private:
    XEngine::OrthographicCameraController m_CameraController;

    //temp
    XEngine::Ref<XEngine::VertexArray> m_SquareVA;
    XEngine::Ref<XEngine::Shader> m_FlatColorShader;

    XEngine::Ref<XEngine::Texture2D> m_CheckboardTexture;

    struct ProfileResult
    {
        const char* Name;
        float Time;
    };

    std::vector<ProfileResult> m_ProfileResults;

    glm::vec4 m_SquareColor = {0.9f, 0.3f, 0.8f, 1.0f};
};


#endif //XENGINEMAIN_SANDBOX2D_H

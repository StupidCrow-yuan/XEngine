//
// Created by yuan on 6/19/22.
//

#ifndef XENGINEMAIN_EXAMPLELAYER_H
#define XENGINEMAIN_EXAMPLELAYER_H

#include "XEngine.h"

class ExampleLayer : public XEngine::Layer
{
public:
    ExampleLayer();
    virtual ~ExampleLayer() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void OnUpdate(XEngine::Timestep ts) override;
    virtual void OnImGuiRender() override;
    void OnEvent(XEngine::Event& e) override;
private:
    XEngine::ShaderLibrary m_ShaderLibrary;
    XEngine::Ref<XEngine::Shader> m_Shader;
    XEngine::Ref<XEngine::VertexArray> m_VertexArray;

    XEngine::Ref<XEngine::Shader> m_FlatColorShader;
    XEngine::Ref<XEngine::VertexArray> m_SquareVA;

    XEngine::Ref<XEngine::Texture2D> m_Texture, m_ChernoLogoTexture;

    XEngine::OrthographicCameraController m_CameraController;
    glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};


#endif //XENGINEMAIN_EXAMPLELAYER_H

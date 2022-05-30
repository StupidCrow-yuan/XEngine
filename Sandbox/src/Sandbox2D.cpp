//
// Created by yuan on 5/28/22.
//

#include "Sandbox2D.h"
#include "imgui.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Platform/OpenGL/OpenGLShader.h"

Sandbox2D::Sandbox2D() : Layer("Sandbox2D"), m_CameraController(1280.0f/ 720.0f)
{
}

void Sandbox2D::OnAttach()
{
    m_SquareVA = XEngine::VertexArray::Create();
    float squareVertices[3 * 4] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.5f,  0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f
    };

    XEngine::Ref<XEngine::VertexBuffer> squareVB;
    squareVB.reset(XEngine::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
    squareVB->SetLayout({
                                {XEngine::ShaderDataType::Float3, "a_Position"}
    });
    m_SquareVA->AddVertexBuffer(squareVB);

    uint32_t squareIndices[6] = {0, 1,2, 2, 3, 0};
    XEngine::Ref<XEngine::IndexBuffer> squareIB;
    squareIB.reset(XEngine::IndexBuffer::Create(squareIndices, sizeof(squareIndices)));
    m_SquareVA->SetIndexBuffer(squareIB);

    m_FlatColorShader = XEngine::Shader::Create(CPP_SRC_DIR"Sandbox/assets/shaders/FlatColor.glsl");
};

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(XEngine::Timestep ts)
{
    //update
    m_CameraController.OnUpdate(ts);

    //Render
    XEngine::RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1.0f});
    XEngine::RenderCommand::Clear();

    XEngine::Renderer::BeginScene(m_CameraController.GetCamera());

    std::dynamic_pointer_cast<XEngine::OpenGLShader>(m_FlatColorShader)->Bind();
    std::dynamic_pointer_cast<XEngine::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

    XEngine::Renderer::Submit(m_FlatColorShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

    XEngine::Renderer::EndScene();
}

void Sandbox2D::OnImGuiRender()
{
    ImGui::Begin("Settings");
    ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
    ImGui::End();
}

void Sandbox2D::OnEvent(XEngine::Event &e)
{
    m_CameraController.OnEvent(e);
}

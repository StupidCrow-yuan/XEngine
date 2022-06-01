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

    XEngine::Renderer2D::BeginScene(m_CameraController.GetCamera());
    XEngine::Renderer2D::DrawQuad({0.0f, 0.0f}, {1.0f, 1.0f}, {0.8f, 0.2f, 0.3f, 1.0f});
    XEngine::Renderer2D::EndScene();
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

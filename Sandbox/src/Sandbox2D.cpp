//
// Created by yuan on 5/28/22.
//

#include "Sandbox2D.h"
#include <imgui.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D() : Layer("Sandbox2D"), m_CameraController(1280.0f/ 720.0f)
{
}

void Sandbox2D::OnAttach()
{
    XE_PROFILE_FUNCTION();
    m_CheckboardTexture = XEngine::Texture2D::Create(CPP_SRC_DIR"Sandbox/assets/textures/Checkerboard.png");
};

void Sandbox2D::OnDetach()
{
    XE_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(XEngine::Timestep ts)
{
    XE_PROFILE_FUNCTION();
    //update
    m_CameraController.OnUpdate(ts);

    //Render
    XEngine::Renderer2D::ResetStats();
    {
        XE_PROFILE_SCOPE("Renderer Prep");
        XEngine::RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1.0f});
        XEngine::RenderCommand::Clear();
    }

    {
        static float rotation = 0.0f;
        rotation += ts * 50.0f;
        
        XE_PROFILE_SCOPE("Renderer Draw");
        XEngine::Renderer2D::BeginScene(m_CameraController.GetCamera());
        
        XEngine::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
        XEngine::Renderer2D::DrawQuad({-1.0, 0.0f}, {0.8f, 0.8f}, { 0.8f, 0.2f, 0.3f, 1.0f });
        XEngine::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });

        XEngine::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckboardTexture, 10.0f);
        XEngine::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckboardTexture, 20.0f);
        
        XEngine::Renderer2D::EndScene();
        
        XEngine::Renderer2D::BeginScene(m_CameraController.GetCamera());
        for (float y = -5.0f; y < 5.0f; y += 0.5f)
        {
            for (float x = -5.0f; x < 5.0f; x += 0.5f)
            {
                glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f};
                XEngine::Renderer2D::DrawQuad({x, y}, {0.450, 0.45f}, color);
            }
        }
        XEngine::Renderer2D::EndScene();
    }

}

void Sandbox2D::OnImGuiRender()
{
    XE_PROFILE_FUNCTION();
    ImGui::Begin("Settings");
    
    auto stats = XEngine::Renderer2D::GetStats();
    ImGui::Text("Renderer2D Stats:");
    ImGui::Text("Draw Calls: %d", stats.DrawCalls);
    ImGui::Text("Quads: %d", stats.QuadCount);
    ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
    ImGui::Text("Indices: %d", stats.GetTotalIndexCount());
    
    ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
    ImGui::End();
}

void Sandbox2D::OnEvent(XEngine::Event &e)
{
    m_CameraController.OnEvent(e);
}

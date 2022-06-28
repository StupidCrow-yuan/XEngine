//
// Created by yuan on 5/12/22.
//

#include "xepch.h"
#include "OrthographicCameraController.h"

#include "Xengine/Core/Input.h"
#include "Xengine/Core/KeyCodes.h"

namespace XEngine {

    OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation)
        : m_AspectRatio(aspectRatio), m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel), m_Rotation(rotation)
    {
    }

    void OrthographicCameraController::OnUpdate(Timestep ts)
    {
        XE_PROFILE_FUNCTION();
        if (Input::IsKeyPressed(XE_KEY_A))
        {
            m_CameraPostion.x += cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
            m_CameraPostion.y += sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
        } else if (Input::IsKeyPressed(XE_KEY_D))
        {
            m_CameraPostion.x -= cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
            m_CameraPostion.y -= sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
        }

        if (Input::IsKeyPressed(XE_KEY_W))
        {
            m_CameraPostion.x -= sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
            m_CameraPostion.y -= cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
        } else if (Input::IsKeyPressed(XE_KEY_S))
        {
            m_CameraPostion.x += sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
            m_CameraPostion.y += cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
        }

        if (m_Rotation)
        {
            if (Input::IsKeyPressed(XE_KEY_Q))
            {
                m_CameraRotation -= m_CameraTranslationSpeed * ts;
            }
            if (Input::IsKeyPressed(XE_KEY_E))
            {
                m_CameraRotation += m_CameraTranslationSpeed * ts;
            }
            if (m_CameraRotation > 180.0f)
                m_CameraRotation -= 360.0f;
            else if (m_CameraRotation <= -180.0f)
                m_CameraRotation += 360.0f;
        }
        m_Camera.SetRotation(m_CameraRotation);//need to call SetRotation to RecalculateViewMatrix
        m_Camera.SetPosition(m_CameraPostion);
        m_CameraTranslationSpeed = m_ZoomLevel;
    }

    void OrthographicCameraController::OnEvent(Event &e)
    {
        XE_PROFILE_FUNCTION();
        EventDispatcher dispatcher(e);
        dispatcher.DisPatch<MouseScrolledEvent>(XE_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
        dispatcher.DisPatch<WindowResizeEvent>(XE_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
    }

    bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent &e)
    {
        XE_PROFILE_FUNCTION();
        m_ZoomLevel -= e.GetYOffset() * 0.25f;
        m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
        m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
        return false;
    }

    bool OrthographicCameraController::OnWindowResized(WindowResizeEvent &e)
    {
        XE_PROFILE_FUNCTION();
        m_AspectRatio = (float)e.GetWidth() / (float)e.GetHeight();
        m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
        return false;
    }
}

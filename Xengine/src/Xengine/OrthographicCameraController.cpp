//
// Created by yuan on 5/12/22.
//

#include "xepch.h"
#include "OrthographicCameraController.h"

#include "Xengine/Input.h"
#include "Xengine/KeyCodes.h"

namespace XEngine {

    OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation)
        : m_AspectRatio(aspectRatio), m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel), m_Rotation(rotation)
    {
    }

    void OrthographicCameraController::OnUpdate(Timestep ts)
    {
        if (Input::IsKeyPressed(XE_KEY_A))
        {
            m_CameraPostion.x -= m_CameraTranslationSpeed * ts;
        } else if (Input::IsKeyPressed(XE_KEY_D))
        {
            m_CameraPostion.x += m_CameraTranslationSpeed * ts;
        }

        if (Input::IsKeyPressed(XE_KEY_W))
        {
            m_CameraPostion.y += m_CameraTranslationSpeed * ts;
        } else if (Input::IsKeyPressed(XE_KEY_S))
        {
            m_CameraPostion.y -= m_CameraTranslationSpeed * ts;
        }

        if (m_Rotation)
        {
            if (Input::IsKeyPressed(XE_KEY_Q))
            {
                m_CameraRotation += m_CameraTranslationSpeed * ts;
            }
            if (Input::IsKeyPressed(XE_KEY_E))
            {
                m_CameraRotation -= m_CameraTranslationSpeed * ts;
            }
        }
        m_Camera.SetRotation(m_CameraRotation);//need to call SetRotation to RecalculateViewMatrix
        m_Camera.SetPosition(m_CameraPostion);
        m_CameraTranslationSpeed = m_ZoomLevel;
    }

    void OrthographicCameraController::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.DisPatch<MouseScrolledEvent>(XE_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
        dispatcher.DisPatch<WindowResizeEvent>(XE_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
    }

    bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent &e)
    {
        m_ZoomLevel -= e.GetYOffset() * 0.25f;
        m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
        m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
        return false;
    }

    bool OrthographicCameraController::OnWindowResized(WindowResizeEvent &e)
    {
        m_AspectRatio = (float)e.GetWidth() / (float)e.GetHeight();
        m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
        return false;
    }
}

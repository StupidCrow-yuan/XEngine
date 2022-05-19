//
// Created by yuan on 5/12/22.
//

#ifndef XENGINEMAIN_ORTHOGRAPHICCAMERACONTROLLER_H
#define XENGINEMAIN_ORTHOGRAPHICCAMERACONTROLLER_H

#include "Renderer/OrthographicCamera.h"
#include "Xengine/Core/Timestep.h"
#include "Xengine/Events/ApplicationEvent.h"
#include "Xengine/Events/MouseEvent.h"

namespace XEngine {
    class OrthographicCameraController
    {
    public:
        OrthographicCameraController(float aspectRatio, bool rotation = false);

        void OnUpdate(Timestep ts);
        void OnEvent(Event& e);

        OrthographicCamera& GetCamera() { return m_Camera; }
        const OrthographicCamera& GetCamera() const { return m_Camera; }

    private:
        bool OnMouseScrolled(MouseScrolledEvent& e);
        bool OnWindowResized(WindowResizeEvent& e);

    private:
        float m_AspectRatio;
        float m_ZoomLevel = 1.0f;
        OrthographicCamera m_Camera;
        bool m_Rotation;
        glm::vec3 m_CameraPostion = {0.0f, 0.0f, 0.0f};
        float m_CameraRotation = 0.0f;
        float m_CameraTranslationSpeed = 50.0f, m_CameraRotationSpeed = 180.0f;
    };
}

#endif //XENGINEMAIN_ORTHOGRAPHICCAMERACONTROLLER_H

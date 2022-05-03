//
// Created by yuan on 5/3/22.
//

#ifndef XENGINEMAIN_ORTHOGRAPHICCAMERA_H
#define XENGINEMAIN_ORTHOGRAPHICCAMERA_H

#include <glm/glm.hpp>

namespace XEngine {
    class OrthographicCamera {
    public:
        OrthographicCamera(float left, float right, float bottom, float top);

        const glm::vec3& GetPosition() const { return m_Position; }
        void SetPostion(const glm::vec3& position) { m_Position = position; }

        float GetRotation() const { return m_Rotation; }
        void SetRotation(float rotation) { m_Rotation = rotation; RecalculateViewMatrix(); }

        const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
        const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
        const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }

    private:
        void RecalculateViewMatrix();
    private:
        glm::mat4 m_ProjectionMatrix;
        glm::mat4 m_ViewMatrix;
        glm::mat4 m_ViewProjectionMatrix;

        glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
        float m_Rotation = 0.0f;
    };
}

#endif //XENGINEMAIN_ORTHOGRAPHICCAMERA_H

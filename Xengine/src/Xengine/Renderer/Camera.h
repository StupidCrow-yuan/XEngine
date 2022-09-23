//
// Created by yuan on 9/17/22.
//

#ifndef XENGINEMAIN_CAMERA_H
#define XENGINEMAIN_CAMERA_H

#include <glm/glm.hpp>

namespace XEngine {
    class Camera
    {
    public:
        Camera() = default;

        virtual ~Camera() = default;

        Camera(const glm::mat4& projection) : m_Projection(projection) {}

        const glm::mat4& GetProjection() const { return m_Projection; }

    protected:
        glm::mat4 m_Projection = glm::mat4(1.0f);
    };
}

#endif //XENGINEMAIN_CAMERA_H

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
        Camera(const glm::mat4& projection) : m_Projection(projection) {}

        const glm::mat4& GetProjection() const { return m_Projection; }
    private:
        glm::mat4 m_Projection;
    };
}

#endif //XENGINEMAIN_CAMERA_H

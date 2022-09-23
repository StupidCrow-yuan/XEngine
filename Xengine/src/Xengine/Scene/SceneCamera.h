//
// Created by yuan on 9/21/22.
//

#ifndef XENGINEMAIN_SCENECAMERA_H
#define XENGINEMAIN_SCENECAMERA_H

#include "Xengine/Renderer/Camera.h"

namespace XEngine {
    class SceneCamera : public Camera
    {
    public:
        SceneCamera();
        virtual ~SceneCamera() = default;

        void SetOrthographic(float size, float nearClip, float farClip);

        void SetViewportSize(uint32_t width, uint32_t height);

        float GetOrthographicSize() const { return m_OrthographicSize; }
        void SetOrthographicSize(float size) { m_OrthographicSize = size;  RecalculateProjection(); }
    private:
        void RecalculateProjection();
    private:
        float m_OrthographicSize = 10.0f;
        float m_OrthographicNear = -1.0f;
        float m_OrthographicFar = 1.0f;
        float m_AspectRatio = 0.0f;
    };
}

#endif //XENGINEMAIN_SCENECAMERA_H

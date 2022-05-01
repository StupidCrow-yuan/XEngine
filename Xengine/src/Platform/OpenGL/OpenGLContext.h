//
// Created by yuan on 5/1/22.
//

#ifndef XENGINEMAIN_OPENGLCONTEXT_H
#define XENGINEMAIN_OPENGLCONTEXT_H

#include "Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace XEngine {
    class OpenGLContext : public  GraphicsContext
    {
    public:
        OpenGLContext(GLFWwindow* windowHandle);

        virtual void Init() override;
        virtual void SwapBuffers() override;

    private:
        GLFWwindow* m_WindowHandle;
    };
}

#endif //XENGINEMAIN_OPENGLCONTEXT_H

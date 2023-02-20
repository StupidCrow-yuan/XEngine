//
// Created by yuan on 5/1/22.
//

#ifndef XENGINEMAIN_GRAPHICSCONTEXT_H
#define XENGINEMAIN_GRAPHICSCONTEXT_H

#include "Xengine/Core/Base.h"

namespace XEngine {
    class GraphicsContext
    {
    public:
        virtual ~GraphicsContext() = default;

        virtual void Init() = 0; //创建context，相当于把glfwSetCurrentContext封装到这里
        virtual void SwapBuffers() = 0; //glfwSwapBuffer 封装到这里

        static Scope<GraphicsContext> Create(void* window); //根据不同的window类型创建对应的content，目前只支持opengl类型
    };
}

#endif //XENGINEMAIN_GRAPHICSCONTEXT_H

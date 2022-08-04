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
        virtual void Init() = 0;
        virtual void SwapBuffers() = 0;

        static Scope<GraphicsContext> Create(void* window);
    };
}

#endif //XENGINEMAIN_GRAPHICSCONTEXT_H

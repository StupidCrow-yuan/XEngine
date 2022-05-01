//
// Created by yuan on 5/1/22.
//

#ifndef XENGINEMAIN_GRAPHICSCONTEXT_H
#define XENGINEMAIN_GRAPHICSCONTEXT_H

namespace XEngine {
    class GraphicsContext
    {
    public:
        virtual void Init() = 0;
        virtual void SwapBuffers() = 0;
    };
}

#endif //XENGINEMAIN_GRAPHICSCONTEXT_H

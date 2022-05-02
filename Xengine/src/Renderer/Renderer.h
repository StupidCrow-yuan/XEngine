//
// Created by yuan on 5/2/22.
//

#ifndef XENGINEMAIN_RENDERER_H
#define XENGINEMAIN_RENDERER_H

namespace XEngine {

    enum class RendererAPI
    {
        None = 0,
        OpenGL = 1
    };

    class Renderer {
    public:
        inline static RendererAPI GetAPI() { return s_RendererAPI; }

    private:
        static RendererAPI s_RendererAPI;
    };
}


#endif //XENGINEMAIN_RENDERER_H

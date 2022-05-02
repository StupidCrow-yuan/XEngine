//
// Created by yuan on 5/2/22.
//

#include "xepch.h"
#include "RenderCommand.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace XEngine {
    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}
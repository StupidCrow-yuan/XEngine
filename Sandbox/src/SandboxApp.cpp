//
// Created by yuan on 4/9/22.
//

#include "XEngine.h"
#include <imgui.h>
#include "Xengine/Core/EntryPoint.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Platform/OpenGL/OpenGLShader.h"
#include <glm/gtc/type_ptr.hpp>
#include "Sandbox2D.h"

class Sandbox : public XEngine::Application
{
public:
    Sandbox(const XEngine::ApplicationSpecification& specification) : XEngine::Application(specification)
    {
        PushLayer(new Sandbox2D());
    }

    ~Sandbox()
    {
    }
};

XEngine::Application* XEngine::CreateApplication(XEngine::ApplicationCommandLineArgs args)
{
    ApplicationSpecification spec;
    spec.Name = "Sandbox";
    spec.WorkingDirectory = "../XEngineInput";
    spec.CommandLineArgs = args;
    return new Sandbox(spec);
}

//
// Created by yuan on 9/4/22.
//

#include <XEngine.h>
#include <Xengine/Core/EntryPoint.h>
#include "EditorLayer.h"

namespace XEngine
{
    class XEngineInput : public Application
    {
    public:
        XEngineInput(ApplicationSpecification& specification) : Application(specification)
        {
            PushLayer(new EditorLayer());
        }
        ~XEngineInput()
        {
        }
    };

    Application* CreateApplication(ApplicationCommandLineArgs args)
    {
        ApplicationSpecification spec;
        spec.Name = "XEngineInput";
        spec.CommandLineArgs = args;
        return new XEngineInput(spec);
    }
}

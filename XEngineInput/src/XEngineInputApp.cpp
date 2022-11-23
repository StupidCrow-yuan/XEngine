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
        XEngineInput(ApplicationCommandLineArgs args) : Application("XEngineInput", args)
        {
            PushLayer(new EditorLayer());
        }
        ~XEngineInput()
        {
        }
    };

    Application* CreateApplication(ApplicationCommandLineArgs args)
    {
        return new XEngineInput(args);
    }
}

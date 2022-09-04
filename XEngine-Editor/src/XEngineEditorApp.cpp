//
// Created by yuan on 9/4/22.
//

#include <XEngine.h>
#include <Xengine/Core/EntryPoint.h>
#include "EditorLayer.h"

namespace XEngine
{
    class XEngineEditor : public Application
    {
    public:
        XEngineEditor() : Application("XEngine Editor")
        {
            PushLayer(new EditorLayer());
        }
        ~XEngineEditor()
        {
        }
    };

    Application* CreateApplication()
    {
        return new XEngineEditor();
    }
}

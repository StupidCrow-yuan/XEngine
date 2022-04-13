//
// Created by yuan on 4/9/22.
//

#ifndef XENGINE_APPLICATION_H
#define XENGINE_APPLICATION_H

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace XEngine {
    class Application {
    public:
        Application();
        virtual ~Application();
        void Run();

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    Application* CreateApplication();
}

#endif //XENGINE_APPLICATION_H

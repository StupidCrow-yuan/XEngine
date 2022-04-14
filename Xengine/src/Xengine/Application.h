//
// Created by yuan on 4/9/22.
//

#ifndef XENGINE_APPLICATION_H
#define XENGINE_APPLICATION_H

#include "Core.h"
#include "Events/Event.h"
#include "Xengine/Events/ApplicationEvent.h"
#include "Window.h"

namespace XEngine {
    class Application {
    public:
        Application();
        virtual ~Application();
        void Run();

        void OnEvent(Event& e);
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    Application* CreateApplication();
}

#endif //XENGINE_APPLICATION_H

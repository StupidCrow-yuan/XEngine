//
// Created by yuan on 4/9/22.
//

#ifndef XENGINE_APPLICATION_H
#define XENGINE_APPLICATION_H

#include "Core.h"
#include "Window.h"

#include "Xengine/LayerStack.h"
#include "Xengine/Events/Event.h"
#include "Xengine/Events/ApplicationEvent.h"

namespace XEngine {
    class Application {
    public:
        Application();
        virtual ~Application();
        void Run();

        void OnEvent(Event& e);
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

    Application* CreateApplication();
}

#endif //XENGINE_APPLICATION_H

//
// Created by yuan on 4/9/22.
//

#ifndef XENGINE_APPLICATION_H
#define XENGINE_APPLICATION_H

#include "Core/Core.h"
#include "Core/Window.h"

#include "Xengine/Core/LayerStack.h"
#include "Xengine/Events/Event.h"
#include "Xengine/Events/ApplicationEvent.h"
#include "Xengine/Core/Timestep.h"
#include "Xengine/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace XEngine {
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void OnEvent(Event& e);
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }

        inline static Application& Get() { return *s_Instance; }

    private:
        void Run();
        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);
    private:
        Scope<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
        ImGuiLayer* m_ImGuiLayer;
        float m_LastFrameTime = 0.0f;
        float m_Minimized = false;
    private:
        static Application* s_Instance;
        friend int ::main(int argc, char** argv);
    };

    // To be defined in CLIENT
    Application* CreateApplication();
}

#endif //XENGINE_APPLICATION_H

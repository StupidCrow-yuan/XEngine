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

namespace XEngine {
    class Application
    {
    public:
        Application();
        virtual ~Application() = default;
        void Run();

        void OnEvent(Event& e);
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }

        inline static Application& Get() { return *s_Instance; }

    private:
        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
        ImGuiLayer* m_ImGuiLayer;
        float m_LastFrameTime = 0.0f;
        float m_Minimized = false;
    private:
        static Application* s_Instance;
    };

    Application* CreateApplication();
}

#endif //XENGINE_APPLICATION_H

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
#include "Xengine/ImGui/ImGuiLayer.h"
#include "Renderer/Shader.h"

namespace XEngine {
    class Application {
    public:
        Application();
        virtual ~Application();
        void Run();

        void OnEvent(Event& e);
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }

        inline static Application& Get() { return *s_Instance; }

    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
        ImGuiLayer* m_ImGuiLayer;
        unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
        std::unique_ptr<Shader> m_Shader;
    private:
        static Application* s_Instance;
    };

    Application* CreateApplication();
}

#endif //XENGINE_APPLICATION_H

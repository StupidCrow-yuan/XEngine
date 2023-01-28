//
// Created by yuan on 4/9/22.
//

#ifndef XENGINE_APPLICATION_H
#define XENGINE_APPLICATION_H

#include "Core/Base.h"
#include "Core/Window.h"

#include "Xengine/Core/LayerStack.h"
#include "Xengine/Events/Event.h"
#include "Xengine/Events/ApplicationEvent.h"
#include "Xengine/Core/Timestep.h"
#include "Xengine/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace XEngine {

    struct ApplicationCommandLineArgs
    {
        int Count = 0;
        char** Args = nullptr;

        const char* operator[] (int index) const
        {
            XE_CORE_ASSERT(index < Count);
            return Args[index];
        }
    };

    struct ApplicationSpecification
    {
        std::string Name = "XEngine Application";
        std::string WorkingDirectory;
        ApplicationCommandLineArgs CommandLineArgs;
    };

    class Application
    {
    public:
        Application(const ApplicationSpecification& specification);
        virtual ~Application();

        void OnEvent(Event& e);
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        Window& GetWindow() { return *m_Window; }

        void Close();

        ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

        static Application& Get() { return *s_Instance; }

        const ApplicationSpecification& GetSpecification() const { return m_Specification; }
    private:
        void Run();
        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);
    private:
        ApplicationSpecification m_Specification;
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
    Application* CreateApplication(ApplicationCommandLineArgs args);
}

#endif //XENGINE_APPLICATION_H

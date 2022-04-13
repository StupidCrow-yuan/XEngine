//
// Created by yuan on 4/13/22.
//

#ifndef XENGINEMAIN_WINDOWSWINDOW_H
#define XENGINEMAIN_WINDOWSWINDOW_H

#include "Xengine/Window.h"
#include <GLFW/glfw3.h>

namespace XEngine {
    class WindowsWindow : public Window {
    public:
        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow();

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_data.Width; }
        inline unsigned int GetHeight() const override { return m_data.Height; }

        //Window attribute
        inline void SetEventCallback(const EventCallbackFn& callback) override { m_data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
    private:
        GLFWwindow* m_Window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSnc;
            EventCallbackFn EventCallback;
        };

        WindowData m_data;
    };
}


#endif //XENGINEMAIN_WINDOWSWINDOW_H

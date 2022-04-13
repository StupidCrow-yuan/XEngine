//
// Created by yuan on 4/13/22.
//

#ifndef XENGINEMAIN_WINDOW_H
#define XENGINEMAIN_WINDOW_H

#include "xepch.h"
#include "Xengine/Core.h"
#include "Xengine/Events/Event.h"

namespace XEngine {
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string& title = "XEngine", unsigned int width = 1280,
                    unsigned int height = 720)
                    : Title(title), Width(width), Height(height)
                    {
                    }
    };
    // Interface representing a desktop system based Window
    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;
        virtual ~Window() {}
        virtual void OnUpdate() = 0;
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        //window attributes
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;
        static  Window* Create(const WindowProps& props = WindowProps());
    };
}


#endif //XENGINEMAIN_WINDOW_H

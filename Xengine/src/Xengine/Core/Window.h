//
// Created by yuan on 4/13/22.
//

#ifndef XENGINEMAIN_WINDOW_H
#define XENGINEMAIN_WINDOW_H

#include "Xengine/Core/Base.h"
#include "Xengine/Events/Event.h"
#include <sstream>

namespace XEngine {
    struct WindowProps
    {
        std::string Title;
        uint32_t Width;
        uint32_t Height;

        WindowProps(const std::string& title = "XEngine Learn", uint32_t width = 1600,
                    uint32_t height = 900)
                    : Title(title), Width(width), Height(height)
                    {
                    }
    };
    // Interface representing a desktop system based Window
    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;
        virtual ~Window() = default;
        virtual void OnUpdate() = 0;
        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

        //window attributes
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;
        virtual void* GetNativeWindow() const = 0;
        static  Scope<Window> Create(const WindowProps& props = WindowProps());
    };
}


#endif //XENGINEMAIN_WINDOW_H

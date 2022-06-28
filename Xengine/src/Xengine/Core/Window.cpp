//
// Created by yuan on 6/28/22.
//

#include "xepch.h"
#include "Xengine/Core/Window.h"

#ifdef XE_PLATFORM_MACOS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace XEngine
{
    Scope<Window> Window::Create(const WindowProps &props)
    {
        #ifdef XE_PLATFORM_MACOS
            return CreateScope<WindowsWindow>(props);
        #else
            XE_CORE_ASSERT(false, "Unknown platform!");
            return nullptr;
        #endif
    }
}

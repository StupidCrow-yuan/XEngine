//
// Created by yuan on 6/28/22.
//

#include "xepch.h"
#include "Xengine/Core/Input.h"

#ifdef XE_PLATFORM_MACOS
#include "Platform/Windows/WindowsInput.h"
#endif

namespace XEngine {
    Scope<Input> Input::s_Instance = Input::Create();

    Scope<Input> Input::Create()
    {
        #ifdef XE_PLATFORM_MACOS
            return CreateScope<WindowsInput>();
        #else
            XE_CORE_ASSERT(false, "Unknown platform!");
            return nullptr;
        #endif
    }
}
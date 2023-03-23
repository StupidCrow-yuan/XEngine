//
// Created by yuan on 4/9/22.
//

#ifndef XENGINE_CORE_H
#define XENGINE_CORE_H

#include "Xengine/Core/PlatformDetection.h"
#include <memory>

// DLL support
#ifdef XE_PLATFORM_WINDOWS
#if XE_DYNAMIC_LINK
		#ifdef XE_BUILD_DLL
			#define HAZEL_API __declspec(dllexport)
		#else
			#define HAZEL_API __declspec(dllimport)
		#endif
	#else
		#define HAZEL_API
	#endif
#elif defined XE_PLATFORM_MACOS
#warning XEngine is supports macos
#endif // End of DLL support

#ifdef XE_DEBUG
    #if defined(XE_PLATFORM_MACOS)
        #define XE_XE_DEBUGBREAK() __debugbreak()
    #elif defined(XE_PLATFORM_LINUX)
        #include <signal.h>
        #define XE_DEBUGBREAK() raise(SIGTRAP)
    #else
        #error "Platform doesn't support debugbreak yet!"
    #endif
    #define XE_ENABLE_ASSERTS
#else
#define XE_DEBUGBREAK()
#endif

#ifdef XE_ENABLE_ASSERTS
    #define XE_ASSERT(x, ...) { if(!(x)) { XE_ERROR("Assertion Failed: {0}", __VA_ARGS__); XE_DEBUGBREAK(); } }
	#define XE_CORE_ASSERT(x, ...) { if(!(x)) { XE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); XE_DEBUGBREAK(); } }
#else
#define XE_ASSERT(x, ...)
#define XE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define XE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace XEngine {
    template<typename T>
    using Scope = std::unique_ptr<T>;
    template<typename T, typename ... Args>
    constexpr  Scope<T> CreateScope(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Ref = std::shared_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }
}

#endif //XENGINE_CORE_H

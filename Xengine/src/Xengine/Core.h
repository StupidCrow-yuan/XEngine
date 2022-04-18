//
// Created by yuan on 4/9/22.
//

#ifndef XENGINE_CORE_H
#define XENGINE_CORE_H

#ifdef XE_PLATFORM_MACOS
    # XEngine is supports macos
#else
    #ifdef XE_BUILD_DLL
        #define #define XE_API __declspec(dllexport)
    #else
        #define Xe_API __declspec(dllimport)
    #endif
#endif

#ifdef XE_DEBUG
    #define XE_ENABLE_ASSERTS
#endif

#ifdef XE_ENABLE_ASSERTS
#define XE_ASSERT(x, ...) { if(!(x)) { XE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define XE_CORE_ASSERT(x, ...) { if(!(x)) { XE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define XE_ASSERT(x, ...)
#define XE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define XE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

#endif //XENGINE_CORE_H

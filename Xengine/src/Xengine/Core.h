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
#endif //XENGINE_CORE_H

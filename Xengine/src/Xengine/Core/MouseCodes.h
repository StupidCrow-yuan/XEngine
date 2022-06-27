//
// Created by yuan on 6/25/22.
//

#ifndef XENGINEMAIN_MOUSECODES_H
#define XENGINEMAIN_MOUSECODES_H

#include "xepch.h"

namespace XEngine
{
    typedef enum class MouseCode : uint16_t
    {
        // From glfw3.h
        Button0                = 0,
        Button1                = 1,
        Button2                = 2,
        Button3                = 3,
        Button4                = 4,
        Button5                = 5,
        Button6                = 6,
        Button7                = 7,

        ButtonLast             = Button7,
        ButtonLeft             = Button0,
        ButtonRight            = Button1,
        ButtonMiddle           = Button2
    } Mouse;

    inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
    {
        os << static_cast<int32_t>(mouseCode);
        return os;
    }
}

#define XE_MOUSE_BUTTON_0      ::XEngine::Mouse::Button0
#define XE_MOUSE_BUTTON_1      ::XEngine::Mouse::Button1
#define XE_MOUSE_BUTTON_2      ::XEngine::Mouse::Button2
#define XE_MOUSE_BUTTON_3      ::XEngine::Mouse::Button3
#define XE_MOUSE_BUTTON_4      ::XEngine::Mouse::Button4
#define XE_MOUSE_BUTTON_5      ::XEngine::Mouse::Button5
#define XE_MOUSE_BUTTON_6      ::XEngine::Mouse::Button6
#define XE_MOUSE_BUTTON_7      ::XEngine::Mouse::Button7
#define XE_MOUSE_BUTTON_LAST   ::XEngine::Mouse::ButtonLast
#define XE_MOUSE_BUTTON_LEFT   ::XEngine::Mouse::ButtonLeft
#define XE_MOUSE_BUTTON_RIGHT  ::XEngine::Mouse::ButtonRight
#define XE_MOUSE_BUTTON_MIDDLE ::XEngine::Mouse::ButtonMiddle

#endif //XENGINEMAIN_MOUSECODES_H

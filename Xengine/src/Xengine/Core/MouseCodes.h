//
// Created by yuan on 6/25/22.
//

#ifndef XENGINEMAIN_MOUSECODES_H
#define XENGINEMAIN_MOUSECODES_H

#include "xepch.h"

namespace XEngine
{
    using MouseCode = uint16_t;
    namespace Mouse
    {
        enum : MouseCode
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
        };
    }
}

#endif //XENGINEMAIN_MOUSECODES_H

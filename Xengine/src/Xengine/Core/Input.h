//
// Created by yuan on 4/18/22.
//

#ifndef XENGINEMAIN_INPUT_H
#define XENGINEMAIN_INPUT_H

#include "xepch.h"
#include <glm/glm.hpp>
#include "Xengine/Core/KeyCodes.h"
#include "Xengine/Core/MouseCodes.h"

namespace XEngine {
    class Input
    {
    public:
        static bool IsKeyPressed(KeyCode key);
        static bool IsMouseButtonPressed(MouseCode button);
        static glm::vec2 GetMousePosition();
        static float GetMouseX();
        static float GetMouseY();
    };
}

#endif //XENGINEMAIN_INPUT_H

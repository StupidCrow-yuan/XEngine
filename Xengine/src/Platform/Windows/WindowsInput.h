//
// Created by yuan on 4/18/22.
//

#ifndef XENGINEMAIN_WINDOWSINPUT_H
#define XENGINEMAIN_WINDOWSINPUT_H

#include "Xengine/Core/Input.h"

namespace XEngine {
    class WindowsInput : public Input {
    protected:
        virtual bool IsKeyPressedImpl(KeyCode key) override;
        virtual bool IsMouseButtonPressedImpl(MouseCode button) override;
        virtual std::pair<float, float> GetMousePositionImpl() override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;
    };
}

#endif //XENGINEMAIN_WINDOWSINPUT_H

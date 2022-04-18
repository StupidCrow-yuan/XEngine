//
// Created by yuan on 4/18/22.
//

#ifndef XENGINEMAIN_WINDOWSINPUT_H
#define XENGINEMAIN_WINDOWSINPUT_H

#include "Xengine/Input.h"

namespace XEngine {
    class WindowsInput : public Input {
    protected:
        virtual bool IsKeyPressedImpl(int keycode) override;
        virtual bool IsMouseButtonPressedImpl(int button) override;
        virtual std::pair<float, float> GetMousePositionImpl() override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;
    };
}

#endif //XENGINEMAIN_WINDOWSINPUT_H

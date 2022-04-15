//
// Created by yuan on 4/14/22.
//

#ifndef XENGINEMAIN_IMGUILAYER_H
#define XENGINEMAIN_IMGUILAYER_H

#include "Xengine/Layer.h"

namespace XEngine {
    class ImGuiLayer : public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event &event);

    private:
        float m_Time = 0.0f;
    };
}

#endif //XENGINEMAIN_IMGUILAYER_H

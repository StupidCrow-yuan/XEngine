//
// Created by yuan on 4/14/22.
//

#ifndef XENGINEMAIN_LAYERSTACK_H
#define XENGINEMAIN_LAYERSTACK_H

#include "Xengine/Core.h"
#include "Layer.h"

namespace XEngine {
    class LayerStack : public Layer {
    public:
        LayerStack();
        ~LayerStack();
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);

        std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer*>::iterator end() { return m_Layers.end(); }

    private:
        std::vector<Layer*> m_Layers;
        unsigned int m_LayerInsertIndex = 0;
    };
}

#endif //XENGINEMAIN_LAYERSTACK_H

//
// Created by yuan on 4/14/22.
//

#ifndef XENGINEMAIN_LAYERSTACK_H
#define XENGINEMAIN_LAYERSTACK_H

#include "Xengine/Core/Base.h"
#include "Layer.h"

namespace XEngine {
    class LayerStack : public Layer {
    public:
        LayerStack() = default;
        ~LayerStack();
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);

        std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer*>::iterator end() { return m_Layers.end(); }
        std::vector<Layer*>::reverse_iterator  rbegin() { return m_Layers.rbegin(); }
        std::vector<Layer*>::reverse_iterator  rend() { return m_Layers.rend(); }

        std::vector<Layer*>::const_iterator begin() const { return m_Layers.begin(); }
        std::vector<Layer*>::const_iterator end() const { return m_Layers.end(); }
        std::vector<Layer*>::const_reverse_iterator rbegin() const { return m_Layers.rbegin(); }
        std::vector<Layer*>::const_reverse_iterator  rend() const { return m_Layers.rend(); }

    private:
        std::vector<Layer*> m_Layers;
        unsigned int m_LayerInsertIndex = 0;
    };
}

#endif //XENGINEMAIN_LAYERSTACK_H

//
// Created by yuan on 4/14/22.
//

#include "xepch.h"
#include "LayerStack.h"

namespace XEngine {

    LayerStack::~LayerStack()
    {
        for (Layer* layer : m_Layers)
        {
            layer->OnDetach();
            delete layer;
        }
    }
    //***************Game Layer ********** iterator it ***********Overlay Layer ***********
    //即iterator作为Layer层和OverLay层的标记位
    void LayerStack::PushLayer(Layer *layer)
    {
        //对于Layer层，都是从m_LayerInsertIndex所在位置往里赛，这样保证了迭代器所在的地方用于是Layer和OverLayer的分界线
        m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
        m_LayerInsertIndex++;
    }

    void LayerStack::PushOverlay(Layer *overlay)
    {
        m_Layers.emplace_back(overlay);//对于ui层，overlay直接塞入vector的最后面
    }

    void LayerStack::PopLayer(Layer *layer)
    {
        auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, layer);
        if (it != m_Layers.begin() + m_LayerInsertIndex)
        {
            layer->OnDetach();
            m_Layers.erase(it);
            m_LayerInsertIndex--;
        }
    }

    void LayerStack::PopOverlay(Layer *overlay)
    {
        auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), overlay);
        if (it != m_Layers.end())
        {
            overlay->OnDetach();
            m_Layers.erase(it);
        }
    }
}
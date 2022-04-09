//
// Created by yuan on 4/9/22.
//

#include "../../XEngine/src/XEngine.h"

class Sandbox : public XEngine::Application
{
public:
    Sandbox()
    {
    }

    ~Sandbox()
    {
    }
};

XEngine::Application* XEngine::CreateApplication()
{
    return new Sandbox();
}
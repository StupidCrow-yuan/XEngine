//
// Created by yuan on 4/9/22.
//

#ifndef XENGINE_ENTRYPOINT_H
#define XENGINE_ENTRYPOINT_H

#include "Application.h"

extern XEngine::Application* XEngine::CreateApplication();

int main()
{
    auto app = XEngine::CreateApplication();
    app->Run();
    delete app;
}

#endif //XENGINE_ENTRYPOINT_H

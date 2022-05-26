//
// Created by yuan on 4/9/22.
//

#ifndef XENGINE_ENTRYPOINT_H
#define XENGINE_ENTRYPOINT_H

extern XEngine::Application* XEngine::CreateApplication();

int main()
{
    XEngine::Log::Init();
    XE_CORE_WARN("Initialized Log");
    int a = 5;
    XE_CORE_INFO("Hello! val = {0}", a);

    auto app = XEngine::CreateApplication();
    app->Run();
    delete app;
}

#endif //XENGINE_ENTRYPOINT_H

//
// Created by yuan on 4/9/22.
//

#ifndef XENGINE_ENTRYPOINT_H
#define XENGINE_ENTRYPOINT_H

extern XEngine::Application* XEngine::CreateApplication();

int main()
{
    XEngine::Log::Init();

    XE_PROFILE_BEGIN_SESSION("Startup", CPP_SRC_DIR"Sandbox/XEngineProfile-Startup.json");
    auto app = XEngine::CreateApplication();
    XE_PROFILE_END_SESSION();
    
    XE_PROFILE_BEGIN_SESSION("Runtime", CPP_SRC_DIR"Sandbox/XEngineProfile-Runtime.json");
    app->Run();
    XE_PROFILE_END_SESSION();
    
    XE_PROFILE_BEGIN_SESSION("Startup", CPP_SRC_DIR"Sandbox/XEngineProfile-Shutdown.json");
    delete app;
    XE_PROFILE_END_SESSION();
}

#endif //XENGINE_ENTRYPOINT_H

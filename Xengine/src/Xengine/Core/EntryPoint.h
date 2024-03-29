//
// Created by yuan on 4/9/22.
//

#ifndef XENGINE_ENTRYPOINT_H
#define XENGINE_ENTRYPOINT_H

#include "Xengine/Application.h"

extern XEngine::Application* XEngine::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
    XEngine::Log::Init();

    XE_PROFILE_BEGIN_SESSION("Startup", CPP_SRC_DIR"Sandbox/XEngineProfile-Startup.json");
    auto app = XEngine::CreateApplication({argc, argv});
    XE_PROFILE_END_SESSION();
    
    XE_PROFILE_BEGIN_SESSION("Runtime", CPP_SRC_DIR"Sandbox/XEngineProfile-Runtime.json");
    app->Run();
    XE_PROFILE_END_SESSION();
    
    XE_PROFILE_BEGIN_SESSION("Shutdown", CPP_SRC_DIR"Sandbox/XEngineProfile-Shutdown.json");
    delete app;
    XE_PROFILE_END_SESSION();
}

#endif //XENGINE_ENTRYPOINT_H

//
// Created by yuan on 4/9/22.
//

#include "Application.h"
#include "xepch.h"
#include "Xengine/Log.h"
#include "Xengine/Events/ApplicationEvent.h"

namespace XEngine {
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        if (e.IsInCategory(EventCategoryApplication))
        {
            XE_TRACE(e);
        }
        if (e.IsInCategory(EventCategoryInput))
        {
            XE_TRACE(e);
        }
        while (true)
        {
//            std::cout << "run application!" << std::endl;
        }
    }

}
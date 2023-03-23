//
// Created by yuan on 10/16/22.
//

#include "xepch.h"
#include "PlatformUtils.h"
#include "Xengine/Application.h"

//#include <commdlg.h>//This header is used by Dialog Boxes

#include "portable-file-dialogs.h" //文件对话框
#include <GLFW/glfw3.h>

namespace XEngine {

    float Time::GetTime()
    {
        return glfwGetTime();
    }

    std::string FileDialogs::OpenFile(const char *filter)
    {
        //file open
        auto f = pfd::open_file("Choose files to read", pfd::path::home(),
                                { "xengine Files (.Xengine)", "*.Xengine",
                                  "All Files"});

        XE_CORE_INFO("Selected files:");
        for (auto const& name : f.result())
        {
            XE_CORE_INFO("Select file's name: {0}", name.c_str());
        }
        return f.result().size() > 0 ? f.result()[0].c_str() : std::string();
    }

    std::string FileDialogs::SaveFile(const char *filter)
    {
        // File save
        auto f = pfd::save_file("Choose file to save",
                                pfd::path::home() + pfd::path::separator() + "readme.txt",
                                { "xengine Files (.Xengine)", ".Xengine" },
                                pfd::opt::force_overwrite);
        XE_CORE_INFO("select file: {0}", f.result());
        return f.result().c_str() == "" ? std::string() : f.result().c_str();
    }
}
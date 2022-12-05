//
// Created by yuan on 12/5/22.
//

#ifndef XENGINEMAIN_CONTENTBROWSERPANEL_H
#define XENGINEMAIN_CONTENTBROWSERPANEL_H

#include <filesystem>
#include "Renderer/Texture.h"

namespace XEngine {
    class ContentBrowserPanel
    {
    public:
        ContentBrowserPanel();

        void OnImGuiRender();
    private:
        std::filesystem::path m_CurrentDirectory;

        Ref<Texture2D> m_DirectoryIcon;
        Ref<Texture2D> m_FileIcon;
    };
}

#endif //XENGINEMAIN_CONTENTBROWSERPANEL_H

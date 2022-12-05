//
// Created by yuan on 12/5/22.
//

#ifndef XENGINEMAIN_CONTENTBROWSERPANEL_H
#define XENGINEMAIN_CONTENTBROWSERPANEL_H

#include <filesystem>

namespace XEngine {
    class ContentBrowserPanel
    {
    public:
        ContentBrowserPanel();

        void OnImGuiRender();
    private:
        std::filesystem::path m_CurrentDirectory;
    };
}

#endif //XENGINEMAIN_CONTENTBROWSERPANEL_H

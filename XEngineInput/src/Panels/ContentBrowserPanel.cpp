//
// Created by yuan on 12/5/22.
//
#include "xepch.h"
#include "ContentBrowserPanel.h"
#include <imgui.h>

namespace XEngine {

    //Once we have projects, change this
    extern const std::filesystem::path g_AssetPath = CPP_SRC_DIR"XEngineInput/assets";//通过 extern 关键字来使得 const 对象在多个文件中共享

    ContentBrowserPanel::ContentBrowserPanel() : m_CurrentDirectory(g_AssetPath)
    {
        m_DirectoryIcon = Texture2D::Create(CPP_SRC_DIR"XEngineInput/Resources/Icons/ContentBrowser/DirectoryIcon.png");
        m_FileIcon = Texture2D::Create(CPP_SRC_DIR"XEngineInput/Resources/Icons/ContentBrowser/FileIcon.png");
    }

    void ContentBrowserPanel::OnImGuiRender()
    {
        ImGui::Begin("Content Browser");

        if (m_CurrentDirectory != std::filesystem::path(g_AssetPath))
        {
            if (ImGui::Button("<-"))
            {
                m_CurrentDirectory = m_CurrentDirectory.parent_path();
            }
        }

        static float padding = 16.0f;
        static float thumbnailSize = 128.0f;//略缩图大小
        float cellSize = thumbnailSize + padding;

        float panelWidth = ImGui::GetContentRegionAvail().x;
        int columnCount = (int)(panelWidth / cellSize);
        if (columnCount < 1)
            columnCount = 1;

        ImGui::Columns(columnCount, 0, false);

        //遍历当前路径下所有的资源文件
        for (auto& directoryEntry : std::filesystem::directory_iterator(m_CurrentDirectory))
        {
            const auto& path = directoryEntry.path();
            auto relativePath = std::filesystem::relative(path, g_AssetPath);//获取相对路径
            std::string filenameString = relativePath.filename().string();
            //imgui使用一个ID栈，只要栈里面有ID，那么接下来创建组件的时候，ID的组件就会从栈里面拿出来，并赋上去
            //每次打开一个新的.xengine文件，都需要重新生成一个id，确保id不会冲突，否则会一直显示打开的第一个文件，类似纹理id的唯一性
            ImGui::PushID(filenameString.c_str());
            Ref<Texture2D> icon = directoryEntry.is_directory() ? m_DirectoryIcon : m_FileIcon;

            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
            ImGui::ImageButton((ImTextureID)icon->GetRendererID(), { thumbnailSize, thumbnailSize}, {0, 1}, {1, 0});

            //支持拖拽，记录拖拽后的文件路径
            if (ImGui::BeginDragDropSource())
            {
                const char* itemPath = reinterpret_cast<const char*>(relativePath.c_str());
                ImGui::SetDragDropPayload("CONTENT_BROWSER_ITEM", itemPath, (strlen(itemPath) + 1));//"CONTENT_BROWSER_ITEM"自定义关键字，在Editory里面需要用到该字段
                ImGui::EndDragDropSource();
            }

            ImGui::PopStyleColor();

            if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
            {
                if (directoryEntry.is_directory())
                {
                    m_CurrentDirectory /= path.filename();
                }
            }
            ImGui::TextWrapped(filenameString.c_str());
            ImGui::NextColumn();

            ImGui::PopID();
        }

        ImGui::Columns(1);

        ImGui::SliderFloat("Thunbnail Size", &thumbnailSize, 16, 512);
        ImGui::SliderFloat("Padding", &padding, 0, 32);

        //todo: status bar
        ImGui::End();
    }
}
//
// Created by yuan on 9/4/22.
//

#ifndef XENGINEMAIN_EDITORLAYER_H
#define XENGINEMAIN_EDITORLAYER_H

#include "XEngine.h"
#include "Xengine/Renderer/Framebuffer.h"
#include "SceneHierarchyPanel.h"
#include "Xengine/Renderer/EditorCamera.h"
#include "Panels/ContentBrowserPanel.h"

namespace XEngine
{
    class EditorLayer : public Layer
    {
    public:
        EditorLayer();
        virtual ~EditorLayer() = default;

        virtual void OnAttach() override;
        virtual void OnDetach() override;

        void OnUpdate(Timestep ts) override;
        virtual void OnImGuiRender() override;
        void OnEvent(Event& e) override;

    private:
        bool OnKeyPressed(KeyPressedEvent& e);
        bool OnMouseButtonPressed(MouseButtonPressedEvent& e);

        void NewScene();
        void OpenScene();
        void OpenScene(const std::filesystem::path& path);
        void SaveSceneAs();

        void OnScenePlay();
        void OnSceneStop();

        //UI Panels
        void UI_ToolBar();

    private:
        XEngine::OrthographicCameraController m_CameraController;

        bool m_ViewportFocused = false;
        bool m_ViewportHovered = false;
        glm::vec2 m_ViewportSize = {0.0f, 0.0f};
        glm::vec2 m_ViewportBounds[2];
        //temp
        Ref<VertexArray> m_SquareVA;
        Ref<Shader> m_FlatColorShader;
        Ref<Framebuffer> m_Framebuffer;

        Ref<Scene> m_ActiveScene;
        Entity m_SquareEntity;
        Entity m_CameraEntity;
        Entity m_SecondCamera;
        EditorCamera m_EditorCamera;
        Entity m_HoveredEntity;

        bool m_PrimaryCamera = true;

        Ref<Texture2D> m_CheckboardTexture;
        glm::vec4 m_SquareColor = {0.2f ,0.3f, 0.8f, 1.0f};

        int m_GizmoType = -1;

        enum class SceneState
        {
            Edit = 0,
            Play = 1
        };
        SceneState m_SceneState = SceneState::Edit;
        //Panels
        SceneHierarchyPanel m_SceneHierachyPanel;
        ContentBrowserPanel m_ContentBrowserPanel;

        //Editor resources
        Ref<Texture2D> m_IconPlay, m_IconStop;
    };
}

#endif //XENGINEMAIN_EDITORLAYER_H

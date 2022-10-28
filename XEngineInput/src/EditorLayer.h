//
// Created by yuan on 9/4/22.
//

#ifndef XENGINEMAIN_EDITORLAYER_H
#define XENGINEMAIN_EDITORLAYER_H

#include "XEngine.h"
#include "Xengine/Renderer/Framebuffer.h"
#include "SceneHierarchyPanel.h"
#include "Xengine/Renderer/EditorCamera.h"

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

        void NewScene();
        void OpenScene();
        void SaveSceneAs();
    private:
        XEngine::OrthographicCameraController m_CameraController;

        bool m_ViewportFocused = false;
        bool m_ViewportHovered = false;
        glm::vec2 m_ViewportSize = {0.0f, 0.0f};
        //temp
        Ref<VertexArray> m_SquareVA;
        Ref<Shader> m_FlatColorShader;
        Ref<Framebuffer> m_Framebuffer;

        Ref<Scene> m_ActiveScene;
        Entity m_SquareEntity;
        Entity m_CameraEntity;
        Entity m_SecondCamera;
        EditorCamera m_EditorCamera;

        bool m_PrimaryCamera = true;

        Ref<Texture2D> m_CheckboardTexture;
        glm::vec4 m_SquareColor = {0.2f ,0.3f, 0.8f, 1.0f};

        int m_GizmoType = -1;
        //Panels
        SceneHierarchyPanel m_SceneHierachyPanel;
    };
}

#endif //XENGINEMAIN_EDITORLAYER_H

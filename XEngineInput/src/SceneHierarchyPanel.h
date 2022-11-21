//
// Created by yuan on 9/30/22.
//

#ifndef XENGINEMAIN_SCENEHIERARCHYPANEL_H
#define XENGINEMAIN_SCENEHIERARCHYPANEL_H

#include "Xengine/Core/Base.h"
#include "Xengine/Core/Log.h"
#include "Xengine/Scene/Scene.h"
#include "Xengine/Scene/Entity.h"

namespace XEngine {
    class SceneHierarchyPanel {
    public:
        SceneHierarchyPanel() = default;
        SceneHierarchyPanel(const Ref<Scene>& scene);

        void SetContext(const Ref<Scene>& scene);

        void OnImGuiRender();

        Entity GetSelectedEntity() const { return m_SelectionContext; }
        void SetSelectedEntity(Entity entity);

    private:
        void DrawEntityNode(Entity entity);
        void DrawComponents(Entity entity);

    private:
        Ref<Scene> m_Context;
        Entity m_SelectionContext;
    };
}

#endif //XENGINEMAIN_SCENEHIERARCHYPANEL_H

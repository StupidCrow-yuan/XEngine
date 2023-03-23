//
// Created by yuan on 9/30/22.
//

#include "SceneHierarchyPanel.h"
#include "Xengine/Scene/Components.h"
#include <imgui.h>
#include <imgui_internal.h>
#include <glm/gtc/type_ptr.hpp>

namespace XEngine {

    extern const std::filesystem::path g_AssetPath;

    SceneHierarchyPanel::SceneHierarchyPanel(const Ref<Scene>& context)
    {
        SetContext(context);
    }

    void SceneHierarchyPanel::SetContext(const Ref<Scene>& context)
    {
        m_Context = context;
        m_SelectionContext = {};
    }

    void SceneHierarchyPanel::OnImGuiRender()
    {
        //Scene Hierarchy 属性面板
        ImGui::Begin("Scene Hierarchy");

        if (m_Context)
        {
            m_Context->m_Registry.each([&](auto entityID)
                                       {
                                           Entity entity{ entityID, m_Context.get() };
                                           DrawEntityNode(entity);
                                       });

            //鼠标处于Scene Hierarchy面板空白处且按下左鼠标，则将m_SelectionContext置空，即Properties为空
            if (ImGui::IsMouseDown(0) && ImGui::IsWindowHovered())
            {
                m_SelectionContext = {};
            }

            //Right-click on black space
            if (ImGui::BeginPopupContextWindow(0, 1, false))
            {
                if (ImGui::MenuItem("Create Empty Entity"))
                    m_Context->CreateEntity("Empty Entity");

                ImGui::EndPopup();
            }
        }

        ImGui::End();

        //Properties属性面板
        ImGui::Begin("Properties");
        if (m_SelectionContext)
        {
            DrawComponents(m_SelectionContext);
        }
        ImGui::End();
    }

    void SceneHierarchyPanel::DrawEntityNode(Entity entity)
    {
        auto& tag = entity.GetComponent<TagComponent>().Tag;

        //每个node都自带OpenOnArrow的flag，如果当前entity正好被选中，那么还会多一个selected flag
        ImGuiTreeNodeFlags flags = ((m_SelectionContext == entity) ? ImGuiTreeNodeFlags_Selected : 0) | ImGuiTreeNodeFlags_OpenOnArrow;
        flags |= ImGuiTreeNodeFlags_SpanAvailWidth;
        bool opened = ImGui::TreeNodeEx((void*)(uint64_t)(uint32_t)entity, flags, tag.c_str());
        //如果鼠标悬浮在item上，且点击了鼠标左键，则返回true
        if (ImGui::IsItemClicked())
        {
            m_SelectionContext = entity;
        }

        bool entityDeleted = false;
        if (ImGui::BeginPopupContextItem())
        {
            if (ImGui::MenuItem("Delete Entity"))
            {
                entityDeleted = true;
            }

            ImGui::EndPopup();
        }

        //如果此节点是expended状态，则需要继续展开
        if (opened)
        {
            ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_SpanAvailWidth;
            bool opened = ImGui::TreeNodeEx((void*)9817239, flags, tag.c_str());
            if (opened)
                ImGui::TreePop();
            ImGui::TreePop();//树节点结束
        }

        if (entityDeleted)
        {
            m_Context->DestroyEntity(entity);
            if (m_SelectionContext == entity)
            {
                m_SelectionContext = {};
            }
        }
    }

    static void DrawVec3Control(const std::string& label, glm::vec3& values, float resetValue = 0.0, float columnWidth = 100.0f)
    {
        ImGuiIO& io = ImGui::GetIO();
        auto boldFont = io.Fonts->Fonts[0];

        //Translation、scale都会有相同的类似DragFloat("###Y"的函数，而ImGui是根据输入的"###Y"来作为identifier的
        //为了让不同组件的相同名字的值可以各自通过UI读写，这里需要绘制最开始加入ID, 绘制结束后PopID
        ImGui::PushID(label.c_str());

        //先在最左边绘制vector代表的label
        ImGui::Columns(2);//label占两列空间
        ImGui::SetColumnWidth(0, columnWidth);
        ImGui::Text(label.c_str());
        ImGui::NextColumn();

        //参考ImGui::DragScalarN函数，意思是在当前行绘制3个Item
        ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{0, 0});

        float lineHeight = GImGui->Font->FontSize + GImGui->Style.FramePadding.y * 2.0f;
        ImVec2 buttonSize = { lineHeight + 3.0f, lineHeight };

        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.8f, 0.1f, 0.15f, 1.0f});
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{0.9f, 0.2f, 0.2f, 1.0f});
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{0.8f, 0.1f, 0.15f, 1.0f});
        ImGui::PushFont(boldFont);
        if (ImGui::Button("X", buttonSize))
            values.x = resetValue;
        ImGui::PopFont();
        ImGui::PopStyleColor(3);

        ImGui::SameLine();
        ImGui::DragFloat("###X", &values.x, 0.1f, 0.0f, 0.0f, "%.2f");
        ImGui::PopItemWidth();
        ImGui::SameLine();

        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.2f, 0.7f, 0.2f, 1.0f});
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{0.3f, 0.8f, 0.3f, 1.0f});
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{0.2f, 0.7f, 0.2f, 1.0f});
        ImGui::PushFont(boldFont);
        if (ImGui::Button("Y", buttonSize))
            values.y = resetValue;
        ImGui::PopFont();
        ImGui::PopStyleColor(3);

        ImGui::SameLine();
        ImGui::DragFloat("###Y", &values.y, 0.1f, 0.0f, 0.0f, "%.2f");
        ImGui::PopItemWidth();
        ImGui::SameLine();

        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.1f, 0.25f, 0.8f, 1.0f});
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{0.2f, 0.35f, 0.9f, 1.0f});
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{0.1f, 0.25f, 0.8f, 1.0f});
        ImGui::PushFont(boldFont);
        if (ImGui::Button("Z", buttonSize))
            values.z = resetValue;
        ImGui::PopFont();
        ImGui::PopStyleColor(3);

        ImGui::SameLine();
        ImGui::DragFloat("###Z", &values.z, 0.1f, 0.0f, 0.0f, "%.2f");
        ImGui::PopItemWidth();

        ImGui::PopStyleVar();

        ImGui::Columns(1);

        ImGui::PopID();
    }

    template<typename T, typename UIFunction>
    static void DrawComponent(const std::string& name, Entity entity, UIFunction uiFunction)
    {
        const ImGuiTreeNodeFlags treeNodeFlags = ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_SpanAvailWidth | ImGuiTreeNodeFlags_AllowItemOverlap | ImGuiTreeNodeFlags_FramePadding;
        if (entity.HasComponent<T>())
        {
            auto& component = entity.template GetComponent<T>();
            ImVec2 contentRegionAvailable = ImGui::GetContentRegionAvail();

            ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2{4, 4});
            float lineHeight = GImGui->Font->FontSize + GImGui->Style.FramePadding.y * 2.0f;
            ImGui::Separator();
            bool open = ImGui::TreeNodeEx((void*)typeid(T).hash_code(), treeNodeFlags, name.c_str());
            ImGui::PopStyleVar();
            ImGui::SameLine(contentRegionAvailable.x - lineHeight * 0.5f);
            if (ImGui::Button("+", ImVec2{ lineHeight, lineHeight }))
            {
                ImGui::OpenPopup("ComponentSettings");
            }

            bool removeComponent = false;
            if (ImGui::BeginPopup("ComponentSettings"))
            {
                if (ImGui::MenuItem("Remove component"))
                    removeComponent = true;

                ImGui::EndPopup();
            }

            if (open)
            {
                uiFunction(component);
                ImGui::TreePop();
            }

            if (removeComponent)
            {
                entity.RemoveComponent<T>();
            }
        }

    }

    void SceneHierarchyPanel::SetSelectedEntity(Entity entity)
    {
        m_SelectionContext = entity;
    }

    void SceneHierarchyPanel::DrawComponents(Entity entity)
    {
        if (!entity.GetScene())
        {
            return;//todo
        }
        if (entity.HasComponent<TagComponent>())
        {
            auto& tag = entity.GetComponent<TagComponent>().Tag;

            char buffer[256];
            memset(buffer, 0, sizeof(buffer));
            strncpy(buffer, tag.c_str(),sizeof(buffer));

            if (ImGui::InputText("##Tag", buffer, sizeof(buffer)))
            {
                tag = std::string(buffer);
            }
        }

        ImGui::SameLine();
        ImGui::PushItemWidth(-1);//确保即使窗口变小，当前弹出选项也可以在右侧窗口之上显示

        //添加add component按钮
        if (ImGui::Button("Add Component"))
        {
            ImGui::OpenPopup("AddComponent");
        }

        if (ImGui::BeginPopup("AddComponent"))
        {
            DisplayAddComponentEntity<CameraComponent>("Camera");
            DisplayAddComponentEntity<SpriteRendererComponent>("Sprite Renderer");
            DisplayAddComponentEntity<CircleRendererComponent>("Circle Renderer");
            DisplayAddComponentEntity<Rigidbody2DComponent>("Rigidbody 2D");
            DisplayAddComponentEntity<BoxCollider2DComponent>("Box Collider 2D");
            DisplayAddComponentEntity<CircleCollider2DComponent>("Circle Collider 2D");
            DisplayAddComponentEntity<LineRendererComponent>("Line 2D");
            DisplayAddComponentEntity<CameraComponent>("Camera");

            if(ImGui::MenuItem("empty"))
            {
                //nothing
                //todo: 为了解决当没有可添加的component时，Add Component选中后会显示小的黑色块
            }

            ImGui::EndPopup();
        }

        ImGui::PopItemWidth();

        DrawComponent<TransformComponent>("Transform", entity, [](auto& component)
        {
            DrawVec3Control("Translation", component.Translation);
            glm::vec3 rotation = glm::degrees(component.Rotation);
            DrawVec3Control("Rotation", rotation);
            component.Rotation = glm::radians(rotation);
            DrawVec3Control("Scale", component.Scale, 1.0f);
        });

        DrawComponent<CameraComponent>("Camera", entity, [](auto& component)
        {
            auto& camera = component.Camera;

            ImGui::Checkbox("Primary", &component.Primary);

            const char* projectionTypeStrings[] = { "Perspective", "Orthographic"};//绘制camera的两种选项，根据不同选项展示不同参数
            const char* currentProjectionTypeString = projectionTypeStrings[(int)camera.GetProjectionType()];//当前选项从数组中找
            if (ImGui::BeginCombo("Projection", currentProjectionTypeString))//BeginCombo是ImGui绘制EnumPopup的方法
            {
                for (int i = 0; i < 2; i++)
                {
                    bool isSelected = currentProjectionTypeString == projectionTypeStrings[i];
                    if (ImGui::Selectable(projectionTypeStrings[i], isSelected))//ImGui::Selectable()显示可选择的选项
                    {
                        currentProjectionTypeString = projectionTypeStrings[i];
                        camera.SetProjectionType((SceneCamera::ProjectionType)i);
                    }

                    if (isSelected)
                    {
                        ImGui::SetItemDefaultFocus();//高亮当前已经选择的Item
                    }
                }
                ImGui::EndCombo();
            }

            if (camera.GetProjectionType() == SceneCamera::ProjectionType::Perspective)
            {
                float perspectiveVerticalFov = glm::degrees(camera.GetPerspectiveVerticalFOV());
                if (ImGui::DragFloat("Vertical FOV", &perspectiveVerticalFov))
                {
                    camera.SetPerspectiveVerticalFOV(glm::radians(perspectiveVerticalFov));
                }

                float perspectiveNear = camera.GetPerspectiveNearClip();
                if (ImGui::DragFloat("Near", &perspectiveNear))
                {
                    camera.SetPerspectiveNearClip(perspectiveNear);
                }

                float perspectiveFar = camera.GetPerspectiveFarClip();
                if (ImGui::DragFloat("Far", &perspectiveFar))
                {
                    camera.SetPerspectiveFarClip(perspectiveFar);
                }
            }

            if (camera.GetProjectionType() == SceneCamera::ProjectionType::Orthographic)
            {
                float orthoSize = camera.GetOrthographicSize();
                if (ImGui::DragFloat("Size", &orthoSize))
                {
                    camera.SetOrthographicSize(orthoSize);
                }

                float orthoNear = camera.GetOrthographicNearClip();
                if (ImGui::DragFloat("Near", &orthoNear))
                {
                    camera.SetOrthographicNearClip(orthoNear);
                }

                float orthoFar = camera.GetOrthographicFarClip();
                if (ImGui::DragFloat("Far", &orthoFar))
                {
                    camera.SetOrthographicFarClip(orthoFar);
                }

                ImGui::Checkbox("Fixed Aspect Ratio", &component.FixedAspectRatio);
            }
        });

        DrawComponent<SpriteRendererComponent>("Sprite Renderer", entity, [](auto& component)
        {
            ImGui::ColorEdit4("Color", glm::value_ptr(component.Color));

            //支持将纹理拖拽到对应的component中
            ImGui::Button("Texture", ImVec2(100.0f, 0.0f));//添加一个button按钮for Texture
            if (ImGui::BeginDragDropTarget())
            {
                if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("CONTENT_BROWSER_ITEM"))
                {
                    const char* path = static_cast<const char *>(payload->Data);
                    std::filesystem::path texturePath = std::filesystem::path(g_AssetPath) / path;
                    Ref<Texture2D> texture = Texture2D::Create(texturePath.string());
                    if (texture->IsLoaded())
                    {
                        component.Texture = texture;
                    }
                    else
                    {
                        XE_WARN("Could not load texture {0}", texturePath.filename().string());
                    }
                }
                ImGui::EndDragDropTarget();
            }
            ImGui::DragFloat("Tiling Factor", &component.TilingFactor, 0.9f, 0.0f, 100.0f);
        });

        DrawComponent<Rigidbody2DComponent>("Rigidbody 2D", entity, [](auto& component)
        {
            const char* bodyTypeStrings[] = { "Static", "Dynamic", "Kinematic"};
            const char* currentBodyTypeString = bodyTypeStrings[(int)component.Type];
            if (ImGui::BeginCombo("Body Type", currentBodyTypeString))
            {
                for (int i = 0; i < 2; i++)
                {
                    bool isSelected = currentBodyTypeString == bodyTypeStrings[i];
                    if (ImGui::Selectable(bodyTypeStrings[i], isSelected))
                    {
                        currentBodyTypeString = bodyTypeStrings[i];
                        component.Type = (Rigidbody2DComponent::BodyType)i;
                    }

                    if (isSelected)
                        ImGui::SetItemDefaultFocus();
                }

                ImGui::EndCombo();
            }

            ImGui::Checkbox("Fixed Rotation", &component.FixedRotation);
        });

        DrawComponent<CircleRendererComponent>("Circle Renderer", entity, [](auto& component)
        {
            ImGui::ColorEdit4("Color", glm::value_ptr(component.Color));
            ImGui::DragFloat("Thickness", &component.Thickness, 0.025f, 0.0f, 1.0f);
            ImGui::DragFloat("Fade", &component.Fade, 0.00025f, 0.0f, 1.0f);
        });

        DrawComponent<BoxCollider2DComponent>("Box Collider 2D", entity, [](auto& component)
        {
            ImGui::DragFloat2("Offset", glm::value_ptr(component.Offset));
            ImGui::DragFloat2("Size", glm::value_ptr(component.Size));
            ImGui::DragFloat("Density", &component.Density, 0.01f, 0.0f, 1.0f);
            ImGui::DragFloat("Friction", &component.Friction, 0.01f, 0.0f, 1.0f);
            ImGui::DragFloat("Restitution", &component.Restitution, 0.01f, 0.0f, 1.0f);
            ImGui::DragFloat("Restitution Threshold", &component.RestitutionThreshold, 0.01f, 0.0f);
        });

        DrawComponent<LineRendererComponent>("Line Renderer", entity, [](auto& component)
        {
            ImGui::ColorEdit4("Color", glm::value_ptr(component.Color));
            ImGui::DragFloat("width", &component.width, 0.1f, 0.0, 100.0f);
        });

        DrawComponent<CircleCollider2DComponent>("Circle Collider 2D", entity, [](auto& component)
        {
            ImGui::DragFloat2("Offset", glm::value_ptr(component.Offset));
            ImGui::DragFloat("Radius", &component.Radius);
            ImGui::DragFloat("Density", &component.Density, 0.01f, 0.0f, 1.0f);
            ImGui::DragFloat("Friction", &component.Friction, 0.01f, 0.0f, 1.0f);
            ImGui::DragFloat("Restitution", &component.Restitution, 0.01f, 0.0f, 1.0f);
            ImGui::DragFloat("Restitution Threshold", &component.RestitutionThreshold, 0.01f, 0.0f);
        });
    }

    template<typename T>
    void SceneHierarchyPanel::DisplayAddComponentEntity(const std::string &entityName)
    {
        if (!m_SelectionContext.HasComponent<T>())
        {
            if (ImGui::MenuItem(entityName.c_str()))
            {
                m_SelectionContext.template AddComponent<T>();
                ImGui::CloseCurrentPopup();
            }
        }
    }
}
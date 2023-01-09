//
// Created by yuan on 9/5/22.
//

#ifndef XENGINEMAIN_COMPONENTS_H
#define XENGINEMAIN_COMPONENTS_H

#include <glm/glm.hpp>
#include "SceneCamera.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Renderer/Texture.h"
#include "Xengine/Core/UUID.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

namespace XEngine {

    struct IDComponent
    {
        UUID ID;

        IDComponent() = default;
        IDComponent(const IDComponent&) = default;
    };

    struct TagComponent
    {
        std::string Tag;

        TagComponent() = default;
        TagComponent(const TagComponent&) = default;
        TagComponent(const std::string& tag) : Tag(tag) {}
    };

    struct TransformComponent
    {
        glm::vec3 Translation = {0.0f, 0.0f, 0.0f };
        glm::vec3 Rotation = { 0.0f, 0.0f, 0.0f };
        glm::vec3 Scale = {1.0f, 1.0f, 1.0f };

        TransformComponent() = default;
        TransformComponent(const TransformComponent&) = default;
        TransformComponent(const glm::vec3& translation) : Translation(translation) {}

        glm::mat4 GetTransform() const
        {
            glm::mat4 rotation = glm::toMat4(glm::quat(Rotation));//采用四元素来构造旋转居中
            return glm::translate(glm::mat4(1.0f), Translation) * rotation * glm::scale(glm::mat4(1.0f), Scale);
        }
    };

    struct SpriteRendererComponent
    {
        glm::vec4 Color{1.0f, 1.0f, 1.0f, 1.0f};
        Ref<Texture2D> Texture;
        float TilingFactor = 1.0f;

        SpriteRendererComponent() = default;
        SpriteRendererComponent(const SpriteRendererComponent&) = default;
        SpriteRendererComponent(const glm::vec4& color) : Color(color) {}
    };

    struct CircleRendererComponent
    {
        glm::vec4 Color{1.0f, 1.0f, 1.0f, 1.0f};
        float Thickness = 1.0f;
        float Fade = 0.005f;

        CircleRendererComponent() = default;
        CircleRendererComponent(const CircleRendererComponent&) = default;
    };

    struct LineRendererComponent
    {
        glm::vec4 Color{1.0f, 0.0f, 1.0f, 1.0f};
        float width = 1.0f;

        LineRendererComponent() = default;
        LineRendererComponent(const LineRendererComponent&) = default;
    };

    struct CameraComponent
    {
       SceneCamera Camera;
        bool Primary = true; //todo: think about moving to Scene
        bool FixedAspectRatio = false;

        CameraComponent() = default;
        CameraComponent(const CameraComponent&) = default;
    };

    //forward delaration
    class ScriptableEntity;

    struct NativeScriptComponent
    {
        ScriptableEntity* Instance = nullptr;

//        std::function<void()> InstantiateFunction;//std::function是一个函数模板类，是一个类;定义在头文件可以用其定义不同的对象，对象的类型可以是普通函数，静态函数以及Lambda表达式

        ScriptableEntity*(*InstantiateScript)();//定义一个名为*InstantiateScript的函数指针，函数类型返回值为ScriptableEntity*，无入参的函数指针
        void (*DestroyScript)(NativeScriptComponent*);//定义一个名为*DestroyScript的函数指针，参数类型为NativeScriptComponent*，返回值类型为void

        template<typename T>
        void Bind()
        {
            InstantiateScript = []() { return static_cast<ScriptableEntity*>(new T()); };
            DestroyScript = [](NativeScriptComponent* nsc) { delete nsc->Instance; nsc->Instance = nullptr; };
        }
    };

    struct Rigidbody2DComponent
    {
        //Static：静态类型； 不受力的影响，物理系统不会对该物体进行计算、性能消耗最低的类型；不可通过MovePosition、MoveRotation来移动，不可通过velocity来改变速度，用来模拟从不移动的物体
        //Dynamic: 动态类型； 受重力和付佳丽的影响，进而改变速度，性能消耗最高的类型，可通过MovePostion、MoveRotation来移动; 可通过velocity来改变速度，用来模拟移动的物体
        //Kinematic： 运动学类型；不受力的影响，性能消耗比Dynamic少，比Static多；可通过MovePostion、MoveRotation来移动；可通过velocity来改变速度，用来模拟大多数时候不动的物体，极少数时候需要移动，比如门
        //请注意，尽管经常将 2D 刚体表述为相互碰撞，但实际上发生碰撞的是每个刚体所连接的 2D 碰撞体。如果没有碰撞体，2D 刚体不能相互碰撞
        enum class BodyType { Static = 0, Dynamic, Kinematic };
        BodyType Type = BodyType::Static;
        bool FixedRotation = false;//固定旋转

        //Storage for runtime
        void* RuntimeBody = nullptr;

        Rigidbody2DComponent() = default;
        Rigidbody2DComponent(const Rigidbody2DComponent&) = default;
    };

    struct BoxCollider2DComponent
    {
        glm::vec2 Offset = {0.0f, 0.0f};
        glm::vec2 Size = {0.5f, 0.5f};

        //TODO(Yan): move into physics material in the future maybe
        float Density = 1.0f;//密度，决定刚体的质量 = 密度 * 体积
        float Friction = 0.5f;//摩擦力，0代表无摩擦，1代表大摩擦
        float Restitution = 0.0f;//弹性系数，0代表完全吸收，1代表完全反弹
        float RestitutionThreshold = 0.5f;

        //Storage for runtime
        void* RuntimeFixture = nullptr;

        BoxCollider2DComponent() = default;
        BoxCollider2DComponent(const BoxCollider2DComponent&) = default;
    };
}

#endif //XENGINEMAIN_COMPONENTS_H

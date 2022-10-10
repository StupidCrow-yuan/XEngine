//
// Created by yuan on 9/5/22.
//

#ifndef XENGINEMAIN_COMPONENTS_H
#define XENGINEMAIN_COMPONENTS_H

#include <glm/glm.hpp>
#include "SceneCamera.h"
#include "ScriptableEntity.h"
#include <glm/gtc/matrix_transform.hpp>

namespace XEngine {

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
            glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), Rotation.x, {1, 0, 0})
                    * glm::rotate(glm::mat4(1.0f), Rotation.y, {0, 1, 0})
                    * glm::rotate(glm::mat4(1.0f), Rotation.z, {0, 0, 1});
            return glm::translate(glm::mat4(1.0f), Translation) * rotation * glm::scale(glm::mat4(1.0f), Scale);
        }
    };

    struct SpriteRendererComponent
    {
        glm::vec4 Color{1.0f, 1.0f, 1.0f, 1.0f};

        SpriteRendererComponent() = default;
        SpriteRendererComponent(const SpriteRendererComponent&) = default;
        SpriteRendererComponent(const glm::vec4& color) : Color(color) {}
    };

    struct CameraComponent
    {
       SceneCamera Camera;
        bool Primary = true; //todo: think about moving to Scene
        bool FixedAspectRatio = false;

        CameraComponent() = default;
        CameraComponent(const CameraComponent&) = default;
    };

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
}

#endif //XENGINEMAIN_COMPONENTS_H

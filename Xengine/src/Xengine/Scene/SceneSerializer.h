//
// Created by yuan on 10/16/22.
//

#ifndef XENGINEMAIN_SCENESERIALIZER_H
#define XENGINEMAIN_SCENESERIALIZER_H

#include "XEngine.h"
#include "Scene.h"

namespace XEngine {
    class SceneSerializer
    {
    public:
        SceneSerializer(const Ref<Scene>& scene);

        void Serialize(const std::string& filepath);
        void SerializeRuntime(const std::string& filepath);

        bool Deserialize(const std::string& filepath);
        bool DeserializeRuntime(const std::string& filepath);

    private:
        Ref<Scene> m_Scene;
    };
}

#endif //XENGINEMAIN_SCENESERIALIZER_H

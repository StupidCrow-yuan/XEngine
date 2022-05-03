//
// Created by yuan on 5/2/22.
//

#ifndef XENGINEMAIN_SHADER_H
#define XENGINEMAIN_SHADER_H

#include <string>
#include <glm/glm.hpp>

namespace XEngine {
    class Shader {
    public:
        Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
        ~Shader();
        void Bind() const;
        void UnBind() const;

        void UnloadUniformMat4(const std::string& name, const glm::mat4& matrix);
    private:
        uint32_t m_RendererID;
    };
}

#endif //XENGINEMAIN_SHADER_H

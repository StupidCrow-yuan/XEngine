//
// Created by yuan on 5/2/22.
//

#ifndef XENGINEMAIN_SHADER_H
#define XENGINEMAIN_SHADER_H

#include <string>

namespace XEngine {
    class Shader {
    public:
        virtual ~Shader() = default;
        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;

        static Shader* Create(const std::string& filepath);
        static Shader* Create(const std::string& vertexSrc, const std::string& fragmentSrc);
    };
}

#endif //XENGINEMAIN_SHADER_H

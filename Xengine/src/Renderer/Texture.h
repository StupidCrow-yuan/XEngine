//
// Created by yuan on 5/3/22.
//

#ifndef XENGINEMAIN_TEXTURE_H
#define XENGINEMAIN_TEXTURE_H

#include <string>
#include "Xengine/Core/Core.h"

namespace XEngine {
    class Texture
    {
    public:
        virtual ~Texture() = default;

        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

        virtual void Bind(uint32_t slot = 0) const = 0;
    };

    class Texture2D : public Texture
    {
    public:
        static Ref<Texture2D> Create(const std::string& path);
    };
}

#endif //XENGINEMAIN_TEXTURE_H

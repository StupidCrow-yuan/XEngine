//
// Created by yuan on 5/3/22.
//

#ifndef XENGINEMAIN_TEXTURE_H
#define XENGINEMAIN_TEXTURE_H

#include <string>
#include "Xengine/Core/Base.h"

namespace XEngine {
    class Texture
    {
    public:
        virtual ~Texture() = default;

        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;
        virtual uint32_t GetRendererID() const = 0;

        virtual const std::string& GetPath() const = 0;

        virtual void SetPath(const std::string& path) = 0;

        virtual void SetData(void* data, uint32_t size) = 0;

        virtual void Bind(uint32_t slot = 0) const = 0;

        virtual bool IsLoaded() const = 0;

        virtual bool operator==(const Texture& other) const = 0;
    };

    class Texture2D : public Texture
    {
    public:
        static Ref<Texture2D> Create(uint32_t width, uint32_t height);
        static Ref<Texture2D> Create(const std::string& path);
    };
}

#endif //XENGINEMAIN_TEXTURE_H

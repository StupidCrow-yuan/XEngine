//
// Created by yuan on 5/3/22.
//

#include "xepch.h"
#include "OpenGLTexture.h"
#include <stb_image.h>
#include <stb_image_write.h>

namespace XEngine {

    OpenGLTexture2D::OpenGLTexture2D(uint32_t width, uint32_t height) : m_Width(width), m_Height(height)
    {
        XE_PROFILE_FUNCTION();
        m_InternalFormat = GL_RGBA8;
        m_DataFormat = GL_RGBA;

        glGenTextures(1, &m_RendererID);
        glBindTexture(GL_TEXTURE_2D, m_RendererID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }

    OpenGLTexture2D::OpenGLTexture2D(const std::string &path)
    {
        XE_PROFILE_FUNCTION();
        int width, height, channels;
        stbi_set_flip_vertically_on_load(1);
        stbi_uc* data = nullptr;
        {
            XE_PROFILE_SCOPE("stbi_load - OpenGLTexture2D::OpenGLTexture2D(const std:string&)");
            data = stbi_load(path.c_str(), &width, &height, &channels, 0);
        }

        if (data)
        {
            m_IsLoaded = true;
            m_Width = width;
            m_Height = height;

            GLenum internalFormat = 0, dataFormat = 0;
            if (channels == 4)
            {
                internalFormat = GL_RGBA8;
                dataFormat = GL_RGBA;
            }
            else if (channels == 3)
            {
                internalFormat = GL_RGB8;
                dataFormat = GL_RGB;
            }

            m_InternalFormat = internalFormat;
            m_DataFormat = dataFormat;

            XE_CORE_ASSERT(internalFormat &dataFormat, "Format not supported!");

            glGenTextures(1, &m_RendererID);

            glBindTexture(GL_TEXTURE_2D, m_RendererID);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

            glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, m_Width, m_Height, 0, dataFormat, GL_UNSIGNED_BYTE, data);
//            glGenerateMipmap(GL_TEXTURE_2D);
            stbi_image_free(data);
            glBindTexture(GL_TEXTURE_2D, 0);

//        glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);// glCreateTextures是OpenGL 4.5+ 的规范定义的API
//        glTextureStorage2D(m_RendererID, 1, GL_RGB8, m_Width, m_Height);
//        glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//        glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//        glTextureSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, GL_RGB, GL_UNSIGNED_BYTE, data);
        }
    }

    OpenGLTexture2D::~OpenGLTexture2D()
    {
        XE_PROFILE_FUNCTION();
        glDeleteTextures(1, &m_RendererID);
    }

    void OpenGLTexture2D::SetData(void *data, uint32_t size)
    {
        XE_PROFILE_FUNCTION();
        uint32_t  bpp = m_DataFormat == GL_RGBA ? 4 : 3;
        XE_CORE_ASSERT(size == m_Width * m_Height * bpp, "Data must be entire texture!");
        glTexImage2D(GL_TEXTURE_2D, 0, m_InternalFormat, m_Width, m_Height, 0, m_DataFormat, GL_UNSIGNED_BYTE, data);
    }

    void OpenGLTexture2D::Bind(uint32_t slot) const
    {
        XE_PROFILE_FUNCTION();
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, m_RendererID);
    }
}
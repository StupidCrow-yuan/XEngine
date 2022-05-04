//
// Created by yuan on 5/3/22.
//

#include "xepch.h"
#include <glad/glad.h>
#include "OpenGLTexture.h"
#include "stb_image.h"

namespace XEngine {
    OpenGLTexture2D::OpenGLTexture2D(const std::string &path)
    {
        int width, height, channels;
        stbi_set_flip_vertically_on_load(1);
        stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
        XE_CORE_ASSERT(data, "Failed to load image!");
        m_Width = width;
        m_Height = height;

        GLenum m_InternalFormat = 0, m_DataFormat = 0;
        if (channels == 4)
        {
            m_InternalFormat = GL_RGBA8;
            m_DataFormat = GL_RGBA;
        }
        else if (channels == 3)
        {
            m_InternalFormat = GL_RGB8;
            m_DataFormat = GL_RGB;
        }
        XE_CORE_ASSERT(m_InternalFormat & m_DataFormat, "Format not supported!");

        glGenTextures(1, &m_RendererID);

        glBindTexture(GL_TEXTURE_2D, m_RendererID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        //修复加载纹理黑屏问题，需要将多级渐远纹理值设置为0而非1
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

        glBindTexture(GL_TEXTURE_2D, 0);

//        glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);// glCreateTextures是OpenGL 4.5+ 的规范定义的API
//        glTextureStorage2D(m_RendererID, 1, GL_RGB8, m_Width, m_Height);
//        glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//        glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//        glTextureSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, GL_RGB, GL_UNSIGNED_BYTE, data);

        stbi_image_free(data);
    }

    OpenGLTexture2D::~OpenGLTexture2D()
    {
        glDeleteTextures(1, &m_RendererID);
    }

    void OpenGLTexture2D::Bind(uint32_t slot) const
    {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, m_RendererID);
    }
}
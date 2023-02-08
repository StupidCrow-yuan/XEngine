//
// Created by yuan on 2/8/23.
//

#include "xepch.h"
#include "FileSystem.h"

namespace XEngine
{
    Buffer FileSystem::ReadFileBinary(const std::filesystem::path& filepath)
    {
        std::ifstream stream(filepath, std::ios::binary | std::ios::ate);

        if (!stream)
        {
            //Failed to open the file
            XE_CORE_ERROR("Failed to open the file: {}", filepath.c_str());
            return {};
        }

        stream.seekg(0, std::ios::end);
        std::streampos end = stream.tellg();
        stream.seekg(0, std::ios::beg);
        uint64_t  size = end - stream.tellg();

        if (size == 0)
        {
            //File is empty
            XE_CORE_ERROR("File is empty: {}", filepath.c_str());
            return {};
        }

        Buffer buffer(size);
        stream.read(buffer.As<char>(), size);
        stream.close();
        return buffer;
    }
}
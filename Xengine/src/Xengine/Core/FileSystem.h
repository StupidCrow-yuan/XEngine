//
// Created by yuan on 2/8/23.
//

#ifndef XENGINEMAIN_FILESYSTEM_H
#define XENGINEMAIN_FILESYSTEM_H

#include "Xengine/Core/Buffer.h"
#include <filesystem>

namespace XEngine
{
    class FileSystem
    {
    public:
        //todo: move to fileSystem class
        static Buffer ReadFileBinary(const std::filesystem::path& filepath);
    };
}

#endif //XENGINEMAIN_FILESYSTEM_H

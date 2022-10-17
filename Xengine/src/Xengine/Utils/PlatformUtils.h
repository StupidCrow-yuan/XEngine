//
// Created by yuan on 10/16/22.
//

#ifndef XENGINEMAIN_PLATFORMUTILS_H
#define XENGINEMAIN_PLATFORMUTILS_H

#include <string>

namespace XEngine {
    class FileDialogs
    {
    public:
        //These return empty strings if cancelled
        static std::string OpenFile(const char* filter);
        static std::string SaveFile(const char* filter);
    };
}

#endif //XENGINEMAIN_PLATFORMUTILS_H

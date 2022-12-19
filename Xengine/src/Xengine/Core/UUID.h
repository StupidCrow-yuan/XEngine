//
// Created by yuan on 12/19/22.
//

#ifndef XENGINEMAIN_UUID_H
#define XENGINEMAIN_UUID_H

#include <stdint.h>
#include <functional>

namespace XEngine {

    class UUID
    {
    public:
        UUID();
        UUID(uint64_t uuid);
        UUID(const UUID&) = default;

        operator uint64_t() const { return m_UUID; }
    private:
        uint64_t m_UUID;
    };

}

namespace std {

    template<>
    struct hash<XEngine::UUID>
    {
        std::size_t operator()(const XEngine::UUID& uuid) const
        {
            return hash<uint64_t>()((uint64_t)uuid);
        }
    };

}

#endif //XENGINEMAIN_UUID_H

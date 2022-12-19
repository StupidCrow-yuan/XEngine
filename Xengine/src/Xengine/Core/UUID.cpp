//
// Created by yuan on 12/19/22.
//

#include "xepch.h"
#include "UUID.h"

#include <random>
#include <unordered_map>

namespace XEngine {
    static std::random_device s_RandomDevice;
    static std::mt19937_64 s_Engine(s_RandomDevice());
    static std::uniform_int_distribution<uint64_t> s_UinformDistribution;

    UUID::UUID() : m_UUID(s_UinformDistribution(s_Engine))
    {
    }

    UUID::UUID(uint64_t uuid) : m_UUID(uuid)
    {
    }
}
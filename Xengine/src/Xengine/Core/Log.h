//
// Created by yuan on 4/10/22.
//

#ifndef XENGINEMAIN_LOG_H
#define XENGINEMAIN_LOG_H

#include "Base.h"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace XEngine {
    class Log {
    public:
        static void Init();

        static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        static Ref<spdlog::logger>& GetClientLogger() { return s_CoreClientLogger; }
    private:
        static Ref<spdlog::logger> s_CoreLogger;
        static Ref<spdlog::logger> s_CoreClientLogger;
    };
}

// Core log macros
#define XE_CORE_TRACE(...)          ::XEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define XE_CORE_INFO(...)           ::XEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define XE_CORE_WARN(...)           ::XEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define XE_CORE_ERROR(...)          ::XEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define XE_CORE_CRITICAL(...)       ::XEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define XE_TRACE(...)               ::XEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define XE_INFO(...)	            ::XEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define XE_WARN(...)	            ::XEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define XE_ERROR(...)	            ::XEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define XE_CRITICAL(...)	        ::XEngine::Log::GetClientLogger()->critical(__VA_ARGS__)

#endif //XENGINEMAIN_LOG_H

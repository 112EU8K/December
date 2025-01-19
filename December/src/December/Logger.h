#ifndef LOGGER_H
#define LOGGER_H

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace December {
    class Logger
    {
        public:
            DECEMBER_API static void init();

            DECEMBER_API inline static std::shared_ptr<spdlog::logger> &GetEngineLogger() { return EngineLogger; }
            DECEMBER_API inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return ClientLogger; }
        protected:

        private:
            static DECEMBER_API std::shared_ptr<spdlog::logger> EngineLogger;
            static DECEMBER_API std::shared_ptr<spdlog::logger> ClientLogger;
    };
}

#define DECEMBER_ENGINE_TRACE    ::December::Logger:GetEngineLogger()->trace(__VA_ARGS__)
#define DECEMBER_ENGINE_INFO      ::December::Logger:GetEngineLogger()->info(__VA_ARGS__)
#define DECEMBER_ENGINE_WARN      ::December::Logger:GetEngineLogger()->warn(__VA_ARGS__)
#define DECEMBER_ENGINE_ERROR    ::December::Logger:GetEngineLogger()->error(__VA_ARGS__)
#define DECEMBER_ENGINE_FATAL    ::December::Logger:GetEngineLogger()->fatal(__VA_ARGS__)

#define DECEMBER_TRACE           ::December::Logger:GetEngineLogger()->trace(__VA_ARGS__)
#define DECEMBER_INFO             ::December::Logger:GetEngineLogger()->info(__VA_ARGS__)
#define DECEMBER_WARN             ::December::Logger:GetEngineLogger()->warn(__VA_ARGS__)
#define DECEMBER_ERROR           ::December::Logger:GetEngineLogger()->error(__VA_ARGS__)
#define DECEMBER_FATAL           ::December::Logger:GetEngineLogger()->fatal(__VA_ARGS__)


#endif // LOGGER_H


#include "Logger.h"

namespace December {

    DECEMBER_API std::shared_ptr<spdlog::logger> Logger::EngineLogger;
    DECEMBER_API std::shared_ptr<spdlog::logger> Logger::ClientLogger;

    static void init() {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        EngineLogger = spdlog::stdout_color_mt("DECEMBER");
        EngineLogger->set_level(spdlog::level::trace);
        ClientLogger = spdlog::stdout_color_mt("APP");
        ClientLogger->set_level(spdlog::level::trace);
    }
}

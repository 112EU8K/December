#include "Logger.h"

namespace December {

    std::shared_ptr<spdlog::logger> Logger::EngineLogger;
    std::shared_ptr<spdlog::logger> Logger::ClientLogger;

    void Logger::init() {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        Logger::GetEngineLogger() = spdlog::stdout_color_mt("DECEMBER");
        Logger::GetEngineLogger()->set_level(spdlog::level::trace);
        Logger::GetClientLogger() = spdlog::stdout_color_mt("EVE");
        Logger::GetClientLogger()->set_level(spdlog::level::trace);
    }

    // Engine log functions
    void Logger::EngineTrace(const std::string& message) {
        Logger::EngineLogger->trace(message);
    }

    void Logger::EngineInfo(const std::string& message) {
        Logger::EngineLogger->info(message);
    }

    void Logger::EngineWarn(const std::string& message) {
        Logger::EngineLogger->warn(message);
    }

    void Logger::EngineError(const std::string& message) {
        Logger::EngineLogger->error(message);
    }

    void Logger::EngineFatal(const std::string& message) {
        Logger::EngineLogger->critical(message);  // No "fatal"
    }                                             // in spdlog;
                                                  // use critical instead.
    // Client log functions
    void Logger::ClientTrace(const std::string& message) {
        Logger::ClientLogger->trace(message);
    }

    void Logger::ClientInfo(const std::string& message) {
        Logger::ClientLogger->info(message);
    }

    void Logger::ClientWarn(const std::string& message) {
        Logger::ClientLogger->warn(message);
    }

    void Logger::ClientError(const std::string& message) {
        Logger::ClientLogger->error(message);
    }

    void Logger::ClientFatal(const std::string& message) {
        Logger::ClientLogger->critical(message);
    }
}

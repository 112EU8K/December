#ifndef LOGGER_H
#define LOGGER_H

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>




namespace December {
    class __declspec(dllexport) Logger
    {
        public:
            static void init();

            static void EngineTrace(const std::string &message);
            static void EngineInfo(const std::string &message);
            static void EngineWarn(const std::string &message);
            static void EngineError(const std::string &message);
            static void EngineFatal(const std::string &message);

            static void ClientTrace(const std::string &message);
            static void ClientInfo(const std::string &message);
            static void ClientWarn(const std::string &message);
            static void ClientError(const std::string &message);
            static void ClientFatal(const std::string &message);

            inline static std::shared_ptr<spdlog::logger> &GetEngineLogger() { return EngineLogger; }
            inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return ClientLogger; }
        private:
            static std::shared_ptr<spdlog::logger> EngineLogger;
            static std::shared_ptr<spdlog::logger> ClientLogger;
    };
}


#endif // LOGGER_H



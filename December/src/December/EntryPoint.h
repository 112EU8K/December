#ifndef _ENTRYPOINT_H
#define _ENTRYPOINT_H

#include "Logger.h"
#include <chrono>
#include <thread>

extern December::Application* December::CreateApplication();

int main(int argc, char** argv)
{
    December::Logger::init();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    December::Logger::ClientInfo("Infinite Application!");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    December::Logger::ClientFatal("Can't change name for now!");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    December::Logger::EngineTrace("It seems that Relying on ChatGPT to fix the problem is not efficient!");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    December::Logger::EngineInfo("My code works now! But I seem to have faced another PROBLEM!");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    December::Logger::EngineWarn("It seems that only EntryPoint.h Gets changed but the other Files stay the Same!");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    December::Logger::EngineInfo("Will fix it Tomorrow");
    auto app = December::CreateApplication();
    app->run();
    delete app;
}
#endif // _ENTRYPOINT_H


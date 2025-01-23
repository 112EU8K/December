#include "application.h"

#include "Events/ApplicationEvent.h"
#include "Logger.h"

namespace December
{
    void Application::run() {

        WindowResizeEvent e(1280, 720);
        December::Logger::init();
        December::Logger::EngineInfo(e.ToString());

        while (true);
    }
}

#include "application.h"

#include "Events/ApplicationEvent.h"
#include "Logger.h"
#include "WindowsWindow.h"

namespace December
{
    Application::Application()
    {
        Logger::init(); // Initialize logger first
        window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application()
    {

    };  // Define the destructor here

    void Application::run() {
        while (running) {
            window->onUpdate();

            // Check if window is still open
            if (auto* sfmlWindow = dynamic_cast<WindowsWindow*>(window.get()))
            {
                if (!sfmlWindow->GetNativeWindow()->isOpen())
                {
                    running = false;
                }
            }
        }
    }
}

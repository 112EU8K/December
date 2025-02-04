#ifndef APPLICATION_H
#define APPLICATION_H
#include <Events/Event.h>
#include <Window.h>
#include <memory>
#include <Core.h>

namespace December
{
    class Application
    {
    public:
        Application();
        virtual ~Application(); // Just declare it virtual, implementation goes in cpp
        void run();
    private:
        std::unique_ptr<Window> window;
        bool running = true;
    };

    Application* CreateApplication();
}
#endif // APPLICATION_H

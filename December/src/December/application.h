#ifndef APPLICATION_H
#define APPLICATION_H
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "LayerStack.h"
#include <memory>
#include "Core.h"

namespace December
{
    class Application
    {
    public:
        Application();
        virtual ~Application(); // Just declare it virtual, implementation goes in cpp
        void run();
        void onEvent(Event &eve);
        void PushLayer(Layer* layer);
        void PushOverlayer(Layer* overlay);
    private:
        bool onWindowClose(WindowCloseEvent &e);
        std::unique_ptr<Window> window;
        bool running = true;
        LayerStack layer_stack;
    };

    Application* CreateApplication();
}
#endif // APPLICATION_H

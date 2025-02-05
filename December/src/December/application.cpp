#include "application.h"

#include "Events/ApplicationEvent.h"
#include "Logger.h"
#include "WindowsWindow.h"

namespace December
{
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
    Application::Application()
    {
        Logger::init(); // Initialize logger first
        window = std::unique_ptr<Window>(Window::Create());
        window->SetEventCallback(BIND_EVENT_FN(Application::onEvent));

    }

    Application::~Application()
    {

    };  // Define the destructor here

    void Application::PushLayer(Layer *layer)
    {
        layer_stack.PushLayer(layer);
    }

    void Application::PushOverlayer(Layer *overlay)
    {
        layer_stack.PushOverlay(overlay);
    }

    void Application::onEvent(Event &eve)
    {
        EventDispatcher dispatcher(eve);
        dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));
        December::Logger::EngineInfo(eve.ToString());

        for (auto it = layer_stack.end(); it != layer_stack.begin(); )
        {
            (*--it)->OnEvent(eve);
            if (eve.Handled) break;

        }
    }

    void Application::run() {
        while (running) {

            for (Layer* layer : layer_stack) layer->OnUpdate();

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

    bool Application::onWindowClose(WindowCloseEvent &e)
    {
        running = false;
        return true;
    }
}

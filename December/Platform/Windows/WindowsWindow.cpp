#include "WindowsWindow.h"

namespace December {
    static bool SFInitialized = false;
    Window* Window::Create(const December::WindowProps& props)
    {
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const December::WindowProps& props)
    {
        Init(props);
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void WindowsWindow::Init(const December::WindowProps& props)
    {
        data.Title = props.Title;
        data.width = props.width;
        data.height = props.height;

        std::stringstream ss;
        ss << "Creating window ";
        ss << data.Title;
        ss << "(";
        ss << data.width;
        ss << ", ";
        ss << data.height;
        ss << ")";

        December::Logger::EngineInfo(ss.str());

        if (!SFInitialized)
        {
            SFInitialized = true;
        }

        window = new sf::RenderWindow(sf::VideoMode(data.width, data.height), data.Title);
        window->setActive(true);
        SetVSync(true);
    }

    void WindowsWindow::Shutdown()
    {
        delete window;
    }

    void WindowsWindow::onUpdate()
    {
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
                // Optionally signal the application to stop
                // You might want to add a way to communicate this to the main loop
            }
        }

        window->clear(); // Clear the window
        // Your rendering code would go here
        window->display(); // Display what was drawn
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        if (enabled) window->setVerticalSyncEnabled(true);
        else window->setVerticalSyncEnabled(false);

        data.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const
    {
        return data.VSync;
    }
}

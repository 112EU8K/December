#include "WindowsWindow.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

namespace December {
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

        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(data.width, data.height), data.Title);
        window->setActive(true);
        SetVSync(true);
    }

    void WindowsWindow::pollEvents()
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    WindowCloseEvent e;
                    data.EventCallBack(e);
                    window->close();
                    break;
                }
                case sf::Event::Resized:
                {
                    WindowResizeEvent e(event.size.width, event.size.height);
                    data.width = event.size.width;
                    data.height = event.size.height;
                    data.EventCallBack(e);
                    break;
                }
                case sf::Event::KeyPressed:
                {
                    KeyPressedEvent e(event.key.code, false);
                    data.EventCallBack(e);
                    break;
                }
                case sf::Event::KeyReleased:
                {
                    KeyReleasedEvent e(event.key.code);
                    data.EventCallBack(e);
                    break;
                }
                case sf::Event::TextEntered:
                {
                    if (event.text.unicode < 128) { // Ensure it's a valid ASCII character
                        char character = static_cast<char>(event.text.unicode);
                        KeyTypedEvent e(character);
                        data.EventCallBack(e);
                    }
                    break;
                }
                case sf::Event::MouseButtonPressed:
                {
                    MouseButtonPressedEvent e(event.mouseButton.button);
                    data.EventCallBack(e);
                    break;
                }
                case sf::Event::MouseButtonReleased:
                {
                    MouseButtonReleasedEvent e(event.mouseButton.button);
                    data.EventCallBack(e);
                    break;
                }
                case sf::Event::MouseMoved:
                {
                    MouseMovedEvent e(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y));
                    data.EventCallBack(e);
                    break;
                }
                case sf::Event::MouseWheelScrolled:
                {
                    MouseScrolledEvent e(event.mouseWheelScroll.delta, 0);
                    data.EventCallBack(e);
                    break;
                }
                default:
                    break;
            }
        }
    }



    void WindowsWindow::Shutdown()
    {
        window.reset();
    }


    void WindowsWindow::onUpdate()
    {
        while (window->pollEvent(event))
        {
            pollEvents();
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

#ifndef WINDOW_H
#define WINDOW_H

#include <Core.h>
#include <Events/Event.h>

namespace December {
    struct WindowProps
    {
        std::string Title;
        unsigned int width;
        unsigned int height;
        WindowProps(const std::string &title = "Dream",
                    unsigned int width = 800,
                    unsigned int height = 600)
            : Title(title), width(width), height(height)
        {
        }
    };

    class Window
    {
    public:
        using EventCallBackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void onUpdate() = 0;
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallBackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };
}

#endif // WINDOW_H

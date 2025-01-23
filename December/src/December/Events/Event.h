#ifndef EVENT_H
#define EVENT_H

#include "../Core.h"
#include <string>
#include <functional>
#include <ostream>

namespace December
{
    enum class EventType
    {
        none = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased,
        MouseMoved,
        MouseWheelScrolled, MouseWheelPressed,
        MouseEntered, MouseLeft
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };

    #define EVENT_CLASS_TYPE(type)\
    static EventType GetStaticType() { return EventType::type; }\
    virtual EventType GetEventType() const override { return GetStaticType(); }\
    virtual const char* GetName() const override { return #type; }

    #define EVENT_CLASS_CATEGORY(category)\
    virtual int GetCategoryFlags() const override { return category; }

    class __declspec(dllexport) Event
    {
        friend class EventDispatcher;
    public:
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }
    protected:
        bool Handled = false;
    };


    class EventDispatcher
    {
        template <typename T>
        using EventFn = std::function<bool(T&)>;
    public:
        EventDispatcher(Event &event)
            : Event(event)
        {
        }

        template <typename T>
        bool dispatch(EventFn<T> func)
        {
            if (T* event = dynamic_cast<T*>(&Event))
            {
                Event.Handled = func(*event);
                return true;
            }
        return false;

        }

    private:
        Event& Event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& event)
    {
        return os << event.ToString();
    }

}

#endif // EVENT_H

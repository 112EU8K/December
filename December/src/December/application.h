#ifndef APPLICATION_H
#define APPLICATION_H
#include <SFML/Graphics.hpp>

namespace December
{
     class Application
    {
    public:
        DECEMBER_API Application();
        DECEMBER_API virtual ~Application();
        DECEMBER_API void run();

    };

    DECEMBER_API Application* CreateApplication();
}

#endif // APPLICATION_H

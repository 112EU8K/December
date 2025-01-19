#include "application.h"

namespace December
{
    Application() {

    }
    virtual ~Application() {

    }
    void run() {
        sf::RenderWindow app(sf::VideoMode(800, 600), "app");

        while (app.isOpen())
        {
            sf::Event event;
            while (app.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    app.close();
                } else if (event.key.code == sf::Keyboard::Escape)
                {
                    app.close();
                }
            }
            app.clear(sf::Color::Black);
            app.display();
        }
    }
}

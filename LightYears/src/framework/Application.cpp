#include "framework/Application.h"

ly::Application::Application() : mWindow{sf::VideoMode(1440, 1024), "Light Years"}
{
}

void ly::Application::Run()
{

    while (mWindow.isOpen())
    {
        sf::Event windowEvent;
        while (mWindow.pollEvent(windowEvent))
        {
            if (windowEvent.type == sf::Event::EventType::Closed)
            {
                mWindow.close();
            }
        }
    }
}

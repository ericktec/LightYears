#include "framework/Application.h"
#include <iostream>

ly::Application::Application() : mWindow{sf::VideoMode(1440, 1024), "Light Years"},
                                 mTargetFrameRate{60.f},
                                 mTickClock{}
{
}

void ly::Application::Run()
{
    mTickClock.restart();
    float accumulativeTime = 0.0f;
    // seconds / frames
    float targetDeltaTime = 1.f / mTargetFrameRate;
    while (mWindow.isOpen())
    {
        sf::Event windowEvent;
        while (mWindow.pollEvent(windowEvent))
        {
            if (windowEvent.type == sf::Event::EventType::Closed)
            {
                mWindow.close();
            }

            accumulativeTime += mTickClock.restart().asSeconds();

            // When it reaches the target delta time or bigger in slower machines
            while (accumulativeTime >= targetDeltaTime)
            {
                /*
                    We decreased the targetDeltatime so if in slow machine
                    we update twice until it catch up to the target frame rate
                */
                accumulativeTime -= targetDeltaTime;
                Tick(targetDeltaTime);
                Render();
            }
        }
    }
}

void ly::Application::Tick(float deltaTime)
{
}

void ly::Application::Render()
{
}

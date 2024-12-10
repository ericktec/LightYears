#pragma once
#include <SFML/Graphics.hpp>

namespace ly
{
    class Application
    {
    public:
        Application();

        void Run();

    private:
        sf::RenderWindow mWindow;

        float mTargetFrameRate;
        sf::Clock mTickClock;

        void RenderInternal();
        void TickInternal(float deltaTime);

        virtual void Render();
        virtual void Tick(float deltaTime);
    };

}
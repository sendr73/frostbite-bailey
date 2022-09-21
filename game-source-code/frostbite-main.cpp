////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "screen.h"

using namespace std;

int main()
{
    const auto gameWidth = 800.f; //Should change to 1000.f and 800.f (just too big for my laptop)
    const auto gameHeight = 600.f;
    const float frostbiteSpeed = 600.f;
    const float icebergSpeed = 150.f;

    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "");
    window.setVerticalSyncEnabled(true);

    Screen screen(window);

    sf::Clock clock;

    while(window.isOpen( ))
    {
        sf::Event evnt; //not using reserved word event
        bool pressed = false; //used to stop multiple jumps
        while(window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
            {
                window.close();
            }
            screen.frostbiteJump(window, evnt, pressed);
        }
        float deltaTime = clock.restart().asSeconds();
        screen.moveFrostbite(window, frostbiteSpeed, deltaTime);
        screen.moveIcerow(window, icebergSpeed, deltaTime); // (window,icebergSpeed,deltaTime);
        screen.icebergCollision(window,icebergSpeed,deltaTime);
        screen.refresh(window);
        window.display();
    }

    return 0;
}

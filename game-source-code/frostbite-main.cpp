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
#include "splashscreen.h"
using namespace std;

int main()
{
    //Game parameters
    const auto gameWidth = 1000.f;
    const auto gameHeight = 800.f;
    const float frostbiteSpeed = 600.f;
    const float icebergSpeed = 150.f;
    const float enemySpeed = 100.f;
    //setting up the window
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "");
    window.setVerticalSyncEnabled(true);
    //create screen object to run the game
    Screen screen(window);
    //setting up splash screen
    splashScreen splash_screen(gameWidth, gameHeight);
    auto drawSplashScreen = true;

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
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                drawSplashScreen  = false; //close the text
            }
            screen.frostbiteJump(window, evnt, pressed);
        }
        if(drawSplashScreen) //if the game has not yet started show instructions
        {
            splash_screen.draw(window);
            window.display();
            float deltaTime = clock.restart().asSeconds(); //Whithout this there might only be 1 iceberg per row
            //temperature_timer.resetClock();
        }
        else //play the game
        {
            float deltaTime = clock.restart().asSeconds();
            screen.moveFrostbite(window, frostbiteSpeed, deltaTime);
            screen.moveIcerow(window, icebergSpeed, deltaTime); // (window,icebergSpeed,deltaTime);
            screen.icebergCollision(window,icebergSpeed,deltaTime);
            screen.checkTemperature(); //should be combined with the action class
            screen.moveEnemyRow(window, enemySpeed, deltaTime);
            screen.enemyCollision(window, enemySpeed, deltaTime); //check for collision with crabs
            screen.refresh(window);
            window.display();
        }

    }

    return 0;
}

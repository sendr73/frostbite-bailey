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
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)&&screen.getStage()!=2)
            {
                if(screen.getStage()==4)
                {
                    screen.nextLevel(window);
                }
                else if(screen.getStage()==5)
                {
                    screen.initialise(window,false);
                }
                else
                {
                    screen.initialise(window,true);
                }
            }
            screen.frostbiteJump(window, evnt, pressed);
        }
        float deltaTime = 0.f;
        switch(screen.getStage())
        {
        case 1:
            splash_screen.draw(window);
            window.display();
            deltaTime = clock.restart().asSeconds(); //Whithout this there might only be 1 iceberg per row
            //temperature_timer.resetClock();
            break;
        case 2:
            screen.checkTemperature(); //should be combined with the action class
            deltaTime = clock.restart().asSeconds();
            screen.moveFrostbite(window, frostbiteSpeed, deltaTime);
            screen.moveIcerow(window, icebergSpeed, deltaTime); // (window,icebergSpeed,deltaTime);
            screen.icebergCollision(window,icebergSpeed,deltaTime);
            screen.moveEnemyRow(window, enemySpeed, deltaTime);
            screen.enemyCollision(window); //check for collision with crabs
            screen.refresh(window);
            window.display();
            if (!screen.hasLives())
            {
                screen.setStage(3);
            }
            break;
        case 3:
            screen.drawMessageScreen("You Lose",sf::Color::Red,"Press the ENTER key to restart",window);
            window.display();
            deltaTime = clock.restart().asSeconds();
            break;
        case 4:
            screen.drawMessageScreen("You Win",sf::Color::Green,"Press the ENTER key to proceed",window);
            window.display();
            deltaTime = clock.restart().asSeconds();
            break;
        case 5:
            screen.drawMessageScreen("You Froze",sf::Color(171,219,227,255),"Lost a life. Press the ENTER key to proceed",window);
            window.display();
            deltaTime = clock.restart().asSeconds();
            break;
        default:
            cout<<"Invalid game stage"<<endl;
        }

    }

    return 0;
}

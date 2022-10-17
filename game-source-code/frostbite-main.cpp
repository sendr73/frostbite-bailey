////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "game.h"
#include "screen.h"
#include "splashscreen.h"

using namespace std;

int main()
{
    //Game parameters
    const auto gameWidth = 1000.f;
    const auto gameHeight = 800.f;

    //setting up the window
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "");
    window.setVerticalSyncEnabled(true);
    //create screen object to run the game
    Screen screen(window);
    //setting up splash screen
    splashScreen splash_screen(gameWidth, gameHeight);
    Frostbite frosty;
    Game game;
    sf::Clock clock;
    bool jump_pressed = false; //used to stop multiple jumps
    bool rev_pressed = false;
    while(window.isOpen( ))
    {
        sf::Event evnt; //not using reserved word event
        while(window.pollEvent(evnt))
        {
            cout << screen.getStage() << endl;
            if (evnt.type == sf::Event::Closed)
            {
                window.close();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)&&screen.getStage()!=2)
            {
                screen.changeDisplay();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&screen.getStage()==2&&!rev_pressed)
            {
                rev_pressed=true;
                screen.reverseIceberg();
            }
            else if((evnt.type == sf::Event::KeyReleased)&&(evnt.key.code == sf::Keyboard::Space))
            {
                rev_pressed=false;
            }
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
            /*screen.checkTemperature(); //should be combined with the action class
            deltaTime = clock.restart().asSeconds();
            screen.moveAllSprites(window,frostbiteSpeed, deltaTime);
            screen.icebergCollision(window,deltaTime);
            screen.enemyCollision(window,deltaTime); //check for collision with crabs
            screen.refresh(window);
            window.display();
            if (!screen.hasLives())
            {
                screen.setStage(3);
            }
            */
            deltaTime = clock.restart().asSeconds();
            jump_pressed=screen.refresh(window, deltaTime, evnt, jump_pressed);
            window.display();
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

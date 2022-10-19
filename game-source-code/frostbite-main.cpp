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
    sf::Clock clock;
    bool jump_pressed = false; //used to stop multiple jumps
    bool rev_pressed = false; //used to debounce multiple reverses
    while(window.isOpen( ))
    {
        sf::Event evnt; //not using reserved word event
        float deltaTime = 0.f;
        screen.refresh(window, deltaTime, clock, evnt, jump_pressed, rev_pressed);
    }
    return 0;
}

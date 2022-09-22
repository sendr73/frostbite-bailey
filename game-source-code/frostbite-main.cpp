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
    //Game parameters
    const auto gameWidth = 1000.f;
    const auto gameHeight = 800.f;
    const float frostbiteSpeed = 600.f;
    const float icebergSpeed = 150.f;
    //setting up the window
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "");
    window.setVerticalSyncEnabled(true);
    //create screen object to run the game
    Screen screen(window);
    //setting up splash screen
    auto drawSplashScreen = true;
    sf::Text header;
    sf::Font font;
    if (!font.loadFromFile("resources/sansation.ttf"))
    {
        std::cout<<"Error Cannot load Font";
    }
    header.setFont(font); //set font, color etc
    header.setString("Frostbite Bailey");
    header.setCharacterSize(60);
    header.setFillColor(sf::Color::Blue);
    header.setStyle(sf::Text::Bold|sf::Text::Underlined);
    sf::FloatRect text_rectangle = header.getLocalBounds();
    //set positon of header
    header.setOrigin(text_rectangle.left + text_rectangle.width/2.0f,
                   text_rectangle.top  + text_rectangle.height/2.0f);
    header.setPosition(sf::Vector2f(gameWidth/2.0f,gameHeight/4.0f));

    sf::Text paragraph;
    paragraph.setString("Use the LEFT and RIGHT arrow keys to move Frostbite left and right \n"
                        "and the UP and DOWN arrow keys to jump platforms, up and down. Try \n"
                        "land on the moving icebergs. If Frostbite falls into the water, he \n"
                        "will respawn in the middle of the safezone. \n \n"
                        "Press the ENTER key to start.");
    paragraph.setFont(font); //set font, color etc
    paragraph.setCharacterSize(30);
    paragraph.setFillColor(sf::Color::White);
    text_rectangle = paragraph.getLocalBounds();
    //set positon of paragraph
    paragraph.setOrigin(text_rectangle.left + text_rectangle.width/2.0f,
                   text_rectangle.top  + text_rectangle.height/2.0f);
    paragraph.setPosition(sf::Vector2f(gameWidth/2.0f,gameHeight/2.0f));

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
            window.draw(header);
            window.draw(paragraph);
            window.display();
            float deltaTime = clock.restart().asSeconds(); //Whithout this there might only be 1 iceberg per row
        }
        else //play the game
        {
            float deltaTime = clock.restart().asSeconds();
            screen.moveFrostbite(window, frostbiteSpeed, deltaTime);
            screen.moveIcerow(window, icebergSpeed, deltaTime); // (window,icebergSpeed,deltaTime);
            screen.icebergCollision(window,icebergSpeed,deltaTime);
            screen.refresh(window);
            window.display();
        }

    }

    return 0;
}

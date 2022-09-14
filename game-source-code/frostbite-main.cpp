////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
//#include <cmath>
//#include <cstdlib>
//#include <ctime>
#include <iostream>

int main()
{
    const int gameWidth = 800; //Is this specified to be a particular value?
    const int gameHeight = 600;

    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "SFML FrostBite", sf::Style::Titlebar | sf::Style::Close);
    while(window.isOpen( ))
    {
        sf::Event evnt;
        while(window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }
    }

    return 0;
}

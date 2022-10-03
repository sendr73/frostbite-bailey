#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include <iostream>
#include <SFML\Graphics.hpp>

class splashScreen
{
    public:
        splashScreen();
        splashScreen(const float gameWidth, const float gameHeight);
        virtual ~splashScreen();
        void draw(sf::RenderWindow &window);

    protected:

    private:
    sf::Text header;
    sf::Font font;
    sf::Text paragraph;
};

#endif // SPLASHSCREEN_H

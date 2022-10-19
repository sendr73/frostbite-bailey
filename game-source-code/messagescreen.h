#ifndef MESSAGESCREEN_H
#define MESSAGESCREEN_H

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
using namespace std;
class MessageScreen
{
    public:
        MessageScreen();
        void drawMessageScreen(const string &title, const sf::Color &title_colour, const string &message, sf::RenderWindow &window);
        virtual ~MessageScreen();

    protected:

    private:
        sf::Text title_text, message_text;
};

#endif // MESSAGESCREEN_H

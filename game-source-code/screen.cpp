//Screen implementation
#include "screen.h"

using namespace std;

Screen::Screen(sf::RenderWindow &window)
{
    setBackground(window);
}

void Screen::setBackground(const sf::RenderWindow &window)
{
    sf::RectangleShape sky(sf::Vector2f(window.getSize().x,0.2*window.getSize().y));
    sky.setFillColor(sf::Color(78,119,195,255));
    sky.setPosition(0.f,0.2*window.getSize().y);
    sf::RectangleShape border(sf::Vector2f(window.getSize().x,0.01*window.getSize().y));
    border.setFillColor(sf::Color(204,117,190,255));
    border.setPosition(0.f,0.19*window.getSize().y);
    sf::RectangleShape safezone(sf::Vector2f(window.getSize().x,0.19*window.getSize().y));
    safezone.setFillColor(sf::Color(156,156,156,255));
    if (!texture.create(window.getSize().x,0.4*window.getSize().y))
    {
        //issue returning error from void, maybe try{catch}?
    }
    texture.clear();
    texture.draw(safezone);
    texture.draw(border);
    texture.draw(sky);
    background.setTexture(texture.getTexture());
}

Screen::~Screen()
{
    //dtor
}

//Screen implementation
#include "Frostbite.h"
Frostbite::~Frostbite()
{
}
Frostbite::Frostbite(std::string imDirectory, const sf::Vector2f &Size)
{
    if(!pTexture.loadFromFile(imDirectory))
    {
        std::cerr<<"Error\n"; //display error if it does not load
    }
    pSprite.setTexture(pTexture);
    pSprite.setScale(Size);
}
void Frostbite::drawPlayer(sf::RenderWindow &window)
{
    window.draw(pSprite);
}
//move player around
void Frostbite::movePlayer(char direction, float moveSpeed)
{
    if(direction == 'u')
    {
        pSprite.move(0, -moveSpeed);
    }
    else if(direction == 'd')
    {
        pSprite.move(0, moveSpeed);
    }
    else if(direction == 'l')
    {
        pSprite.move(-moveSpeed, 0);
    }
    else if(direction == 'r')
    {
        pSprite.move(moveSpeed, 0);
    }
}
//get and set players positon (should be center of player for now)
const sf::Vector2f Frostbite::getPlayerPosition() const
{
    return pSprite.getPosition();
}
void Frostbite::setPlayerPostion(float x, float y)
{
    pSprite.setPosition(x,y);
}




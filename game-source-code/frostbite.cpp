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
void Frostbite::movePlayer(char direction, float moveSpeed, const float gameHeight, const float gameWidth)
{
    if(direction == 'u')
    {
        pSprite.move(0, -moveSpeed);
        //screen colision on the top
        if(getPlayerPosition().y<0)
            setPlayerPostion(getPlayerPosition().x,0);
    }
    else if(direction == 'd')
    {
        pSprite.move(0, moveSpeed);
        //screen colision on the bottom
        if(getPlayerPosition().y+getPlayerHeight()>gameHeight)
            setPlayerPostion(getPlayerPosition().x,gameHeight-getPlayerHeight() );
    }
    else if(direction == 'l')
    {
        pSprite.move(-moveSpeed, 0);
        //screen colision on the left
        if(getPlayerPosition().x<0)
            setPlayerPostion(0,getPlayerPosition().y);
    }
    else if(direction == 'r')
    {
        pSprite.move(moveSpeed, 0);
        //screen colision on the right
        if(getPlayerPosition().x+getPlayerWidth()>gameWidth)
            setPlayerPostion(gameWidth-getPlayerWidth(), getPlayerPosition().y);
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

//get players width
const float Frostbite::getPlayerWidth() const
{
    return pSprite.getTexture()->getSize().x * pSprite.getScale().x;
}
const float Frostbite::getPlayerHeight() const
{
    return pSprite.getTexture()->getSize().x * pSprite.getScale().x;
}


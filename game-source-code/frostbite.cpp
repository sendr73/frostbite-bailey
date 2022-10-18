//Frostbite implementation
#include "Frostbite.h"
Frostbite::Frostbite(std::string imDirectory, const sf::Vector2f &Size): Element(imDirectory, Size)
{
    setPosition(200,100); //set Sprite to top left
    jumped = false;
}
// move player around horizontally
void Frostbite::move(char direction, const float &x, const float &y, float moveSpeed)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) //set direction from input keyboard
    {
        direction = 'l';
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        direction = 'r';
    }
    moveElement(direction,moveSpeed);
    // screen collision logic on the left
    if(getPosition().x<0 + getWidth()/2) //adjust the sides by width/2 when checking left and right
    {
        setPosition(getWidth()/2,getPosition().y);
    }
    // screen collision logic on the right
    if(getPosition().x>x-getWidth()/2) //adjust the sides by width/2 when checking left and right
    {
        setPosition(x-getWidth()/2, getPosition().y);
    }

}
// make player jump vertically (was added with the intention to animate)
void Frostbite::jump(char direction, float moveSpeed, const float gameHeight, const float gameWidth)
{
    jumped = true;
    moveElement(direction, moveSpeed);
    if(getPosition().y<0.375*gameHeight) // collision at upper limit of playing screen (below score etc)
    {
        setPosition(getPosition().x,0.375*gameHeight); // limits at the upper bound, ensures no height desync w/ icebergs
    }

    if(getPosition().y+getHeight()>gameHeight) // collision at bottom limit of playing screen
    {
        setPosition(getPosition().x,gameHeight); // limits to the bottom of the screen, respawns - desync irrelevent
    }
}
// returns if frostbite has jumped
const bool Frostbite::hasJumped() const
{
    return jumped;
}
// get players width
const float Frostbite::getWidth() const
{
    return getSize().x ;
}
// get players height
const float Frostbite::getHeight() const
{
    return getSize().y ;
}
// gets player speed
const float Frostbite::getSpeed() const
{
    return speed;
}
// resets characteristics
void Frostbite::reset()
{
    jumped = false;
}
// virtual destructor
Frostbite::~Frostbite()
{
}

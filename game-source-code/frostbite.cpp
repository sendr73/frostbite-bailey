//Screen implementation
#include "Frostbite.h"
Frostbite::Frostbite(std::string imDirectory, const sf::Vector2f &Size): Element(imDirectory, Size)
{
    setPosition(getWidth()/2,getHeight()); //set Sprite to top left
    jumped = false;
}
/*void Frostbite::draw(sf::RenderWindow &window)
{
    window.draw(fSprite);
}
*/
//move player around
void Frostbite::move(char direction, const sf::RenderWindow &window, float moveSpeed)
{
    auto gameHeight = window.getSize().y;
    auto gameWidth = window.getSize().x;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) //set direction from input keyboard
    {
        direction = 'l';
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        direction = 'r';
    }
    moveElement(direction,moveSpeed);

    //screen colision on the left
    if(getPosition().x<0 + getWidth()/2)
    {
        //adjust the sides by width/2 when checking left and right
        setPosition(getWidth()/2,getPosition().y);
        //setPostion(gameWidth/2,0.375*gameHeight);//set Sprite to top middle
        //return true; //indicate there was a clash
    }

    //screen colision on the right
    if(getPosition().x>gameWidth-getWidth()/2) //adjust the sides by width/2 when checking left and right
    {
        setPosition(gameWidth-getWidth()/2, getPosition().y);
        //return true;
    }

    //return false;
}
//make player jump
void Frostbite::jump(char direction, float moveSpeed, const float gameHeight, const float gameWidth)
{
    jumped = true;
    std::cout<<direction;
    moveElement(direction, moveSpeed);
    /*
    if(direction == 'u')
    {
        if(!(getPosition().y-moveSpeed< 0.f + getHeight())) //if tries to exceed boundaries, don't move (avoids misalignment with icebergs)
        {
            move(, -moveSpeed);
        }
    }
    else if(direction == 'd')
    {
        move(0, moveSpeed);
        //screen colision on the bottom
        if(getPosition().y>gameHeight) //check to base line
            setPosition(getPosition().x,gameHeight);
    }
    */
}
//returns if frostbite has jumped
const bool Frostbite::hasJumped() const
{
    return jumped;
}
/*
//get and set players positon (should be center of player for now)
const sf::Vector2f Frostbite::getPosition() const
{
    return fSprite.getPosition();
}
*/


//get players width
const float Frostbite::getWidth() const
{
    return getSize().x ;
}
const float Frostbite::getHeight() const
{
    return getSize().y ;
}

/*
//get bounding box
sf::FloatRect Frostbite::getBounding () const
{
    return fSprite.getGlobalBounds();
}
*/
//resets characterisitcs
void Frostbite::reset()
{
    jumped = false;
}
Frostbite::~Frostbite()
{
}

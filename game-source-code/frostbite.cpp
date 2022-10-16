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

    //screen colision on the left
    if(getPosition().x<0 + getWidth()/2)
    {
        //adjust the sides by width/2 when checking left and right
        setPosition(getWidth()/2,getPosition().y);

    }

    //screen colision on the right
    if(getPosition().x>x-getWidth()/2) //adjust the sides by width/2 when checking left and right
    {
        setPosition(x-getWidth()/2, getPosition().y);
    }
}
//make player jump
void Frostbite::jump(char direction, float moveSpeed, const float gameHeight, const float gameWidth)
{
    jumped = true;
    std::cout<<direction;
    moveElement(direction, moveSpeed);

   // if(direction == 'u' && !(getPosition().y-moveSpeed< 0.f + getHeight())) //if tries to exceed boundaries, don't move (avoids misalignment with icebergs)
   // {
   //     moveElement('d', moveSpeed);
   // }
    //screen colision on the bottom
   // if(direction == 'd'&& getPosition().y>gameHeight) //check to base line
   //     setPosition(getPosition().x,gameHeight);

}
//returns if frostbite has jumped
const bool Frostbite::hasJumped() const
{
    return jumped;
}

//get players width
const float Frostbite::getWidth() const
{
    return getSize().x ;
}
const float Frostbite::getHeight() const
{
    return getSize().y ;
}

//resets characterisitcs
void Frostbite::reset()
{
    jumped = false;
}
Frostbite::~Frostbite()
{
}

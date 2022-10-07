//Screen implementation
#include "Frostbite.h"
Frostbite::~Frostbite()
{
}
Frostbite::Frostbite(std::string imDirectory, const sf::Vector2f &Size)
{
    if(!fTexture.loadFromFile(imDirectory))
    {
        std::cerr<<"Error\n"; //display error if it does not load
    }
    fSprite.setTexture(fTexture);
    fSprite.setScale(Size);
    fSprite.setOrigin(getWidth()/2,getHeight()); //set orign to bottom centre
    setPostion(getWidth()/2,getHeight()); //set Sprite to top left
    jumped = false;
}
void Frostbite::draw(sf::RenderWindow &window)
{
    window.draw(fSprite);
}
//move player around
void Frostbite::move(char direction, const sf::RenderWindow &window, float moveSpeed)
{
    auto gameHeight = window.getSize().y;
    auto gameWidth = window.getSize().x;
    if(direction == 'l')
    {
        fSprite.move(-moveSpeed, 0);
        //screen colision on the left
        if(getPosition().x<0 + getWidth()/2)
        {//adjust the sides by width/2 when checking left and right
            setPostion(getWidth()/2,getPosition().y);
            //setPostion(gameWidth/2,0.375*gameHeight);//set Sprite to top middle
            //return true; //indicate there was a clash
        }
    }
    else if(direction == 'r')
    {
        fSprite.move(moveSpeed, 0);
        //screen colision on the right
        if(getPosition().x>gameWidth-getWidth()/2) //adjust the sides by width/2 when checking left and right
         {
             setPostion(gameWidth-getWidth()/2, getPosition().y);
             //return true;
         }
    }
    //return false;
}
//make player jump
void Frostbite::jump(char direction, float moveSpeed, const float gameHeight, const float gameWidth)
{
    jumped = true;
    if(direction == 'u')
    {
        if(!(getPosition().y-moveSpeed< 0.f + getHeight())) //if tries to exceed boundaries, don't move (avoids misalignment with icebergs)
        {
            fSprite.move(0, -moveSpeed);
        }
    }
    else if(direction == 'd')
    {
        fSprite.move(0, moveSpeed);
        //screen colision on the bottom
        if(getPosition().y>gameHeight) //check to base line
            setPostion(getPosition().x,gameHeight);
    }
}
//returns if frostbite has jumped
const bool Frostbite::hasJumped() const
{
    return jumped;
}
//get and set players positon (should be center of player for now)
const sf::Vector2f Frostbite::getPosition() const
{
    return fSprite.getPosition();
}
void Frostbite::setPostion(float x, float y)
{
    fSprite.setPosition(x,y);
}

//get players width
const float Frostbite::getWidth() const
{
    return fSprite.getTexture()->getSize().x * fSprite.getScale().x;
}
const float Frostbite::getHeight() const
{
    return fSprite.getTexture()->getSize().y * fSprite.getScale().y;
}

//get bounding box
sf::FloatRect Frostbite::getBounding () const
{
    return fSprite.getGlobalBounds();
}
//resets characterisitcs
void Frostbite::reset()
{
    jumped = false;
}

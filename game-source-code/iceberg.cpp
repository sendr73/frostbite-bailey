//Screen implementation
#include "iceberg.h"

Iceberg::~Iceberg()
{
}

Iceberg::Iceberg(std::string imDirectory, const sf::Vector2f &Size): Element("resources/iceberg.png",sf::Vector2f(1.f,1.f))
{
    /*  if(!iTexture.loadFromFile(imDirectory))
      {
          std::cerr<<"Error in loading iceberg texture\n";
      }
      iSprite.setTexture(iTexture);
      iSprite.setScale(Size);
      iSprite.setOrigin(getWidth()/2,getHeight()/2); //origin reset to middle of iceberg
      */
    direction = 'r';
    landed = false;
}
/*
void Iceberg::draw(sf::RenderWindow &window)
{
    window.draw(iSprite);
}*/

void Iceberg::move(char direction, const sf::RenderWindow &window, float moveSpeed)
{
    auto gameHeight = window.getSize().y;
    auto gameWidth = window.getSize().x;
    moveElement(direction, moveSpeed);
    // if(direction == 'l')
    // {
    //iSprite.move(-moveSpeed, 0);
    if(getPosition().x+getWidth()/2<=0)
    {
        setPosition(gameWidth-getWidth()/2,getPosition().y);
        //overlapIceberg.setPosition(-overlapIceberg.getWidth()/2,getPosition().y);
    }
    /*else if(getPosition().x-getWidth()/2<0)
    {
       // overlapIceberg.setPosition((gameWidth+getPosition().x),getPosition().y);
    }
    */
    // }
    // else if(direction == 'r')
    // {
    if(getPosition().x-getWidth()/2>=gameWidth)
    {
        setPosition(getWidth()/2,getPosition().y);
        // overlapIceberg.setPosition(-overlapIceberg.getWidth()/2,getPosition().y);
    }
    /*else if(getPosition().x+getWidth()/2>gameWidth)
    {
       // overlapIceberg.setPosition((getPosition().x-gameWidth),getPosition().y);
    }*/
}

const char Iceberg::getDirection() const
{
    return direction;
}

void Iceberg::setDirection(const char dir)
{
    direction = dir;
}

const float Iceberg::getWidth() const
{
    return getSize().x;
}

const float Iceberg::getHeight() const
{
    return getSize().y;
}
//logic for when landed on
void Iceberg::landedOn(std::string imDirectory)
{
    setTexture(imDirectory);
    landed = true;
}
//returns if has been landed on
bool Iceberg::beenLandedOn()
{
    return landed;
}
//resets characteristics
void Iceberg::reset(std::string imDirectory)
{
    setTexture(imDirectory);
    landed = false;
}

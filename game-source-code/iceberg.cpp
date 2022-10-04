//Screen implementation
#include "iceberg.h"

Iceberg::~Iceberg()
{
}

Iceberg::Iceberg(std::string imDirectory, const sf::Vector2f &Size)
{
    if(!iTexture.loadFromFile(imDirectory))
    {
        std::cerr<<"Error in loading iceberg texture\n";
    }
    iSprite.setTexture(iTexture);
    iSprite.setScale(Size);
    iSprite.setOrigin(getWidth()/2,getHeight()/2); //origin reset to middle of iceberg
    direction = 'r';
    landed = false;
}

void Iceberg::draw(sf::RenderWindow &window)
{
    window.draw(iSprite);
}

void Iceberg::move(float moveSpeed, const float gameHeight, const float gameWidth, Iceberg &overlapIceberg)
{
    if(direction == 'l')
    {
        iSprite.move(-moveSpeed, 0);
        if(getPosition().x+getWidth()/2<=0)
        {
            setPosition(gameWidth-getWidth()/2,getPosition().y);
            overlapIceberg.setPosition(-overlapIceberg.getWidth()/2,getPosition().y);
        }
        else if(getPosition().x-getWidth()/2<0)
        {
            overlapIceberg.setPosition((gameWidth+getPosition().x),getPosition().y);
        }
    }
    else if(direction == 'r')
    {
        iSprite.move(moveSpeed, 0);
        if(getPosition().x-getWidth()/2>=gameWidth)
        {
            setPosition(getWidth()/2,getPosition().y);
            overlapIceberg.setPosition(-overlapIceberg.getWidth()/2,getPosition().y);
        }
        else if(getPosition().x+getWidth()/2>gameWidth)
        {
            overlapIceberg.setPosition((getPosition().x-gameWidth),getPosition().y);
        }
    }
}

const sf::Vector2f Iceberg::getPosition() const
{
    return iSprite.getPosition();
}

void Iceberg::setPosition(float x, float y)
{
    iSprite.setPosition(x,y);
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
    return iSprite.getTexture()->getSize().x*iSprite.getScale().x;
}

const float Iceberg::getHeight() const
{
    return iSprite.getTexture()->getSize().y*iSprite.getScale().y;
}
//logic for when landed on
void Iceberg::landedOn(std::string imDirectory)
{
    if(!iTexture.loadFromFile(imDirectory))
    {
        std::cerr<<"Error in loading iceberg texture when landed\n";
    }
    iSprite.setTexture(iTexture);
    landed = true;
}
//returns if has been landed on
bool Iceberg::beenLandedOn()
{
    return landed;
}

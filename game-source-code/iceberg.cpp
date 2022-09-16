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
    iSprite.setOrigin(getIcebergWidth()/2,getIcebergHeight()/2);
}

void Iceberg::drawIceberg(sf::RenderWindow &window)
{
    window.draw(iSprite);
}

void Iceberg::moveIceberg(char direction, float moveSpeed, const float gameHeight, const float gameWidth, Iceberg &overlapIceberg)
{
    if(direction == 'l')
    {
        iSprite.move(-moveSpeed, 0);
        if(getIcebergPosition().x+getIcebergWidth()/2<=0)
        {
            setIcebergPosition(getIcebergWidth()/2,getIcebergPosition().y);
        }
        else if(getIcebergPosition().x-getIcebergWidth()/2<0)
        {
            overlapIceberg.setIcebergPosition((gameWidth-getIcebergPosition().x),getIcebergPosition().y);
        }
    }
    else if(direction == 'r')
    {
        iSprite.move(moveSpeed, 0);
        if(getIcebergPosition().x-getIcebergWidth()/2>=gameWidth)
        {
            setIcebergPosition(getIcebergWidth()/2,getIcebergPosition().y);
        }
        else if(getIcebergPosition().x+getIcebergWidth()/2>gameWidth)
        {
            overlapIceberg.setIcebergPosition((getIcebergPosition().x-gameWidth),getIcebergPosition().y);
        }
    }
}

const sf::Vector2f Iceberg::getIcebergPosition() const
{
    return iSprite.getPosition();
}

void Iceberg::setIcebergPosition(float x, float y)
{
    iSprite.setPosition(x,y);
}

const float Iceberg::getIcebergWidth() const
{
    return iSprite.getTexture()->getSize().x*iSprite.getScale().x;
}

const float Iceberg::getIcebergHeight() const
{
    return iSprite.getTexture()->getSize().y*iSprite.getScale().y;
}

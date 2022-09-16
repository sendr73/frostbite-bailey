//Screen implementation
#include "iceberg.h"

Iceberg::~Iceberg()
{
}

Iceberg::Iceberg(std::string imDirectory, const sf::Vector2f &Size)
{
    if(!iTexture.loadFromFile(imDirectory))
    {
        std::cerr<<"Error\n"; //display error if it does not load
    }
    iSprite.setTexture(iTexture);
    iSprite.setScale(Size);
    iSprite.setOrigin(iSprite.getScale().x/2,iSprite.getScale().y/2);
}

void Iceberg::drawIceberg(sf::RenderWindow &window)
{
    window.draw(iSprite);
}

void Iceberg::moveIceberg(char direction, float moveSpeed, const float gameHeight, const float gameWidth, sf::Sprite &overlapIceberg)
{

}

const sf::Vector2f Iceberg::getIcebergPosition() const
{

}

void setIcebergPostion(float x, float y)
{

}

const float Iceberg::getIcebergWidth() const
{

}

const float Iceberg::getIcebergHeight() const
{

}

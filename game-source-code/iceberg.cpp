//Screen implementation
#include "iceberg.h"

Iceberg::~Iceberg()
{
}

Iceberg::Iceberg(std::string imDirectory, const sf::Vector2f &Size): Element("resources/iceberg.png",sf::Vector2f(1.f,1.f))
{
    direction = 'r';
    landed = false;
    speed = 150.f;
}

void Iceberg::move(char direction, const float &x, const float &y, float moveSpeed)
{
    moveElement(direction, moveSpeed*speed);
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

const float Iceberg::getSpeed()
{
    return speed;
}
//resets characteristics
void Iceberg::reset(std::string imDirectory)
{
    setTexture(imDirectory);
    landed = false;
}

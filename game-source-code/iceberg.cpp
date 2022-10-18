//Iceberg implementation
#include "iceberg.h"
// default constructor
Iceberg::~Iceberg()
{
}
// parametized constructor, default values of iceberg.png and corresponding scale
Iceberg::Iceberg(std::string imDirectory, const sf::Vector2f &Size): Element("resources/iceberg.png",sf::Vector2f(1.f,1.f))
{
    direction = 'r';
    landed = false;
    speed = 150.f;
}
// moves the iceberg in the specified direction, with boundaries x and y
void Iceberg::move(char direction, const float &x, const float &y, float moveSpeed)
{
    moveElement(direction, moveSpeed*speed);
}
// retruns private member function direction
const char Iceberg::getDirection() const
{
    return direction;
}
// changes private member function direction
void Iceberg::setDirection(const char dir)
{
    direction = dir;
}
// retruns width of iceberg
const float Iceberg::getWidth() const
{
    return getSize().x;
}
// returns height of iceberg
const float Iceberg::getHeight() const
{
    return getSize().y;
}
// logic for when landed on, changes to image string
void Iceberg::landedOn(std::string imDirectory)
{
    setTexture(imDirectory);
    landed = true;
}
// returns if has been landed on (private member landed)
bool Iceberg::beenLandedOn()
{
    return landed;
}
// returns private member speed of the iceberg
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

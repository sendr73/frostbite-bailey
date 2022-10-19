#include "element.h"

Element::Element()
{
    //ctor
}

Element::Element(std::string imDirectory, const sf::Vector2f &Size)
{
    if(!texture_.loadFromFile(imDirectory))
    {
        std::cerr<<"Error cannot load generic image\n"; //display error if it does not load
    }
    sprite_.setTexture(texture_);
    sprite_.setOrigin(texture_.getSize().x/2,texture_.getSize().y); //set orign to bottom centre
}

void Element::moveElement(Direction direction, float moveSpeed)
{
    switch (direction)
    {
        case Direction::Left:
            sprite_.move(-moveSpeed, 0);
            break;
        case Direction::Right:
            sprite_.move(+moveSpeed, 0);
            break;
        case Direction::Up:
            sprite_.move(0,-moveSpeed);
            break;
        case Direction::Down:
            sprite_.move(0,+moveSpeed);
            break;
        default:
            //std::cout<<"Invalid direction"<<std::endl;
            break;
    }
}

void Element::setTexture(std::string imDirectory)
{
    if(!texture_.loadFromFile(imDirectory))
    {
        std::cerr<<"Error in loading texture";
    }
    sprite_.setTexture(texture_);
}

//get and set sprites position
const sf::Vector2f Element::getPosition() const
{
    return sprite_.getPosition();
}

void Element::setPosition(float x, float y)
{
    sprite_.setPosition(x,y);
}

//get player size
const sf::Vector2<unsigned int>  Element::getSize() const
{
    return texture_.getSize();
}


//get bounding box
sf::FloatRect Element::getBoundaries () const
{
    return sprite_.getGlobalBounds();
}

const sf::Sprite Element::getObject() const
{
    return sprite_;
}

Element::~Element()
{
    //dtor
}


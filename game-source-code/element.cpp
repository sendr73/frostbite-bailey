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

void Element::moveElement(char direction, float moveSpeed)
{
    switch (direction)
    {
        case 'l':
            sprite_.move(-moveSpeed, 0);
            break;
        case 'r':
            sprite_.move(+moveSpeed, 0);
            break;
        case 'u':
            sprite_.move(0,-moveSpeed);
            break;
        case 'd':
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

void Element::draw(sf::RenderWindow &window)
{
    window.draw(sprite_);
   // std::cout<<"Draw";
}

Element::~Element()
{
    //dtor
}


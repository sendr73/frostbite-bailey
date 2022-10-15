#include "icesystem.h"

IceSystem::IceSystem(const float &x, const float &y)
{
    icesystem_.push_back(i1);
    icesystem_.push_back(i2);
    icesystem_.push_back(i3);
    icesystem_.push_back(i4);
}

void IceSystem::move(char direction, const sf::RenderWindow &window, float moveSpeed) //move both rows
{
    for(int i = 0; i < row; i++)
    {
        icesystem_[i].move('q', window, moveSpeed); //q is passed in as a direction as direction is specified in the rows themselves
    }
}

void IceSystem::draw(sf::RenderWindow &window) //should be separated into a different class (print class)
{
    for(auto i =0; i<icesystem_.size(); i++)
    {
        icesystem_[i].draw(window);
    }
}

IceSystem::~IceSystem()
{
    //dtor
}

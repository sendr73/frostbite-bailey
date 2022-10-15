#include "icesystem.h"

IceSystem::IceSystem()
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

void IceSystem::collision(Frostbite &frostbite, const sf::RenderWindow &window, const float &deltaTime)
{
    sf::FloatRect frostbite_boundary_box = frostbite.getBoundaries();
    for(auto ice_row_it:icesystem_)
    {
        auto ice_row_boundary = ice_row_it.getRowBoundaries(); //get vector of the bourdary boxes of each enemy
        for(auto ice_boundary_it : ice_row_boundary)
        {
          if(frostbite_boundary_box.intersects(ice_boundary_it)) //if they intersect, the enemy will push frostbite along with them, generally causing him to fall off an iceberg
            {
                frostbite.move(ice_row_it[0].getDirection(),window,ice_row_it[0].getSpeed()*deltaTime);
            }
        }
    }
}

Icerow IceSystem::operator[](const int& index)
{
    return icesystem_[index];
}

const int IceSystem::size() const
{
    return icesystem_.size();
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

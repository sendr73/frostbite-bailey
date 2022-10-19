#include "icesystem.h"
// constructor for IceSystem, hardcoding is more efficient since there will always be 4 rows
IceSystem::IceSystem()
{
    icesystem_.push_back(i1);
    icesystem_.push_back(i2);
    icesystem_.push_back(i3);
    icesystem_.push_back(i4);
}
// moves each Icerow in the IceSystem using Icerow's move function
void IceSystem::move(Direction direction, const float &x, const float &y, float moveSpeed) //move both rows
{
    for(int i = 0; i < row; i++)
    {
        icesystem_[i].move(Direction::Null, x,y, moveSpeed); //q is passed in as a direction as direction is specified in the rows themselves
    }
}
// checks the collision for each row and returns the index of the collision. -1 if no collision
int IceSystem::collision(Frostbite &frostbite, const float &x, const float &y, const float &deltaTime)
{
    int index = -1; // default index
    int num = 0; // int num variable (easier than converting an iterator into an int)
    sf::FloatRect frostbite_boundary_box = frostbite.getBoundaries();
    for(auto ice_row_it:icesystem_)
    {
        num++; // increment num, tracking the row number
        auto ice_row_boundary = ice_row_it.getRowBoundaries(); // get vector of the bourdary boxes of each enemy
        for(auto ice_boundary_it : ice_row_boundary)
        {
          if(frostbite_boundary_box.intersects(ice_boundary_it))
            {
                // frostbite moves with the iceberg. Can use index of 0 since the speed is consistant
                frostbite.move(ice_row_it[0].getDirection(),x,y,ice_row_it[0].getSpeed()*deltaTime);
                index = num; // index stores the row number
                break;
            }
        }
    }
    return index;
}
// operator overload that returns the Icerow at index
Icerow IceSystem::operator[](const int& index)
{
    return icesystem_[index];
}
// returns the size of the IceSystem (should always be 4)
const int IceSystem::size() const
{
    return icesystem_.size();
}
// executes the landedOn function for the row at index, i
void IceSystem::rowLandedOn(const int &i)
{
    icesystem_[i].landedOn();
}

// executes reverse for the i-th Icerow in IceSystem
void IceSystem::reverse(const int &i)
{
    icesystem_[i].reverse();
}
// resets all Icebergs in IceSystem
void IceSystem::reset()
{
    for(int i = 0; i < icesystem_.size();i++)
    {
        icesystem_[i].reset();
    }
}
// default destuctor
IceSystem::~IceSystem()
{
    //dtor
}

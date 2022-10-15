#include "icesystem.h"

IceSystem::IceSystem(const float &x, const float &y)
{
    for (int i = 0; i < row; i++)
    {
        Icerow icerow(x,y,row);
        icesystem_.push_back(icerow);
    }
}

void IceSystem::move(const sf::RenderWindow &window,const float &moveSpeed)
{
    for(int i = 0; i < icesystem_.size(); i++)
    {
        icesystem_[i].moveRow(window,moveSpeed);
    }
}

IceSystem::~IceSystem()
{
    //dtor
}

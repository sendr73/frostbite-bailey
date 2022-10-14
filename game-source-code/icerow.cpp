#include "icerow.h"

Icerow::Icerow(const float &x, const float &y, const int &row)
{
    Iceberg iceberg;
    icerow_ = std::vector<Iceberg>(4,iceberg);
    int height = (row+1)*(0.125*y)+(0.375*y);
    for(int i = 0; i < icerow_.size();i++)
    {
        if(i%2==1)
        {
            icerow_[i].setDirection('l');
            icerow_[i].setPosition(-(i)*(20+iceberg.getWidth()),height);
        }
        else
        {
            icerow_[i].setPosition(x+(i)*(20+iceberg.getWidth()),height);
        }
    }
}

void Icerow::moveRow(const sf::RenderWindow &window, const float &moveSpeed)
{
    for(int i = 0; i < icerow_.size();i++)
    {
        icerow_[i].move(icerow_[i].getDirection(), window, moveSpeed);
    }
}

Icerow::~Icerow()
{
    //dtor
}

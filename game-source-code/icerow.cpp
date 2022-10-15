#include "icerow.h"

Icerow::Icerow(const float &x, const float &y, const int &row)
{
    //Iceberg iceberg_;
    icerow_ = std::vector<Iceberg>(4,iceberg_);
    int height = (row+1)*(0.125*y)+(0.390*y);
    if(row%2==1)
    {
        for(int i = 0; i < icerow_.size(); i++)
        {
            icerow_[i].setDirection('l');
            icerow_[i].setPosition(-(i+1)*(iceberg_.getWidth())-20,height);
        }
    }
    else
    {
        for(int i = 0; i < icerow_.size(); i++)
        {
            icerow_[i].setPosition(x+(i+1)*(iceberg_.getWidth())+20,height);
        }
    }
}

Iceberg Icerow::operator[](const int& index)
{
    return icerow_[index];
}

const int Icerow::size() const
{
    return icerow_.size();
}

void Icerow::move(char direction, const sf::RenderWindow &window, float deltaTime)
{
    //the passed in direction is not needed, as each row has a direciton set at construction
    auto gameWidth = window.getSize().x;
    auto gameHeight = window.getSize().y;
    const int last = icerow_.size();
    for(int i = 0; i<last-1; i++) //itterate through row and moves each enemy
    {
        icerow_[i].move(icerow_[i].getDirection(),window, deltaTime);
        if(icerow_[i].getDirection()=='r')
        {
            if(icerow_[i].getPosition().x-icerow_[i].getWidth()/2>=gameWidth)
            {
                icerow_[i].setPosition(gameWidth-icerow_[i].getPosition().x,icerow_[i].getPosition().y);
            }
        }
        else
        {
            if(icerow_[i].getPosition().x+icerow_[i].getWidth()/2<=0)
            {
                icerow_[i].setPosition(gameWidth-icerow_[i].getPosition().x,icerow_[i].getPosition().y);
            }
        }
    }
}

void Icerow::draw(sf::RenderWindow &window)
{
    for(auto i =0; i<icerow_.size(); i++)
    {
        icerow_[i].draw(window);
    }
}

Icerow::~Icerow()
{
    //dtor
}

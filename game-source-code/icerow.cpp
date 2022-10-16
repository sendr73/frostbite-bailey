#include "icerow.h"

Icerow::Icerow(const float &x, const float &y, const int &row)
{
    //Iceberg iceberg_;
    icerow_ = vector<Iceberg>(4,iceberg_);
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

void Icerow::move(char direction, const float &x, const float &y, float deltaTime)
{
    //the passed in direction is not needed, as each row has a direciton set at construction
    const int last = icerow_.size();
    for(int i = 0; i<last-1; i++) //itterate through row and moves each enemy
    {
        icerow_[i].move(icerow_[i].getDirection(),x,y, deltaTime);
        if(icerow_[i].getDirection()=='r')
        {
            if(icerow_[i].getPosition().x-icerow_[i].getWidth()/2>=x)
            {
                icerow_[i].setPosition(x-icerow_[i].getPosition().x,icerow_[i].getPosition().y);
            }
        }
        else
        {
            if(icerow_[i].getPosition().x+icerow_[i].getWidth()/2<=0)
            {
                icerow_[i].setPosition(x-icerow_[i].getPosition().x,icerow_[i].getPosition().y);
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

void Icerow::landedOn()
{
    for(auto i =0; i<icerow_.size(); i++)
    {
        icerow_[i].landedOn("resources/iceberg_landed.png");
    }
}

vector<sf::FloatRect> Icerow::getRowBoundaries() const //returns a vector containing the boundaries of each enemy in the row
{
    vector<sf::FloatRect> rowBoundaries;
    for(auto icerow_it : icerow_)
    {
        sf::FloatRect boundary = icerow_it.getBoundaries();
        boundary.width -= 100.f;
        boundary.left += 40.f;
        rowBoundaries.push_back(boundary);
    }
    return rowBoundaries;
}
void Icerow::reverse()
{
    char d;
    if(icerow_[0].getDirection()=='r')
    {d = 'l';}
    else
    {d = 'r';}
    for(int i = 0; i < icerow_.size();i++)
    {
        icerow_[i].setDirection(d);
    }
}

void Icerow::reset()
{
    for(int i = 0; i < icerow_.size();i++)
    {
        icerow_[i].reset("resources/iceberg.png");
    }
}

Icerow::~Icerow()
{
    //dtor
}

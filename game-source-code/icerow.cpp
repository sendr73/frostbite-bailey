#include "icerow.h"
// constructor for Icerow
Icerow::Icerow(const float &x, const float &y, const int &row)
{
    icerow_ = vector<std::shared_ptr<Iceberg>>{make_shared<Iceberg>(), make_shared<Iceberg>(), make_shared<Iceberg>(), make_shared<Iceberg>()};
    int height = (row+1)*(0.125*y)+(0.390*y); //based on the initial position of Frostbite
    if(row%2==1) //checks if row is odd
    {
        for(auto i = 0; i < icerow_.size(); i++)
        {
            icerow_[i]->setDirection(Direction::Left); //make direction left
            icerow_[i]->setPosition(-(i+1)*(iceberg_.getWidth())-20,height); //sets position
        }
    }
    else
    {
        for(auto i = 0; i < icerow_.size(); i++)
        {
            icerow_[i]->setPosition(x+(i+1)*(iceberg_.getWidth())+20,height); //sets position
        }
    }
}
// operator overload
Iceberg Icerow::operator[](const int& index)
{
    return *icerow_[index];
}
// returns size of icerow_
const int Icerow::size() const
{
    return icerow_.size();
}
// moves each Iceberg in Icerow, direction not needed, passed in as 'Q'
void Icerow::move(Direction direction, const float &x, const float &y, float deltaTime)
{
    // the passed in direction is not needed, as each row has a direciton set at construction
    const int last = icerow_.size();
    for(int i = 0; i<last-1; i++) // iterate through row and moves each enemy
    {
        icerow_[i]->move(icerow_[i]->getDirection(),x,y, deltaTime);
        if(icerow_[i]->getDirection()==Direction::Right) // if the iceberg is travelling right
        {
            if(icerow_[i]->getPosition().x-icerow_[i]->getWidth()/2>=x) // if the Iceberg at i exceeds the right screen boundary
            {
                icerow_[i]->setPosition(x-icerow_[i]->getPosition().x,icerow_[i]->getPosition().y); // move Iceberg to left of screen
            }
        }
        else // Iceberg is travelling left
        {
            if(icerow_[i]->getPosition().x+icerow_[i]->getWidth()/2<=0) // if the Iceberg at i exceeds the left screen boundary
            {
                icerow_[i]->setPosition(x-icerow_[i]->getPosition().x,icerow_[i]->getPosition().y); // move Iceberg to right of screen
            }
        }
    }
}

// changes the properties of each Iceberg in Icerow to be landed on
void Icerow::landedOn()
{
    for(auto i =0; i<icerow_.size(); i++)
    {
        icerow_[i]->landedOn("resources/iceberg_landed.png");
    }
}
// gets boundaries of each Iceberg - used for collisions
vector<sf::FloatRect> Icerow::getRowBoundaries() const //returns a vector containing the boundaries of each enemy in the row
{
    vector<sf::FloatRect> rowBoundaries;
    for(auto icerow_it : icerow_)
    {
        sf::FloatRect boundary = icerow_it->getBoundaries();
        boundary.width -= 100.f; // the texture is assymetrically slanted, decrease the right boundary to correspond to texture
        boundary.left += 40.f; // same applies as above, change is just less drastic
        rowBoundaries.push_back(boundary);
    }
    return rowBoundaries;
}
// reverse the direction of each Iceberg in Icerow
void Icerow::reverse()
{
    Direction d;
    if(icerow_[0]->getDirection()==Direction::Right)
    {d = Direction::Left;}
    else
    {d = Direction::Right;}
    for(int i = 0; i < icerow_.size();i++)
    {
        icerow_[i]->setDirection(d);
    }
}
// resets the properties of each Iceberg in Icerow
void Icerow::reset()
{
    for(int i = 0; i < icerow_.size();i++)
    {
        icerow_[i]->reset("resources/iceberg.png");
    }
}
// default destructor
Icerow::~Icerow()
{
    //dtor
}

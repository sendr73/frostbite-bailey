#include "igloo.h"

Igloo::Igloo()
{
    complete = false;
    blockAmount = 0;
}
//generates blocks
void Igloo::generateBlocks(const float x, const float y)
{
    sf::Vector2f blockSize{100.f,50.f};
    sf::Vector2f blockOrigin{blockSize.x/2,blockSize.y};
    for(int i = 0; i < 16; i++)
    {
        blocks[i].setSize(blockSize);
        blocks[i].setOrigin(blockOrigin); //sets to bottom-middle
        if(i<5)
        {
            blocks[i].setPosition(sf::Vector2f(x-(i*blockSize.x),y));
        }
        else if(i<10)
        {
            blocks[i].setPosition(sf::Vector2f(x-((i-5)*blockSize.x),y-blockSize.y));
        }
        else if(i<14)
        {
            blocks[i].setPosition(sf::Vector2f(x-((i-10)*blockSize.x)+blockSize.x/4,y-(2*blockSize.y)));
        }
        else if(i<16)
        {
            blocks[i].setPosition(sf::Vector2f(x-((i-14)*blockSize.x)+blockSize.x/2,y-(3*blockSize.y)));
        }
    }
}
//increments block amount
void Igloo::incrementBlockAmount()
{
    blockAmount++;
    if (blockAmount==16)
    {
        complete = true;
    }
}
//checks if Igloo is finished building
const bool Igloo::isComplete() const
{
    return complete;
}
Igloo::~Igloo()
{
    //dtor
}

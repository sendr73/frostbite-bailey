#include "igloo.h"

Igloo::Igloo()
{
    complete = false;
    blockAmount = 0;
}
//generates blocks
void Igloo::generateBlocks(const float x, const float y)
{
    sf::Vector2f blockSize{75.f,25.f};
    sf::Vector2f blockOrigin{blockSize.x/2,blockSize.y};
    //defining each block
    sf::RectangleShape block(blockSize);
    block.setOrigin(blockOrigin);
    block.setFillColor(sf::Color::White);

    blocks=vector<sf::RectangleShape>(16,block);
    for(int i = 0; i < 16; i++)
    {
        blocks[i] = sf::RectangleShape(blockSize);
        blocks[i].setOrigin(blockOrigin); //sets to bottom-middle
        if(i<5)
        {
            blocks[i].setPosition(sf::Vector2f(x-blockSize.x/1.5-(i*blockSize.x),0.25*y));
        }
        else if(i<10)
        {
            blocks[i].setPosition(sf::Vector2f(x-blockSize.x/1.5-((i-5)*blockSize.x),0.25*y-blockSize.y));
        }
        else if(i<13)
        {
            blocks[i].setPosition(sf::Vector2f(x-blockSize.x/1.5-((i-10)*blockSize.x)-blockSize.x,0.25*y-(2*blockSize.y)));
        }
        else if(i<15)
        {
            blocks[i].setPosition(sf::Vector2f(x-blockSize.x/1.5-((i-13)*blockSize.x)-3*blockSize.x/2,0.25*y-(3*blockSize.y)));
        }
        else
        {
            blocks[i] = sf::RectangleShape(sf::Vector2f(45.f,60.f));
            blocks[i].setOrigin(blocks[i].getSize().x/2,blocks[i].getSize().y);
            blocks[i].setFillColor(sf::Color::Black);
            blocks[i].setPosition(sf::Vector2f(x-blockSize.x/1.5-4*blockSize.x/2,0.25*y));
        }
    }
}
//increments block amount
void Igloo::incrementBlockAmount()
{
    if (blockAmount==16)
    {
        complete = true;
    }
    else
    {
        blockAmount++;
    }
}
//checks if Igloo is finished building
const bool Igloo::isComplete() const
{
    return complete;
}
//sets complete
void Igloo::toggleComplete()
{
    if(complete)
    {
        complete = false;
    }
    else
    {
        complete = true;
    }
}
//draws igloo up until blockAmount
const int Igloo::getBlockAmount() const
{
    return blockAmount;
}

const sf::RectangleShape Igloo::getBlock(const int &i) const
{
    return blocks[i];
}
//returns block position
const sf::Vector2f Igloo::getBlockPosition(const int &i) const
{
    return blocks[i-1].getPosition();
}
//returns block position
const sf::Vector2f Igloo::getBlockSize(const int &i) const
{
    return blocks[i-1].getSize();
}
//resets igloo
void Igloo::reset()
{
    toggleComplete();
    blockAmount=0;
}
Igloo::~Igloo()
{
    //dtor
}

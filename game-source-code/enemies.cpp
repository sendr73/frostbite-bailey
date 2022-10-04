#include "enemies.h"

Enemies::Enemies()
{
    //ctor
}

Enemies::Enemies(std::string imDirectory, const sf::Vector2f &Size)
{
    if(!eTexture.loadFromFile(imDirectory))
    {
        std::cerr<<"Error in loading enemies texture\n";
    }
    eSprite.setTexture(eTexture);
    eSprite.setScale(Size);
    eSprite.setOrigin(getWidth()/2,getHeight()/2); //origin reset to middle of iceberg
    direction = 'r';
}
void Enemies::draw(sf::RenderWindow &window)
{
    window.draw(eSprite);
}

void Enemies::move(float moveSpeed, const float gameHeight, const float gameWidth, Enemies &overlapEnemy)
{
    if(direction == 'l')
    {
        eSprite.move(-moveSpeed, 0);
        if(getPosition().x+getWidth()/2<=0)
        {
            setPosition(gameWidth-getWidth()/2,getPosition().y);
            overlapEnemy.setPosition(-overlapEnemy.getWidth()/2,getPosition().y);
        }
        else if(getPosition().x-getWidth()/2<0)
        {
            overlapEnemy.setPosition((gameWidth+getPosition().x),getPosition().y);
        }
    }
    else if(direction == 'r')
    {
        eSprite.move(moveSpeed, 0);
        if(getPosition().x-getWidth()/2>=gameWidth)
        {
            setPosition(getWidth()/2,getPosition().y);
            overlapEnemy.setPosition(-overlapEnemy.getWidth()/2,getPosition().y);
        }
        else if(getPosition().x+getWidth()/2>gameWidth)
        {
            overlapEnemy.setPosition((getPosition().x-gameWidth),getPosition().y);
        }
    }
}

const sf::Vector2f Enemies::getPosition() const
{
    return eSprite.getPosition();
}

void Enemies::setPosition(float x, float y)
{
    eSprite.setPosition(x,y);
}

const char Enemies::getDirection() const
{
    return direction;
}

void Enemies::setDirection(const char dir)
{
    direction = dir;
}

const float Enemies::getWidth() const
{
    return eSprite.getTexture()->getSize().x*eSprite.getScale().x;
}

const float Enemies::getHeight() const
{
    return eSprite.getTexture()->getSize().y*eSprite.getScale().y;
}

Enemies::~Enemies()
{
    //dtor
}

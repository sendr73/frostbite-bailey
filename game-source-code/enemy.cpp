#include "enemy.h"

Enemy::Enemy(): Element("resources/crab.png",sf::Vector2f(1.f,1.f)), direction{'r'}
{
    //ctor
}

Enemy::Enemy(std::string imDirectory): Element(imDirectory,sf::Vector2f(1.f,1.f)), direction{'r'}
{

}
/*
void Enemies::draw(sf::RenderWindow &window)
{
    window.draw(eSprite);
}
*/

void Enemy::move(char direction, const sf::RenderWindow &window, float moveSpeed) //enemeis must store its own speed
{
    auto gameHeight = window.getSize().y;
    auto gameWidth = window.getSize().x;
    moveElement(direction, moveSpeed);
//  eSprite.move(-moveSpeed, 0);
    if(getPosition().x+getWidth()/2<=0)
    {
        setPosition(gameWidth-getWidth()/2,getPosition().y);
        //overlapEnemy.setPosition(-overlapEnemy.getWidth()/2,getPosition().y);
    }

    /*        else if(getPosition().x-getWidth()/2<0)
            {
                //overlapEnemy.setPosition((gameWidth+getPosition().x),getPosition().y);
            } */
    if(getPosition().x-getWidth()/2>=gameWidth)
    {
        setPosition(getWidth()/2,getPosition().y);
        //overlapEnemy.setPosition(-overlapEnemy.getWidth()/2,getPosition().y);
    }
    else if(getPosition().x+getWidth()/2>gameWidth)
    {
        //overlapEnemy.setPosition((getPosition().x-gameWidth),getPosition().y);
    }

}
/*
const sf::Vector2f Enemies::getPosition() const
{
    return eSprite.getPosition();
}

void Enemies::setPosition(float x, float y)
{
    eSprite.setPosition(x,y);
}
*/

const char Enemy::getDirection() const
{
    return direction;
}

void Enemy::setDirection(const char dir)
{
    direction = dir;
}

const float Enemy::getWidth() const
{
    return getSize().x;
}

const float Enemy::getHeight() const
{
    return getSize().y;
}

/*
//get bounding box
sf::FloatRect Enemies::getBounding () const
{
    return eSprite.getGlobalBounds();
}
*/

Enemy::~Enemy()
{
    //dtor
}

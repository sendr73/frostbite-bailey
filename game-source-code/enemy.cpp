#include "enemy.h"

Enemy::Enemy(): Element("resources/crab.png",sf::Vector2f(1.f,1.f)), enemySpeed(70.0f), direction('r')
{
}

Enemy::Enemy(std::string imDirectory): Element(imDirectory,sf::Vector2f(1.f,1.f)), enemySpeed(70.0f), direction('r')
{
}

void Enemy::move(char direction, const float &x, const float &y, float deltaTime)
{
    moveElement(direction, deltaTime*enemySpeed);
    if(getPosition().x+getWidth()/2<=0)
    {
        setPosition(x-getWidth()/2,getPosition().y);
    }

    if(getPosition().x-getWidth()/2>=x)
    {
        setPosition(getWidth()/2,getPosition().y);
    }
}

const char Enemy::getDirection() const
{
    return direction;
}

void Enemy::setDirection(const char dir)
{
    direction = dir;
}
const float Enemy::getSpeed() const
{
    return enemySpeed;
}
const float Enemy::getWidth() const
{
    return getSize().x;
}

const float Enemy::getHeight() const
{
    return getSize().y;
}

Enemy::~Enemy()
{
    //dtor
}

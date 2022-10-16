#include "enemy.h"

Enemy::Enemy(): Element("resources/crab.png",sf::Vector2f(1.f,1.f))
{
    //ctor
}

Enemy::Enemy(std::string imDirectory): Element(imDirectory,sf::Vector2f(1.f,1.f))
{

}
/*
void Enemies::draw(sf::RenderWindow &window)
{
    window.draw(eSprite);
}
*/

void Enemy::move(char direction, const float &x, const float &y, float deltaTime) //enemeis must store its own speed
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

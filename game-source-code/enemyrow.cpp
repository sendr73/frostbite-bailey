#include "enemyrow.h"
#include <iostream>
#include "element.h"


EnemyRow::EnemyRow(std::string imDirectory, const MovementType &movement, float xStartPosition, float yStartPosition, Direction direction)
{
    enemy_row = vector<shared_ptr<Enemy>>{make_shared<Enemy>(imDirectory), make_shared<Enemy>(imDirectory), make_shared<Enemy>(imDirectory)} ;
    //set position of each enemy in the row
    for(int j = 0; j<enemy_row.size(); j++) //loops through columns
    {
        enemy_row[j]->setPosition((xStartPosition)+2*(j)*enemy_row[j]->getWidth()
                                 ,(yStartPosition+100)); //.y)+(frostbite.getPosition().y)+10);
    }
    movement_type_ = movement;
    direction_ = direction;
}
void EnemyRow::move(Direction direction, const float &x, const float &y, float deltaTime)
{
    //the passed in direction is not needed, as each row has a direciton set at construction
    for(int i = 0; i<enemy_row.size(); i++) //itterate through row and moves each enemy
    {
        enemy_row[i]->move(direction_,x,y, deltaTime);
    }
}
Direction EnemyRow::getDirection()
{
    return direction_;
}
const float EnemyRow::getSpeed()
{
    return enemy_row[0]->getSpeed(); //get set speed of any emeny
}

vector<sf::FloatRect> EnemyRow::getRowBoundaries() const //returns a vector containing the boundaries of each enemy in the row
{
    vector<sf::FloatRect> rowBoundaries;
    for(auto enemy_it : enemy_row)
    {
        auto boundary = enemy_it->getBoundaries();
        rowBoundaries.push_back(boundary);
    }
    return rowBoundaries;
}
Enemy EnemyRow::operator[](const int& index)
{
    return *enemy_row[index];
}
void EnemyRow::draw(sf::RenderWindow &window) //enables drawing - should be placed in separate class
{
    for(auto i =0; i<enemy_row.size(); i++)
    {
        enemy_row[i]->draw(window);
    }
}

EnemyRow::~EnemyRow()
{
    //dtor
}

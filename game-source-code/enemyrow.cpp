#include "enemyrow.h"

EnemyRow::EnemyRow()
{
    //ctor
}

EnemyRow::EnemyRow(std::string imDirectory, const MovementType &movement, float screenWidth, float screenHeight)
{

    Enemy enemy_ = Enemy(imDirectory);
    enemy_row=vector<Enemy>(4,enemy_); //initializes 1D
    //is setting position presentation or design
    for(int j = 0; j<enemy_row.size(); j++) //loops through columns
    {
        enemy_row[j].setPosition((20)+2*(j)*enemy_.getWidth()
                               ,(0.3*screenHeight)); //.y)+(frostbite.getPosition().y)+10);
        enemy_row[j].setDirection('l');
    }

}
void EnemyRow::move(char direction, const sf::RenderWindow &window, float deltaTime)
{
    for(int i = 0; i<enemy_row.size(); i++) //size of crab row == size of clam row
    {
        enemy_row[i].move(direction,window, enemySpeed*deltaTime);
        //enemy_row[i].move(,'r',window, enemySpeed*deltaTime);
    }

}

EnemyRow::~EnemyRow()
{
    //dtor
}

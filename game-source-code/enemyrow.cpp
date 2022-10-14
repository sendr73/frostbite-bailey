#include "enemyrow.h"
#include <iostream>

EnemyRow::EnemyRow()
{
    //ctor
}

EnemyRow::EnemyRow(std::string imDirectory, const MovementType &movement, float screenWidth, float screenHeight)
{

    std::cout<<"Constructor";

    enemy_row=vector<Enemy>(4,enemy_crab); //initializes 1D
    //is setting position presentation or design
    for(int j = 0; j<enemy_row.size(); j++) //loops through columns
    {
        enemy_row[j].setPosition((40)+2*(j)*enemy_crab.getWidth()
                                 ,(0.55*screenHeight+100)); //.y)+(frostbite.getPosition().y)+10);
        enemy_row[j].setDirection('l');
    }
    movement_type_ = movement;


}
void EnemyRow::move(char direction, const sf::RenderWindow &window, float deltaTime)
{


    auto gameWidth = window.getSize().x;
    auto gameHeight = window.getSize().y;

    for(int i = 0; i<enemy_row.size(); i++) //size of crab row == size of clam row
    {
        enemy_row[i].move('l',window, deltaTime);
        //moveSprite(clamrow[i],'r',window, enemySpeed*deltaTime);
    }

}
void EnemyRow::draw(sf::RenderWindow &window)
{

    //std::cout<<"Draw";
    for(auto i =0; i<enemy_row.size(); i++)
    {
        //std::cout<<"Draw 2";
        enemy_row[i].draw(window);
    }

}


EnemyRow::~EnemyRow()
{
    //dtor
}

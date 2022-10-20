#include "enemysystem.h"

EnemySystem::EnemySystem()
{
    enemy_matrix.push_back(make_shared<EnemyRow>("resources/crab.png", 40.f, 460.f, Direction::Left));
    enemy_matrix.push_back(make_shared<EnemyRow>("resources/clam.png", 40.f, 570.f, Direction::Right));
}
void EnemySystem::move(Direction direction, const float &x, const float &y, float deltaTime) //move both rows
{
    enemy_matrix[0]->move(Direction::Null, x,y, deltaTime); //q is passed in as a direction as direction is specified in the rows themselves
    enemy_matrix[1]->move(Direction::Null, x,y, deltaTime);
}
int EnemySystem::collision(Frostbite &frostbite,const float &x, const float &y, const float &deltaTime)
{
    int index = -1;
    int num = 0;
    sf::FloatRect frostbite_boundary_box = frostbite.getBoundaries();
    for(auto enemy_row_it: enemy_matrix)
    {
        num++;
        auto enemy_row_boundary = enemy_row_it->getRowBoundaries(); //get vector of the bourdary boxes of each enemy
        for(auto enemy_boundary_it : enemy_row_boundary)
        {
            if(frostbite_boundary_box.intersects(enemy_boundary_it)) //if they intersect, the enemy will push frostbite along with them, generally causing him to fall off an iceberg
            {
                frostbite.setPosition(x,2*y); //moves off any Iceberg
                index = num;
            }
        }
    }
    return index;
}

EnemyRow EnemySystem::operator[](const int& index)
{
    return *enemy_matrix[index];
}

EnemySystem::~EnemySystem()
{
    //dtor
}

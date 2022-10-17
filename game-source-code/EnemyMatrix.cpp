#include "EnemyMatrix.h"

EnemyMatrix::EnemyMatrix()
{
    enemy_matrix.push_back(make_shared<EnemyRow>("resources/crab.png", MovementType::Glide, 40.f, 460.f, 'l'));
    enemy_matrix.push_back(make_shared<EnemyRow>("resources/clam.png", MovementType::Glide, 40.f, 570.f, 'r'));
}
void EnemyMatrix::move(char direction, const float &x, const float &y, float deltaTime) //move both rows
{
    enemy_matrix[0]->move('q', x,y, deltaTime); //q is passed in as a direction as direction is specified in the rows themselves
    enemy_matrix[1]->move('q', x,y, deltaTime);
}
int EnemyMatrix::collision(Frostbite &frostbite,const float &x, const float &y, const float &deltaTime)
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
                frostbite.move(enemy_row_it->getDirection(),x,y, enemy_row_it->getSpeed()*deltaTime);
                index = num;
            }
        }
    }
    return index;
}

void EnemyMatrix::draw(sf::RenderWindow &window) //should be separated into a different class (print class)
{
    for(auto i =0; i<enemy_matrix.size(); i++)
    {
        enemy_matrix[i]->draw(window);
    }
}

EnemyMatrix::~EnemyMatrix()
{
    //dtor
}

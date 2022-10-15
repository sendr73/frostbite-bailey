#include "EnemyMatrix.h"

EnemyMatrix::EnemyMatrix()
{

    enemy_matrix.push_back(enemy_row_crab);

    enemy_matrix.push_back(enemy_row_clam);
}
void EnemyMatrix::move(char direction, const sf::RenderWindow &window, float moveSpeed)
{

    enemy_matrix[0].move('l', window, moveSpeed);
    enemy_matrix[01].move('r', window, moveSpeed);

}
void EnemyMatrix::collision(Frostbite &frostbite,const sf::RenderWindow &window)
{
    sf::FloatRect frostbite_boundary_box = frostbite.getBoundaries();
    for(auto i =0; i<enemy_matrix.size(); i++)
    {
        auto enemy_rowBoundary = enemy_matrix[i].getRowBoundaries();
        for(auto i =0; i<enemy_rowBoundary.size(); i++)
        {
          if(frostbite_boundary_box.intersects(enemy_rowBoundary[i]))
            {
                std::cout<<"Intersect";
                frostbite.move(enemy_matrix[i].getDirection(),window, enemy_matrix[i].getSpeed());
            }
        }
    }
}
void EnemyMatrix::draw(sf::RenderWindow &window)
{

    //std::cout<<"Draw";
    for(auto i =0; i<enemy_matrix.size(); i++)
    {
        //std::cout<<"Draw 2";
        enemy_matrix[i].draw(window);
    }

}

EnemyMatrix::~EnemyMatrix()
{
    //dtor
}

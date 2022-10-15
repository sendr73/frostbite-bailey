#include "EnemyMatrix.h"

EnemyMatrix::EnemyMatrix() //populate the enemy matrix array by pushing back the two enemy rows
{
    enemy_matrix.push_back(enemy_row_crab);
    enemy_matrix.push_back(enemy_row_clam);
}
void EnemyMatrix::move(char direction, const sf::RenderWindow &window, float moveSpeed) //move both rows
{
    enemy_matrix[0].move('q', window, moveSpeed); //q is passed in as a direction as direction is specified in the rows themselves
    enemy_matrix[01].move('q', window, moveSpeed);
}
void EnemyMatrix::collision(Frostbite &frostbite,const sf::RenderWindow &window)
{
    sf::FloatRect frostbite_boundary_box = frostbite.getBoundaries();
    for(auto enemy_row_it: enemy_matrix)
    {
        auto enemy_row_boundary = enemy_row_it.getRowBoundaries(); //get vector of the bourdary boxes of each enemy
        for(auto enemy_boundary_it : enemy_row_boundary)
        {
          if(frostbite_boundary_box.intersects(enemy_boundary_it)) //if they intersect, the enemy will push frostbite along with them, generally causing him to fall off an iceberg
            {
                frostbite.move(enemy_row_it.getDirection(),window, enemy_row_it.getSpeed());
            }
        }
    }
}
void EnemyMatrix::draw(sf::RenderWindow &window) //should be separated into a different class (print class)
{
    for(auto i =0; i<enemy_matrix.size(); i++)
    {
        enemy_matrix[i].draw(window);
    }
}

EnemyMatrix::~EnemyMatrix()
{
    //dtor
}

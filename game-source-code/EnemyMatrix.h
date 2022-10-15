//Class consisting of Enemy rows through composition
//This is the enemy class called by the game
//It uses class motion to move and deals with collisions through collision class
#ifndef ENEMYMATRIX_H
#define ENEMYMATRIX_H
#include <vector>
#include <string>
#include "enemyrow.h"
#include "motion.h"
#include "Collisions.h"
using namespace std;

class EnemyMatrix: public Motion, public Collisions
{
    public:
        EnemyMatrix(); //default construction is fine, not parameters are required to be passed through
        virtual void move(char direction, const sf::RenderWindow &window, float moveSpeed) override;
        virtual void collision(Frostbite &frostbite, const sf::RenderWindow &window) override;
        void draw(sf::RenderWindow &window);
        virtual ~EnemyMatrix();

    protected:

    private:
        //should implement smart pointers
        EnemyRow enemy_row_crab = EnemyRow("resources/crab.png", MovementType::Glide, 40.f, 460.f, 'l'); //two enemy rows created with different textures
        EnemyRow enemy_row_clam = EnemyRow("resources/clam.png", MovementType::Glide, 40.f, 565.f, 'r'); //they are pushed back into the enemy-matrix at construction
        vector<EnemyRow> enemy_matrix;
};

#endif // ENEMYMATRIX_H

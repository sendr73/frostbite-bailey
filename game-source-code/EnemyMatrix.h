//Class consisting of Enemy rows through composition
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
        EnemyMatrix();
        virtual void move(char direction, const sf::RenderWindow &window, float moveSpeed) override;
        virtual void collision(Frostbite &frostbite, const sf::RenderWindow &window) override;
        void draw(sf::RenderWindow &window);
        virtual ~EnemyMatrix();

    protected:

    private:
        EnemyRow enemy_row_crab = EnemyRow("resources/crab.png", MovementType::Glide, 40.f, 460.f);
        EnemyRow enemy_row_clam = EnemyRow("resources/clam.png", MovementType::Glide, 40.f, 560.f);
        vector<EnemyRow> enemy_matrix;

};

#endif // ENEMYMATRIX_H

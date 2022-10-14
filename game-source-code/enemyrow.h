#ifndef ENEMYROW_H
#define ENEMYROW_H
#include <vector>
#include <string>
//#include <iostream>
#include "enemy.h"
#include "motion.h"
#include "print.h"

using namespace std;
//should add  enum for movement type
enum class MovementType{Glide = 1, Stagger = 2};
class EnemyRow: public Motion
{
    public:
        EnemyRow();
        EnemyRow(std::string imDirectory, const MovementType &movement,float screenWidth, float screenHeight );
        virtual void move(char direction, const sf::RenderWindow &window, float moveSpeed) override;
        void draw(sf::RenderWindow &window);
        virtual ~EnemyRow();

    protected:

    private:
        Enemy enemy_crab = Enemy("resources/crab.png"); //enemy (set to crab)
        Enemy enemy_clam = Enemy("resources/clam.png"); //enemy (set to crab)
        const char direction = 'l'; //should be able to be changed
        vector<Enemy> enemy_row;
        Enemy overlap_enemy = Enemy("resources/frostbite.png");
        MovementType movement_type_ = MovementType::Glide; //initialized as glide
};

#endif // ENEMYROW_H

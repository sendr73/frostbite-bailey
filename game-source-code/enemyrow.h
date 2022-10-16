//Enemy row class
// Uses composition to create a vector of Enemy Class
// Interface Inheritance of Motion
// Has a private variable, direction, which sets direction of the row
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
        EnemyRow(std::string imDirectory, const MovementType &movement,float xStartPosition, float yStartPositionm, char direction);
        virtual void move(char direction, const float &x, const float &y, float deltaTime) override;
        char getDirection();
        const float getSpeed();
        vector<sf::FloatRect> getRowBoundaries() const;
        void draw(sf::RenderWindow &window);
        virtual ~EnemyRow();

    protected:

    private:
        Enemy enemy_ = Enemy("resources/crab.png"); //enemy, default is crab but can be changed with re-texturing
        char direction_ = 'l'; //initialized as left but is re-initialized in constructor
        const float EnemySpeed = 100.0f;
        vector<Enemy> enemy_row;
        Enemy overlap_enemy = Enemy("resources/frostbite.png");
        MovementType movement_type_ = MovementType::Glide; //initialized as glide - not yet implemented but important if birds are created
};

#endif // ENEMYROW_H

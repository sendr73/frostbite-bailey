/**
 * \brief Enemy Matrix Composing of a vector of EnemyRows
 *
 * Consists of the total enemy system, ultimately creating a 2D vector of enemies
 * Uses interface inheritance with move function
 * Overwrites collision function from Collision class
 * Deals with collisions with frostbite
 * Class that is called and created by the game
 *
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
 */

#ifndef ENEMYMATRIX_H
#define ENEMYMATRIX_H
#include <vector>
#include <string>
#include <memory>
#include "enemyrow.h"
#include "motion.h"
#include "Collisions.h"
using namespace std;

class EnemyMatrix: public Motion, public Collisions
{
    public:
        /**
        * \brief Enemy constructor
        *
        * Creates a vector consisting of two enemy rows;
        * Initializes the one enemy row to consist of crabs and the other to consist of clams
        * Sets direction of the two rows to be left and right respectedly
        *
        * No parameters required
        */
        EnemyMatrix();

        /**
        * \brief move function overwridden from motion class
        *
        * Itteratres through the vector and moves each enemy-row by passing on the input parameters to the EnemyRow.move function
        *
        * \param direction to move -
        * \param x is board width ????
        * \param y is board height ????
        * \param deltaTime is time passed
        */
        virtual void move(Direction direction, const float &x, const float &y, float moveSpeed) override;

        /**
        * \brief collision function overwridden from collision class
        *
        * Function checks the global boundaries of Frostbite with each enemy
        * If there is an intersection, Frostbite is pushed along with the enemy row
        *
        * \param Frosbite sprite passed by reference
        * \param x is board width ????
        * \param y is board height ????
        * \param deltaTime is time-passed
        */

        virtual int collision(Frostbite &frostbite, const float &x, const float &y, const float &deltaTime) override;

        /**
        * \brief Fucntion to ensure that the row can be drawn
        *
        * Itterates through the vector of enemmy-rows and calls the draw funciton of each one
        *
        */
        void draw(sf::RenderWindow &window);

        /**
        * \brief Default Destructor
        */
        virtual ~EnemyMatrix();

    protected:

    private:
        //should implement smart pointers
       // EnemyRow enemy_row_crab; // = EnemyRow("resources/crab.png", MovementType::Glide, 40.f, 460.f, 'l'); //two enemy rows created with different textures
        //EnemyRow enemy_row_clam; // = EnemyRow("resources/clam.png", MovementType::Glide, 40.f, 360.f, 'r'); //they are pushed back into the enemy-matrix at construction
        vector<std::shared_ptr<EnemyRow>> enemy_matrix;
};

#endif // ENEMYMATRIX_H

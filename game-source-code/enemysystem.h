/**
 * \brief Enemy System Composing of a vector of EnemyRow.
 * Consists of the total Enemy system, ultimately creating a 2D vector of Enemy Elements.
 * Uses interface inheritance from the abstract Motion and Collision classes.
 * Ensures that all the Enemy objects move correctly.
 * Deals with collisions with Frostbite.
 * Class that is called and created by the Game.
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
 */

#ifndef ENEMYSYSTEM_H
#define ENEMYSYSTEM_H
#include <vector>
#include <string>
#include <memory>
#include "enemyrow.h"
#include "motion.h"
#include "Collisions.h"
using namespace std;

class EnemySystem: public Motion, public Collisions
{
    public:
        /**
        * \brief Enemy constructor.
        * Creates a vector consisting of two EnemyRow objects.
        * Initializes the one EnemyRow to consist of crabs and the other to consist of clams.
        * Sets direction of the two rows to be left and right respectivelly.
        * No parameters required.
        */
        EnemySystem();

        /**
        * \brief move function overwridden from Motion class.
        * Iteratres through the vector and moves each EnemyRow by passing on the input parameters to the EnemyRow.move function.
        * \param direction to move, expected to be Direction::Null as direction of each row is pre-determined
        * \param x is board width
        * \param y is board height
        * \param deltaTime is time passed and is multipled with speed when implemented in EnemyRow
        */
        virtual void move(Direction direction, const float &x, const float &y, float deltaTime) override;

        /**
        * \brief collision function overwridden from Collision class.
        * Function checks the global boundaries of Frostbite with each Enemy.
        * If there is an intersection, Frostbite is pushed along with the EnemyRow.
        * The index of the EnemyRow is returned if collided, -1 if no collision.
        * \param Frosbite sprite passed by reference
        * \param x is board width
        * \param y is board height
        * \param deltaTime is time passed and is multipled with speed if Frostbite must be pushed
        */
        virtual int collision(Frostbite &frostbite, const float &x, const float &y, const float &deltaTime) override;

        /**
        * \brief [] operator overload.
        * Uses the [] operator to access the i-th Icerow in Icesystem. Cannot manipulate, just access.
        * \param index in EnemySystem
        * \return EnemyRow at index, i, in Enemy System
        */
        EnemyRow operator[](const int& index);

        /**
        * \brief Default Destructor
        */
        virtual ~EnemySystem();

    protected:

    private:
        vector<std::shared_ptr<EnemyRow>> enemy_matrix;
};

#endif // ENEMYMATRIX_H

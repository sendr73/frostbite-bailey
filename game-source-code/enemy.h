#ifndef ENEMIES_H
#define ENEMIES_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include "motion.h"
#include "element.h"

using namespace std;

/**
 * \brief Basic Enemy Element, can take on multiple skins.
 *
 * Uses implementation inheritance to inherite Element's public functions.
 * Uses interface inheritance with move function from Motion.
 * Has a set speed (direction is set in the enemy_rows).
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
 */
class Enemy: public Motion, public Element
{
    public:
        /**
        * \brief Default Enemy constructor.
        * Sets texture to crab.png by default.
        * Sets enemy speed to 70
        */
        Enemy();

        /**
        * \brief Enemy constructor.
        * Sets enemy speed to 70.
        * Sets texture from provided image.
        * \param imDirectory sets texture to be that image
        */
        Enemy(std::string imDirectory);

        /**
        * \brief move function overridden from Motion class.
        * Moves the Enemy object in given direction and at speed determined by deltaTime*enemySpeed.
        * Checks and adjusts for collisions at the end of the screen.
        * \param direction to move, expected to be set to Direction::Null
        * \param x is board width
        * \param y is board height
        * \param deltaTime is time passed and will be multipled with enemey speed when moving
        */
        virtual void move(Direction direction, const float &x, const float &y, float deltaTime) override; //function of class motion to move

        /**
        * \brief Function to get Enemy's width.
        * Gets the Enemy Element's size and returns its size.x
        * \return Width of the Enemy
        */
        const float getWidth() const;

        /**
        * \brief Function to get Enemy's height.
        * Gets the Enemy Element's size and returns its size.y
        * \return Height of Enemy
        */
        const float getHeight() const;

        /**
        * \brief Function that returns Enemy's speed.
        * \return the private member variable, enemySpeed, that is set as a const at construction
        */
        const float getSpeed() const;

        /**
        * \brief Default Enemy Destructor
        */
        virtual ~Enemy();

    protected:

    private:
        const float enemySpeed; //determines the speed of each enemy
};

#endif // ENEMIES_H

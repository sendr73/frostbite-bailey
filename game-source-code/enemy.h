/**
 * \brief Basic Enemy Element, can take on multiple skins
 *
 *Uses implementation inheritance to inherite elements public functions (should ideally change to composition)
 *Uses interface inheritance with move function
 *Has a set speed (direction is set in the enemy_rows)
 * @author Ruth-Ann Wright (2351852)
 */

#ifndef ENEMIES_H
#define ENEMIES_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include "motion.h"
#include "element.h"

class Enemy: public Motion, public Element
{
    public:
        /**
        * \brief Default Enemy constructor
        *
        * Sets texture to crab.png
        * Sets enemy speed to 70
        */
        Enemy();

        /**
        * \brief Enemy constructor
        *
        * Sets enemy speed to 70
        *
        * \param imDirectory sets texture to be that image
        */
        Enemy(std::string imDirectory);

        /**
        * \brief move function overwridden from motion class
        *
        * Moves the enemey object in given direction and at speed determined by deltaTime*enemySpeed
        * Checks and adjusts for collisions at the end of the board
        * \param direction to move - is ignored and enemy's private member variable direction is used
        * \param x is board width ????
        * \param y is board height ????
        * \param deltaTime is time passed as is multipled with enemey speed when moving
        */
        virtual void move(char direction, const float &x, const float &y, float deltaTime) override; //function of class motion to move

        /**
        * \brief Function to get enemy's width
        *
        * Gets the enemy-element's size and returns its sixe.x
        * \return enemy's width
        */
        const float getWidth() const;

        /**
        * \brief Function to get enemy's height
        *
        * Gets the enemy-element's size and returns its sixe.y
        *
        * \return enemy's height
        */
        const float getHeight() const;

        /**
        * \brief Function that returns enemy's speed
        *
        * Returns the private member variable enemy-speed, that is set as a const at construction
        *
        * \return enemy's speed
        */
        const float getSpeed() const;

        /**
        * \brief Default Enemy Destructor
        */
        virtual ~Enemy();

    protected:

    private:
        const float enemySpeed; //determines the speeed of each enemy
        char direction; //direction of each enemy
};

#endif // ENEMIES_H

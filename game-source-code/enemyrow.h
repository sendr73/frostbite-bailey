/**
 * \brief Enemy Row made composing of a vector of Enemy class
 *
 * Uses interface inheritance with move function
 * Has a set direction which is passed to each enemy object in the row
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
 */

#ifndef ENEMYROW_H
#define ENEMYROW_H
#include <vector>
#include <string>
#include <iostream>
#include <memory> //for smart pointers
#include "enemy.h"
#include "motion.h"

using namespace std;

class EnemyRow: public Motion
{
    public:
        /**
        * \brief Enemy constructor
        * Creates a vector consisting of three enemys with skin defined by imDirectory
        * Sets direction of the row and movement type
        * Sets the starting position of each enemy element
        *
        * \param imDirectory sets texture of each enemy in the row to be that image
        * \param xStartPosition sets the horizontal position of the left most element in the array
        * \param yStartPosition sets the vertical position of the left most element in the array
        * \param direction sets the direction of each enemy element
        */
        EnemyRow(std::string imDirectory,float xStartPosition, float yStartPositionm, Direction direction);

        /**
        * \brief move function overridden from motion class
        *
        * Iteratres through the vector and moves each enemy by passing the input parameters to the Enemy.move function with the direction
        *
        * \param direction to move, expected to be Direction::Null
        * \param x is board width, used to check for edge of screen collisions
        * \param y is board height, used to check for edge of screen collisions
        * \param deltaTime is the change in time
        */
        virtual void move(Direction direction, const float &x, const float &y, float deltaTime) override;

        /**
        * \brief Function to get the direction of row
        *
        * returns the private member variable direction - a member of Direction enum class
        *
        * \return enemy_row's direction
        */
        Direction getDirection();

        /**
        * \brief Function to get the speed that the row is moving
        *
        * Returns the row speed by getting the speed of the enemy
        *
        * \return the speed of enemy element in the row vector
        */
        const float getSpeed();

        /**
        * \brief Function to get the boundaries of each element in the row
        *
        * Returns the boundary of each element by itterating through the vector and storing
        * each boundary in a result vector
        *
        * \return vector of all the element's boundary rectangles
        */
        vector<sf::FloatRect> getRowBoundaries() const;

        /**
        * \brief Overload index operator
        */
        Enemy operator[](const int& index);

        /**
        * \brief Returns size of the enemy vector
        */
        const int getSize();

        /**
        * \brief Default Destructor
        */
        virtual ~EnemyRow();

    private:
        Direction direction_ = Direction::Left; //initialized as left but is re-initialized in constructor
        std::vector<std::shared_ptr<Enemy>> enemy_row;

};

#endif

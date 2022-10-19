/**
 * \brief Enemy Row made composing of a vector of Enemy class
 *
 *Uses interface inheritance with move function
 *Has a set direction which is passed to each enemy object in the row
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
#include "print.h"

using namespace std;

enum class MovementType{Glide = 1, Stagger = 2}; //should I delete??
class EnemyRow: public Motion
{
    public:
        /**
        * \brief Enemy constructor
        * Creates a vector consisting of three enemys with skin defined by imDirectotr
        * Sets direction of the row and movement type
        * Sets the starting position of each enemy element
        *
        * \param imDirectory sets texture of each enemy in the row to be that image
        * \param movement sets movement type to that one (Should be deleted???)
        * \param xStartPosition sets the horizontal position of the left most element in the array
        * \param yStartPosition sets the vertical position of the left most element in the array
        * \param direction sets the direction of each enemy element
        */
        EnemyRow(std::string imDirectory, const MovementType &movement,float xStartPosition, float yStartPositionm, Direction direction);

        /**
        * \brief move function overwridden from motion class
        *
        * Iteratres through the vector and moves each enemy by passing on the input parameters to the Enemy.move function
        *
        * \param direction to move -
        * \param x is board width ????
        * \param y is board height ????
        * \param deltaTime is time passed
        */
        virtual void move(Direction direction, const float &x, const float &y, float deltaTime) override;

        /**
        * \brief Function to get the direction the row is moving
        *
        * returns the private member variable direction
        *
        * \return enemy-row's direction
        */
        Direction getDirection();

        /**
        * \brief Function to get the speed that the row is moving
        *
        * Returns the row speed by getting the speed of an enmey element
        *
        * \return the speed of enemy element in the row vector
        */
        const float getSpeed();

        /**
        * \brief Function to get the boundaries of each element in the row
        *
        * Returns the boundary of each element by itterating through the vector and storing
        * each boundary in a vector
        *
        * \return vector of all the element's boundary rectangles
        */
        vector<sf::FloatRect> getRowBoundaries() const;

        /**
        * \brief Function to ensure that the row can be drawn
        *
        * Iterates through the vector of enemies and calls the draw function of each one
        *
        */
        void draw(sf::RenderWindow &window);

        /**
        * \brief Overload index operator
        */
        Enemy operator[](const int& index);

        /**
        * \brief Default Destructor
        */
        virtual ~EnemyRow();

    private:
        Direction direction_ = Direction::Left; //initialized as left but is re-initialized in constructor
        std::vector<std::shared_ptr<Enemy>> enemy_row;
       // Enemy overlap_enemy = Enemy("resources/frostbite.png");
        MovementType movement_type_ = MovementType::Glide; //initialized as glide - not yet implemented but important if birds are created
};

#endif // ENEMYROW_H

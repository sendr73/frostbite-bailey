/**
 * \brief Motion Class
 *
 * Base class with that allows for interface inheritance
 *
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
 */

#ifndef MOTION_H
#define MOTION_H
#include <SFML\Graphics.hpp>
#include "element.h" //required to get direction enum

class Motion
{
    public:
        /**
        * \brief Default Motion constructor
        */

        Motion();
        /**
        * \brief move function that deals with horizontal motion
        * Direction is passed in to move the object that overrides the virtual function.
        * The speed is determined by deltaTime*speed.
        * \param direction to move
        * \param x is the width of the screen
        * \param y is the height of the screen
        * \param moveSpeed is the speed that the object travels
        */
        virtual void move(Direction direction, const float &x, const float &y, float moveSpeed) = 0;

        /**
        * \brief Default Motion Destructor
        */
        virtual ~Motion();

    protected:

    private:
};

#endif // MOTION_H

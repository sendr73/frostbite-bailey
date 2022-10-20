#ifndef COLLISIONS_H
#define COLLISIONS_H
#include "Frostbite.h"
#include <SFML\Graphics.hpp>

using namespace std;

/**
 * \brief Collisions Class.
 * Base class with that allows for interface inheritance
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
 */
class Collisions
{
    public:
        /**
        * \brief Default Collisions constructor
        */
        Collisions();

        /**
        * \brief Virtual collision function.
        * Objects that will be colliding/interacting with Frostbite will override this function. They will need to take the
        * screen size and change in time as parameters because the collisions will lead to activity (like moving with an Iceberg).
        * \param frostbite Frostbite object
        * \param x width of the screen
        * \param y height of the screen
        * \param deltaTime change in time, that will define the dstance travelled by the Elements
        */
        virtual int collision(Frostbite &frostbite, const float &x, const float &y, const float &deltaTime) = 0;

        /**
        * \brief Default Collisions Destructor
        */
        virtual ~Collisions();

    protected:

    private:
};

#endif // COLLISIONS_H

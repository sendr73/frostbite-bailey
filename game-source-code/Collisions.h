#ifndef COLLISIONS_H
#define COLLISIONS_H
#include "Frostbite.h"
#include <SFML\Graphics.hpp>

class Collisions
{
    public:
        Collisions();
        virtual int collision(Frostbite &frostbite, const float &x, const float &y, const float &deltaTime) = 0;
        virtual ~Collisions();

    protected:

    private:
};

#endif // COLLISIONS_H

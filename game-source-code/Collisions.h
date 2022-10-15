#ifndef COLLISIONS_H
#define COLLISIONS_H
#include "Frostbite.h"
#include <SFML\Graphics.hpp>

class Collisions
{
    public:
        Collisions();
        virtual void collision(Frostbite &frostbite, const sf::RenderWindow &window) = 0;
        virtual ~Collisions();

    protected:

    private:
};

#endif // COLLISIONS_H

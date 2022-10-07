#ifndef MOTION_H
#define MOTION_H
#include <SFML\Graphics.hpp>

class Motion
{
    public:
        Motion();
        virtual ~Motion();
        virtual void move(char direction, const sf::RenderWindow &window, float moveSpeed) = 0;

    protected:

    private:
};

#endif // MOTION_H

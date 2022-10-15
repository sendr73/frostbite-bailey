#ifndef ICESYSTEM_H
#define ICESYSTEM_H

#include "icerow.h"
#include <SFML\Graphics.hpp>
#include <vector>

class IceSystem
{
    public:
        IceSystem(const float &x=0, const float &y=0);
        void move(const sf::RenderWindow &window,const float &moveSpeed);
        virtual ~IceSystem();

    protected:

    private:
        std::vector<Icerow> icesystem_;
        const int row = 4;
};

#endif // ICESYSTEM_H

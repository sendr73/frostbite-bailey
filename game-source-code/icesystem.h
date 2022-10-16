#ifndef ICESYSTEM_H
#define ICESYSTEM_H

#include "icerow.h"
#include <SFML\Graphics.hpp>
#include <vector>
#include "Collisions.h"

class IceSystem: public Motion, public Collisions
{
    public:
        IceSystem();
        virtual void move(char direction, const sf::RenderWindow &window, float deltaTime) override;
        virtual int collision(Frostbite &frostbite, const sf::RenderWindow &window, const float &deltaTime) override;
        Icerow operator[](const int& index);
        int const size() const;
        void draw(sf::RenderWindow &window);
        virtual ~IceSystem();

    protected:

    private:
        Icerow i1;
        Icerow i2 = Icerow(1000.f,800.f,1);
        Icerow i3 = Icerow(1000.f,800.f,2);
        Icerow i4 = Icerow(1000.f,800.f,3);
        std::vector<Icerow> icesystem_;
        const int row = 4;
};

#endif // ICESYSTEM_H

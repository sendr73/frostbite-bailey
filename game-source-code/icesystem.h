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
        virtual void move(char direction, const float &x, const float &y, float deltaTime) override;
        virtual int collision(Frostbite &frostbite, const float &x, const float &y, const float &deltaTime) override;
        Icerow operator[](const int& index);
        int const size() const;
        void rowLandedOn(const int &i);
        void draw(sf::RenderWindow &window);
        void reset();
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

#ifndef ICEROW_H
#define ICEROW_H

#include "iceberg.h"
#include <SFML\Graphics.hpp>
#include <vector>

class Icerow: public Motion
{
    public:
        Icerow(const float &x=1000.f, const float &y=800.f,const int &row=0);
        void draw(sf::RenderWindow &window);
        virtual void move(char direction, const sf::RenderWindow &window, float deltaTime) override;
        virtual ~Icerow();

    protected:

    private:
        Iceberg iceberg_;
        std::vector<Iceberg> icerow_;
};

#endif // ICEROW_H

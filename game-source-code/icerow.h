#ifndef ICEROW_H
#define ICEROW_H

#include "iceberg.h"
#include <SFML\Graphics.hpp>
#include <vector>

class Icerow
{
    public:
        Icerow(const float &x=0, const float &y=0,const int &row=0);
        void moveRow(const sf::RenderWindow &window,const float &moveSpeed);
        virtual ~Icerow();

    protected:

    private:
        std::vector<Iceberg> icerow_;
};

#endif // ICEROW_H

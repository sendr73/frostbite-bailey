#ifndef ICEROW_H
#define ICEROW_H

#include "iceberg.h"
#include <SFML\Graphics.hpp>
#include <memory>
#include <vector>

using namespace std;

class Icerow: public Motion
{
    public:
        Icerow(const float &x=1000.f, const float &y=800.f,const int &row=0);
        Iceberg operator[](const int& index);
        const int size() const;
        void draw(sf::RenderWindow &window);
        virtual void move(char direction, const float &x, const float &y, float deltaTime) override;
        void landedOn();
        vector<sf::FloatRect> getRowBoundaries() const;
        void reverse();
        void reset();
        virtual ~Icerow();

    protected:

    private:
        Iceberg iceberg_;
        std::vector<std::shared_ptr<Iceberg>> icerow_;
};

#endif // ICEROW_H

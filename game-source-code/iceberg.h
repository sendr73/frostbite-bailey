#ifndef ICEBERG
#define ICEBERG

#include <iostream>
#include <SFML\Graphics.hpp>
#include "motion.h"
#include "element.h"
//
class Iceberg: public Motion, public Element
{
    public:
        Iceberg(): Element("resources/iceberg.png",sf::Vector2f(1.f,1.f)),direction{'r'},landed{false}{
        //default constructor
        }
        Iceberg(std::string imDirectory, const sf::Vector2f &Size);
        //draws the iceberg on the window
       // void draw(sf::RenderWindow &window);
        //moves the iceberg
        virtual void move(char direction, const float &x, const float &y, float moveSpeed) override;
        //getter and setter for the position of the iceberg
       // const sf::Vector2f getPosition() const;
        //void setPosition(float x, float y);
        //getter and setter for the direction of the iceberg
        const char getDirection() const;
        void setDirection(const char dir);
        //get iceberg dimensions
        const float getWidth() const;
        const float getHeight() const;
        //logic for when landed on
        void landedOn(std::string imDirectory);
        bool beenLandedOn();
        //resets characteristics of iceberg
        const float getSpeed();
        void reset(std::string imDirectory);
        virtual ~Iceberg();

    private:
        //sf::Texture iTexture;
        //sf::Sprite iSprite;
        char direction; //will be 'r' by default, see constructor
        bool landed; //will be false by default
        float speed=150.f;
};

#endif

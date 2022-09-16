#ifndef ICEBERG
#define ICEBERG

#include <iostream>
#include <SFML\Graphics.hpp>

class Iceberg
{
    public:
        Iceberg(){
        //default constructor
        }
        Iceberg(std::string imDirectory, const sf::Vector2f &Size);
        //draws the iceberg on the window
        void draw(sf::RenderWindow &window);
        //moves the iceberg
        void move(char direction, float moveSpeed, const float gameHeight, const float gameWidth, Iceberg &overlapIceberg);
        //getter and setter for the position of the iceberg
        const sf::Vector2f getPosition() const;
        void setPosition(float x, float y);
        //get iceberg dimensions
        const float getWidth() const;
        const float getHeight() const;
        virtual ~Iceberg();

    private:
        sf::Texture iTexture;
        sf::Sprite iSprite;
};

#endif

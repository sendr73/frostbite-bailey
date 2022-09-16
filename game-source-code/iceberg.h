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
        void drawIceberg(sf::RenderWindow &window);
        //moves the iceberg
        void moveIceberg(char direction, float moveSpeed, const float gameHeight, const float gameWidth, sf::Sprite &overlapIceberg);
        //getter and setter for the position of the iceberg
        const sf::Vector2f getIcebergPosition() const;
        void setIcebergPostion(float x, float y);
        //get iceberg dimensions
        const float getIcebergWidth() const;
        const float getIcebergHeight() const;
        virtual ~Iceberg();

    private:
        sf::Texture iTexture;
        sf::Sprite iSprite;
};

#endif

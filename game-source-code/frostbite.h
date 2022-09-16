#ifndef FROSTBITE_H
#define FROSTBITE_H

#include <iostream>
#include <SFML\Graphics.hpp>

class Frostbite
{
    public:
        Frostbite(){
        //default
        }
        Frostbite(std::string imDirectory, const sf::Vector2f &Size);
        void draw(sf::RenderWindow &window);

        //move player around
        void move(char direction, float moveSpeed, const float gameHeight, const float gameWidth);
        //get and set players positon (should be center of player for now)
        const sf::Vector2f getPosition() const ;
        void setPostion(float x, float y);
        //get players width
        const float getWidth() const ;
        const float getHeight() const ;
        virtual ~Frostbite();

    protected:

    private:
        sf::Texture fTexture;
        sf::Sprite fSprite;
};

#endif // FROSTBITE_H


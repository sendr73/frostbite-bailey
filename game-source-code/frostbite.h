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
        void drawPlayer(sf::RenderWindow &window);

        //move player around
        void movePlayer(char direction, float moveSpeed);
        //get and set players positon (should be center of player for now)
        const sf::Vector2f getPlayerPosition() const ;
        void setPlayerPostion(float x, float y);
        virtual ~Frostbite();

    protected:

    private:
        sf::Texture pTexture;
        sf::Sprite pSprite;
};

#endif // FROSTBITE_H


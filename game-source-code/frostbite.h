#ifndef FROSTBITE_H
#define FROSTBITE_H

#include <iostream>
#include <SFML\Graphics.hpp>
#include "motion.h"
#include "element.h"

class Frostbite: public Motion, public Element
{
    public:
        Frostbite(): Element("resources/frostbite.png",sf::Vector2f(1.f,1.f)){
        };
        Frostbite(std::string imDirectory, const sf::Vector2f &Size);
         //move player around
        virtual void move(char direction, const sf::RenderWindow &window, float moveSpeed) override;
        //make frostbite jump
        void jump(char direction, float moveSpeed, const float gameHeight, const float gameWidth);
        //returns true if frostbite has jumped
        const bool hasJumped() const;
        //using base class getSize, get the width and height of Frosbite
        const float getWidth() const ;
        const float getHeight() const ;
        //reset Frostbite's starting postion
        void reset();
        virtual ~Frostbite();

    protected:

    private:
       // sf::Texture fTexture;
       // sf::Sprite fSprite;
        bool jumped; //to see if the player has jumped, has implicatiins when counting icebergs for score
};

#endif // FROSTBITE_H


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
        //default

        };
        Frostbite(std::string imDirectory, const sf::Vector2f &Size);
        //void draw(sf::RenderWindow &window);

        //move player around
        virtual void move(char direction, const sf::RenderWindow &window, float moveSpeed) override;
        //make frostbite jump
        void jump(char direction, float moveSpeed, const float gameHeight, const float gameWidth);
        //returns if frostbite has jumped
        const bool hasJumped() const;
        //get and set players positon (should be center of player for now);
        //const sf::Vector2f getPosition() const ;
       // void setPostion(float x, float y);
        //get players width
        const float getWidth() const ;
        const float getHeight() const ;
        //return global boundaries
        //sf::FloatRect getBounding () const;
        //resets Frostbite characteristics
        void reset();
        virtual ~Frostbite();

    protected:

    private:
       // sf::Texture fTexture;
       // sf::Sprite fSprite;
        bool jumped; //to see if the player has jumped, has implicatiins when counting icebergs for score
};

#endif // FROSTBITE_H


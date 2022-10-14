#ifndef ENEMIES_H
#define ENEMIES_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include "motion.h"
#include "element.h"

class Enemy: public Motion, public Element
{
    public:
        Enemy();
        Enemy(std::string imDirectory);
        //for now much of this code is repeated in the iceberge class
        //consider creating another base code for sprite which has move, get dimenstions etc

        //draws enemy on the window
        //void draw(sf::RenderWindow &window);
        //moves enemy
       virtual void move(char direction, const sf::RenderWindow &window, float moveSpeed) override;
        //getter and setter for the position of enemy
      //  const sf::Vector2f getPosition() const;
       // void setPosition(float x, float y);
        //getter and setter for the direction of enemy
        const char getDirection() const;
        void setDirection(const char dir);
        //get enemies dimensions
        const float getWidth() const;
        const float getHeight() const;
        //return global boundaries
        sf::FloatRect getBounding () const;
        virtual ~Enemy();

    protected:

    private:
       // sf::Texture eTexture;
        //sf::Sprite eSprite;
        char direction; //will be 'r' by default, see constructor
};

#endif // ENEMIES_H

#ifndef ENEMIES_H
#define ENEMIES_H
#include <iostream>
#include <SFML\Graphics.hpp>

class Enemies
{
    public:
        Enemies();
        Enemies(std::string imDirectory, const sf::Vector2f &Size);
        //for now much of this code is repeated in the iceberge class
        //consider creating another base code for sprite which has move, get dimenstions etc

        //draws enemy on the window
        void draw(sf::RenderWindow &window);
        //moves enemy
        void move(float moveSpeed, const float gameHeight, const float gameWidth, Enemies &overlapEnemy);
        //getter and setter for the position of enemy
        const sf::Vector2f getPosition() const;
        void setPosition(float x, float y);
        //getter and setter for the direction of enemy
        const char getDirection() const;
        void setDirection(const char dir);
        //get enemies dimensions
        const float getWidth() const;
        const float getHeight() const;
        //return global boundaries
        sf::FloatRect getBounding () const;
        virtual ~Enemies();

    protected:

    private:
        sf::Texture eTexture;
        sf::Sprite eSprite;
        char direction; //will be 'r' by default, see constructor
};

#endif // ENEMIES_H

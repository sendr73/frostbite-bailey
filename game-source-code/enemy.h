//Enemy Class
//Uses implementation inheritance to inherite elements public functions (should ideally change to composition)
//Uses interface inheritance with move function
//Has a set speed (direction is set in the enemy_rows)
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

       virtual void move(char direction, const sf::RenderWindow &window, float deltaTime) override; //function of class motion to move

        const float getWidth() const; //uses elements functions to get clearer dimensions
        const float getHeight() const;
        const char getDirection() const;
        void setDirection(const char dir);
        const float getSpeed() const;
        //return global boundaries
        sf::FloatRect getBounding () const;
        virtual ~Enemy();

    protected:

    private:
        const float enemySpeed = 100.0f;
        char direction;
};

#endif // ENEMIES_H

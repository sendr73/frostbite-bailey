/**
 * \brief Frostbite Character
 *
 * Uses implementation inheritance to inherite elements public functions (should ideally change to composition)
 * Uses interface inheritance with move function from class motion
 * Has a set speed (direction is set in the enemy_rows)
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender
 */
#ifndef FROSTBITE_H
#define FROSTBITE_H

#include <iostream>
#include <SFML\Graphics.hpp>
#include "motion.h"
#include "element.h"

class Frostbite: public Motion, public Element
{
    public:
       /**
        * \brief Default Frostbite constructor
        *
        * Sets texture to frostbite.png
        */
        Frostbite(): Element("resources/frostbite.png",sf::Vector2f(1.f,1.f)){
        };
        /**
        * \brief Frostbite constructor with image parameter
        *
        * Sets texture to passed in image - useful for two player mode
        */
        Frostbite(std::string imDirectory, const sf::Vector2f &Size);

        /**
        * \brief move function overwridden from motion class, deals with horizontal motion
        *
        * checks for keyboard input and if there is, it will set the direction according to it
        * if no input direction supplied function moves the frosbite in given direction.
        * The speed is determined by deltaTime*FrostbiteSpeed
        * Checks and adjusts for collisions at the end of the board
        * \param direction to move - is ignored if there is additional input from keyboard
        * \param x is board width ????
        * \param y is board height ????
        * \param deltaTime is time passed as is multipled with enemey speed when moving
        */
        virtual void move(char direction, const float &x, const float &y, float moveSpeed) override;

        /**
        * \brief jump function
        *
        * Moves the player up and down by the input vertical speed
        * prevents any double jumping by checking the boolean jumped variable
        * \param direction to move - is up or down
        * \param moveSpeed determines how high/low Frostbite must jump
        * \param x is board width ????
        * \param y is board height ????
        */
        void jump(char direction, float moveSpeed, const float gameHeight, const float gameWidth);

        /**
        * \brief checks if Frostbite has jumped
        *
        * used to prevent double jumping
        * \return boolean private member variable jumped
        */
        const bool hasJumped() const;

        /**
        * \brief Function to get frosbites's width
        *
        * Gets the frostbite-element's size and returns its sixe.x
        * \return frostbite's width
        */
        const float getWidth() const ;

        /**
        * \brief Function to get frosbites's height
        *
        * Gets the frostbite-element's size and returns its sixe.y
        * \return frostbite's height
        */
        const float getHeight() const ;

        /**
        * \brief Function that returns frostbites's speed
        *
        * Returns the private member variable speed, that is set as a const at construction
        *
        * \return frostbite's speed
        */
        const float getSpeed() const;

        /**
        * \brief Function that resets jumped to false
        */
        void reset();

        /**
        * \brief Default Frostbie Destructor
        */
        virtual ~Frostbite();

    protected:

    private:
       // sf::Texture fTexture;
       // sf::Sprite fSprite;
        bool jumped; //to see if the player has jumped, has implicatiins when counting icebergs for score
        const float speed = 400.f;
};

#endif // FROSTBITE_H


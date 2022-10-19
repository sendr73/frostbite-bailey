/**
 * \brief Frostbite Character
 *
 * Uses implementation inheritance to inherite Element's public functions (should ideally change to composition).
 * Uses interface inheritance with move function from class, Motion.
 * Has a set speed
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
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
        * Sets texture to passed in image - useful for two player mode or animations.
        */
        Frostbite(std::string imDirectory, const sf::Vector2f &Size);

        /**
        * \brief move function overwridden from Motion class, deals with horizontal motion
        *
        * Checks for keyboard input and if there is, it will set the direction according to it
        * if no input direction supplied function moves the frosbite in given direction.
        * The speed is determined by deltaTime*speed.
        * Checks and adjusts for collisions at the boundaries of the screen
        * \param direction to move - is ignored if there is additional input from keyboard
        * \param x is the width of the screen
        * \param y is the height of the screen
        * \param deltaTime is time passed as is multipled with speed when moving
        */
        virtual void move(Direction direction, const float &x, const float &y, float moveSpeed) override;

        /**
        * \brief jump function
        *
        * Moves the player up and down by the input vertical speed. This is set as a ratio
        * of height to ensure Frostbite always lines up with interactable elements.
        * Prevents any double jumping by checking the boolean jumped variable.
        * \param direction to move - is up or down
        * \param moveSpeed determines how high/low Frostbite must jump
        * \param x is the width of the screen
        * \param y is the height of the screen
        */
        void jump(Direction direction, float moveSpeed, const float gameHeight, const float gameWidth);

        /**
        * \brief checks if Frostbite has jumped
        *
        * used to prevent double jumping, and also scoring logic with icebergs
        * \return boolean private member variable jumped
        */
        const bool hasJumped() const;

        /**
        * \brief Function to get Frostbites's width
        *
        * Gets the Frostbite-element's size and returns its sixe.x
        * \return Frostbite's width
        */
        const float getWidth() const ;

        /**
        * \brief Function to get Frostbites's height
        *
        * Gets the Frostbite-element's size and returns its sixe.y
        * \return Frostbite's height
        */
        const float getHeight() const ;

        /**
        * \brief Function that returns Frostbites's speed
        *
        * Returns the private member variable speed, that is set as a const at construction
        *
        * \return Frostbite's speed
        */
        const float getSpeed() const;

        /**
        * \brief Function that resets jumped to false
        */
        void reset();

        /**
        * \brief Default Frostbite Destructor
        */
        virtual ~Frostbite();

    protected:

    private:
        bool jumped; //to see if the player has jumped, has implications when counting icebergs for score
        const float speed = 400.f;
};

#endif // FROSTBITE_H


/**
 * \brief Iceberg Element
 * Uses implementation inheritance to inherite Element's public functions (should ideally change to composition).
 * Uses interface inheritance with move function from class, Motion.
 * Has a set speed
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
 */
#ifndef ICEBERG
#define ICEBERG

#include <iostream>
#include <SFML\Graphics.hpp>
#include "motion.h"
#include "element.h"
//
class Iceberg: public Motion, public Element
{
    public:
        /**
        * \brief Default Iceberg constructor
        * Sets texture to iceberg.png, scale to 1:1, direction to right and landed to false
        */
        Iceberg(): Element("resources/iceberg.png",sf::Vector2f(1.f,1.f)),direction{'r'},landed{false}{}

        /**
        * \brief Iceberg constructor with image parameter
        * Sets texture to passed in image - useful for two player mode or landed on graphical changes.
        * \param imDirectory is a string of the directory to the image (texture)
        * \param Size is the scale applied to the texture
        */
        Iceberg(std::string imDirectory, const sf::Vector2f &Size);

        /**
        * \brief move function overwridden from Motion class, deals with horizontal motion
        * No direction is required since Iceberg has it's own direction defined.
        * The speed is determined by deltaTime*speed.
        * \param direction to move - is ignored
        * \param x is the width of the screen
        * \param y is the height of the screen
        * \param deltaTime is time passed and is multipled with speed when moving
        */
        virtual void move(char direction, const float &x, const float &y, float deltaTime) override;

        /**
        * \brief Function to get Iceberg's direction
        * Gets the Iceberg-element's direction
        * \return Iceberg's direction
        */
        const char getDirection() const;

        /**
        * \brief Function to set Iceberg's direction
        * Sets the Iceberg-element's direction, useful for chnaging direction with SPACE
        * \param Iceberg's direction
        */
        void setDirection(const char dir);

        /**
        * \brief Function to get Icebergs's width
        * Gets the Iceberg-element's size and returns its size.x
        * \return Iceberg's height
        */
        const float getWidth() const;

        /**
        * \brief Function to get Icebergs's height
        * Gets the Iceberg-element's size and returns its size.y
        * \return Iceberg's height
        */
        const float getHeight() const;

        /**
        * \brief Function that to chnage properties when landed on
        * When an iceberg is landed on, chnage private boolean landed to true and
        * change the appearance of the iceberg to imDirectory
        * \param imDirectory is a string of the directory to the image (texture)
        */
        void landedOn(std::string imDirectory);

        /**
        * \brief Function to get if Iceberg has been landed on
        * \return private boolean member landed
        */
        bool beenLandedOn();

        /**
        * \brief Function that returns Icebergs's speed
        * Returns the private member variable speed, that is set as a const at construction
        * \return Iceberg's speed
        */
        const float getSpeed();

        /**
        * \brief Function that resets landed to false and restores texture
        * \param imDirectory is a string of the directory to the image (texture)
        */
        void reset(std::string imDirectory);

        /**
        * \brief Default Iceberg Destructor
        */
        virtual ~Iceberg();

    private:
        char direction; //will be 'r' by default, see constructor
        bool landed; //will be false by default
        float speed=150.f;
};

#endif

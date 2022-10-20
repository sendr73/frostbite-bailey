//basic element class, used later for implementation (probably should be changed to be used in compositon)
/**
 * \brief Element Class.
 * Base class with functions that all Sprites will inherit.
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
 */

#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>
#include <iostream>
#include <SFML\Graphics.hpp>

enum class Direction{Up, Down, Left, Right, Null};
class Element
{
    public:
        /**
        * \brief Default Element constructor.
        */
        Element();

        /**
        * \brief Parametized Element constructor.
        * A texture is taken in as a string imDirectory, and scale is taken in. This is then assigned to texture_ member.
        * and then used to create a Sprite, sprite_.
        * \param imDirectory is the directory of the texture
        * \param Size is the scale of the object created.
        */
        Element(std::string imDirectory, const sf::Vector2f &Size);

        /**
        * \brief Gets the x and y coordinate of Element.
        * \return A position Vector2f containing the x and y coordinate
        */
        const sf::Vector2f getPosition() const;

        /**
        * \brief Sets the x and y coordinate of Element.
        * \param x The x coordinate
        * \param y The y coordinate
        */
        void setPosition(float x, float y);

        /**
        * \brief Gets the size of the Element.
        * Since a Sprite has no size, the scale of sprite_ and size of the texture were multiplied
        * to return a unsigned int representative of the size of the Element.
        * \return A Vector2f containing the width and height of sprite_
        */
        const sf::Vector2<unsigned int> getSize() const;

        /**
        * \brief Gets the Boundaries of Element.
        * These boundaries are used to check that objects are colliding. It is not const because some
        * assymetrical textures need to be compensated for (Iceberg).
        * \return A FloatRect containing boundaries of sprite_
        */
        sf::FloatRect getBoundaries() const;

        /**
        * \brief Moves the Element.
        * \param direction The direction that the Element is required to move
        * \param moveSpeed The speed at which the Element is moving
        */
        void moveElement(Direction direction, float moveSpeed);

        /**
        * \brief Sets the texture of the Element.
        * It is required to be public in case the Element needs to chnage appearance
        * \param imDirectory is the directory of the texture
        */
        void setTexture(std::string imDirectory);

        /**
        * \brief Returns the Element Sprite.
        * Used only in presentation
        * \return constant private member sprite_
        */
        const sf::Sprite getObject() const;

        /**
        * \brief Default IceSystem Destructor
        */
        virtual ~Element();

    protected:

    private:
        sf::Sprite sprite_;
        sf::Texture texture_;
};

#endif // ELEMENT_H

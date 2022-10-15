//basic element class, used later for implementation (probably should be changed to be used in compositon)
#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>
#include <iostream>
#include <SFML\Graphics.hpp>

class Element
{
    public:
        Element();
        Element(std::string imDirectory, const sf::Vector2f &Size);
        const sf::Vector2f getPosition() const ;
        void setPosition(float x, float y);         //set position
        const sf::Vector2<unsigned int> getSize() const;
        sf::FloatRect getBoundaries() const;
        void moveElement(char direction, float moveSpeed);
        void setTexture(std::string imDirectory);
        void draw(sf::RenderWindow &window); //overriding the draw function from print class, interface inheritance
        virtual ~Element();
        sf::Sprite sprite_;
        sf::Texture texture_;
    protected:

    private:

};

#endif // ELEMENT_H

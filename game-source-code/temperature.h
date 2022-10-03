#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>

class temperature
{
    public:
        temperature();
        virtual ~temperature();
        void draw(sf::RenderWindow &window);
        void reset_temperature_clock(); //important so that the clock does not tick with splash screen up

    protected:

    private:
        sf::Clock clock;
        int temperature_int = 45; //initial temperature;
        sf::Font font;
        sf::Text temperature_;
};

#endif // TEMPERATURE_H

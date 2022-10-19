/**
 * \brief Temperature Class
 *
 * A class created to initialize the Temperature to 45 and then decrement it every second
 *
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
 */
#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>

class temperature
{
    public:
        /**
         * \brief Temperature Constructor
         * Initializes the clock_, and associated font and text of the timer.
         */
        temperature();

         /**
         * \brief Resets the clock_.
         * Resets the private member variable clock when required
         */
        void resetClock();

         /**
         * \brief Update the Temperature.
         * Checks the time passed, if it is greater than 1 second, decrement the temperature_
         */
        void update();

        /**
        * \brief Function to return the temperature
        * \returns private member variable temperature_int;
        */
        const int getTemperature() const;

        /**
        * \brief Default Temperature Destructor
        */
        virtual ~temperature();
    protected:

    private:
        sf::Clock clock_;
        int temperature_int = 45; //initial temperature;
        sf::Font font_;
        sf::Text temperature_;
};

#endif // TEMPERATURE_H

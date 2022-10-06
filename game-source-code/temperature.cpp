#include "temperature.h"

temperature::temperature() //default constructor
{
    clock.restart(); //start clock
    //load font for the display
    if (!font.loadFromFile("resources/sansation.ttf"))
    {
        std::cout<<"Error Cannot load Font";
    }
    temperature_.setFont(font); //set font, color etc
    temperature_.setCharacterSize(30);
    temperature_.setFillColor(sf::Color::White);
}
void temperature::resetClock()
{
    clock.restart();
    temperature_int = 45;
}
void temperature::draw(sf::RenderWindow &window)
{
    auto time_ellapsed_sec = clock.getElapsedTime().asSeconds(); //get elapsed time as seconds (default is float)
    auto speed_timer = 1.0f; // large it is slower the timer will count
    if(time_ellapsed_sec >= speed_timer ) //compare to set time
    {
        temperature_int--; //decrement the temperature deisplayed on the screen
        clock.restart(); //reset the clock
    }

    std::string myString = std:: to_string(temperature_int);
    temperature_.setString(myString + "°");
    window.draw(temperature_);
}
//getter for temperature
const int temperature::getTemperature() const
{
    return temperature_int;
}

temperature::~temperature()
{
    //dtor
}

#include "temperature.h"
// default constructor
temperature::temperature()
{
    clock_.restart(); // start clock
    // load font for the display
    if (!font_.loadFromFile("resources/sansation.ttf"))
    {
        std::cout<<"Error Cannot load Font";
    }
    temperature_.setFont(font_); // set font, color etc
    temperature_.setCharacterSize(30);
    temperature_.setFillColor(sf::Color::White);
}
// resets the temperature clock
void temperature::resetClock()
{
    clock_.restart();
    temperature_int = 45;
}
// updates temperature
void temperature::update()
{
    auto time_ellapsed_sec = clock_.getElapsedTime().asSeconds(); // get elapsed time as seconds (default is float)
    auto speed_timer = 1.0f; // large it is slower the timer will count
    if(time_ellapsed_sec >= speed_timer ) // compare to set time
    {
        temperature_int--; // decrement the temperature deisplayed on the screen
        clock_.restart(); // reset the clock
    }
}
// getter for temperature
const int temperature::getTemperature() const
{
    return temperature_int;
}
// virtual destructor
temperature::~temperature()
{
    //dtor
}

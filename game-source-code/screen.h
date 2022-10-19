/**
 * \brief Screen Class.
 * This is a class that deals with the presentation layer of the project.
 * Inherits the protected objects in Game and the public function that hides the functionality
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
 */
#ifndef SCREEN
#define SCREEN

#include <vector>
#include <SFML\Graphics.hpp>
#include "game.h"

using namespace std;

class Screen: public Game
{
public:
    /**
    * \brief Default Screen constructor
    */
    Screen(){}

    /**
    * \brief Parametized Screen constructor.
    * Sets texture to of the background Sprite, based on the dimensions of the window.
    * \param window is the RenderWindow on which Screen is displayed
    */
    Screen(sf::RenderWindow &window);

    /**
    * \brief Function that changes what is displayed on the Screen.
    * Calls specific helper functions based on the current stage in the Game.
    */
    void changeDisplay();

    /**
    * \brief Generic function that draws a Message Screen. The input of the title, title colour and message is inputted
    * into the function. The window parameter is passed in so the Message Screen members can be drawn.
    * \param title is a string that is displayed as the Title of the Message Screen
    * \param title_colour is the sf::Color that sets the colour of the Title
    * \param message is a string of the subtext on the Message Screen
    * \param window is the RenderWindow on which Screen is displayed
    */
    void drawMessageScreen(const string &title, const sf::Color &title_colour, const string &message, sf::RenderWindow &window);

    /**
    * \brief Function that refreshes the Screen. This calls the private helper function defined in the Screen Class and the public
    * play function inherited from Game to update and draw the members of the Game class.
    * \param window is the RenderWindow on which Screen is displayed
    * \param deltaTime is a float that passes in a change in time - defining how far each Element moves
    * \param evnt is an sf::Event that is passed in and operated on if required
    * \param pressed is a boolean-type that checks if a button has been pressed (specifically for debouncing jumping)
    */
    bool refresh(sf::RenderWindow &window, float &deltaTime, sf::Clock &clock, sf::Event &evnt, bool &jump_pressed, bool &rev_pressed);

    /**
    * \brief Default Iceberg Destructor
    */
    virtual ~Screen();

protected:
    sf::RenderTexture texture; //texture object
    sf::Sprite background; //sprite object for background
    sf::Font font;
    sf::Text score_text;
    void setBackground(const sf::RenderWindow &window); //sets background on screen
    void drawIgloo(sf::RenderWindow &window); //helper that draws igloo
    void drawScore(sf::RenderWindow &window); //helper that draws score
};

#endif

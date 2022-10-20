#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace std;

class FontNotLoaded{};

/**
 * \brief Splash Screen Class for Initial Instructions
 *
 * A class created for presentation alone
 * It draws the instructions for the game
 * Used as a helper Class for Screen
 *
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
 */
class splashScreen
{
    public:
         /** \brief  Default Constructor
         */
        splashScreen();
         /** \brief  Constructor with input game screen parameters
         *
         * Will initalize the splash screen message by initialzing the private member variables
         * header and paragraph and set their positions
         *
         * \param gameWidth used to set position of the message
         * \param gameHeight used to set position of the message
         */
        splashScreen(const float gameWidth, const float gameHeight);

        /** \brief Draw funcition to print out the splash screen on the window
         *
         * \param window passed by reference, on which the message is displayed
         */
        void draw(sf::RenderWindow &window);

        /** \brief  Default Destructor
         */
        virtual ~splashScreen();


    protected:

    private:
    sf::Text header;
    sf::Font font;
    sf::Text paragraph;
};

#endif // SPLASHSCREEN_H

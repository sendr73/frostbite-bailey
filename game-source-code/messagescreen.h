/**
 * \brief Message Screen Class
 *
 * A class created for presentation alone
 * It draws the inputted message
 * Used as a helper Class for Screen
 *
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
 */

#ifndef MESSAGESCREEN_H
#define MESSAGESCREEN_H

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
using namespace std;
class MessageScreen
{
    public:
        /** \brief  Default Constructor
         * No initialization needed
         */
        MessageScreen();

        /** \brief Function to draw a message on Screen
         *
         * \param title is the text required for the title
         * \param title_colour sets the title colour
         * \param message is the required text for the paragraph
         * \param window is passed by reference to allow for drawing
         *
         */
        void drawMessageScreen(const string &title, const sf::Color &title_colour, const string &message, sf::RenderWindow &window);

        /** \brief  Default Destructor
         */
        virtual ~MessageScreen();

    protected:

    private:
        sf::Text title_text;
        sf::Text message_text;
};

#endif // MESSAGESCREEN_H

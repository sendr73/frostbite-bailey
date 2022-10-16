#ifndef SCREEN
#define SCREEN

#include <vector>
#include <SFML\Graphics.hpp>
#include "game.h"

using namespace std;

class Screen: public Game
{
public:
    Screen(){}
    //parametized constructor
    Screen(sf::RenderWindow &window);
    void drawMessageScreen(const string &title, const sf::Color &title_colour, const string &message, sf::RenderWindow &window);
    //refreshes the window
    void refresh(sf::RenderWindow &window);
    //destructor
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

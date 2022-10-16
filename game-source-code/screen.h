#ifndef SCREEN
#define SCREEN

#include <vector>
#include <SFML\Graphics.hpp>

using namespace std;

class Screen
{
public:
    Screen(){
        //default
    }
    //parametized constructor
    Screen(sf::RenderWindow &window);
    //getter and setter for stage
    const int getStage() const;
    void setStage(const int &i);
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
    int stage;
    void setBackground(const sf::RenderWindow &window); //sets background on screen
    void drawIgloo(sf::RenderWindow &window); //helper that draws igloo
    void drawScore(sf::RenderWindow &window); //helper that draws score
};

#endif

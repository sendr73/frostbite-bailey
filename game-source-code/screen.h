#ifndef SCREEN
#define SCREEN

#include <iostream>
#include <vector>
#include <SFML\Graphics.hpp>
#include "icesystem.h"
#include "frostbite.h"
#include "score.h"
#include "igloo.h"
#include "temperature.h"
#include "EnemyMatrix.h"

using namespace std;

class Screen
{
public:
    Screen(){
        //default
    }
    //parametized constructor
    Screen(sf::RenderWindow &window);
    //making the frostbite object jump on window, based on events

    void frostbiteJump(const sf::RenderWindow &window, const sf::Event &event, bool &pressed);
    //function to use overwritten move function
    void moveAllSprites(sf::RenderWindow& window,const float& frostbiteSpeed,const float& deltaTime);
    //function to move any class inherited from motion
    void moveSprite(Motion& spriteA, char direction, sf::RenderWindow &window, const float &moveSpeed) const;
    //moving the frostbite object on window
    void moveFrostbite(const sf::RenderWindow &window, const float &speed, const float &deltaTime);
    //moving the rows of ice on screen
    void icebergCollision(sf::RenderWindow &window, const float &);
    //collsion logic between frostbite and enemies
    void enemyCollision(sf::RenderWindow &window,const float &);
    //check for negative temperature
    void checkTemperature();
    //getter and setter for stage
    const int getStage() const;
    void setStage(const int &i);
    const bool hasLives() const;
    void nextLevel(const sf::RenderWindow &window);
    void drawMessageScreen(const string &title, const sf::Color &title_colour, const string &message, sf::RenderWindow &window);
    void initialise(sf::RenderWindow &window, const bool &resetScore);
    //refreshes the window
    void refresh(sf::RenderWindow &window);
    //destructor
    virtual ~Screen();

protected:
    sf::RenderTexture texture; //texture object
    sf::Sprite background; //sprite object for background
    sf::Font font;
    sf::Text score_text;
    temperature temperature_timer;
    Frostbite frostbite=Frostbite("resources/frostbite.png",sf::Vector2f(1.f,1.f)); //frostbite object
    Score score;
    Igloo igloo;
    IceSystem ice_system;
    EnemyMatrix enemy_matrix;
    int stage;
    void setBackground(const sf::RenderWindow &window); //sets background on screen
    void setFrostbite(const sf::RenderWindow &window); //sets frostbite properties on screen
    void setIgloo(const sf::RenderWindow &window); //set igloo
    bool isOnIceberg(const Iceberg &iceberg); //helper that returns if frostbite is on an iceberg
    void drawIgloo(sf::RenderWindow &window); //helper that draws igloo
    void drawScore(sf::RenderWindow &window); //helper that draws score
    const bool isWithinDoorway() const;
};

#endif

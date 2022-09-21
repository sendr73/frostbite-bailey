#ifndef SCREEN
#define SCREEN

#include <iostream>
#include <vector>
#include <SFML\Graphics.hpp>
#include "iceberg.h"
#include "frostbite.h"

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
    //moving the frostbite object on window
    void moveFrostbite(const sf::RenderWindow &window, const float &speed, const float &deltaTime);
    //moving the rows of ice on screen
    void moveIcerow(sf::RenderWindow &window, const float &speed, const float &deltaTime);
    //collsion logic between frostbite and icebergs
    void icebergCollision(sf::RenderWindow &window,const float &, const float &);
    //refreshes the window
    void refresh(sf::RenderWindow &window);
    //destructor
    virtual ~Screen();

protected:
    sf::RenderTexture texture; //texture object
    sf::Sprite background; //sprite object for background
    Frostbite frostbite=Frostbite("frostbite.png",sf::Vector2f(1.f,1.f)); //frostbite object
    Iceberg iceberg=Iceberg("iceberg.png",sf::Vector2f(1.f,1.f)); //iceberg object
    float row=4; //amount of rows (default of 4)
    float column=4; //amount of columns (default of 3 + overlap)
    vector<vector<Iceberg>> icerow; //2D vector of icebergs (could segregate into classes)
    void setBackground(const sf::RenderWindow &window); //sets background on screen
    void setFrostbite(const sf::RenderWindow &window); //sets frostbite properties on screen
    void setIcebergRows(const sf::RenderWindow &window); //sets iceberg properties on screen
    bool isOnIceberg(const Iceberg &iceberg); //helper that returns if frostbite is on an iceberg
};

#endif

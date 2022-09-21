//Screen implementation
#include "screen.h"

using namespace std;

Screen::Screen(sf::RenderWindow &window)
{
    setBackground(window);
    setFrostbite(window);
    setIcebergRows(window);
}
//sets texture of background based on dimensions of the window
void Screen::setBackground(const sf::RenderWindow &window) //All take in the window as parameters, maybe change to height and width?
{

    sf::RectangleShape sky(sf::Vector2f(window.getSize().x,0.2*window.getSize().y));
    sky.setFillColor(sf::Color(78,119,195,255)); //Values taken from screenshot, maybe give them aliases?
    sky.setPosition(0.f,0.2*window.getSize().y);
    sf::RectangleShape border(sf::Vector2f(window.getSize().x,0.01*window.getSize().y));
    border.setFillColor(sf::Color(204,117,190,255));
    border.setPosition(0.f,0.19*window.getSize().y);
    sf::RectangleShape safezone(sf::Vector2f(window.getSize().x,0.19*window.getSize().y));
    safezone.setFillColor(sf::Color(156,156,156,255));
    if (!texture.create(window.getSize().x,0.4*window.getSize().y))
    {
        //issue returning error from void, maybe try{catch}?
    }
    texture.clear(); //draw textures
    texture.draw(safezone);
    texture.draw(border);
    texture.draw(sky);
    background.setTexture(texture.getTexture()); //set texture of background
}
//sets the starting position of Frostbite
void Screen::setFrostbite(const sf::RenderWindow &window)
{
    frostbite.setPostion(window.getSize().x/2,0.375*window.getSize().y); //maybe setting an origin is more optimal for resetting
}
//sets the positions and directions of icebergs in specific rows
void Screen::setIcebergRows(const sf::RenderWindow &window)
{
    icerow=vector<vector<icebergSandbox>>(row,vector<icebergSandbox>(column,iceberg)); //initializes 2D
    for(int i = 0; i < icerow.size(); i++) //loops through rows
    {
        for(int j = 0; j<icerow[i].size(); j++) //loops through columns
        {
            if(i%2==0)
            {
                icerow[i][j].setPosition(-(j)*(20+iceberg.getWidth()) //this loop creates distance between objects
                                         ,(i+1)*(0.125*window.getSize().y)+(frostbite.getPosition().y));
            }
            else
            {
                icerow[i][j].setDirection('l'); //additionally needs to make rows travel in the opposite direction if odd row
                icerow[i][j].setPosition((window.getSize().x)+(j)*(20+iceberg.getWidth())
                                         ,(i+1)*(0.125*window.getSize().y)+(frostbite.getPosition().y));
            }
        }
        icerow[i][icerow.size()-1].setPosition(-iceberg.getWidth()/2,iceberg.getPosition().y); //sets the last icerberg as "overlap"
    }
}
//executes the up/down movement when as specific event is initiated
void Screen::frostbiteJump(const sf::RenderWindow &window, const sf::Event &event, bool &pressed)
{
    if ((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Up)&&(pressed == false))
    {
        pressed = true; //while true, cannot be double clicked
        frostbite.move('u',0.125*window.getSize().y,window.getSize().y,window.getSize().x);
    }
    if ((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::Up))
    {
        pressed = false;
    }
    if ((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Down)&&(pressed == false))
    {
        pressed = true; //while true, cannot be double clicked
        frostbite.move('d',0.125*window.getSize().y,window.getSize().y,window.getSize().x);
    }
    if ((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::Down))
    {
        pressed = false;
    }
}
//moves Frostbite based on keyboard input, based on the refresh rate (deltaTime)
void Screen::moveFrostbite(const sf::RenderWindow &window, const float &frostbiteSpeed, const float &deltaTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        frostbite.move('l',frostbiteSpeed*deltaTime,window.getSize().y,window.getSize().x);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        frostbite.move('r',frostbiteSpeed*deltaTime,window.getSize().y,window.getSize().x);
    }
}

Screen::~Screen()
{
    //dtor
}

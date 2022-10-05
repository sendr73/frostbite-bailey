//Screen implementation
#include "screen.h"

using namespace std;

Screen::Screen(sf::RenderWindow &window)
{
    setBackground(window);
    setFrostbite(window);
    setIcebergRows(window);
    setEnemyRows(window);
    setIgloo(window);
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
    icerow=vector<vector<Iceberg>>(row,vector<Iceberg>(column,iceberg)); //initializes 2D
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
void Screen::setEnemyRows(const sf::RenderWindow &window)
{
    enemyrow=vector<Enemies>(4,enemy_); //initializes 1D
    cout<<"Enemy width "<<enemy_.getWidth();
    for(int j = 0; j<enemyrow.size(); j++) //loops through columns
    {
        enemyrow[j].setPosition((20)+2*(j)*enemy_.getWidth()
                                ,(0.3*window.getSize().y)+(frostbite.getPosition().y));
    }
    // enemyrow[enemyrow.size()-1].setPosition(-enemy_.getWidth()/2,enemy_.getPosition().y); //sets the last icerberg as "overlap"
}
//sets the positions of the blocks in the iceberg
void Screen::setIgloo(const sf::RenderWindow &window)
{
    igloo.generateBlocks(window.getSize().x,window.getSize().y);
}

//executes the up/down movement when as specific event is initiated
void Screen::frostbiteJump(const sf::RenderWindow &window, const sf::Event &event, bool &pressed)
{
    if ((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Up)&&(pressed == false))
    {
        pressed = true; //while true, cannot be double clicked
        frostbite.jump('u',0.125*window.getSize().y,window.getSize().y,window.getSize().x);
    }
    if ((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::Up))
    {
        pressed = false;
    }
    if ((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Down)&&(pressed == false))
    {
        pressed = true; //while true, cannot be double clicked
        frostbite.jump('d',0.125*window.getSize().y,window.getSize().y,window.getSize().x);
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

void Screen::moveIcerow(sf::RenderWindow &window, const float &icebergSpeed, const float &deltaTime)
{
    for(int i = 0; i<icerow.size(); i++)
    {
        for(int j = 0; j<icerow[i].size()-1; j++)
        {
            icerow[i][j].move(icebergSpeed*deltaTime,window.getSize().y,window.getSize().x,icerow[i][icerow[i].size()-1]);
        }
    }
}
void Screen::moveEnemyRow(sf::RenderWindow &window, const float &enemySpeed, const float &deltaTime)
{
    for(int i = 0; i<enemyrow.size(); i++)
    {
        enemyrow[i].move(enemySpeed*deltaTime,window.getSize().y,window.getSize().x,enemyrow[i]);
    }
}

bool Screen::isOnIceberg(const Iceberg &iceberg)
{
    if((frostbite.getPosition().x-frostbite.getWidth()/2>iceberg.getPosition().x-iceberg.getWidth()/2)
            &&(frostbite.getPosition().x+frostbite.getWidth()/2<iceberg.getPosition().x+iceberg.getWidth()/2)
            &&((frostbite.getPosition().y>iceberg.getPosition().y-iceberg.getHeight()/2)
               &&(frostbite.getPosition().y<iceberg.getPosition().y+iceberg.getHeight()/2)))
    {
        return true;
    }
    return false;
}

bool Screen::enemyClash(const Enemies &enemy)
{
    if((frostbite.getPosition().x-frostbite.getWidth()/2>enemy.getPosition().x-enemy.getWidth()/2)
            &&(frostbite.getPosition().x+frostbite.getWidth()/2<enemy.getPosition().x+enemy.getWidth()/2)
            &&((frostbite.getPosition().y>enemy.getPosition().y-enemy.getHeight()/2)
               &&(frostbite.getPosition().y<enemy.getPosition().y+enemy.getHeight()/2)))
    {
        return true;
    }
    return false;
}

void Screen::icebergCollision(sf::RenderWindow &window,const float &icebergSpeed, const float &deltaTime)
{
    bool landed = false;
    for(int i = 0; i<icerow.size(); i++)
    {
        for(int j = 0; j<icerow[i].size(); j++)
        {
            if(isOnIceberg(icerow[i][j]))
            {
                frostbite.move(icerow[i][j].getDirection(),icebergSpeed*deltaTime,window.getSize().y,window.getSize().x);
                landed = true;
                if(!icerow[i][j].beenLandedOn())
                {
                    for (int k = 0; k<icerow[i].size(); k++)
                    {
                        icerow[i][k].landedOn("resources/iceberg_landed.png");
                    }
                    score.increaseScore();
                }
                igloo.incrementBlockAmount();
                break;
            }
            else if(frostbite.getPosition().y>0.45*window.getSize().y&&j==icerow[i].size()-1&&i==icerow.size()-1)
            {
                frostbite.setPostion(window.getSize().x/2,0.375*window.getSize().y);
            }
        }
        if(landed)
        {
            landed = false;
            break;
        }
    }
}
/*
void Screen::enemyCollision(sf::RenderWindow &window,const float &, const float &)
{
    for(int i =0; i<enemyrow.size(); i++)
    {
        sf::FloatRect frosbite_boundary_box = frosbite.
    }
}
*/

void Screen::drawScore(sf::RenderWindow &window)
{
    if (!font.loadFromFile("resources/sansation.ttf"))
    {
        std::cout<<"Error Cannot load Font";
    }
    score_text.setFont(font); //set font, color etc
    score_text.setCharacterSize(30);
    score_text.setFillColor(sf::Color::White);
    string s = "Level: "+to_string(score.getLevel())+'\t'+"Score: "+to_string(score.getScore())+'\t'+"Lives: "+to_string(score.getLives());
    score_text.setString(s);
    sf::FloatRect score_textbox = score_text.getLocalBounds();
    score_text.setPosition(sf::Vector2f(5.f,30.f));
    window.draw(score_text);
}

void Screen::drawIgloo(sf::RenderWindow &window)
{
    int blockNum = igloo.getBlockAmount();
    for (int i = 0; i < blockNum; i++)
    {
        window.draw(igloo.getBlock(i));
    }
}

void Screen::refresh(sf::RenderWindow &window)
{
    window.clear(sf::Color(38,79,155));
    window.draw(background);
    drawScore(window);
    drawIgloo(window);
    for(int i = 0; i<icerow.size(); i++)
    {
        for(int j = 0; j < icerow[i].size(); j++)
        {
            icerow[i][j].draw(window);
        }
    }
    for(int i = 0; i < enemyrow.size(); i++)
    {
        enemyrow[i].draw(window);
    }
    temperature_timer.draw(window);
    frostbite.draw(window);
}

void Screen::checkTemperature()
{
    if(temperature_timer.getTemperature()<0) //if he has frozen
    {
        temperature_timer.resetClock(); //reset temperature
        score.decreaseLives(); //decrease his lives
    }
}

Screen::~Screen()
{
    //dtor
}

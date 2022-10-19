//Screen implementation
#include "screen.h"

using namespace std;

Screen::Screen(sf::RenderWindow &window): splash_screen(window.getSize().x, window.getSize().y)
{
    setBackground(window);
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
void Screen::drawSplashScreen(sf::RenderWindow& window)
{
    splash_screen.draw(window);
}
void Screen::changeDisplay()
{
    if(getStage()==4){nextLevel();}
    else if(getStage()==5){initialize(false);}
    else{initialize(true);}
}
//getter for game stage
const int Screen::getStage() const
{
    return stage;
}
void Screen::setStage(const int &i)
{
    stage = i;
}
//drawing functions
void Screen::drawMessageScreen(const string &title, const sf::Color &title_colour, const string &message, sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);
    message_screen_.drawMessageScreen(title, title_colour, message, window);
}
// draws score
void Screen::drawScore(sf::RenderWindow &window)
{
    string s = "Level: "+to_string(score.getLevel())+'\t'+"Score: "+to_string(score.getScore())+'\t'+"Lives: "+to_string(score.getLives());
    score_text = setTextparam(s, 30, sf::Color::White);
    sf::FloatRect score_textbox = score_text.getLocalBounds();
    score_text.setPosition(sf::Vector2f(5.f,30.f));
    window.draw(score_text);
}
sf::Text Screen::setTextparam(string text, int char_size, sf::Color colour)
{
    sf::Text text_;
    if (!font.loadFromFile("resources/sansation.ttf"))
    {
        std::cout<<"Error Cannot load Font";
    }
    text_.setFont(font); //set font, color etc
    text_.setCharacterSize(char_size);
    text_.setFillColor(colour);
    text_.setString(text);
    return text_;
}

// draws igloo
void Screen::drawIgloo(sf::RenderWindow &window)
{
    int blockNum = igloo.getBlockAmount();
    for (int i = 0; i < blockNum; i++)
    {
        window.draw(igloo.getBlock(i));
    }
}


void Screen::drawEnemySystem(sf::RenderWindow &window)
{
   for(auto i =0; i<enemy_matrix[0].getSize(); i++)
   {
       window.draw(enemy_matrix[0][i].getObject());
       window.draw(enemy_matrix[1][i].getObject());
   }
}

void Screen::drawIcebergSystem(sf::RenderWindow &window)
{
   for(auto i =0; i<ice_system.size(); i++)
   {
        drawIcebergRow(window, ice_system[i]);
   }
}

void Screen::drawIcebergRow(sf::RenderWindow &window, Icerow ice_row)
{
   for(auto i =0; i<ice_row.size(); i++)
   {
       window.draw(ice_row[i].getObject());
       window.draw(ice_row[i].getObject());
   }
}


bool Screen::refresh(sf::RenderWindow &window, float &deltaTime, sf::Event &evnt, bool &pressed)
{
    checkTemperature();
    if(!hasLives())
    {stage = 3;}
    move(deltaTime);
    pressed = frostbiteJump(evnt,pressed);
    icebergCollision(deltaTime);
    enemyCollision(deltaTime); //check for collision with crabs
    window.clear(sf::Color(38,79,155));
    window.draw(background);
    drawScore(window);
    drawIgloo(window);
    drawEnemySystem(window);
    drawIcebergSystem(window);
    temperature_timer.draw(window);
    window.draw(frostbite.getObject());
    return pressed;
}

Screen::~Screen()
{
    //dtor
}

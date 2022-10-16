//Screen implementation
#include "screen.h"

using namespace std;

Screen::Screen(sf::RenderWindow &window)
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
    sf::Font font;
    if (!font.loadFromFile("resources/sansation.ttf"))
    {
        std::cout<<"Error Cannot load Font";
    }
    window.clear(sf::Color::Black);
    sf::Text title_text, message_text;
    title_text.setFont(font); //set font, color etc
    title_text.setString(title);
    title_text.setCharacterSize(90);
    title_text.setFillColor(title_colour);
    title_text.setStyle(sf::Text::Bold|sf::Text::Underlined);
    sf::FloatRect text_rectangle = title_text.getLocalBounds();
    title_text.setOrigin(text_rectangle.left + text_rectangle.width/2.0f,
                         text_rectangle.top  + text_rectangle.height/2.0f);
    title_text.setPosition(sf::Vector2f(window.getSize().x/2.0f,window.getSize().y/4.0f));
    message_text.setString(message);
    message_text.setFont(font); //set font, color etc
    message_text.setCharacterSize(30);
    message_text.setFillColor(sf::Color::White);
    text_rectangle = message_text.getLocalBounds();
    message_text.setOrigin(text_rectangle.left + text_rectangle.width/2.0f,
                           text_rectangle.top  + text_rectangle.height/2.0f);
    message_text.setPosition(sf::Vector2f(window.getSize().x/2.0f,window.getSize().y/2.0f));
    window.draw(title_text);
    window.draw(message_text);
}
// draws score
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
// draws igloo
void Screen::drawIgloo(sf::RenderWindow &window)
{
    int blockNum = igloo.getBlockAmount();
    for (int i = 0; i < blockNum; i++)
    {
        window.draw(igloo.getBlock(i));
    }
}

bool Screen::refresh(sf::RenderWindow &window, float &deltaTime, sf::Event &evnt, bool &pressed)
{
    move(deltaTime);
    pressed = frostbiteJump(evnt,pressed);
    icebergCollision(deltaTime);
    enemyCollision(deltaTime); //check for collision with crabs
    window.clear(sf::Color(38,79,155));
    window.draw(background);
    drawScore(window);
    drawIgloo(window);
    enemy_matrix.draw(window);
    ice_system.draw(window);
    temperature_timer.draw(window);
    frostbite.draw(window);
    return pressed;
}

Screen::~Screen()
{
    //dtor
}

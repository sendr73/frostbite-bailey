#include "splashscreen.h"


splashScreen::splashScreen(const float gameWidth, const float gameHeight)
{
    if (!font.loadFromFile("resources/sansation.ttf"))
    {
        throw FontNotLoaded{};
    }
    header.setFont(font); //set font, color etc
    header.setString("Frostbite Bailey");
    header.setCharacterSize(60);
    header.setFillColor(sf::Color::Blue);
    header.setStyle(sf::Text::Bold|sf::Text::Underlined);
    sf::FloatRect text_rectangle = header.getLocalBounds();
    //set positon of header
    header.setOrigin(text_rectangle.left + text_rectangle.width/2.0f,
                     text_rectangle.top  + text_rectangle.height/2.0f);
    header.setPosition(sf::Vector2f(gameWidth/2.0f,gameHeight/4.0f));


    paragraph.setString("Use the LEFT and RIGHT arrow keys to move Frostbite left and right \n"
                        "and the UP and DOWN arrow keys to jump platforms, up and down. \n"
                        "Try to land on the moving icebergs to build the igloo. Beware of the\n"
                        "crabs and clams and do not fall in the water, as you will loose a \n"
                        "life. If the temperature decreases below zero you will freeze and \n"
                        "lose a life. To win build and enter the igloo before your lives run out\n\n"
                        "Press the ENTER key to start.");
    paragraph.setFont(font); //set font, color etc
    paragraph.setCharacterSize(30);
    paragraph.setFillColor(sf::Color::White);
    text_rectangle = paragraph.getLocalBounds();
    //set positon of paragraph
    paragraph.setOrigin(text_rectangle.left + text_rectangle.width/2.0f,
                        text_rectangle.top  + text_rectangle.height/2.0f);
    paragraph.setPosition(sf::Vector2f(gameWidth/2.0f,gameHeight/2.0f));
}

void splashScreen::draw(sf::RenderWindow &window)
{
    window.draw(header);
    window.draw(paragraph);
}

splashScreen::~splashScreen()
{
    //dtor
}


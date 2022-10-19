#include "messagescreen.h"

MessageScreen::MessageScreen()
{
    //ctor
}

void MessageScreen::drawMessageScreen(const string &title, const sf::Color &title_colour, const string &message, sf::RenderWindow &window)
{
    sf::Font font;
    if (!font.loadFromFile("resources/sansation.ttf"))
    {
        std::cout<<"Error Cannot load Font";
    }
    window.clear(sf::Color::Black);
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

MessageScreen::~MessageScreen()
{
    //dtor
}

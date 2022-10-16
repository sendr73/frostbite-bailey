#include "game.h"

Game::Game(const float &width,const float &height)
{
    GAME_WIDTH=width;
    GAME_HEIGHT=height;
    setFrostbite();
    setIgloo();
}

//sets the starting position of Frostbite
void Game::setFrostbite()
{
    frostbite.setPosition(GAME_WIDTH/2,0.375*GAME_HEIGHT); //maybe setting an origin is more optimal for resetting
}
//executes the up/down movement when as specific event is initiated
void Game::frostbiteJump(const sf::Event &event, bool &pressed)
{
    if ((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Up)&&(pressed == false))
    {
        pressed = true; //while true, cannot be double clicked
        if(cannotEnter())
        {
            //do nothing
        }
        else if(canEnter())
        {
            //stage=4;
        }
        else
        {
            frostbite.jump('u',0.125*GAME_HEIGHT,GAME_HEIGHT,GAME_WIDTH);
        }
    }
    if ((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::Up))
    {
        pressed = false;
    }
    if ((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Down)&&(pressed == false))
    {
        pressed = true; //while true, cannot be double clicked
        frostbite.jump('d',0.125*GAME_HEIGHT,GAME_HEIGHT,GAME_WIDTH);
    }
    if ((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::Down))
    {
        pressed = false;
    }
}

void Game::move(const float& deltaTime)
{
    move(frostbite, 'Q', deltaTime);
    move(enemy_matrix, 'Q', deltaTime); //set random direction
    move(ice_system, 'Q', deltaTime);
}

//helper to move Sprites
void Game::move(Motion& spriteA, char direction, const float &moveSpeed) const
{
    sf::RenderWindow window(sf::VideoMode(GAME_WIDTH,GAME_HEIGHT),"");
    spriteA.move(direction, window, moveSpeed);
}

//sets the positions of the blocks in the iceberg
void Game::setIgloo()
{
    igloo.generateBlocks(GAME_WIDTH,GAME_HEIGHT);
}

const bool Game::isWithinDoorway() const
{
    const float x = igloo.getBlockPosition(16).x;
    const float width = igloo.getBlockSize(16).x;
    if((frostbite.getPosition().x<x+width)
            &&(frostbite.getPosition().x>x-width))
    {
        return true;
    }
    return false;
}

const bool Game::cannotEnter() const
{
    if((!igloo.isComplete()&&frostbite.getPosition().y<=0.375*GAME_HEIGHT)
        ||frostbite.getPosition().y<=0.25*GAME_HEIGHT
        ||(frostbite.getPosition().y==0.375*GAME_HEIGHT&&!isWithinDoorway()))
        {
            return true;
        }
        return false;
}
const bool Game::canEnter() const
{
    if(igloo.isComplete()&&frostbite.getPosition().y<=0.375*GAME_HEIGHT&&isWithinDoorway())
    {
        return true;
    }
    return false;
}

Game::~Game()
{
    //dtor
}

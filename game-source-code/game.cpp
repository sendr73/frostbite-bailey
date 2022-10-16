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

void Game::move(const float& frostbiteSpeed,const float& deltaTime)
{
    moveSprite(frostbite, 'Q', window, frostbiteSpeed);
    moveSprite(enemy_matrix, 'Q', window, deltaTime); //set random direction
    moveSprite(ice_system, 'Q', window, deltaTime);
}

//helper to move Sprites
void Game::move(Motion& spriteA, char direction, const float &moveSpeed) const
{
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

Game::~Game()
{
    //dtor
}

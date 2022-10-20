#include "game.h"
// constructor that assigns width, height to private members and sets stage to be 1
Game::Game(const float &width,const float &height)
{
    if(width>1600.f)
    {
        throw InvalidWidth{};
    }
    else if(height>800.f)
    {
        throw InvalidHeight{};
    }
    else
    {
        GAME_WIDTH=width;
        GAME_HEIGHT=height;
    }
    stage = 1;
}
// plays the game
void Game::play(float &deltaTime,sf::Event &evnt, bool &jump_pressed, bool &rev_pressed)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&stage==2&&!rev_pressed)
    {
        rev_pressed=true;
        reverseIceberg();
    }
    else if((evnt.type == sf::Event::KeyReleased)&&(evnt.key.code == sf::Keyboard::Space))
    {
        rev_pressed=false;
    }
    checkTemperature();
    if(!hasLives())
    {stage = 3;}
    move(deltaTime);
    frostbiteJump(evnt,jump_pressed);
    icebergCollision(deltaTime);
    enemyCollision(deltaTime); //check for collision with crabs
}
//getter for game stage
const int Game::getStage() const
{
    return stage;
}
void Game::setStage(const int &i)
{
    stage = i;
}
// sets the starting position of Frostbite
void Game::setFrostbite()
{
    frostbite.setPosition(GAME_WIDTH/2,0.375*GAME_HEIGHT); //maybe setting an origin is more optimal for resetting
}
// executes the up/down movement when as specific event is initiated
bool Game::frostbiteJump(const sf::Event &event, bool &pressed)
{
    if ((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Up)&&(pressed == false))
    {
        pressed = true; //while true, cannot be double clicked
        if(cannotEnter()){} // do nothing
        else if(canEnter())
        {stage=4;} // frostbite wins the game
        else
        {frostbite.jump(Direction::Up,0.125*GAME_HEIGHT,GAME_HEIGHT,GAME_WIDTH);}
    }
    if ((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::Up))
    {
        pressed = false; // key is no longer pressed
    }
    if ((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Down)&&(pressed == false))
    {
        pressed = true; //while true, cannot be double clicked
        frostbite.jump(Direction::Down,0.125*GAME_HEIGHT,GAME_HEIGHT,GAME_WIDTH);
    }
    if ((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::Down))
    {
        pressed = false; // key is no longer pressed
    }
    return pressed;
}
// moves all movable members in Game
void Game::move(const float& deltaTime)
{
    move(frostbite, Direction::Null, frostbite.getSpeed()*deltaTime);
    move(enemy_matrix, Direction::Null, deltaTime); //set random direction
    move(ice_system, Direction::Null, deltaTime);
}
// helper to move Sprites
void Game::move(Motion& spriteA, Direction direction, const float &moveSpeed) const
{
    spriteA.move(direction, GAME_WIDTH,GAME_HEIGHT, moveSpeed);
}
// sets the positions of the blocks in the iceberg
void Game::setIgloo()
{
    igloo.generateBlocks(GAME_WIDTH,GAME_HEIGHT);
}
// iceberg collisions
void Game::icebergCollision(const float &deltaTime)
{
    if(frostbite.getPosition().y>0.45*GAME_HEIGHT)
    {
        switch(ice_system.collision(frostbite,GAME_WIDTH,GAME_HEIGHT,deltaTime))
        {
        case -1:
            respawn(); // this means that Frostbite is not on the safezone and is not on an iceberg
            break;
        case 1:
            if(!ice_system[0][0].beenLandedOn()&&frostbite.hasJumped()){landing(0);}
            break;
        case 2:
            if(!ice_system[1][0].beenLandedOn()&&frostbite.hasJumped()){landing(1);}
            break;
        case 3:
            if(!ice_system[2][0].beenLandedOn()&&frostbite.hasJumped()){landing(2);}
            break;
        case 4:
            if(!ice_system[3][0].beenLandedOn()&&frostbite.hasJumped()){landing(3);}
            break;
        default:
            break;
        }
    }
}
// enemy collisions
void Game::enemyCollision(const float &deltaTime)
{
   auto i = enemy_matrix.collision(frostbite, GAME_WIDTH,GAME_HEIGHT, deltaTime);
   if(i == 1)
   {
       score.decreaseLives();
   }
}
// initialises game to play
void Game::initialize(const bool &resetScore)
{
    stage = 2;
    ice_system.reset();
    if(resetScore){score.reset();}
    setFrostbite();
    setIgloo();
    temperature_timer.resetClock();
}
// frostbite respawns
void Game::respawn()
{
    frostbite.reset();
    frostbite.setPosition(GAME_WIDTH/2,0.375*GAME_HEIGHT);
    score.decreaseLives();
}
// make frostbite land
void Game::landing(const int &i)
{
    ice_system.rowLandedOn(i);
    score.increaseScore();
    igloo.incrementBlockAmount(false);
    frostbite.reset();
    if(igloo.getBlockAmount()%4==0&!igloo.isComplete())
    {
        ice_system.reset();
    }
}
// reverses iceberg direction
void Game::reverseIceberg()
{
    auto row = ice_system.collision(frostbite,GAME_WIDTH,GAME_HEIGHT,0);
    if(row!=-1)
    {
        ice_system.reverse(row-1);
        igloo.incrementBlockAmount(true);
        ice_system.reset();
    }
}
// checks if has lives
const bool Game::hasLives() const
{
    if(score.getLives()==0)
    {return false;}
    return true;
}
// enters a new level
void Game::nextLevel()
{
    stage = 2;
    frostbite.setPosition(GAME_WIDTH/2,0.375*GAME_HEIGHT);
    score.increaseLevel();
    temperature_timer.resetClock();
    frostbite.reset();
    ice_system.reset();
    igloo.reset();
}
// checks temperature of the timer
void Game::checkTemperature()
{
    temperature_timer.update();
    if(temperature_timer.getTemperature()<=0) //if he has frozen
    {
        temperature_timer.resetClock(); //reset temperature
        score.decreaseLives(); //decrease his lives
        if(score.getLives()==0)
        {stage = 3;}
        else
        {stage = 5;}
    }
}
// checks in line with enterence
const bool Game::isWithinDoorway() const
{
    const float x = igloo.getBlockPosition(16).x;
    const float width = igloo.getBlockSize(16).x;
    if((frostbite.getPosition().x<x+width)
            &&(frostbite.getPosition().x>x-width))
    {return true;}
    return false;
}
// checks if Frostbite cannot enter igloo
const bool Game::cannotEnter() const
{
    if((!igloo.isComplete()&&frostbite.getPosition().y<=0.375*GAME_HEIGHT)
        ||frostbite.getPosition().y<=0.25*GAME_HEIGHT
        ||(frostbite.getPosition().y==0.375*GAME_HEIGHT&&!isWithinDoorway()))
        {return true;}
        return false;
}
// checks if frostbite can enter igloo
const bool Game::canEnter() const
{
    if(igloo.isComplete()&&frostbite.getPosition().y<=0.375*GAME_HEIGHT&&isWithinDoorway())
    {return true;}
    return false;
}
// default destructor
Game::~Game()
{
    //dtor
}

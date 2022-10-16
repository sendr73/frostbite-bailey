#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <SFML\Graphics.hpp>
#include "icesystem.h"
#include "frostbite.h"
#include "score.h"
#include "igloo.h"
#include "temperature.h"
#include "EnemyMatrix.h"

class Game
{
    public:
        Game(const float &width=1000.f,const float &height = 800.f);
        //making the frostbite object jump on window, based on events
        void frostbiteJump(const sf::Event &event, bool &pressed);
        //function to use overwritten move function
        void move(const float& deltaTime);
        //function to move any class inherited from motion
        void move(Motion& spriteA, char direction, const float &moveSpeed) const;
        //moving the rows of ice on screen
        void icebergCollision(const float &deltaTime);
        //collsion logic between frostbite and enemies
        void enemyCollision(const float &deltaTime);
        //getter and setter for stage
        const int getStage() const;
        void setStage(const int &i);
        virtual ~Game();

    protected:
        float GAME_WIDTH=1000.f, GAME_HEIGHT=800.f;
        temperature temperature_timer;
        Frostbite frostbite=Frostbite("resources/frostbite.png",sf::Vector2f(1.f,1.f)); //frostbite object
        Score score;
        Igloo igloo;
        IceSystem ice_system;
        EnemyMatrix enemy_matrix;
        int stage;
        void setFrostbite(); //sets frostbite properties on screen
        void setIgloo(); //set igloo
        void landing(const int &i);
        void initialize(const bool &resetScore);
        void respawn();
        void nextLevel();
        void checkTemperature(); //check for negative temperature
        const bool isWithinDoorway() const;
        const bool cannotEnter() const;
        const bool canEnter() const;
        const bool hasLives() const;
};

#endif // GAME_H

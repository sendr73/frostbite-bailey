/**
 * \brief Game Class
 * The class in which all elements are created and game logic is implemented
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
 */
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
        /**
        * \brief Game constructor
        * Takes in width and height as parameters (see default allocations) and assigns them to local
        * private variables GAME_WIDTH and GAME_HEIGHT, stage is set to 1
        * \param Width of screen
        * \param Height of screen
        */
        Game(const float &width=1000.f,const float &height = 800.f);

        /**
        * \brief Reverses the direction of the Iceberg
        * Executes the reversal of the Icerow on which an Iceberg is being collided with
        */
        void reverseIceberg();

        /**
        * \brief Default Game Destructor
        */
        virtual ~Game();

    protected:
        temperature temperature_timer;
        Frostbite frostbite=Frostbite("resources/frostbite.png",sf::Vector2f(1.f,1.f)); //frostbite object
        Score score;
        Igloo igloo;
        IceSystem ice_system;
        EnemyMatrix enemy_matrix;
        int stage;
        /**
        * \brief Makes Frostbite jump (separated from move in case of animating)
        * Checks for an event, if that event is called, jumps.
        * Uses private Game helper functions to see if certain cases are met. If they are met Frostbite is
        * allowed to take certain actions. Parameter pressed checks if button has been released, used to debounce.
        * \param Event from user, like the up or down arrow
        * \param bool pressed, that checks if the button has been released or not
        * \return if the button has been pressed
        */
        bool frostbiteJump(const sf::Event &event, bool &pressed);

        /**
        * \brief Moves all the elements of the screen
        * Uses the helper function of the same name to move each individual Sprite per deltaTime
        * This is an example of the polymorphism OOP concept.
        * \param deltaTime is the change in time dictated by the refresh rate, passed into lower move() functions.
        */
        void move(const float& deltaTime);

        /**
        * \brief Helper move function
        * Moves each Sprite belonging to objects in Game. Direction is not always needed to be populated but required
        * in the function as objects use interface inheritance to override move() from Motion.
        * \param The Sprite that is being moved
        * \param The direction of the movement (populated with Q)
        * \param speed that the object is moving
        */
        void move(Motion& spriteA, Direction direction, const float &moveSpeed) const;

        /**
        * \brief Iceberg collision function
        * Checks if Frostbite has collided with all Icebergs in an IceSystem, executes as defined in IceSystem
        * \param change in time, deltaTime, defines how far the objects move
        */
        void icebergCollision(const float &deltaTime);

        /**
        * \brief Enemy collision function
        * Checks if Frostbite has collided with an Enemy, executes as defined in EnemyMatrix
        * \param change in time, deltaTime, defines how far the objects move
        */
        void enemyCollision(const float &deltaTime);

        /**
        * \brief Initializes the game
        * Sets all elements of the Game to be ready to play. If you want to restart a level, boolean resetScore
        * is set to false, but if you want to set elemets for a new game, set to true. stage is set to 2
        * \param boolean resetScore that detrmines if you reset the Score object
        */
        void initialize(const bool &resetScore);

        /**
        * \brief Respawns Frostbite
        * Sets Frostbite's position to be at the origin and decreases its lives
        */
        void respawn();

        /**
        * \brief Checks the temperature
        * Checks if temperature_timer has run out of time. Then either decreases the lives or ends the game.
        * If the life is lost this way, stage is set to 5 otherwise stage is set to 3.
        */
        void checkTemperature();

        /**
        * \brief Increases the level
        * Resets all members' properties and positions, besides score and lives. Increases the level of the Game.
        */
        void nextLevel();

        /**
        * \brief Checks if the player has lives remaining
        * Checks if player has lives. Then either decreases the lives or ends the game.
        * If the player has no lives, stage is set to 3.
        * \return True if the player has lives, false otherwise
        */
        const bool hasLives() const;

    private:
        float GAME_WIDTH=1000.f, GAME_HEIGHT=800.f;

        /**
        * \brief Sets the Frostbite object for the Game
        * Places Frostbite at the origin on the screen, ready to play the Game
        */
        void setFrostbite();

        /**
        * \brief Sets the Igloo for the Game
        * Generates the blocks in the Igloo, sets the number of blocks gained by the player as 0.
        */
        void setIgloo();

        /**
        * \brief Executes certain actions when a landing has been completed
        * Frostbite lands on an Iceberg. If the amount of blocks buit is a multiple of 4, reset the properties of IceSystem
        * \param Index, i, of the Icerow that has been landed on in IceSystem.
        */
        void landing(const int &i);

        /**
        * \brief Checks if Frostbite is aligned with Igloo's doorway
        * \return True if within the doorway and on safezone, False otherwise
        */
        const bool isWithinDoorway() const;

        //Note: Both of the following need to be created as these functions are used to dictate the behaviour of frostbiteJump

        /**
        * \brief Checks if Frostbite cannot enter the Igloo and win the round
        * \return True if Frostbite cannot win, False otherwise
        */
        const bool cannotEnter() const;

        /**
        * \brief Checks if Frostbite can enter the Igloo and win the round
        * \return True if Frostbite can win, False otherwise
        */
        const bool canEnter() const;
};

#endif // GAME_H

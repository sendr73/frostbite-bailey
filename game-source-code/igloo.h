#ifndef IGLOO_H
#define IGLOO_H
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

/**
 * \brief Igloo Class
 * Class that deals with generation and manipulation of the Igloo
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
 */
class Igloo
{
    public:
        /**
        * \brief Default Igloo constructor
        */
        Igloo();

        /**
        * \brief Checks if Igloo is complete
        *
        * \return True if complete, False otherwise
        */
        const bool isComplete() const;

        /**
        * \brief Toggles if Igloo is complete
        *
        * If Igloo is complete, make Igloo not complete
        * This allows for the igloo to be rebuilt
        */
        void toggleComplete();

        /**
        * \brief Generates blocks of Igloo
        *
        * Generating all blocks at the beginning of the Game is more memory expensive, but computationally
        * becomes more optimal as the game goes on for time. Width and Height are used to set positions
        *
        * \param x is the width of the game
        * \param y is the height of the game
        */
        void generateBlocks(const float x, const float y);

        /**
        * \brief Increments the amount of blocks
        *
        * If boolean subtract is true, increment negativelly, otherwise increase the amount until 16
        *
        * \param subtract is a boolean variable and determining the sign of the addition
        */
        void incrementBlockAmount(bool subtract);

        /**
        * \brief Gets amount of blocks
        *
        * \returns private member blockAmount
        */
        const int getBlockAmount() const;

        /**
        * \brief Gets a specific RectangleShape of the block
        *
        * This is used to draw the Block in the persentation layer
        *
        * \param index for which block to return
        *
        * \return i-th index of private RectangleShape vector blocks
        */
        const sf::RectangleShape getBlock(const int &index) const;

        /**
        * \brief Gets position of a block
        *
        * This is typically used to get the position of the Door block (16th index) to see if
        * Frostbite is aligned to enter the Igloo or not.
        *
        * \param index for which block's position to get
        *
        * \return i-th Vector2f position of block from private RectangleShape vector blocks
        */
        const sf::Vector2f getBlockPosition(const int &index) const;

        /**
        * \brief Gets size of a block
        *
        * This is typically used to get the width of the Door block (16th index) to see if
        * Frostbite is aligned to enter the Igloo or not.
        *
        * \param index of which block size to get
        *
        * \return i-th Vector2f position of block from private RectangleShape vector blocks
        */
        const sf::Vector2f getBlockSize(const int &i) const;

        /**
        * \brief Resets properties of the Igloo
        *
        * Sets blockAmount to 0, and complete to 0
        */
        void reset();

        /**
        * \brief Default IceSystem Destructor
        */
        virtual ~Igloo();

    protected:

    private:
        vector<sf::RectangleShape> blocks;
        bool complete;
        int blockAmount;
};

#endif // IGLOO_H

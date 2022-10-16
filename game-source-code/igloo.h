#ifndef IGLOO_H
#define IGLOO_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class Igloo
{
    public:
        Igloo();
        //getter to check if it is complete
        const bool isComplete() const;
        //method to set complete
        void toggleComplete();
        //helper method to generate blocks
        void generateBlocks(const float x, const float y);
        //helper method to increase block amount
        void incrementBlockAmount(bool subtract);
        //method to get block amount
        const int getBlockAmount() const;
        //returns one block
        const sf::RectangleShape getBlock(const int &i) const;
        //returns block position
        const sf::Vector2f getBlockPosition(const int &i) const;
        //returns block position
        const sf::Vector2f getBlockSize(const int &i) const;
        //resets igloo characteristics
        void reset();
        virtual ~Igloo();

    protected:

    private:
        vector<sf::RectangleShape> blocks;
        bool complete;
        int blockAmount;
        //helper method to check if a new row must be added
};

#endif // IGLOO_H

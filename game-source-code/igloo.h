#ifndef IGLOO_H
#define IGLOO_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class Igloo
{
    public:
        Igloo(const sf::RenderWindow &window);
        //getter to check if it is complete
        const bool isComplete() const;
        virtual ~Igloo();

    protected:

    private:
        vector<sf::RectangleShape> blocks;
        bool complete;
        int blockAmount;
        //helper method to generate blocks
        void generateBlocks(const float x, const float y);
        //helper method to increase block amount
        void incrementBlockAmount();
        //helper method to check if a new row must be added
};

#endif // IGLOO_H
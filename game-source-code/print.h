#ifndef PRINT_H
#define PRINT_H
#include <SFML\Graphics.hpp>

class Print
{
    public:
        Print();
        virtual void drawPrint(sf::RenderWindow &window) = 0;
        virtual ~Print();

    protected:

    private:
};

#endif // PRINT_H

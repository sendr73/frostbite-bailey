/**
 * \brief Icerow Class
 * Uses interface inheritance with move function from class, Motion.
 * Uses composition inheritance of Iceberg objects
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
 */
#ifndef ICEROW_H
#define ICEROW_H

#include "iceberg.h"
#include <SFML\Graphics.hpp>
#include <memory>
#include <vector>

using namespace std;

class Icerow: public Motion
{
    public:
        /**
        * \brief Icerow constructor
        *
        * Sets game width, x and height, y as 1000 and 800 by default. row is 0 by default.
        * row controls the height assigned to each Iceberg in icerow_. There are three Icebergs
        * created per Icerow, with each position shifted. These positions are determined by the
        * initial direction of the Icerow, dictated by the number of the row.
        *
        * \param x is the game width
        * \param x is the game height
        * \param row is the row number - used
        */
        Icerow(const float &x=1000.f, const float &y=800.f,const int &row=0);

        /**
        * \brief [] operator overload
        * Uses the [] operator to access Iceberg elements. Cannot manipulate, just access
        * \param index in Icerow
        * \return Iceberg at index, i, in icerow_
        */
        Iceberg operator[](const int& index);

        /**
        * \brief Function to get Icerow's size
        * Gets the icerow_'s size and returns it
        * \return Size of the Icerow
        */
        const int size() const;

        /**
        * \brief move function overwridden from Motion class, deals with horizontal motion
        * No direction is required since Iceberg has it's own direction defined.
        * \param direction to move - is ignored
        * \param x is the width of the screen
        * \param y is the height of the screen
        * \param deltaTime is time passed and is multipled with speed when implemented in Iceberg
        */
        virtual void move(Direction direction, const float &x, const float &y, float deltaTime) override;

        /**
        * \brief executes landedOn function for each Iceberg in Icerow
        */
        void landedOn();

        /**
        * \brief returns the boundaries of each Iceberg using Element's getBounding function
        * This is used for collision logic in each row when colliding with Frostbite
        * \return vector of FloatRect boundaries of each Iceberg in Icerow
        */
        vector<sf::FloatRect> getRowBoundaries() const;

        /**
        * \brief reverse function changes private member direction in each Iceberg in icerow_
        * No direction is required since Iceberg has it's own direction defined, which is flipped.
        */
        void reverse();

        /**
        * \brief Each Iceberg in the Icerow is resetted
        * This executes the reset function defined in Iceberg
        */
        void reset();

        /**
        * \brief Default Icerow Destructor
        */
        virtual ~Icerow();

    protected:

    private:
        Iceberg iceberg_;
        std::vector<std::shared_ptr<Iceberg>> icerow_;
};

#endif // ICEROW_H

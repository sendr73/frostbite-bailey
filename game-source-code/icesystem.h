/**
 * \brief IceSystem Class
 * Uses interface inheritance with move function from class, Motion.
 * Also uses interface inheritance with collision function from class, Collisions
 * Uses composition inheritance of Icerow objects, which composes of Icebergs
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
 */
#ifndef ICESYSTEM_H
#define ICESYSTEM_H
#include "icerow.h"
#include <SFML\Graphics.hpp>
#include <vector>
#include "Collisions.h"

class IceSystem: public Motion, public Collisions
{
    public:
        /**
        * \brief IceSystem constructor
        * Creates four rows of Icerows. No parameters are required since the amount
        * of rows created are constant every game.
        */
        IceSystem();

        /**
        * \brief move function overwridden from Motion class, deals with horizontal motion
        * No direction is required since each Iceberg in Icerow has it's own direction defined.
        * \param direction to move - is ignored
        * \param x is the width of the screen
        * \param y is the height of the screen
        * \param deltaTime is time passed and is multipled with speed when implemented in Iceberg
        */
        virtual void move(Direction direction, const float &x, const float &y, float deltaTime) override;

        /**
        * \brief collision function overwridden from Collision class
        * Takes in a Frostbite object and check if its boundaries collide with all Iceberg in IceSystem.
        * If boundaries do intersect, returns the index of the row in IceSystem that it collided with and
        * Frostbite is moved at the speed of the Iceberg that is collided with.
        * \param Frostbite object
        * \param x is the width of the screen
        * \param y is the height of the screen
        * \param deltaTime is time passed and is multiplied with speed of the Iceberg collided with
        */
        virtual int collision(Frostbite &frostbite, const float &x, const float &y, const float &deltaTime) override;

        /**
        * \brief [] operator overload
        * Uses the [] operator to access the i-th Icerow in Icesystem. Cannot manipulate, just access
        * \param index in IceSystem
        * \return Icerow at index, i, in icesystem_
        */
        Icerow operator[](const int& index);

        /**
        * \brief Function to get IceSystem's size
        * Gets the icesystem_'s size and returns it
        * \return Size of the Icerow
        */
        int const size() const;

        /**
        * \brief Executes landedOn (defined in Icerow) for the i-th icesystem_ member
        * \param index in IceSystem
        */
        void rowLandedOn(const int &i);

        /**
        * \brief Executes draw in Icerow, that draws each Iceberg
        * \param RenderWindow window
        */
        void draw(sf::RenderWindow &window);

        /**
        * \brief Executes reverse in Icerow, that reverses the direction of each Iceberg
        * \param index in IceSystem
        */
        void reverse(const int &i);

        /**
        * \brief Executes reset in Icerow, that resets the properties of all Icebergs
        */
        void reset();

        /**
        * \brief Default IceSystem Destructor
        */
        virtual ~IceSystem();

    protected:

    private:
        Icerow i1; //default Icerow
        Icerow i2 = Icerow(1000.f,800.f,1); // second row
        Icerow i3 = Icerow(1000.f,800.f,2); // third row
        Icerow i4 = Icerow(1000.f,800.f,3); // fourth row
        std::vector<Icerow> icesystem_;
        const int row = 4;
};

#endif // ICESYSTEM_H

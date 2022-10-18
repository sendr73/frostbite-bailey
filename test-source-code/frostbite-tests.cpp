#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <Windows.h>
#include "doctest.h"

#include "../game-source-code/iceberg.h"
#include "../game-source-code/frostbite.h"
#include "../game-source-code/enemy.h"
#include "../game-source-code/temperature.h"

Iceberg iceberg("resources/iceberg.png",sf::Vector2f(1.f,1.f)); //known to exist, will create another test case later on
Iceberg overlap("resources/iceberg.png",sf::Vector2f(1.f,1.f));
const auto ICEBERG_SPEED = 150.f;
const auto GAME_HEIGHT = 900.f;
const auto GAME_WIDTH = 1600.f;
const auto ICEBERG_HEIGHT = GAME_HEIGHT - 200.f;

Frostbite frostbite("resources/iceberg.png",sf::Vector2f(1.f,1.f));
const auto FROSTBITE_SPEED = 6.f;
const auto FROSTBITE_JUMP= 100.f;

Enemy enemyCrab("resources/crab.png");

temperature temperature_timer;


using namespace std;

TEST_CASE("Iceberg moves right") //Testing for x and y axis
{
    iceberg.setPosition(100,ICEBERG_HEIGHT);
    //direction is right by default
    const auto [initial_x,initial_y] = iceberg.getPosition();
    iceberg.move('r',GAME_HEIGHT,GAME_WIDTH,ICEBERG_SPEED);
    CHECK(iceberg.getPosition().x>initial_x);
    CHECK(iceberg.getPosition().y==initial_y); //makes sure not moving upwards
}

TEST_CASE("Iceberg moves left") //Testing for x and y axis
{
    iceberg.setPosition(100,ICEBERG_HEIGHT);
    iceberg.setDirection('l'); //setting direction to be left
    const auto [initial_x,initial_y] = iceberg.getPosition();
    iceberg.move('l',GAME_HEIGHT,GAME_WIDTH,ICEBERG_SPEED);
    CHECK(iceberg.getPosition().x<initial_x);
    CHECK(iceberg.getPosition().y==initial_y); //makes sure not moving upwards
}
/*
TEST_CASE("Iceberg overlaps correctly") //Multiple assertions, commented below
{
    overlap.setPosition(-overlap.getWidth()/2,ICEBERG_HEIGHT); //Equivalent to origin position
    const auto initial_x = overlap.getPosition().x;
    iceberg.setDirection('r');
    iceberg.setPosition(100,overlap.getPosition().y);
    iceberg.move(ICEBERG_SPEED,GAME_HEIGHT,GAME_WIDTH,overlap); //Should NOT overlap, x should not change
    CHECK(overlap.getPosition().x==initial_x);
    iceberg.setPosition(GAME_WIDTH-80.f,ICEBERG_HEIGHT); //when moved, the right-hand side exceeds bounds by 70
   // cout << iceberg.getPosition().x << endl;
    iceberg.move(ICEBERG_SPEED,GAME_HEIGHT,GAME_WIDTH,overlap); //Should overlap, x should be at at iceberg.x-GAME_WIDTH
    //cout << iceberg.getPosition().x << endl;
    CHECK(overlap.getPosition().x==iceberg.getPosition().x-GAME_WIDTH);
}
*/
TEST_CASE("Frostbite Move Left, keeps vertical position and changes horizontal positon by - speed") //Testing for x and y axis
{
    frostbite.setPosition(500,500); //set initial positon
    const auto left  = 'l'; //set direction
    frostbite.move(left, GAME_WIDTH, GAME_HEIGHT, FROSTBITE_SPEED);
    CHECK(500 == frostbite.getPosition().y); //check y axis that it remains the same
    CHECK((500 - FROSTBITE_SPEED) == frostbite.getPosition().x); //check x axis that it decreases by the speed
}

TEST_CASE("Frostbite Move Right, keeps vertical position and changes horizontal positon by + speed") //Testing for x and y axis
{
    frostbite.setPosition(500,500); //set initial positon
    const auto right  = 'r'; //set direction
    frostbite.move(right, GAME_WIDTH, GAME_HEIGHT, FROSTBITE_SPEED);
    CHECK(500 == frostbite.getPosition().y); //check y axis that it remains the same
    CHECK((500 + FROSTBITE_SPEED) == frostbite.getPosition().x); //check x axis that it increase by the speed
}

TEST_CASE("Frostbite Jump, keeps horizontal position and changes vertical positon by Jump value") // should be by jump not speed (needs a new implementation)
{
    frostbite.setPosition(500,500); //set initial positon
    const auto up  = 'u'; //set direction
    frostbite.jump(up, FROSTBITE_JUMP, GAME_HEIGHT, GAME_WIDTH); //jump is independent of speed
    CHECK(500 == frostbite.getPosition().x); //check x axis that it remains the same
    CHECK((500 - FROSTBITE_JUMP) == frostbite.getPosition().y); //check y axis that it increase by the speed/jump
}

TEST_CASE("Frostbite Move Down, keeps horizontal position and changes vertical positon by + JUMP amount") // should be by jump not speed (needs a new implementation)
{
    frostbite.setPosition(500,500); //set initial positon
    const auto down  = 'd'; //set direction
    frostbite.jump(down, FROSTBITE_JUMP, GAME_HEIGHT, GAME_WIDTH);
    CHECK(500 == frostbite.getPosition().x); //check x axis that it remains the same
    CHECK((500 + FROSTBITE_JUMP) == frostbite.getPosition().y); //check y axis that it increase by the speed/jump
}

TEST_CASE("Frostbite Screen Collision at top score section will stop Frostbite from jumping too high")
{
    auto frostbite_height = frostbite.getHeight();
    frostbite.setPosition(500,400); //set initial positon to be close to top
    const auto initial_y = 0.375*GAME_HEIGHT; //what Frosbite's position will be reset to
    frostbite.jump('u', FROSTBITE_JUMP, GAME_HEIGHT, GAME_WIDTH);
    CHECK(initial_y == frostbite.getPosition().y); //check y position is set to frosbite_height with top collision
}

TEST_CASE("Frostbite Screen Collision at bottom prevents Sprite's vertical position from being greater than board height")
{
    frostbite.setPosition(500,GAME_HEIGHT-1); //set initial positon
    frostbite.jump('d', FROSTBITE_SPEED, GAME_HEIGHT, GAME_WIDTH);
    CHECK(GAME_HEIGHT -frostbite.getHeight() == frostbite.getPosition().y);//check y positon to be equal to game height
}
/*
TEST_CASE("Frostbite Screen Collision at right prevents Sprite from sticking over edge")
{
    auto frostbite_half_width = frostbite.getWidth()/2;
    frostbite.setPosition(GAME_WIDTH-frostbite_half_width -1,500); //close to edge
    frostbite.move('r', GAME_HEIGHT, GAME_WIDTH, FROSTBITE_SPEED);
    CHECK(GAME_WIDTH-frostbite_half_width== frostbite.getPosition().x); //check x axis that it is width minus half of Frostbite's width
}

TEST_CASE("Frostbite Screen Collision at left prevents Sprite from sticking over edge")
{
    auto frostbite_half_width = frostbite.getWidth()/2;
    frostbite.setPosition(frostbite_half_width + 1,500); //close to edge
    frostbite.move('l', GAME_HEIGHT, GAME_WIDTH, FROSTBITE_SPEED);
    CHECK(frostbite_half_width== frostbite.getPosition().x); //check x axis that it is half of Frostbite's width
}
/*
//enemies test cases
TEST_CASE("Enemies Location can be Set Correctly")

{
    enemyCrab.setPosition(10.0f, 10.0f);
    CHECK(enemyCrab.getPosition().x==10.0f);
    CHECK(enemyCrab.getPosition().y==10.0f);
}

TEST_CASE("Enemies default direction is right")
{
    CHECK('r' == enemyCrab.getDirection());
}

TEST_CASE("If enemies direction is right, enemy will move to the right at given speed")
{
    enemyCrab.setPosition(10.0f, 10.0f);
    enemyCrab.move(100.0f, GAME_HEIGHT, GAME_WIDTH, enemyCrab);
    CHECK(enemyCrab.getPosition().x==110.0f);
    CHECK(enemyCrab.getPosition().y==10.0f); //check that y-driection has not changed
}

TEST_CASE("Enemies direction can be changed to left")
{
    enemyCrab.setDirection('l');
    CHECK('l' == enemyCrab.getDirection());
}

TEST_CASE("If enemies direction is left, enemy will move to the left at given speed")
{
    enemyCrab.setDirection('l');
    enemyCrab.setPosition(210.0f, 10.0f);
    enemyCrab.move(100.0f, GAME_HEIGHT, GAME_WIDTH, enemyCrab);
    CHECK(enemyCrab.getPosition().x==110.0f);
    CHECK(enemyCrab.getPosition().y==10.0f); //check that y-driection has not changed
}

TEST_CASE("Enemies moving off the screen uses the overlap correctly") //Multiple assertions, commented below
{
    auto enemyHeight = enemyCrab.getHeight(); //get height of enemy crab
    overlapE.setPosition(-overlapE.getWidth()/2,enemyHeight);
    const auto initial_x = overlapE.getPosition().x;
    enemyCrab.setDirection('r'); //set to move right
    enemyCrab.setPosition(100,overlapE.getPosition().y);
    enemyCrab.move(100,GAME_HEIGHT,GAME_WIDTH,overlapE); //Should NOT overlap, the overlap enemy's position should not change
    CHECK(overlapE.getPosition().x==initial_x);
    enemyCrab.setPosition(GAME_WIDTH-80.f,ICEBERG_HEIGHT); //when moved, the right-hand side exceeds boundary
    enemyCrab.move(100,GAME_HEIGHT,GAME_WIDTH,overlapE); //Extra enemy should appear at overlap
    CHECK(overlapE.getPosition().x==enemyCrab.getPosition().x-GAME_WIDTH);
}


TEST_CASE("Check Default reset temperature is 45")
{
    temperature_timer.resetClock(); //reset clock and temperature
    CHECK(45 == temperature_timer.getTemperature());
}

/*
TEST_CASE("Check that the temperature decreaes over time")
{
    sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "");
    temperature_timer.resetClock(); //reset clock and temperature
    Sleep(1000); //sleep for some time
    temperature_timer.draw(window); //this functions will update the temperature
    CHECK( temperature_timer.getTemperature()<45); //check the temperatuer

}
*/



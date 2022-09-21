#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../game-source-code/iceberg.h"
#include "../game-source-code/frostbite.h"

Iceberg iceberg("iceberg.png",sf::Vector2f(1.f,1.f)); //known to exist, will create another test case later on
Iceberg overlap("iceberg.png",sf::Vector2f(1.f,1.f));
const auto ICEBERG_SPEED = 150.f;
const auto GAME_HEIGHT = 900.f;
const auto GAME_WIDTH = 1600.f;
const auto ICEBERG_HEIGHT = GAME_HEIGHT - 200.f;

Frostbite frostbite("resources/iceberg.png",sf::Vector2f(1.f,1.f));
const auto FROSTBITE_SPEED = 6.f;


using namespace std;

TEST_CASE("Iceberg moves right") //Testing for x and y axis
{
    iceberg.setPosition(100,ICEBERG_HEIGHT);
    //direction is right by default
    const auto [initial_x,initial_y] = iceberg.getPosition();
    iceberg.move(ICEBERG_SPEED,GAME_HEIGHT,GAME_WIDTH,overlap);
    CHECK(iceberg.getPosition().x>initial_x);
    CHECK(iceberg.getPosition().y==initial_y); //makes sure not moving upwards
}

TEST_CASE("Iceberg moves left") //Testing for x and y axis
{
    iceberg.setPosition(100,ICEBERG_HEIGHT);
    iceberg.setDirection('l'); //setting direction to be left
    const auto [initial_x,initial_y] = iceberg.getPosition();
    iceberg.move(ICEBERG_SPEED,GAME_HEIGHT,GAME_WIDTH,overlap);
    CHECK(iceberg.getPosition().x<initial_x);
    CHECK(iceberg.getPosition().y==initial_y); //makes sure not moving upwards
}

TEST_CASE("Iceberg overlaps correctly") //Multiple assertions, commented below
{
    overlap.setPosition(-overlap.getWidth()/2,ICEBERG_HEIGHT); //Equivalent to origin position
    const auto initial_x = overlap.getPosition().x;
    iceberg.setDirection('r');
    iceberg.setPosition(100,overlap.getPosition().y);
    iceberg.move(ICEBERG_SPEED,GAME_HEIGHT,GAME_WIDTH,overlap); //Should NOT overlap, x should not change
    CHECK(overlap.getPosition().x==initial_x);
    iceberg.setPosition(GAME_WIDTH-80.f,ICEBERG_HEIGHT); //when moved, the right-hand side exceeds bounds by 70
    cout << iceberg.getPosition().x << endl;
    iceberg.move(ICEBERG_SPEED,GAME_HEIGHT,GAME_WIDTH,overlap); //Should overlap, x should be at at iceberg.x-GAME_WIDTH
    cout << iceberg.getPosition().x << endl;
    CHECK(overlap.getPosition().x==iceberg.getPosition().x-GAME_WIDTH);
}

TEST_CASE("Frostbite Move Left, keeps vertical position and changes horizontal positon by - speed") //Testing for x and y axis
{
    frostbite.setPostion(500,500); //set initial positon
    const auto left  = 'l'; //set direction
    frostbite.move(left, FROSTBITE_SPEED, GAME_HEIGHT, GAME_WIDTH);
    CHECK(500 == frostbite.getPosition().y); //check y axis that it remains the same
    CHECK((500 - FROSTBITE_SPEED) == frostbite.getPosition().x); //check x axis that it decreases by the speed
}

TEST_CASE("Frostbite Move Right, keeps vertical position and changes horizontal positon by + speed") //Testing for x and y axis
{
    frostbite.setPostion(500,500); //set initial positon
    const auto right  = 'r'; //set direction
    frostbite.move(right, FROSTBITE_SPEED, GAME_HEIGHT, GAME_WIDTH);
    CHECK(500 == frostbite.getPosition().y); //check y axis that it remains the same
    CHECK((500 + FROSTBITE_SPEED) == frostbite.getPosition().x); //check x axis that it increase by the speed
}

TEST_CASE("Frostbite Move Up, keeps horizontal position and changes vertical positon by - speed") // should be by jump not speed (needs a new implementation)
{
    frostbite.setPostion(500,500); //set initial positon
    const auto up  = 'u'; //set direction
    frostbite.move(up, FROSTBITE_SPEED, GAME_HEIGHT, GAME_WIDTH);
    CHECK(500 == frostbite.getPosition().x); //check x axis that it remains the same
    CHECK((500 - FROSTBITE_SPEED) == frostbite.getPosition().y); //check y axis that it increase by the speed/jump
}

TEST_CASE("Frostbite Move Down, keeps horizontal position and changes vertical positon by + speed") // should be by jump not speed (needs a new implementation)
{
    frostbite.setPostion(500,500); //set initial positon
    const auto down  = 'd'; //set direction
    frostbite.move(down, FROSTBITE_SPEED, GAME_HEIGHT, GAME_WIDTH);
    CHECK(500 == frostbite.getPosition().x); //check x axis that it remains the same
    CHECK((500 + FROSTBITE_SPEED) == frostbite.getPosition().y); //check y axis that it increase by the speed/jump
}

TEST_CASE("Frostbite Screen Collision at top prevents Sprite's vertical position from being less than its height")
{
    auto frostbite_height = frostbite.getHeight();
    frostbite.setPostion(500,frostbite_height + 1); //set initial positon to be close to top
    frostbite.move('u', FROSTBITE_SPEED, GAME_HEIGHT, GAME_WIDTH);
    CHECK(frostbite_height == frostbite.getPosition().y); //check y position is set to frosbite_height with top collision
}
TEST_CASE("Frostbite Screen Collision at bottom prevents Sprite's vertical position from being greater than board height")
{
    auto frostbite_height = frostbite.getHeight();
    frostbite.setPostion(500,GAME_HEIGHT-1); //set initial positon
    frostbite.move('d', FROSTBITE_SPEED, GAME_HEIGHT, GAME_WIDTH);
    CHECK(GAME_HEIGHT == frostbite.getPosition().y);//check y positon to be equal to game height
}

TEST_CASE("Frostbite Screen Collision at right prevents Sprite from sticking over edge")
{
    auto frostbite_half_width = frostbite.getWidth()/2;
    frostbite.setPostion(GAME_WIDTH-frostbite_half_width -1,500); //close to edge
    frostbite.move('r', FROSTBITE_SPEED, GAME_HEIGHT, GAME_WIDTH);
    CHECK(GAME_WIDTH-frostbite_half_width== frostbite.getPosition().x); //check x axis that it is width minus half of Frostbite's width
}

TEST_CASE("Frostbite Screen Collision at left prevents Sprite from sticking over edge")
{
    auto frostbite_half_width = frostbite.getWidth()/2;
    frostbite.setPostion(frostbite_half_width + 1,500); //close to edge
    frostbite.move('l', FROSTBITE_SPEED, GAME_HEIGHT, GAME_WIDTH);
    CHECK(frostbite_half_width== frostbite.getPosition().x); //check x axis that it is half of Frostbite's width
}

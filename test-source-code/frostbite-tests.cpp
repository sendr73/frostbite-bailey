#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../game-source-code/iceberg.h"

Iceberg iceberg("iceberg.png",sf::Vector2f(1.f,1.f)); //known to exist, will create another test case later on
Iceberg overlap("iceberg.png",sf::Vector2f(1.f,1.f));
const auto ICEBERG_SPEED = 150.f;
const auto GAME_HEIGHT = 900.f;
const auto GAME_WIDTH = 1600.f;
const auto ICEBERG_HEIGHT = GAME_HEIGHT - 200.f;

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

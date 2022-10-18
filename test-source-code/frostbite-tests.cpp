#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <Windows.h>
#include "doctest.h"

#include "../game-source-code/iceberg.h"
#include "../game-source-code/frostbite.h"
#include "../game-source-code/enemy.h"
#include "../game-source-code/temperature.h"
#include "../game-source-code/enemyrow.h"
#include "../game-source-code/icerow.h"
#include "../game-source-code/score.h"

const auto ICEBERG_SPEED = 150.f;
const auto GAME_HEIGHT = 800.f;
const auto GAME_WIDTH = 1000.f;
const auto ICEBERG_HEIGHT = GAME_HEIGHT - 200.f;
const auto DELTATIME = 2.0f;

Iceberg iceberg("resources/iceberg.png",sf::Vector2f(1.f,1.f)); //known to exist, will create another test case later on
Iceberg overlap("resources/iceberg.png",sf::Vector2f(1.f,1.f));
Icerow ice_row(GAME_WIDTH, GAME_HEIGHT, 1);

Frostbite frostbite("resources/iceberg.png",sf::Vector2f(1.f,1.f));
const auto FROSTBITE_SPEED = 6.f;
const auto FROSTBITE_JUMP= 100.f;

Enemy enemyCrab("resources/crab.png");
EnemyRow enemy_row("resources/crab.png", MovementType::Glide, 40.f, 460.f, 'r');

temperature temperature_timer;

Score score_;


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
TEST_CASE("Check Iceberge Row constructor sets all the enemies in the row from the row parameter")
{
    //formula for height is {(1+row)(0.125)+0.39}*GameHeight
    auto row = 1.0f;
    auto expected_height =  ((1+row)*0.125+0.39)*GAME_HEIGHT;
    CHECK(expected_height== ice_row[0].getPosition().y);
    CHECK(expected_height== ice_row[2].getPosition().y);
}


TEST_CASE("Check Each Iceberg in the row moves by the Speed*DeltaTime")
{
    ice_row.move('r', GAME_WIDTH, GAME_HEIGHT, DELTATIME);
    ice_row.move('r', GAME_WIDTH, GAME_HEIGHT, DELTATIME);
    ice_row.move('r', GAME_WIDTH, GAME_HEIGHT, DELTATIME);
    auto initial_position_1 = ice_row[0].getPosition().x;
    auto initial_position_2 = ice_row[1].getPosition().x;
    auto initial_position_3 = ice_row[2].getPosition().x;
    auto speed = iceberg.getSpeed();
    auto direction = ice_row[0].getDirection();
    //cout<<direction; direction is left
    ice_row.move('l', GAME_WIDTH, GAME_HEIGHT, DELTATIME); //note that the actual direction is non-relevent
    CHECK(initial_position_1 -speed*DELTATIME  == ice_row[0].getPosition().x);
    CHECK(initial_position_2 -speed*DELTATIME  == ice_row[1].getPosition().x);
    CHECK(initial_position_3 -speed*DELTATIME  == ice_row[2].getPosition().x);
}



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
    CHECK(GAME_HEIGHT == frostbite.getPosition().y);//check y positon to be equal to game height
}

TEST_CASE("Frostbite Screen Collision at right prevents Sprite from sticking over edge")
{
    auto frostbite_half_width = frostbite.getWidth()/2;
    frostbite.setPosition((GAME_WIDTH-frostbite_half_width -1),500); //close to edge
    frostbite.move('r',GAME_WIDTH,  GAME_HEIGHT,  FROSTBITE_SPEED);
    CHECK(GAME_WIDTH-frostbite_half_width== frostbite.getPosition().x); //check x axis that it is width minus half of Frostbite's width
}

TEST_CASE("Frostbite Screen Collision at left prevents Sprite from sticking over edge")
{
    auto frostbite_half_width = frostbite.getWidth()/2;
    frostbite.setPosition(frostbite_half_width + 1,500); //close to edge
    frostbite.move('l', GAME_HEIGHT, GAME_WIDTH, FROSTBITE_SPEED);
    CHECK(frostbite_half_width== frostbite.getPosition().x); //check x axis that it is half of Frostbite's width
}

//enemies test cases
TEST_CASE("Enemies Location can be Set Correctly")

{
    enemyCrab.setPosition(10.0f, 10.0f);
    CHECK(enemyCrab.getPosition().x==10.0f);
    CHECK(enemyCrab.getPosition().y==10.0f);
}

TEST_CASE("Enemies default Speed is 70")
{
    CHECK(70 == enemyCrab.getSpeed());
}

TEST_CASE("If enemies direction is right, enemy will move to the right at given speed")
{
    enemyCrab.setPosition(10.0f, 10.0f);

    enemyCrab.move('r', GAME_WIDTH,GAME_HEIGHT, DELTATIME);
    CHECK(enemyCrab.getPosition().x == (10.0f + DELTATIME*70) );
    CHECK(enemyCrab.getPosition().y == 10.0f); //check that y-driection has not changed
}

/*
TEST_CASE("Enemies direction can be changed to left")
{
    enemyCrab.setDirection('l');
    CHECK('l' == enemyCrab.getDirection());
}
*/

TEST_CASE("If enemies direction is left, enemy will move to the left at given speed")
{
    enemyCrab.setPosition(400.0f, 10.0f);
    enemyCrab.move('l', GAME_WIDTH,GAME_HEIGHT, DELTATIME);
    CHECK(enemyCrab.getPosition().x==(400.0f - 70*DELTATIME));
    CHECK(enemyCrab.getPosition().y==10.0f); //check that y-driection has not changed
}

/*
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
*/



TEST_CASE("Check Enemy Row constructor sets first enemy at given positions")
{
    CHECK(40 == enemy_row[0].getPosition().x);
}

TEST_CASE("Each Enemy in Enemy Row is spaced out from the other one by 2 times their width")
{
    auto enemyWidth = enemyCrab.getWidth();
    CHECK(2*enemyWidth == (enemy_row[1].getPosition().x- enemy_row[0].getPosition().x));
}

TEST_CASE("Check Each Enemy in the row moves by the enemySpeed*DeltaTime")
{
    auto initial_position_1 = enemy_row[0].getPosition().x;
    auto initial_position_2 = enemy_row[1].getPosition().x;
    auto initial_position_3 = enemy_row[2].getPosition().x;
    auto enemy_speed = enemyCrab.getSpeed();
    enemy_row.move('r', GAME_WIDTH, GAME_HEIGHT, DELTATIME);
    CHECK(initial_position_1 +enemy_speed*DELTATIME  == enemy_row[0].getPosition().x);
    CHECK(initial_position_2 +enemy_speed*DELTATIME  == enemy_row[1].getPosition().x);
    CHECK(initial_position_3 +enemy_speed*DELTATIME  == enemy_row[2].getPosition().x);
}

TEST_CASE("Check Default reset temperature is 45")
{
    temperature_timer.resetClock(); //reset clock and temperature
    CHECK(45 == temperature_timer.getTemperature());
}


TEST_CASE("Check that the temperature decreaes over time")
{
    sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "");
    temperature_timer.resetClock(); //reset clock and temperature
    Sleep(1000); //sleep for some time - will result in screen popping up - don't know why
    temperature_timer.update(); //this functions will update the temperature
    CHECK( temperature_timer.getTemperature()<45); //check the temperatuer

}

TEST_CASE("Check Score::Lives at start is 3")
{
      CHECK(3 == score_.getLives());
}
TEST_CASE("Check Score::Score at start is 0")
{
      CHECK(0 == score_.getScore());
}
TEST_CASE("Check Score::Level at start is 1")
{
      CHECK(1 == score_.getLevel());
}
TEST_CASE("Check Score::Increase Score works")
{
    auto initial_score = score_.getScore();
    auto score_increment = 100.0f;
    score_.increaseScore(score_increment);
    CHECK(initial_score + score_increment*10 == score_.getScore()); //each point is worth ten, so score increment is multipled by 10
}

TEST_CASE("Check that Score::Increase and Decrease lives works")
{
    auto initial_= score_.getLives();
    score_.increaseLives();
    CHECK(++initial_  == score_.getLives());
    score_.decreaseLives();
    CHECK(--initial_  == score_.getLives());

}

TEST_CASE("Check that Score::Increase Level works")
{
    auto initial_= score_.getLevel();
    score_.increaseLevel();
    CHECK(++initial_  == score_.getLevel());
}

TEST_CASE("Check that Score::Reset re-initializes all varaibles")
{
    score_.reset();
    CHECK(1 == score_.getLevel());
    CHECK(3 == score_.getLives());
    CHECK(0 == score_.getScore());
}







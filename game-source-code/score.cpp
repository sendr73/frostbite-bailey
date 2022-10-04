#include "score.h"

Score::Score()
{
    point = 10;
    score = 0;
    level = 1;
    lives = 3;;
}
//getter for score
const int Score::getScore() const
{
    return score;
}
//increases score
void Score::increaseScore()
{
    score=score+point;
}
//increases score based on remaining temperature
void Score::increaseScore(const int &temp)
{
    score=score+(temp*point);
}
//gets current level
const int Score::getLevel() const
{
    return level;
}
//increases level
void Score::increaseLevel()
{
    level++;
}
//gets current lives
const int Score::getLives() const
{
    return lives;
}
//increases lives
void Score::increaseLives()
{
    lives++;
}
//decreases lives
void Score::decreaseLives()
{
    lives--;
}
Score::~Score()
{
    //dtor
}

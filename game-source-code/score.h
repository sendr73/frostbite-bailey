/**
 * \brief Score Class
 *
 * Class that deals with lives, level and and score
 *
 * @author Ruth-Ann Wright (2351852)
 * @author Daron Sender (2332451)
 */
#ifndef SCORE_H
#define SCORE_H


class Score
{
    public:
        /**
        * \brief Score default constructor
        *
        * Initializes the private member variables
        */
        Score();

        /**
        * \brief Gets the current score
        *
        * \returns priavte-member variable 'score'
        */
        const int getScore() const;

        /**
        * \brief Increments the score by 1
        */
        void increaseScore();

        /**
        * \brief Increases the score by amount specified
        *
        * \param temp amount to increment the score by
        */
        void increaseScore(const int &temp);

        /**
        * \brief Gets the current level
        *
        * \returns priavte-member variable 'level'
        */
        const int getLevel() const;

        /**
        * \brief Increments the level by 1
        */
        void increaseLevel();


        /**
        * \brief Gets the Lives
        *
        * \returns priavte-member variable 'lives'
        */
        const int getLives() const;

        /**
        * \brief Increments the lives by 1
        */
        void increaseLives();

        /**
        * \brief Decrements the lives by 1
        */
        void decreaseLives();

        /**
        * \brief Resets all the private memeber variables
        *
        * sets lives to 3, level to 1, score to 0
        */
        void reset();

        /**
        * \brief Default Score Destructor
        */
        virtual ~Score();

    protected:

    private:
        int point;
        int score;
        int level;
        int lives;
};

#endif // SCORE_H

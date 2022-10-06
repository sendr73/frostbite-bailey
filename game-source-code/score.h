#ifndef SCORE_H
#define SCORE_H


class Score
{
    public:
        Score();
        //getter and increment for score
        const int getScore() const;
        void increaseScore();
        // case when round ends, add score proportional to temperature left
        void increaseScore(const int &temp);
        //getter and increment for level
        const int getLevel() const;
        void increaseLevel();
        //getter and increment for lives
        const int getLives() const;
        void increaseLives();
        void decreaseLives();
        void reset();
        virtual ~Score();

    protected:

    private:
        int point;
        int score;
        int level;
        int lives;
};

#endif // SCORE_H

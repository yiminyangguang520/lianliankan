class ScoreHelper
{
public:
    ScoreHelper(int _score)
        : curScore(_score)
    {

    }

    ~ScoreHelper()
    {
        //��curScoreд�����ݿ�
    }

    void addScore(int score)
    {
        curScore += score*scoreRank;
    }

    int score()
    {
        return curScore;
    }

private:
    const static int scoreRank = 10;
    int curScore;
};
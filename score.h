#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{

public:
    Score(QGraphicsItem * parent=0);
    void increase(int score);
    int getScore();
private:
    int _score = 1;
    int _bossScore = 1;
};
inline int Score::getScore(){return _score;}

#endif // SCORE_H

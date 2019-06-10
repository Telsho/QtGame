#include "score.h"
#include <QFont>
#include "boss.h"
#include <QGraphicsScene>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    setPlainText(QString("Score: ") + QString::number(_score - 1 ));
    setDefaultTextColor((Qt::black));
    setFont(QFont("times",16));

}

void Score::increase(int score)
{
    _score += score;
    _bossScore +=score;

    setPlainText(QString("Score: ") + QString::number(_score - 1));

    if(_bossScore > 100)
    {
        _bossScore=0;
        Boss * boss = new Boss(1.2);
        scene()->addItem(boss);
    }

}

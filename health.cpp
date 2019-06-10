#include "health.h"
#include <QFont>
#include "game.h"

extern Game * game;

Health::Health(QGraphicsItem *parent)
{
    setPos(200,0);
    setPlainText(QString("Life : ") + QString::number(_hp));
    setDefaultTextColor((Qt::black));
    setFont(QFont("times",16));
}

void Health::decrease()
{
    _hp--;
    setPlainText(QString("Life : ") + QString::number(_hp));
    if(_hp == 0){
        game->gameOver();
    }

}

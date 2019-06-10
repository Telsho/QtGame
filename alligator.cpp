#include "alligator.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QSize>
#include <QDebug>
#include "game.h"

extern Game* game;
Alligator::Alligator(int hp, int velocity, int scoreReward, int numCoins, double ratio): Ennemy(hp,velocity,scoreReward,numCoins,ratio)
{
    setPos(750,330);

    setPixmap(QPixmap(":/images/croco.png").scaled(150,150));
    timer = new QTimer(this);
    timer1 = new QTimer(this);

    connect(timer1, SIGNAL(timeout()), this, SLOT(attack()));
    connect(timer, SIGNAL(timeout()), this, SLOT(moveAnimation()));

    timer1->start(50);
    timer->start(50);


}



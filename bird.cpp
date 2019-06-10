#include "bird.h"

Bird::Bird(int hp, int velocity, int scoreReward, int numCoins, double ratio): Ennemy(hp,velocity,scoreReward,numCoins,ratio)
{
    setPos(750,200);

    setPixmap(QPixmap(":/images/bird.png").scaled(150,150));
    timer = new QTimer(this);
    timer1 = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(attack()));
    connect(timer, SIGNAL(timeout()), this, SLOT(moveAnimation()));

    timer1->start(50);
    timer->start(50);


}

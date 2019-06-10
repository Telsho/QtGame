#include "pinguin.h"
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "graphicsmovieitem.h"
#include "game.h"

extern Game * game;

Pinguin::Pinguin(int hp, int velocity, int scoreReward, int numCoins, double ratio): Ennemy(hp,velocity,scoreReward,numCoins,ratio)
{

    setPos(750,330);
    setPixmap(QPixmap(":/images/pinguin.png").scaled(150,150));
    timer = new QTimer(this);
    timer1 = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(attack()));
    connect(timer, SIGNAL(timeout()), this, SLOT(pinguinMove()));


    timer1->start(50);
    timer->start(50);
}

void Pinguin::pinguinMove()
{
    int speed = (int)floor(_velocity*_ratio);

    if(!_falling){
        setPos(x() - speed,y() - 20);
    }
    else{
        setPos(x() - speed,y() + 20);
    }

    if(y() <= 200){
        _falling = true;
    }
    else if(y() >= 330){
        _falling = false;
    }

}

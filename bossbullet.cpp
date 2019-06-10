#include "bossbullet.h"
#include "player.h"
#include <QGraphicsScene>
#include "game.h"

extern Game * game;

BossBullet::BossBullet(int velocity, double ratio): Actors(0,velocity,ratio)
{
    setPixmap(QPixmap(":/images/bossBullet.png").scaled(10,10));

    QTimer * timers = new QTimer(this);
    connect(timers, SIGNAL(timeout()), this, SLOT(bulletTravel()));

    timers->start(50);;
}


void BossBullet::bulletTravel()
{
    int speed = (int)floor(_velocity*_ratio);
    setPos(x() - speed,y());

    if(pos().x() < 0 || pos().x() > 700)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();
    foreach(QGraphicsItem * i, colliding_items)
    {
       if(typeid(*i) == typeid(Player)){
           game->health->decrease();
           scene()->removeItem(this);
           delete this;
       }
    }
}

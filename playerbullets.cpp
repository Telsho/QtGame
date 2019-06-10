#include "playerbullets.h"
#include <QTimer>
#include <QKeyEvent>
#include <QList>
#include <QGraphicsScene>
#include <QDebug>
#include "controller.h"
#include "alligator.h"
#include "ennemy.h"


PlayerBullets::PlayerBullets(int velocity, double ratio): Actors(0,velocity,ratio)
{
    setPixmap(QPixmap(":/images/bulletJane.png").scaled(80,80));

    QTimer * timers = new QTimer(this);
    connect(timers, SIGNAL(timeout()), this, SLOT(bulletTravel()));

    timers->start(50);;
}

void PlayerBullets::bulletTravel()
{
    int speed = (int)floor(_velocity*_ratio);
    setPos(x() + speed,y());

    if(pos().x() < 0 || pos().x() > 700)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }

    Ennemy * item;

    QList<QGraphicsItem *> colliding_items = collidingItems();
    foreach(QGraphicsItem * i, colliding_items)
    {
       item = dynamic_cast<Ennemy *>(i);
       if(item)
       {
            item->damageTaken(this->_ratio*1);
            scene()->removeItem(this);
            delete this;
            return;
       }
    }
}

#include "coin.h"
#include <QTimer>
#include "player.h"
#include <QGraphicsScene>
#include <QDebug>

Coin::Coin(int x, int y, int velocity, int ratio): Actors(0,velocity,ratio)
{
   setPos(x,y+50);

   setPixmap(QPixmap(":/images/coin.png").scaled(50,50));
   timer = new QTimer(this);
   connect(timer, SIGNAL(timeout()), this, SLOT(moveCoins()));
   timer->start(50);
}

Coin::Coin()
{

}

void Coin::moveCoins()
{
    int speed = (int)floor(_velocity*_ratio);
    setPos(x() - speed,y());

    if(pos().x() < 0 || pos().x() > 700)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }

    Player * item;

    QList<QGraphicsItem *> colliding_items = collidingItems();
    foreach(QGraphicsItem * i, colliding_items)
    {
       if(typeid(*i) == typeid(Player)){
           item = dynamic_cast<Player *>(i);
           if(item)
           {
                item->addCoin();
                scene()->removeItem(this);
                delete this;
                return;
           }
       }
    }
}

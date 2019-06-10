#include "actors.h"
#include <QDebug>
#include <QGraphicsScene>
#include "ennemy.h"
#include <QList>
#include "player.h"
#include "playerbullets.h"
#include <string>
#include <sstream>
#include <QPixmapCache>
#include "game.h"
#include <QDebug>
extern Game * game;
using namespace std;

Actors::Actors(QGraphicsItem *parent, int velocity, double ratio): QGraphicsPixmapItem()
{
    _velocity = velocity;
    _ratio = ratio;
}

Actors::~Actors()
{
}



void Actors::moveAnimation()
{

    qDebug() << (long long)this;
    int speed = (int)floor(_velocity*_ratio);
    setPos(x() - speed,y());
    if(pos().x() < 0 || pos().x() > 800)
    {
        delete timer;
        scene()->removeItem(this);
        delete this;
        return;
    }
}













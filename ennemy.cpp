#include "ennemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include "coin.h"
#include "player.h"
#include "game.h"

extern Game * game;

Ennemy::Ennemy(int hp, int velocity, int scoreReward, int numCoins, double ratio): Actors(0,velocity,ratio)
{
    this->_hp = hp;
    this->_scoreReward = scoreReward;
    this->_numCoins = numCoins;
}

Ennemy::~Ennemy()
{
}


void Ennemy::damageTaken(int damage)
{
    _hp -= damage;
    if(_hp <= 0)
    {
        dead();
    }
}


void Ennemy::dead()
{

    game->score->increase(_scoreReward);

    double xActor = x();
    double yActor = y();


    Coin *coins[5];

    for(int i=0; i < _numCoins; i++)
    {
        coins[i] = new Coin(xActor,yActor,_velocity,_ratio);
        scene()->addItem(coins[i]);
        xActor -= 20;
    }

    scene()->removeItem(this);
    delete this;
}

void Ennemy::attack()
{
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


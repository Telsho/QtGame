#include "boss.h"
#include "ennemy.h"
#include "bossbullet.h"
#include <QGraphicsScene>
#include <QDebug>

Boss::Boss(double ratio): Ennemy(10,3,1,5,ratio)
{
    setPos(200,210);
    walkPath = ":/gif/pigWalk.gif";
    deathPath =":/gif/pigDie.gif";
    attackPath = ":/gif/pigShoot.gif";

    timer = new QTimer(this);
    timer1 = new QTimer(this);

    qDebug() << "THE BOSS IS COMING";
    animation = new QMovie(walkPath);
    animation->setScaledSize(size);
    animation->setSpeed(50*_ratio);
    animation->start();
    setPixmap(animation->currentPixmap());
    //connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    //timer->start(100);

    //bossRoutine();

}

void Boss::bossRoutine()
{

    if(_frame){
        animation = new QMovie(walkPath);
        animation->setScaledSize(size);
        animation->setSpeed(50*_ratio);
        animation->start();
        setPixmap(animation->currentPixmap());

    }
     _frame = 0;
    disconnect(timer1,SIGNAL(timeout()),0,0);



    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(100);
}

void Boss::bossShoot()
{

    disconnect(timer,SIGNAL(timeout()),0,0);
    animation = new QMovie(attackPath);
    animation->setScaledSize(size);
    animation->setSpeed(50*_ratio);
    animation->start();
    setPixmap(animation->currentPixmap());

    BossBullet * bullet = new BossBullet(8,1.5);
    bullet->setPos(x(),y()+70);
    scene()->addItem(bullet);


    connect(timer1, SIGNAL(timeout()), this, SLOT(attackBoss()));
    timer1->start(100);
}

void Boss::attackBoss()
{

    animation->start();
    setPixmap(animation->currentPixmap());
    _frame++;

    if(_frame == 10){
        bossRoutine();
    }


}

void Boss::move()
{
    qDebug() << "THE BOSS IS MOOVING";
    _frame++;
    int speed = (int)floor(_velocity*_ratio);
    setPos(x() - speed,y());
    animation->setSpeed(50*_ratio);
    animation->start();
    setPixmap(animation->currentPixmap());

    if(_frame == 30)
    {
        _frame = 0;
        bossShoot();
    }
}

void Boss::dead()
{

}

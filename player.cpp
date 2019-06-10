#include "player.h"
#include "playerbullets.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>
#include "game.h"

extern Game * game;

Player::Player(int velocity, double ratio): Actors(0,velocity, ratio)
{
    setPos(-80,300);
    animation = new QMovie(":gif/janeStance.gif");
    animation->setScaledSize(sizePlayer);
    animation->start();
    setPixmap(animation->currentPixmap());

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveJane()));

    timer->start(50);
}


void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {

        delete animation;
        animation = new QMovie(":gif/janeJump.gif");
        animation->setScaledSize(sizePlayer);
        disconnect(timer,SIGNAL(timeout()),0,0);
        connect(timer, SIGNAL(timeout()), this, SLOT(jumpingJane()));
        timer->start(15);
    }

    if(event->key() == Qt::Key_A)
    {
        game->ammo->decreaseCurrentAmmo();
        int currentAmmo = game->ammo->getCurrentAmmo();


        if(currentAmmo == 0){
            QTimer::singleShot(700,this,SLOT(reload()));
        }


        if(currentAmmo > 0)
        {
            _frame = 0;
            qDebug() << "shoooot";
            delete animation;
            animation = new QMovie(":gif/janeShoot.gif");
            animation->setScaledSize(sizePlayer);
            disconnect(timer,SIGNAL(timeout()),0,0);
            connect(timer, SIGNAL(timeout()), this, SLOT(shootJane()));
            timer->start(20);

            PlayerBullets * bullet = new PlayerBullets(20,1.05);
            bullet->setPos(x()+160,y()+70);
            scene()->addItem(bullet);
        }
    }
    if(event->key() == Qt::Key_R)
    {
        QTimer::singleShot(700,this,SLOT(reload()));
    }

}

void Player::addCoin()
{
    _coins++;

    if(_coins%10 == 0){
        game->ammo->increaseCapacity();
    }
}

void Player::shootJane()
{
    _jumping = false;
    if(y() != 300)
    {
        _jumping = true;
    }
    if(_jumping){
        setPos(x(),y() + 10);
        if(y() >= 300){
            setPos(x(),300);
            startAnimation();
            _jumping = false;
        }
    }
    animation->setSpeed(100*_ratio);
    animation->start();
    setPixmap(animation->currentPixmap());
    _frame++;
    if(_frame == 5 && !_jumping){
        startAnimation();
    }
}


void Player::jumpingJane()
{
    animation->start();
    setPixmap(animation->currentPixmap());
    if(y() < 80)
    {
        _jumping = true;
    }
    if(_jumping)
    {
        setPos(x(),y() + 10);
        if(y() >= 300){
            startAnimation();
            _jumping = false;
        }
    }
    else
    {
        setPos(x(),y() - 10);
    }
}


void Player::moveJane()
{
    animation->setSpeed(100*_ratio);
    animation->start();
    setPixmap(animation->currentPixmap());
}

void Player::reload()
{
    game->ammo->reload();
}

void Player::startAnimation()
{
    if(y() < 300){
        connect(timer, SIGNAL(timeout()), this, SLOT(jumpingJane()));
        timer->start(5);
    }
    delete animation;
    animation = new QMovie(":gif/janeStance.gif");
    animation->setSpeed(200);
    animation->setScaledSize(sizePlayer);
    animation->start();
    setPixmap(animation->currentPixmap());
    disconnect(timer,SIGNAL(timeout()),0,0);

    delete timer;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveJane()));
    timer->start(50);
}

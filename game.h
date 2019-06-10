#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "score.h"
#include "controller.h"
#include "player.h"
#include "health.h"
#include <QMovie>
#include "ammo.h"


class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget * parent=NULL);

    void displayMenu();
    void gameOver();

    QGraphicsScene * scene;
    Controller * controller;
    Score * score;
    Ammo * ammo;
    Health * health;
    Player * player;
    QMovie * movie;

public slots:
    void start();



};

#endif // GAME_H

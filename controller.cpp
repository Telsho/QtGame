#include "controller.h"
#include "pinguin.h"
#include "hyena.h"
#include "alligator.h"
#include "bird.h"
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QMovie>
#include "game.h"

extern Game * game;

Controller::Controller(QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    QTimer * timeer = new QTimer(this);
    connect(timeer,SIGNAL(timeout()),this,SLOT(spawnner()));
    timeer->start(3000);

}

void Controller::spawnner()
{
       double ratio = 1+ (game->score->getScore()/100);
       _random_number = rand() % 100;
       if(_random_number <= 27){
           Alligator  *alligator = new Alligator(3,5,5,2,ratio);
           scene()->addItem(alligator);
       }
       else if(_random_number > 27 && _random_number <= 54 ){
           Bird  *bird = new Bird(2,10,5,2,ratio);
           scene()->addItem(bird);
       }
       else if(_random_number > 54 && _random_number <= 81 ){
           Hyena  *hyena = new Hyena(2,12,5,2,ratio);
           scene()->addItem(hyena);
       }
       else {
           Pinguin  *pinguin = new Pinguin(2,8,10,2,ratio);
           scene()->addItem(pinguin);
       }


}

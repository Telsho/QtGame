#ifndef UTILS_H
#define UTILS_H
#include <QObject>
#include <QWidget>
#include "player.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include "alligator.h"
#include "bird.h"
#include "hyena.h"
#include "pinguin.h"

class Controller: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Controller(QGraphicsItem * parent=0);

private:
    Alligator * alligator;
    Pinguin * pinguin;
    Hyena * hyena;
    Bird * bird;
    int _random_number;
    int _instance = 0;

public slots:
    void spawnner();
};
#endif // UTILS_H

#ifndef ACTORS_H
#define ACTORS_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMovie>
#include <Qsize>
#include <QTimer>
#include "graphicsmovieitem.h"

class Actors: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Actors(QGraphicsItem * parent =0, int velocity = 1, double ratio = 0.1);
    ~Actors();
protected:
    QTimer * timer;
    QTimer * timer1;
    int _velocity;
    double _ratio;
    QString path;


public slots:
    void moveAnimation();

};



#endif // ACTORS_H

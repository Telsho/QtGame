#ifndef PINGUIN_H
#define PINGUIN_H
#include "ennemy.h"
#include <QObject>
#include <QWidget>

class Pinguin: public Ennemy
{
    Q_OBJECT
public:
    Pinguin(int hp, int velocity, int scoreReward, int numCoins, double ratio);
public slots:
    void pinguinMove();

private:
    bool _falling = false;
};

#endif // PINGUIN_H

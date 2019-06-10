#ifndef BIRD_H
#define BIRD_H
#include "ennemy.h"
#include <QObject>

class Bird:public Ennemy
{
    Q_OBJECT
public:
    Bird(int hp, int velocity, int scoreReward, int numCoins, double ratio);
};

#endif // BIRD_H

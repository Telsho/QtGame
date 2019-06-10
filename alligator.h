#ifndef ALLIGATOR_H
#define ALLIGATOR_H
#include "ennemy.h"


class Alligator: public Ennemy{
    Q_OBJECT

public:
    Alligator(int hp, int velocity, int scoreReward, int numCoins, double ratio);

public slots:
};

#endif // ALLIGATOR_H

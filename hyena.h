#ifndef HYENA_H
#define HYENA_H
#include "ennemy.h"

class Hyena: public Ennemy
{
    Q_OBJECT
public:
    Hyena(int hp, int velocity, int scoreReward, int numCoins, double ratio);


};

#endif // HYENA_H

#ifndef COIN_H
#define COIN_H
#include "actors.h"

class Coin: public Actors
{
    Q_OBJECT
public:
    Coin(int x,int y,int velocity = 1,int ratio = 0.1);
    Coin();

public slots:
    void moveCoins();
};

#endif // COIN_H

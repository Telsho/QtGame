#ifndef PLAYERBULLETS_H
#define PLAYERBULLETS_H
#include "actors.h"

class PlayerBullets: public Actors
{
    Q_OBJECT
public:
    PlayerBullets(int velocity, double ratio);
private slots:
    void bulletTravel();
};

#endif // PLAYERBULLETS_H

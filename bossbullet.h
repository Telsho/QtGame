#ifndef BOSSBULLET_H
#define BOSSBULLET_H
#include "actors.h"

class BossBullet: public Actors
{
    Q_OBJECT
public:
    BossBullet(int velocity, double ratio);
private slots:
    void bulletTravel();
};

#endif // BOSSBULLET_H

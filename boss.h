#ifndef BOSS_H
#define BOSS_H
#include "ennemy.h"

class Boss: public Ennemy
{
    Q_OBJECT
public:
    Boss(double ratio);
private:
    const QSize size = QSize(180,180);
    QString walkPath;
    QString deathPath;
    QString attackPath;
    QMovie * animation;
    int _frame = 0;
    void bossRoutine();
    void bossShoot();

private slots:
    void attackBoss();
    void move();
    void dead();
};

#endif // BOSS_H

#ifndef ENNEMY_H
#define ENNEMY_H
#include <QGraphicsPixmapItem>
#include "actors.h"
#include <QString>

using namespace std;

class Ennemy: public Actors{
    Q_OBJECT
public:
    Ennemy(int hp,int velocity,int scoreReward,int numCoins,double ratio);
    ~Ennemy();
    void damageTaken(int damage);
    void dropCoins();
    int getHp();
    int getCoins();
    int getScore();
    void dead();


private:
    int _hp;
    int _scoreReward;
    int _numCoins;
    int _frame = 0;


public slots:
    void attack();

};

inline int Ennemy::getHp(){return _hp;}
inline int Ennemy::getCoins(){return _numCoins;}
inline int Ennemy::getScore(){return _scoreReward;}

#endif // ENNEMY_H

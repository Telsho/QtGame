#ifndef PLAYER_H
#define PLAYER_H
#include "actors.h"
#include <QKeyEvent>
#include <QTimer>

class Player: public Actors
{
    Q_OBJECT
public:
    Player(int velocity, double ratio);
    Player();
    void keyPressEvent(QKeyEvent * event);
    void addCoin();
    void reduceHp();
    void augmentHp();
    int getHp();

private:

    int _ammoCapacity = 6;
    int _currentAmmo = 6;
    const QSize sizePlayer = QSize(200,200);
    QMovie * animation;
    bool _jumping = false;
    int _coins =0;
    int _hp=3;
protected:
    int _frame;


public slots:
    void shootJane();
    void jumpingJane();
    void startAnimation();
    void moveJane();
    void reload();

};

inline void Player::augmentHp(){_hp++;}
inline void Player::reduceHp(){_hp--;}
inline int Player::getHp(){return _hp;}

#endif // PLAYER_H

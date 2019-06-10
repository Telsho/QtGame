#ifndef AMMO_H
#define AMMO_H
#include <QGraphicsTextItem>

class Ammo: public QGraphicsTextItem
{
public:
    Ammo(QGraphicsItem * parent=0);
    void increaseCapacity();
    int getCurrentAmmo();
    void decreaseCurrentAmmo();
    void reload();
private:
    int _currentAmmo = 6;
    int _ammoCapacity = 6;
};
inline int Ammo::getCurrentAmmo(){return _currentAmmo;}
#endif // AMMO_H

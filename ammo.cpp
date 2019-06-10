#include "ammo.h"
#include <QFont>
#include <QString>

Ammo::Ammo(QGraphicsItem *parent)
{
    setPos(0,20);
    setPlainText(QString("Current ammo : ") + QString::number(_currentAmmo) + QString("      Ammo capacity : ") + QString::number(_ammoCapacity)) ;
    setDefaultTextColor((Qt::black));
    setFont(QFont("times",16));
}

void Ammo::increaseCapacity()
{
    _ammoCapacity++;
    setPlainText(QString("Current ammo : ") + QString::number(_currentAmmo) + QString("      Ammo capacity : ") + QString::number(_ammoCapacity)) ;
}

void Ammo::decreaseCurrentAmmo()
{
    _currentAmmo--;
    if(_currentAmmo >= 0){
        setPlainText(QString("Current ammo : ") + QString::number(_currentAmmo) + QString("      Ammo capacity : ") + QString::number(_ammoCapacity)) ;
    }
}

void Ammo::reload()
{
    _currentAmmo = _ammoCapacity;
    setPlainText(QString("Current ammo : ") + QString::number(_currentAmmo) + QString("      Ammo capacity : ") + QString::number(_ammoCapacity)) ;

}

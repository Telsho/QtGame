#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem
{
public:
    Health(QGraphicsItem * parent=0);
    void decrease();
    int getHealth();
private:
    int _hp = 3;
};

inline int Health::getHealth(){return _hp;}


#endif // HEALTH_H

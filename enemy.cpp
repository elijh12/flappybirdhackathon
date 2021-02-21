#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>

Enemy::Enemy()
{
    setRect(760,0,40,100);
    setRect(760, 500, 40, 100);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    setPos(x()+20,y());
    if(pos().x() < -10){
        scene()->removeItem(this);
        delete this;
    }
}

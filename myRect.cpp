#include "myRect.h"
#include "bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>

MyRect::MyRect()
{
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer->start(25);
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space){
        setPos(x(),y()-200);
    }
    /*else if (event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space){
        Bullet* bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }*/
}

void MyRect::move()
{
    setPos(x(),y()+10);
    if(pos().y() < 0 || pos().y() > 550){
        scene()->removeItem(this);
        delete this;
    }
}

void MyRect::spawnTube()
{

}

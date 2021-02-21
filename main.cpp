#include "mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "myRect.h"
#include <QApplication>
#include <QKeyEvent>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();
    MyRect * player = new MyRect();

    player->setRect(0,0,50,50);

    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800,600);
    view->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2,view->height()/2);

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawnTube()));

    //MainWindow w;
    //w.show();
    return a.exec();
}

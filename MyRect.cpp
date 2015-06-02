#include "MyRect.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "MyBullet.h"
#include <QDebug>
#include "MyEnemy.h"

MyRect::MyRect(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    QPixmap player(":/images/rsz_olaf_from_disneys_frozen_1.png");
    setPixmap(player);
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    /*if(event->key() == Qt :: Key_Left){
        if(pos().x()>0)
        setPos(x()-20,y());
    }
    else if (event->key() == Qt :: Key_Right){
        if(pos().x() +100 < 800)
        setPos(x()+20, y());
    }*/
    if (event->key() == Qt :: Key_Up){
        setPos(x(), y()-20);
    }
    else if (event->key() == Qt :: Key_Down){
            setPos(x(), y()+20);
    }
    else if (event->key() == Qt :: Key_Space){
        //Create a Bullet
        MyBullet * bullet = new MyBullet();
        bullet->setPos(x(),y()+50);
        //qDebug() << "hahaha";
        scene()->addItem(bullet);
    }
}

void MyRect::spawn()
{
    //create an enemy
MyEnemy * enemy = new MyEnemy();
scene()->addItem(enemy);
}

#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "MyEnemy.h"
#include "MyRect.h"
#include "MyBullet.h"

/**
 * @brief MyRect::MyRect
 * This is the function that will keep track of our player
 * @param parent
 * This states that it is a QGraphicsItem Object
 */
MyRect::MyRect(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    QPixmap player(":/images/rsz_olaf_from_disneys_frozen_1.png");
    setPixmap(player);
}

/**
 * @brief MyRect::keyPressEvent
 * This is the function that will help us to be able to control our player by pressing the keys (up and down)
 * Also, it sets up the space key so that we can shoot the enemy with a snowball
 * @param event
 */
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
        if(pos().y()>0)
        setPos(x(), y()-20);
    }
    else if (event->key() == Qt :: Key_Down){
        if(pos().y()<400)
            setPos(x(), y()+20);
    }
    else if (event->key() == Qt :: Key_Space){
        //Create a Bullet
        MyBullet * bullet = new MyBullet();
        bullet->setPos(x(),y()+55);
        scene()->addItem(bullet);
    }
}

/**
 * @brief MyRect::spawn
 * This is the function that will help us to create the enemy
 */
void MyRect::spawn()
{
    //Create an enemy and add it to the scene
    MyEnemy * enemy = new MyEnemy();
    scene()->addItem(enemy);
}

#include "MyBullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "MyEnemy.h"
#include "MyScore.h"
#include "Game.h"

extern Game* game;

MyBullet::MyBullet(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent)
{
    // draw the rect


    // draw the image
    setPixmap(QPixmap(":/images/rsz_snowball.png"));


    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void MyBullet::move()
{
    // if collides, destroy
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for (size_t i =0, n = colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i]))==typeid(MyEnemy)){
            // increase the score
            game->score->increase();

            scene() -> removeItem(colliding_items[i]);
            scene() -> removeItem(this);

            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // move bullets up
    setPos(x()-10,y());
    if(pos().y()< 0){
        scene()->removeItem(this);
        delete this;
    }
}

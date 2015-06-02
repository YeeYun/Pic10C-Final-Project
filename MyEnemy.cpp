#include "MyEnemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "Game.h"

extern Game* game;
int health = 3;

MyEnemy::MyEnemy():QObject(),QGraphicsPixmapItem()
{
    int random_number = rand() % 700;
    setPos(0,random_number);

    // draw the rect
    //setRect(0,0,100,100);

    QPixmap enemy (":/images/rsz_marshmallow.png");
    setPixmap(enemy);
   // QPixmap::size(100,100);

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void MyEnemy::move()
{
    setPos(x()+5,y());
    if(pos().x() >700){
        // decrease the score
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}


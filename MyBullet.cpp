#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "MyEnemy.h"
#include "MyScore.h"
#include "Game.h"
#include "MyBullet.h"

//This is to help us to create a "Global" variable of a pointer to Game
extern Game* game;


/**
 * @brief MyBullet::MyBullet
 * This is the function that will help to draw the bullet
 * @param parent
 * This is just an indicator that we are using QGraphicsItem for this bullet object
 */
MyBullet::MyBullet(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent)
{
    //Draw the bullet image
    setPixmap(QPixmap(":/images/rsz_snowball.png"));

    //This is to connect the timer with the movements of the bullets
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

/**
 * @brief MyBullet::move
 * This is the function that we use to write the functionality of our bullet
 * When the bullet collides with the enemy, we will be able increase the score by one
 * Also, after collision, the bullet and the collided enemy will both be deleted
 */
void MyBullet::move()
{
    //If the bullet did collide with the enemy, destroy it
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for (size_t i =0, n = colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i]))==typeid(MyEnemy)){

            //Increase the score
            game->score->increase();

            //Remove both the bullets and the enemy
            scene() -> removeItem(colliding_items[i]);
            scene() -> removeItem(this);

            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //This is to monitor the bullet's movement to the right
    //Also, when the bullet went out of the screen, it will also be removed and deleted
    setPos(x()-10,y());
    if(pos().y()< 0){
        scene()->removeItem(this);
        delete this;
    }
}

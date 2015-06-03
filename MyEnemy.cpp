#include "MyEnemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "Game.h"
#include <QPushButton>
extern Game* game;


unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator (seed);

MyEnemy::MyEnemy():QObject(),QGraphicsPixmapItem()
{
    std::uniform_int_distribution<int> distribution(0,470);
    int random_number = distribution(generator);
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
    if(pos().x() >1000){
        // decrease the score
        game->health->decrease();
        //int a = game->health->getHealth() ;
        //a--;
        //qDebug()<<game->health->getHealth();
        scene()->removeItem(this);
        delete this;
        if (game->health->getHealth()<0){
            //qDebug()<<"lost";
            game->scene->clear();
            QGraphicsTextItem* overText = new QGraphicsTextItem("Sorry, You lost >_<");
            overText->setFont(QFont("Comic Sans MS",20,QFont::Bold));
            overText->setPos(350, 250);
            game->scene->addItem(overText);

            QPushButton* quit1 = new QPushButton("Quit");
            quit1->resize(100,70);
            quit1->move(overText->x(),overText->y()+50);
            //QFont newFont("Courier", 20, QFont::Bold, true);
            //quit1->setFont(newFont);
            quit1->setStyleSheet("border-style: outset; border-width: 2px; border-radius: 10px; border-color: beige; font: bold 14px;min-width: 10em; padding: 6px");
            game->scene->addWidget(quit1);
            QObject::connect(quit1,SIGNAL(clicked()),game,SLOT(close()));

            //game->scene->removeItem(game->player);

            //game->scene->removeItem(game->);
            /*for (size_t i = 0, n = scene()->items().size(); i < n; i++){
                scene()->items()[i]->setEnabled(false);
            }*/
          //qDebug()<<getHealth();
        }
    }
}


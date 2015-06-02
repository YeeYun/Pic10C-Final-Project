#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>
#include <QTimer>
#include "MyScore.h"
#include "Game.h"
#include <QImage>
#include <QPushButton>
//#include "Button.h"
#include <QGraphicsTextItem>
#include <QGraphicsProxyWidget>
#include <QFont>
#include <QDebug>



Game::Game()
{
    //life = 3;

    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,900);
    QImage back (":/images/rsz_frozen1.jpg");
    setBackgroundBrush(QBrush(back));

    setFixedSize(800,900);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    player = new MyRect();
    //player->setRect(0,0,100,100);
    player->setPos(scene->width()-200,250);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene -> addItem(player);



    //player->setPos(view->width()/2, view->height()-player->rect().height());

    // Score
    score = new MyScore();
    scene->addItem(score);

    health = new MyHealth();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);




    QGraphicsTextItem* instruction = new QGraphicsTextItem("Instructions: \n 1. shoot the snow at your enemy. \n 2. You will win a point when you kill one enemy. \n 3. You will lose a life if your enemy gets out safely. \n 4. You can move your player by pressing left and right key. \n 5. Press the space key to destroy your enemy.");
    instruction -> setPos(health->x(), health->y()+50);
    scene->addItem(instruction);

    //QGraphicsProxyWidget* quit = new QGraphicsProxyWidget();
    //scene->addItem(quit);

    QPushButton* quit1 = new QPushButton("Quit");
    quit1->resize(100,70);
    quit1->move(scene->width()-770,550);
    QFont newFont("Courier", 20, QFont::Bold, true);
    quit1->setFont(newFont);
    quit1->setStyleSheet("border-style: outset; border-width: 2px; border-radius: 10px; border-color: beige; font: bold 14px;min-width: 10em; padding: 6px");
    scene->addWidget(quit1);
    QObject::connect(quit1,SIGNAL(clicked()),this,SLOT(close()));


    // spawn enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

   // if (health->getHealth()<4){
        //gameover();
     //qDebug()<<this->health->getHealth();
    //}
}


void Game::gameover()
{
    scene->clear();

    for (size_t i = 0, n = scene->items().size(); i < n; i++){
        scene->items()[i]->setEnabled(false);
    }



    QGraphicsTextItem* overText = new QGraphicsTextItem("You lost");
    overText->setPos(0,0);
    scene->addItem(overText);
}

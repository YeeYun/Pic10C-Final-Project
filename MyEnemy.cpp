#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include <QPushButton>
#include "Game.h"
#include "MyEnemy.h"

//This is to help us to create a "Global" variable of a pointer to Game
extern Game* game;

//The following two lines used the c++ 11 standard to randomly generate the number
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator (seed);

/**
 * @brief MyEnemy::MyEnemy
 * This is the function that will help us to generate the enemy
 */
MyEnemy::MyEnemy():QObject(),QGraphicsPixmapItem()
{
    //The following lines will generate the random number, which wil determine the position of the enemy
    std::uniform_int_distribution<int> distribution(0,450);
    int random_number = distribution(generator);
    setPos(0,random_number);

    QPixmap enemy (":/images/rsz_marshmallow.png");
    setPixmap(enemy);

    //Connect the time with the movement of the enemy
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

/**
 * @brief MyEnemy::move
 * This is the move function that will move the enemy to the right
 * when the enemy gets out of the screen, the life will decrease one, and the enemy will be removed
 * when the life is smaller than 0,
 */
void MyEnemy::move()
{
    setPos(x()+5,y());
    if(pos().x() >950){
        //Decrease the life
        game->health->decrease();

        //It will remove the enemy and will delete the enemy
        scene()->removeItem(this);
        delete this;

        //If the life is smaller than 0, then, the scene will get cleared and the window will prompt the message saying the user lost, and offers the option to quit the game.
        if (game->health->getHealth()<0){

            //Clear the scene
            game->scene->clear();

            //Prompt the user the Text "You Lost"
            QGraphicsTextItem* overText = new QGraphicsTextItem("Sorry, You lost >_<");
            overText->setFont(QFont("Comic Sans MS",20,QFont::Bold));
            overText->setPos(400, 250);
            overText->setDefaultTextColor("white");
            game->scene->addItem(overText);

            //Prompt the user the PushButton to quit the game
            QPushButton* quit1 = new QPushButton("Quit");
            quit1->resize(60,50);
            quit1->move(overText->x(),overText->y()+50);
            quit1->setStyleSheet("border-style: outset; border-width: 2px; border-radius: 10px; border-color: beige; font: bold 14px;min-width: 10em; padding: 6px");
            game->scene->addWidget(quit1);
            QObject::connect(quit1,SIGNAL(clicked()),game,SLOT(close()));

        }
    }
}


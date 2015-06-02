#include "MyHealth.h"
#include <QFont>
#include <QDebug>
#include "Game.h"

int MyHealth::health1 = 3;
extern Game* game;
MyHealth::MyHealth(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //initialize the health to 3
    //health1 = 3;

    // draw the text
    setPlainText(QString("Lives: ") + QString::number(health1));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",30));
}

void MyHealth::decrease()
{
    --health1;
    setPlainText(QString("Lives: ") + QString::number(health1));
    //qDebug()<< health1;
}

int MyHealth::getHealth()
{
    return health1;
    //qDebug()<< health1;
}


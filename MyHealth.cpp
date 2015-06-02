#include "MyHealth.h"
#include <QFont>

MyHealth::MyHealth(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //initialize the health to 3
    health = 3;

    // draw the text
    setPlainText(QString("Lives: ") + QString::number(health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",30));
}

void MyHealth::decrease()
{
    health--;
    setPlainText(QString("Lives: ") + QString::number(health));


}

int MyHealth::getHealth()
{
    return health;
}


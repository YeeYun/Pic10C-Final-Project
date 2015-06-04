#include <QFont>
#include <QDebug>
#include "Game.h"
#include "MyHealth.h"

//Initiate the static int varialbe health1
int MyHealth::health1 = 3;

//This is to help us to create a "Global" variable of a pointer to Game
extern Game* game;

/**
 * @brief MyHealth::MyHealth
 * This is the function that will be used to keep track of the life of the player
 * @param parent
 * This states that it is a QGraphicsItem.
 */
MyHealth::MyHealth(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //This will help us draw the Text onto the scene
    setPlainText(QString("Lives: ") + QString::number(health1));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",30));
}

/**
 * @brief MyHealth::decrease
 * This is the function that will decrease the life
 * Also, whenever the life is decreased, the message that is on the scene will also get updated
 */
void MyHealth::decrease()
{
    --health1;
    setPlainText(QString("Lives: ") + QString::number(health1));
}

/**
 * @brief MyHealth::getHealth
 * This is the get function that will help us to retrieve the data of the private variable health1
 * @return the number of the life
 */
int MyHealth::getHealth()
{
    return health1;
}


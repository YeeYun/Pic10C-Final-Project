#include "MyScore.h"
#include <QFont>

/**
 * @brief MyScore::MyScore
 * This is the function that will help us to keep track of the score
 * @param parent
 * This states that it is a QGraphicsItem Object
 */
MyScore::MyScore(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //Initialize the score to 0
    score = 0;

    //Draw the text onto the screen
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",30));
}


/**
 * @brief MyScore::increase
 * This is the helper function that will help us to increase the score when an enemy is killed
 * Also, when the score is increased, the text on the scene will also get updated
 */
void MyScore::increase()
{
    ++ score;
    setPlainText(QString("Score: ") + QString::number(score));
}

/**
 * @brief MyScore::getScore
 * This is the get function that will help us to get the data of the score
 * @return the data of the score.
 */
int MyScore::getScore()
{
    return score;
}

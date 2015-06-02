#include "MyScore.h"
#include <QFont>

MyScore::MyScore(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",30));
}

void MyScore::increase()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}

int MyScore::getScore()
{
    return score;
}

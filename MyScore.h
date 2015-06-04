#ifndef MYSCORE_H
#define MYSCORE_H

#include <QGraphicsTextItem>

class MyScore:public QGraphicsTextItem{
public:
    MyScore(QGraphicsItem* parent = 0);
    void increase ();
    int getScore();
private:
    int score;
};


#endif // MYSCORE_H

#ifndef MYHEALTH_H
#define MYHEALTH_H
#include <QGraphicsTextItem>

class MyHealth:public QGraphicsTextItem{

public:
    MyHealth(QGraphicsItem* parent = 0);
    void decrease ();
    int getHealth();
private:
    int health;
};


#endif // MYHEALTH_H

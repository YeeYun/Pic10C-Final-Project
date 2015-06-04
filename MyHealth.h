#ifndef MYHEALTH_H
#define MYHEALTH_H

#include <QGraphicsTextItem>

class MyHealth:public QGraphicsTextItem{

public:
    MyHealth(QGraphicsItem* parent = 0);
    void decrease ();
    int getHealth();
private:
    static int health1;
};


#endif // MYHEALTH_H

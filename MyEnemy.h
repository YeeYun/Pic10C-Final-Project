#ifndef MYENEMY_H
#define MYENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class MyEnemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    MyEnemy();
public slots:
    void move();
};

#endif // MYENEMY_H

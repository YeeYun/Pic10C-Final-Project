#ifndef MYBULLET_H
#define MYBULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class MyBullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    MyBullet(QGraphicsItem* parent=0);
public slots:
    void move();
};

#endif // MYBULLET_H

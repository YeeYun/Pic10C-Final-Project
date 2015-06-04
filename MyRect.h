#ifndef MYRECT_H
#define MYRECT_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>


class MyRect : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    MyRect(QGraphicsItem* parent=0);
    void keyPressEvent(QKeyEvent* event);
public slots:
    void spawn();
};

#endif // MYRECT_H

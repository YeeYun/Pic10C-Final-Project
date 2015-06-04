#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "MyScore.h"
#include "MyHealth.h"
#include "MyEnemy.h"
#include "MyBullet.h"
#include "MyRect.h"

class Game:public QGraphicsView{
    Q_OBJECT
friend class mainwindow;
public:
    Game();
    QGraphicsScene * scene;
    MyRect* player;
    MyScore * score;
    MyHealth * health;
public slots:
    void mainPage();
    void start();
    void instructions();

};

#endif // GAME_H

#ifndef GAME_H
#define GAME_H
#include <QMainWindow>
#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>
#include <QTimer>
#include "MyScore.h"
#include "MyHealth.h"
#include "MyEnemy.h"
#include "MyBullet.h"

class Game:public QGraphicsView{
    Q_OBJECT
friend class mainwindow;
public:
    Game();
    QGraphicsScene * scene;
    MyRect* player;
    MyScore * score;
    MyHealth * health;
    void gameover();

    //void displayMainMenu();
//public slots:
    //void start();
//private:
  //  void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
  //  void drawGui();
};

#endif // GAME_H

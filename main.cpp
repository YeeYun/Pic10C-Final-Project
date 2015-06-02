#include <QApplication>
#include "Game.h"
//#include "mainwindow.h"

Game * game;

int main(int argc, char*argv[]){
   QApplication a (argc, argv);

   //MainWindow w;
   //w.show();

    game = new Game();
    game->show();
   //game->displayMainMenu();

   return a.exec();
}

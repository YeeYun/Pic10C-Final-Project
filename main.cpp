#include <QApplication>
#include "Game.h"

Game * game;

/**
 * @brief main
 * This is the function that the complie will use
 * This will create the game
 * @param argc
 * @param argv
 * @return
 * It will retrun the scene that we create in the game
 */
int main(int argc, char*argv[]){
   QApplication a (argc, argv);

    game = new Game();
    game->show();

   return a.exec();
}

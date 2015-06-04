#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QImage>
#include <QPushButton>
#include <QGraphicsTextItem>
#include <QGraphicsProxyWidget>
#include <QFont>
#include <QDebug>
#include "MyScore.h"
#include "Game.h"
#include "MyRect.h"

/**
 * @brief Game::Game
 * This is the Game function that will prompt the users the first page of the game with the choices of playing and of reading the instructions.
 */
Game::Game(){
    //Create a new Scene that will have size 1000*600
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,600);
    QImage back (":/images/rsz_frozen-background-images.jpg");
    setBackgroundBrush(QBrush(back));

    setFixedSize(1000,600);

    //This will disable the scroll bars in the window
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //This will show the users the text "Welcome to the Frozen World"
    QGraphicsTextItem* startText = new QGraphicsTextItem("Welcome to the Frozen World!");
    startText->setFont(QFont("Comic Sans MS",30,QFont::Bold));
    startText->setDefaultTextColor("white");
    startText->setPos(280, 200);
    scene->addItem(startText);

    //This is a PushButton that will allow the users to start to play the game
    QPushButton* start = new QPushButton("Play");
    start->resize(60,50);
    start->move(400,startText->y()+100);
    start->setStyleSheet("border-style: outset; border-width: 2px; border-radius: 15px; border-color: blue; font: bold 14px;min-width: 10em; padding: 6px");
    scene->addWidget(start);
    QObject::connect(start,SIGNAL(clicked()),this,SLOT(start()));

    //This is a PushButton that will allow the users to read the instruction
    QPushButton* instruction = new QPushButton("Instruction");
    instruction->resize(60,50);
    instruction->move(400,startText->y()+160);
    instruction->setStyleSheet("border-style: outset; border-width: 2px; border-radius: 15px; border-color: blue; font: bold 14px;min-width: 10em;padding: 6px");
    scene->addWidget(instruction);
    QObject::connect(instruction,SIGNAL(clicked()),this,SLOT(instructions()));
}

/**
 * @brief Game::mainPage
 * This is another function that has the similar funtionaliaty as the Game()
 * This function will allow the users to be able to go back to the mainPage
 */
void Game::mainPage(){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,600);
    QImage back (":/images/rsz_frozen-background-images.jpg");
    setBackgroundBrush(QBrush(back));

    setFixedSize(1000,600);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QGraphicsTextItem* startText = new QGraphicsTextItem("Welcome to the Frozen World!");
    startText->setFont(QFont("Comic Sans MS",30,QFont::Bold));
    startText->setDefaultTextColor("white");
    startText->setPos(280, 200);
    scene->addItem(startText);

    QPushButton* start = new QPushButton("Play");
    start->resize(60,50);
    start->move(400,startText->y()+100);
    start->setStyleSheet("border-style: outset; border-width: 2px; border-radius: 15px; border-color: blue; font: bold 14px;min-width: 10em; padding: 6px");
    scene->addWidget(start);
    QObject::connect(start,SIGNAL(clicked()),this,SLOT(start()));

    QPushButton* instruction = new QPushButton("Instruction");
    instruction->resize(60,50);
    instruction->move(400,startText->y()+160);
    instruction->setStyleSheet("border-style: outset; border-width: 2px; border-radius: 15px; border-color: blue; font: bold 14px;min-width: 10em;padding: 6px");
    scene->addWidget(instruction);
    QObject::connect(instruction,SIGNAL(clicked()),this,SLOT(instructions()));
}

/**
 * @brief Game::instructions
 * This is the function that when users clicked the instructions button in the mainPage, it would prompt the instructions of the game
 * On this page, the users can read the instructions, and also have the choice to play or go back to the main page
 */
void Game::instructions(){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,600);
    QImage back (":/images/rsz_frozen-background-images.jpg");
    setBackgroundBrush(QBrush(back));

    setFixedSize(1000,600);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QGraphicsTextItem* instruction = new QGraphicsTextItem("Instructions: \n 1. shoot the snow at your enemy. \n 2. You will win a point when you kill one enemy. \n 3. You will lose a life if your enemy gets out safely. \n 4. You can move your player by pressing up and down key. \n 5. Press the space key to create a snowball that can destroy the enemy.");
    instruction -> setPos(250,170);
    instruction -> setDefaultTextColor("white");
    instruction ->setFont(QFont("Comic Sans MS",16));
    scene->addItem(instruction);

    QPushButton* playnow = new QPushButton("Play Now");
    playnow->setStyleSheet("border-style: outset; border-width: 2px; border-radius: 20px; border-color: blue; font: bold 14px;min-width: 10em; padding: 6px");
    playnow->resize(60,50);
    playnow->move(300,400);
    scene->addWidget(playnow);
    QObject::connect(playnow,SIGNAL(clicked()),this,SLOT(start()));

    QPushButton* Goback = new QPushButton("Main Page");
    Goback->setStyleSheet("border-style: outset; border-width: 2px; border-radius: 20px; border-color: blue; font: bold 14px;min-width: 10em; padding: 6px");
    Goback->resize(60,50);
    Goback->move(500,400);
    scene->addWidget(Goback);
    QObject::connect(Goback,SIGNAL(clicked()),this,SLOT(mainPage()));
}


/**
 * @brief Game::start
 * This function will start the game for the users
 */
void Game:: start()
{
    //life = 3;

    //Create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,600);
    QImage back (":/images/rsz_1frozen.jpg");
    setBackgroundBrush(QBrush(back));

    setFixedSize(1000,600);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Create the player, and place it onto the scene
    player = new MyRect();
    player->setPos(scene->width()-200,200);

    //These two functions will allow us to focus on the player and to use the keyPressEvent
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene -> addItem(player);



    //Create the Score bar
    score = new MyScore();
    scene->addItem(score);

    //Create the Life bar
    health = new MyHealth();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    //Create the quite button which will allow the users to quit the game whenever they want to
    QPushButton* quit1 = new QPushButton("Quit");
    quit1->resize(60,50);
    quit1->move(scene->width()-975,545);
    QFont newFont("Courier", 20, QFont::Bold, true);
    quit1->setFont(newFont);
    quit1->setStyleSheet("border-style: outset; border-width: 2px; border-radius: 20px; border-color: blue; font: bold 14px;min-width: 10em; padding: 6px");
    scene->addWidget(quit1);
    QObject::connect(quit1,SIGNAL(clicked()),this,SLOT(close()));

    //Create the going back button which will allow the users to go back to the main page
    QPushButton* Goback = new QPushButton("Main Page");
    Goback->setStyleSheet("border-style: outset; border-width: 2px; border-radius: 20px; border-color: blue; font: bold 14px;min-width: 10em; padding: 6px");
    Goback->resize(60,50);
    Goback->move(quit1->x()+200,quit1->y());
    scene->addWidget(Goback);
    QObject::connect(Goback,SIGNAL(clicked()),this,SLOT(mainPage()));


    // spawn enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);
}




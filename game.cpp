#include "game.h"
#include <QMovie>
#include "boss.h"
#include "button.h"

Game::Game(QWidget *parent)
{

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,480);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,480);
    scene->setBackgroundBrush(QBrush(QImage(":/images/BackGround2.png")));
    setScene(scene);

}

void Game::displayMenu()
{
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Jeu de la mort qui tue"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

    QGraphicsTextItem * text = new QGraphicsTextItem();
    text->setPos(200,0);
    text->setPlainText(QString("R -> Recharger \nESPACE -> Sauter \nA -> Tirer"));
    text->setDefaultTextColor((Qt::black));
    text->setFont(QFont("times",30));
    scene->addItem(text);
}

void Game::start()
{
    scene->clear();
    Boss * boss = new Boss(2);
    boss->setFocus();



    scene->setBackgroundBrush(QBrush(QImage(":/images/BackGround2.png")));

    player = new Player(1,0.1);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    scene->addItem(health);

    ammo = new Ammo();
    scene->addItem(ammo);

    controller = new Controller();
    scene->addItem(controller);


    show();
}

void Game::gameOver(){
    for (size_t i = 0, n = scene->items().size(); i < n; i++){
        scene->items()[i]->setEnabled(false);
    }

    delete controller;
    delete player;
    delete health;
    delete score;
    delete ammo;

    Button* playAgain = new Button(QString("Play Again"));
    playAgain->setPos(410,300);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(start()));

    Button* quit = new Button(QString("Quit"));
    quit->setPos(410,375);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));


}


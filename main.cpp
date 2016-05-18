#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include<QGraphicsRectItem>
#include <QApplication>
#include"Body.h"
#include "Board.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene();


   QGraphicsView *view = new QGraphicsView(scene);
   view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



   Body *body = new Body();


   view->setFixedSize(500,500);
   scene->setSceneRect(0,0,500,500);

   Board *board = new Board(10,10);
   body->setRect(0,0,50,50);
   board->setWindow_H_W(scene);
   board->putOnBoard(body);


    scene->addItem(body);
   // Show the picutre
   view->show();
    return a.exec();
}

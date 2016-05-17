#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include<QGraphicsRectItem>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene();


   QGraphicsView *view = new QGraphicsView(scene);
   view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



   QGraphicsRectItem *rect = new QGraphicsRectItem();
   rect->setRect(0,0,400,400);



   scene->addItem(rect);

   view->setFixedSize(800,600);
   scene->setSceneRect(0,0,800,600);

   // Show the picutre
   view->show();
    return a.exec();
}

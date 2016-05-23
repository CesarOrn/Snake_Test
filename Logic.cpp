#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include<QGraphicsRectItem>
#include <QApplication>
#include <QTimer>
#include"logic.h"
#include <QObject>
#include<QDebug>
#include<QList>

Logic::Logic(){
start =1;
 scene = new QGraphicsScene();


view = new QGraphicsView(scene);
view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



body = new Body();



view->setFixedSize(500,500);
scene->setSceneRect(0,0,500,500);

board = new Board(100,100,scene);
body->setRect(0,0,5,5);

board->getScene(scene);
board->spawnFood();
body->setLastX(0);
body->setLastY(-5);
scene->addItem(body);
allBody= new Body*[500*500];



// Show the picutre
view->show();
body->setFlag(Body::ItemIsFocusable);//not focuse yet but abllity
body->setFocus();
body->setIncrament(board->getBoardH(),board->getBoardW());
allBody[0]=body;
numBody=0;
numBody++;
timer = new QTimer();
QObject::connect(timer,SIGNAL(timeout()),body,SLOT(goforward()));
timer->start(50);
}

void Logic::addBody()
{

    allBody[start]= new Body();
    allBody[start]->setRect(0,0,5,5);

    allBody[start]->setPos(allBody[start-1]->getLastX(),allBody[start-1]->getLastY());
    allBody[start]->setLastX(allBody[start]->x()-(allBody[start-1]->x()-allBody[start]->x()));
     allBody[start]->setLastY(allBody[start]->y()-(allBody[start-1]->y()-allBody[start]->y()));
     scene->addItem(allBody[start]);
    start++;
}

void Logic::upDateBack()
{
    int i =1;
    while(i<start){
        qDebug()<<start;
        qDebug()<<i;
        allBody[i]->setLastX(allBody[i]->x());
        allBody[i]->setLastY(allBody[i]->y());
        allBody[i]->setPos(allBody[i-1]->getLastX(),allBody[i-1]->getLastY());
    i++;
    }

}

void Logic::gameOver()
{
    for(int i = 0; i<250000&& i<start;i++){
        scene->removeItem(allBody[i]);
        delete(allBody[i]);
    }

}

void Logic::hitDetection()
{
    QList <QGraphicsItem *> colliding_items = body->collidingItems();
    for(int i = 0 , n= colliding_items.size();i<n;i++){
        if(typeid(*colliding_items[i])==typeid(Food)){
            qDebug()<< "hit food";
           allBody[0]->scene()->removeItem(colliding_items[i]);
            board->spawnFood();
            addBody();
            delete(colliding_items[i]);
        }else if (typeid(*colliding_items[i])==typeid(Body)){
            timer->stop();
            gameOver();
            return;
        }
    }

}



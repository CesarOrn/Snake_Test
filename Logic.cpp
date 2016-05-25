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
#include "mt.h"
#include"Food.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>


Logic::Logic(){
start =1;
 scene = new QGraphicsScene();

myrand = new MersenneTwister();



view = new QGraphicsView(scene);
view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



body = new Body();



view->setFixedSize(500,500);
scene->setSceneRect(0,0,500,500);

board = new Board(100,100,scene);
body->setRect(0,0,5,5);

board->getScene(scene);
spawnFood();
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
    allBody[start]->setLastX(0);
     allBody[start]->setLastY(0);
     scene->addItem(allBody[start]);
    start++;
}

void Logic::upDateBack()
{
    int i =1;

    while(i<start){
        //qDebug()<<start;
        //qDebug()<<i;


        allBody[i]->setLastX(allBody[i]->x());
        allBody[i]->setLastY(allBody[i]->y());
        allBody[i]->setPos(allBody[i-1]->getLastX(),allBody[i-1]->getLastY());
    i++;
    }

}

void Logic::gameOver()
{
    // deletes objects be removing the scene
    for(int i = 0; i<250000&& i<start;i++){

        scene->removeItem(allBody[i]);
        delete(allBody[i]);

    }

}

void Logic::hitDetection()
{
    QList <QGraphicsItem *> colliding_items = body->collidingItems();
    for(int i = 0 , n= colliding_items.size();i<n;i++){
        if(typeid(*colliding_items[i])==typeid(Food)&&colliding_items[i]->x()!=allBody[0]->x()
                &&colliding_items[i]->y()!=allBody[0]->y()){
            qDebug()<< "hit food";
           allBody[0]->scene()->removeItem(colliding_items[i]);
            spawnFood();
            addBody();
            delete(colliding_items[i]);
        }else if (typeid(*colliding_items[i])==typeid(Body)&&colliding_items[i]->x()==allBody[0]->x()
                  && colliding_items[i]->y()==allBody[0]->y()){
            timer->stop();
            gameOver();
            return;
        }
     }
       if (allBody[0]->x()<0 ||allBody[0]->x()>490||
           allBody[0]->y()<0 || allBody[0]->y()>490){

        gameOver();
        }
}

int Logic::calculateInFrontX(int first, int last)
{
    return (allBody[first]->x()-allBody[last]->x())/5;
}

int Logic::calculateInFrontY(int first, int last)
{
    return (allBody[first]->y()-allBody[last]->y())/5;
}

void Logic::msleep(unsigned long msecs)
{
    QThread::msleep(msecs);
}

unsigned long Logic::getRand()
{
    return myrand->genrand_int32();

}

void Logic::spawnFood()
{

    qDebug()<<"started";
    int x;
    int y;

    Food *food = new Food();
    srand(time(NULL));
    x=rand();
    srand(time(NULL));
    y=rand();
    food->setRect(0,0,5,5);
    food->setPos((x*5)%490,(y*5)%490);
    qDebug()<<food->x();
    qDebug()<<food->y();


    //qDebug()<<"hello";
    scene->addItem(food);
}



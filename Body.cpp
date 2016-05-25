#include "Body.h"
#include <QList>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

#include"logic.h"

extern Logic *logic; //external gobale


Body::Body()
{
    this->yDir=1;
    this->xDir=0;
}

void Body::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if(xDir!=1){
            yDir=0;
            xDir=-1;
        }
    }
    else if (event->key() == Qt::Key_Right){
        if(xDir!=-1){
            yDir=0;
            xDir=1;
        }
    }
    else if(event->key()==Qt::Key_Up){
        //qDebug()<<"hit up";
        if(yDir!=1){
            yDir=-1;
            xDir=0;
        }
    }
    else if(event->key()==Qt::Key_Down){
        if(yDir!=-1){
            yDir=1;
            xDir=0;
        }
    }
}

void Body::setIncrament(int h, int w)
{
    this->yInc=h;
    this->xInc=w;
}

void Body::setLastX(int x)
{
    lPosX=x;
}

void Body::setLastY(int y)
{
    lPosY=y;
}

int Body::getLastX()
{
    return lPosX;
}

int Body::getLastY()
{
    return lPosY;
}

void Body::goforward()
{
    lPosX=this->x();
    lPosY=this->y();
    //qDebug()<<lPosX;
    //qDebug()<<lPosY;
    this->setPos(x()+(xDir*xInc),y()+(yDir*yInc));
    logic->upDateBack();
    //colliding_items = collidingItems();
    logic->hitDetection();


}


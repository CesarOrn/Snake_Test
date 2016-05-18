#include "Board.h"
#include "Body.h"
#include <QGraphicsScene>
#include <QDebug>


Board::Board(int hight,int width)
{
    this->hight= hight;
    this->width= width;


}

void Board::putOnBoard(Body *body)
{

    body->setPos(windWidth*(body->xpos),windHight*(body->ypos));
    qDebug()<<(body->ypos);

}

void Board::setWindow_H_W(QGraphicsScene *scene)
{
    //set incrament for x and y
    //when mulitpying where body is at

    this->windHight= scene->height()/hight;
    qDebug()<<(windHight);
    this->windWidth= scene->width()/width;
    qDebug()<<(windWidth);
}



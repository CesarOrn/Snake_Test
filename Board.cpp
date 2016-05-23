#include "Board.h"
#include <QGraphicsScene>
#include <QDebug>
#include "Food.h"
#include <stdlib.h>
#include <QGraphicsScene>



Board::Board(int boardH, int boardW, QGraphicsScene*scean){

    this->BoardH=scean->height()/boardH;
    this->BoardW=scean->width()/boardW;

}

int Board::getBoardH()
{
    return this->BoardH;
}

int Board::getBoardW()
{
    return this->BoardW;
}

void Board::getScene(QGraphicsScene *scene){
    this->scene =scene;
}

void Board::spawnFood()
{
    Food *food = new Food();
    food->setRect(0,0,5,5);
    food->setPos(rand()%500,rand()%500);
    //qDebug()<<"hello";
    scene->addItem(food);
}





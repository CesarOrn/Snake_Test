#include "Board.h"
#include <QGraphicsScene>
#include <QDebug>
#include "Food.h"
#include <stdlib.h>
#include <QGraphicsScene>
#include "Logic.h"

extern Logic *logic;


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







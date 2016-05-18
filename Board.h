#ifndef BOARD_H
#define BOARD_H
#include<QGraphicsScene>
#include"Body.h"


class Board{
    
public:
    Board(int hight,int width);

    void putOnBoard(Body *body);

    void setWindow_H_W(QGraphicsScene *scene);

    Body *gameBoard;


    
    
private:
    int hight;
    int width;
    int windHight;
    int windWidth;



    
};

#endif // BOARD_H

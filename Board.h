#ifndef BOARD_H
#define BOARD_H

#include<QGraphicsScene>


class Board{
    
public:
    Board(int boardH,int boardW, QGraphicsScene*scean);

    int getBoardH();
    int getBoardW();


    void getScene(QGraphicsScene *scene);

    void spawnFood();


private:
    QGraphicsScene *scene;
    int BoardH;
    int BoardW;


};
#endif // BOARD_H

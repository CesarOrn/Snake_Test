#ifndef LOGIC_H
#define LOGIC_H
#include<QGraphicsScene>
#include"food.h"
#include <QGraphicsView>
#include"Body.h"
#include "Board.h"
#include<QTimer>

class Logic:public QGraphicsView{

public:
    Logic();

    void addBody();
    void upDateBack();
    void gameOver();
    void hitDetection();

    QGraphicsView *view;
    Food *food;
    Board *board;
    Body *body;
    Body**allBody;
    int numBody;
    QTimer *timer;

    QGraphicsScene *scene;


private:
    int start;


};

#endif // LOGIC_H

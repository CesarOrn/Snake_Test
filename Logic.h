#ifndef LOGIC_H
#define LOGIC_H
#include<QGraphicsScene>
#include"food.h"
#include <QGraphicsView>
#include"Body.h"
#include "Board.h"
#include<QTimer>
#include<QThread>
#include "mt.h"
class Logic:public QGraphicsView{

public:
    Logic();

    void addBody();
    void upDateBack();
    void gameOver();
    void hitDetection();
    int calculateInFrontX(int first);
    int calculateInFrontX(int first,int last);
    int calculateInFrontY(int first);
    int calculateInFrontY(int first,int last);
    static void msleep(unsigned long msecs);
    unsigned long getRand();
    void spawnFood();

    QGraphicsView *view;
    Food *food;
    Board *board;
    Body *body;
    Body**allBody;
    int numBody;
    QTimer *timer;

    QGraphicsScene *scene;
    MersenneTwister *myrand;


private:
    int start;


};

#endif // LOGIC_H

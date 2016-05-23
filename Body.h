#ifndef HEAD_H
#define HEAD_H

#include<QGraphicsRectItem>
#include <QKeyEvent>
#include<QObject>
#include<QGraphicsScene>
#include<QList>




class Body: public QObject ,public QGraphicsRectItem/*, public QObject*/{
    Q_OBJECT

public:
    Body();

    void keyPressEvent(QKeyEvent *event);

    void setIncrament(int h,int w);



    void setLastX(int x);
    void setLastY(int y);

    int getLastX();
    int getLastY();

    QList <QGraphicsItem *> colliding_items;

public slots:
    void goforward();




private:


    int yDir;
    int xDir;
    int yInc;
    int xInc;
    int lPosX;
    int lPosY;

};


#endif // HEAD_H

#ifndef HEAD_H
#define HEAD_H

#include<QGraphicsRectItem>
//#include<QObject>


class Body: public QGraphicsRectItem/*, public QObject*/{
   // Q_OBJECT

public:
    Body();

    void touchBody();

    void lastPos();

//public slots:
    //void goforward();

    int xpos;
    int ypos;

private:


};


#endif // HEAD_H

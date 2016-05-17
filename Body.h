#ifndef HEAD_H
#define HEAD_H

#include<QGraphicsRectItem>
#include<QObject>

class Body: public QGraphicsRectItem{
    Q_OBJECT

public:
    Body();

    touchBody();

    lastPos();

public slots:
    moveforward();


private:

};


#endif // HEAD_H

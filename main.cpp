#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include<QGraphicsRectItem>
#include <QApplication>
#include <QTimer>
#include"Body.h"
#include "Board.h"
#include"logic.h"
#include <QObject>

Logic *logic;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    logic=new Logic();


    return a.exec();
}

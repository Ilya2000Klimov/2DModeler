#include "canvas.h"

Canvas::Canvas(QWidget *parent)
    : QWidget{parent}
{
    // QWidget function to set the width & height of widget
    setFixedSize(1000,1000);
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPaintDevice *device(this);


    //     LINE
    class Line myLine(20, 90, 100, 20);
    myLine.setPen(Qt::green, 5, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
    myLine.draw(device);

    myLine.move(100,20);  // Testing Line move
    myLine.draw(device);


    //     Circle
    class Circle myCircle(750, 150, 200);
    myCircle.setPen(Qt::black, 12, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
    myCircle.setBrush(Qt::magenta, Qt::SolidPattern);
    myCircle.draw(device);

    myCircle.move(750,450);  // Testing Circle move
    myCircle.draw(device);


    //     Rectangle
    class Rectangle myRect(20, 200, 170, 100);
    myRect.setPen(Qt::blue, 0, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin);
    myRect.setBrush(Qt::red, Qt::VerPattern);
    myRect.draw(device);

    myRect.move(20, 400);  // Testing Rectangle move
    myRect.draw(device);


    //     Square
    class Square mySquare(250, 150, 200);
    mySquare.setPen(Qt::red, 0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    mySquare.setBrush(Qt::blue, Qt::HorPattern);
    mySquare.draw(device);

    mySquare.move(250, 450);  // Testing Square move
    mySquare.draw(device);


    //     Ellipse
    class Ellipse myEllipse(520, 200, 170, 100);
    myEllipse.setPen(Qt::black, 12, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
    myEllipse.setBrush(Qt::white, Qt::NoBrush);
    myEllipse.draw(device);

    myEllipse.move(520,320);  // Testing Ellipse move
    myEllipse.draw(device);

}


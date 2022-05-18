#include "canvas.h"
#include "../shapes/AllShapes.h"

Canvas::Canvas(QWidget *parent)
    : QWidget{parent}, vShapeList(cs1c::vector<cs1c::Shape*> ())
{
    // QWidget function to set the width & height of widget
    setFixedSize(1000,1000);
    pPaint = nullptr;
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPaintDevice *device(this);
    pPaint = new QPainter(this);

    for(const cs1c::Shape* shape : vShapeList)
    {
        shape->draw(device);
    }
    delete pPaint;
    /*
    //     LINE
    cs1c::Line myLine(&paint, 20, 90, 100, 20);
    myLine.setPen(Qt::green, 5, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
    myLine.draw(device);

    myLine.move(100,20);  // Testing Line move
    myLine.draw(device);


    //     Circle
    cs1c::Circle myCircle(&paint, 750, 150, 200);
    myCircle.setPen(Qt::black, 12, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
    myCircle.setBrush(Qt::magenta, Qt::SolidPattern);
    myCircle.draw(device);

    myCircle.move(750,450);  // Testing Circle move
    myCircle.draw(device);


    //     Rectangle
    cs1c::Rectangle myRect(&paint, 20, 200, 170, 100);
    myRect.setPen(Qt::blue, 0, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin);
    myRect.setBrush(Qt::red, Qt::VerPattern);
    myRect.draw(device);

    myRect.move(20, 400);  // Testing Rectangle move
    myRect.draw(device);


    //     Square
    cs1c::Square mySquare(&paint, 250, 150, 200);
    mySquare.setPen(Qt::red, 0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    mySquare.setBrush(Qt::blue, Qt::HorPattern);
    mySquare.draw(device);

    mySquare.move(250, 450);  // Testing Square move
    mySquare.draw(device);


    //     Ellipse
    cs1c::Ellipse myEllipse(&paint, 520, 200, 170, 100);
    myEllipse.setPen(Qt::black, 12, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
    myEllipse.setBrush(Qt::white, Qt::NoBrush);
    myEllipse.draw(device);

    myEllipse.move(520,320);  // Testing Ellipse move
    myEllipse.draw(device);

    //     Polygon
    cs1c::Polygon myPolygon(&paint);

    myPolygon.setPoints(900, 90);
    myPolygon.setPoints(910, 20);
    myPolygon.setPoints(970, 40);
    myPolygon.setPoints(980, 80);
    myPolygon.setPen(Qt::cyan, 6, Qt::DashDotDotLine, Qt::FlatCap, Qt::MiterJoin);
    myPolygon.setBrush(Qt::yellow, Qt::SolidPattern);
    myPolygon.draw(device);

    myPolygon.move(25,80);  // Testing Polygon move
    myPolygon.draw(device);

    //     Polyline
   cs1c::Polyline myPolyline(&paint);

   myPolyline.setPoints(460, 90);
   myPolyline.setPoints(470, 20);
   myPolyline.setPoints(530, 40);
   myPolyline.setPoints(540, 80);

   myPolyline.setPen(Qt::green, 6, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
   myPolyline.draw(device);

   myPolyline.move(100,40);  // Testing Polyline move
   myPolyline.draw(device);

   //     Text
   cs1c::Text myText(&paint);

   myText.setRect(250, 25, 500, 50);
   myText.setText("Class Project 2 - 2D Graphics Modeler");
   myText.setAlignment(Qt::AlignCenter);
   myText.setTextPointSize(10);
   myText.setTextFontFamily("Comic Sans MS");
   myText.setTextFontStyle("StyleItalic");
   myText.setTextFontWeight("Normal");
   myText.setColor("Yellow");
   myText.draw(device);

   myText.move(100,40);  // Testing Polyline move
   myText.draw(device);*/

}


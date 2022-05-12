#include "Polyline.h"
#include "../file-parsing/ShapeListingSpecification.h"

using namespace cs1c;

Polyline::Polyline(QPainter* pPainter, int ID) : Shape(pPainter)
{
    setID(ID);
}

Polyline::Polyline(int numOfPoints)
{
    this->numOfPoints=numOfPoints;
}

Polyline::~Polyline(){}

void Polyline::draw(QPaintDevice* pDevice)
{
    paint->begin(pDevice);
    paint->setPen(getPen());
    paint->setBrush(getBrush());
    paint->drawPolyline(arrOfPoints,numOfPoints);
    paint->end();
}

void Polyline::move(int x, int y)
{
    QPoint (x,y);
    double moveX=0;
    double moveY=0;
    //difference between the first coordinate and the coordinate we are moving to
    moveX = x-vPoint[0].x();
    moveY=y-vPoint[0].y();

    //setting the new coordinates as that particular point, ie the point has moved
    //int points is the point that is being moved
    for(QPointF& point : arrOfPoints)
    {
        point.rx() +=moveX;
        point.ry() +=moveY;
    }
}

double Polyline::area()
{
    return 0;
}
double Polyline::perimeter()
{
    return 0;
}

void Polyline::setPoints(QPoint* remPoints,int numOfPoints)
{
    for(QPointF& point : arrOfPoints)
    {
       vPoint.push_back(point);
    }
}

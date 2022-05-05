#include "polyline.h"

Polyline::Polyline(QPaintDevice* device, int ID)
{

}

Polyline::~Polyline()
{

}

void Polyline::draw(QPainter *paint)
{
   /* auto paint=getPainter(device);
    paint->drawLine(A,B);*/ //code shown in class for Line.cpp - for reference
    paint->setPen(getPen());
    paint->setBrush(getBrush());
    paint->drawPolyline(arrOfPoints,numOfPoints);
}

void Polyline::move(int x, int y, int points) const
{
    QPoint (x,y);
}

void Polyline::perimeter()
{
 //no perimeter to be calculated
}

void Polyline::area()
{
// no area to be calculated
}

void Polyline::setPoints(QPoint* remPoints,int numOfPoints)
{
 for(int index =0;index<numOfPoints;index++)
 {
     arrOfPoints[index]=remPoints[index];
 }
}

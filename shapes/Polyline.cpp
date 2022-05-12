#include "Polyline.h"
#include "../file-parsing/ShapeListingSpecification.h"

using namespace cs1c;

Polyline::Polyline(QPainter* pPainter, int ID) : Shape(pPainter)
{
    setID(ID);
}

Polyline::~Polyline()
{}

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
}

void Polyline::move(int x, int y, int points) const
{
    QPoint (x,y);
}


void Polyline::setPoints(QPoint* remPoints,int numOfPoints)
{
 for(int index =0;index<numOfPoints;index++)
 {
     arrOfPoints[index]=remPoints[index];
 }
}

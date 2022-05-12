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

void cs1c::Polyline::operator>>(QTextStream& fileStream)
{
    fileStream << "\nShapeId: " << this->getID()
        << "\nShapeType: Ellipse"
        << "\nShapeDimensions: ";
    // Repeat for all but last point
    int i = 1;
    while(i < numOfPoints)
    {
         fileStream << points[i - 1].x() << ", " << points[i - 1].y() << ", ";
         i++;
    }
    fileStream << points[i - 1].x() << ", " << points[i - 1].y();
    fileStream << "\nPenColor: " << slp::colorResolver.key(this->getPen().color())
        << "\nPenWidth: " << this->getPen().width()
        << "\nPenStyle: " << slp::penStyleResolver.key(this->getPen().style())
        << "\nPenCapStyle: " << slp::penCapStyleResolver.key(this->getPen().capStyle())
        << "\nPenJoinStyle: " << slp::penJoinStyleResolver.key(this->getPen().joinStyle());
}

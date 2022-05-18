#include "Shape.h"

using namespace cs1c;

Shape::Shape()
{
    shapeID = 0;
    pen = Qt::SolidLine;
    brush = Qt::SolidPattern;
    //shape = None;
}
Shape::Shape(QPainter* pPainter) : paint{pPainter}
{
    shapeID = 0;
    pen = Qt::SolidLine;
    brush = Qt::SolidPattern;
}
//----------------------------------------------------------------------
Shape::Shape(int shapeID, QPen pen, QBrush brush) //shapeType shape)
{
    this->shapeID = shapeID;
    this->pen = pen;
    this->brush = brush;
    //this->shape = None;
}
//----------------------------------------------------------------------
Shape::~Shape(){}
//----------------------------------------------------------------------
void Shape::setID(int ID)
{
    shapeID = ID;
}
//----------------------------------------------------------------------
//void Shape::setShape(shapeType s)
//{
//    shape = s;
//}
//----------------------------------------------------------------------
void Shape::setPen(QColor color, int width, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join)
{
    pen.setColor(color);
    pen.setWidthF(width);
    pen.setStyle(style);
    pen.setCapStyle(cap);
    pen.setJoinStyle(join);
}
//----------------------------------------------------------------------
void Shape::setBrush(QColor color, Qt::BrushStyle style)
{
    brush.setColor(color);
    brush.setStyle(style);
}
//----------------------------------------------------------------------
int Shape::getID() const
{
    return shapeID;
}
//----------------------------------------------------------------------
//shapeType Shape::getShapeType() const
//{
//    return shape;
//}
//----------------------------------------------------------------------
const QPen& Shape::getPen() const
{
    return pen;
}
//----------------------------------------------------------------------
const QBrush& Shape::getBrush() const
{
    return brush;
}
//----------------------------------------------------------------------
// Overloaded operators
bool Shape::operator==(const Shape& ID)
{
    return shapeID == ID.shapeID;
}
//----------------------------------------------------------------------
bool Shape::operator<(const Shape& ID)
{
    return shapeID < ID.shapeID;
}
//----------------------------------------------------------------------

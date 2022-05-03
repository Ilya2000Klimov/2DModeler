#include "shape.h"

Shape::Shape()
{
    shapeID = 0;
    shape = Line;
}
//----------------------------------------------------------------------
Shape::Shape(int shapeID, QPen pen, QBrush brush, shapeType shape)
{
    this->shapeID = shapeID;
    this->shape = shape;
}
//----------------------------------------------------------------------
Shape::~Shape(){}
//----------------------------------------------------------------------
void Shape::setID(int ID)
{
    shapeID = ID;
}
//----------------------------------------------------------------------
void Shape::setShape(shapeType s)
{
    shape = s;
}
//----------------------------------------------------------------------
void Shape::setPen(QColor color, int width, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join)
{
    pen.setColor(color);
    pen.setWidthF(width);
    pen.setStyle(style);
    pen.setCapStyle(cap);
    pen.setJoinStyle(join);
    // Pen color? pen default constructor has Qbrush parameter, Qcolor?
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
// Overloaded operators
bool operator==(const Shape& ID);
bool operator<(const Shape& ID);
//----------------------------------------------------------------------

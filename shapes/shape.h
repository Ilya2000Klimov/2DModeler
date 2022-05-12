#ifndef SHAPE_H
#define SHAPE_H
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QPaintDevice>

enum shapeType { None, Line, Polyline, Polygon, Rectangle, Ellipse, Circle, Square, Text };

class Shape
{
private:
    int shapeID;
    QPen pen;
    QBrush brush;
    shapeType shape;
protected:
    QPainter *paint;

public:
    Shape();
    Shape(int shapeID, QPen pen, QBrush brush, shapeType shape);
    Shape (const Shape& copy) = delete; // copy constructor
    Shape& operator=(const Shape& copy) = delete; // assignment operator
    void setID(int ID);
    void setShape(shapeType s);
    void setPen(QColor color, int width, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join);
    void setBrush(QColor color, Qt::BrushStyle style);
    virtual ~Shape();
    virtual void draw(QPaintDevice* pDevice) = 0;
    virtual void move(int x, int y) = 0;
    virtual double perimeter() = 0;
    virtual double area() = 0;
    int getID() const;
    shapeType getShapeType() const;
    QPen& getPen();
    QBrush& getBrush();
    // Overloaded operators
    bool operator==(const Shape& ID);
    bool operator<(const Shape& ID);
};
#endif // SHAPE_H


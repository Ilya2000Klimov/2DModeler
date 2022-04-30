#ifndef SHAPE_H
#define SHAPE_H
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QFont>

enum shapeType { Line, Polyline, Polygon, Rectangle, Ellipse, Text };

class Shape : public QPainter
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
    int getID() const;
    void setShape(shapeType s);
    virtual ~Shape();
    virtual void draw(QPaintDevice *device) = 0;
    virtual void move() = 0;
    virtual void perimeter() = 0;
    virtual void area() = 0;
    void setPen(qreal width,Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join);
    void setBrush(QColor color, Qt::BrushStyle style);
    // Overloaded operators
    bool operator==(const Shape& ID);
    bool operator<(const Shape& ID);
};
#endif // SHAPE_H

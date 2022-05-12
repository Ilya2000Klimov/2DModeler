#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

namespace cs1c
{
class Circle : public Shape
{
private:
    int x, y, radius;

public:
    Circle();
    Circle(QPainter* pPainter);
    Circle(int x, int y, int radius);
    virtual ~Circle();
    void setRadius(int r);
    void setX(int x);
    void setY(int y);
    int getRadius() const;
    int getX() const;
    int getY() const;
    virtual void draw(QPaintDevice* pDevice) override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
    virtual ShapeType type() const override;
//    virtual void operator>>(QTextStream& fileStream) override;
    virtual void setDimensions(int dimensions[], int dimensionCount) override;
};
}
#endif // CIRCLE_H

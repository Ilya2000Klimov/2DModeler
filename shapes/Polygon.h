#ifndef POLYGON_H
#define POLYGON_H
#include <QPoint>
#include "Shape.h"
#include "../vector.h"

namespace cs1c
{
class Polygon : public Shape
{
private:
    cs1c::vector<QPoint> vPoints;

public:
    Polygon();
    Polygon(QPainter* pPainter);
    Polygon(cs1c::vector<QPoint> vPoint, int count);
    virtual ~Polygon();
    void setPoints(int, int);
    cs1c::vector<QPoint>& getPoints();
    virtual void operator>>(QTextStream& fileStream) override;
    virtual void setDimensions(int dimensions[], int dimensionCount) override;
    virtual void draw(QPaintDevice *device) override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
};
}
#endif // POLYGON_H

#ifndef POLYLINE_H
#define POLYLINE_H
#include <QPoint>
#include "Shape.h"

namespace cs1c
{
class Polyline : public Shape
{
private:
    cs1c::vector<QPoint> vPoints;

public:
    Polyline();
    Polyline(QPainter* pPainter);
    Polyline(cs1c::vector<QPoint> vPoints);
    virtual ~Polyline();
    void setPoints(int, int);
    cs1c::vector<QPoint>& getPoints();
    virtual void setDimensions(int dimensions[], int dimensionCount) override;
    virtual void draw(QPaintDevice *device) override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
};
}
#endif // POLYLINE_H

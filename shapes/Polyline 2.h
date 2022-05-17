#ifndef POLYLINE_H
#define POLYLINE_H
#include <QPoint>
#include <QVector>
#include "Shape.h"

namespace cs1c
{
class Polyline : public Shape
{
private:
    QVector<QPoint> vPoints;

public:
    Polyline();
    Polyline(QPainter* pPainter);
    Polyline(QVector<QPoint> vPoints);
    virtual ~Polyline();
    void setPoints(int, int);
    QVector<QPoint>& getPoints();
    virtual void setDimensions(int dimensions[], int dimensionCount) override;
    virtual void draw(QPaintDevice *device) override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
};
}
#endif // POLYLINE_H

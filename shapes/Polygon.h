#ifndef POLYGON_H
#define POLYGON_H
#include <QPoint>
#include <QVector>
#include "Shape.h"

namespace cs1c
{
class Polygon : public Shape
{
private:
    QVector<QPoint> myPoints;
    int count;
    QPoint* p_point;

public:
    Polygon();
    Polygon(QPoint* p_point, int count);
    virtual ~Polygon();
    void setPoints(int, int);
    QVector<QPoint>& getPoints();
    virtual void operator>>(QTextStream& fileStream) override;
    virtual void setDimensions(int dimensions[], int dimensionCount) override;
    virtual void draw(QPaintDevice *device) override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
};
}
#endif // POLYGON_H

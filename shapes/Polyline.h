#ifndef POLYLINE_H
#define POLYLINE_H
#include "Shape.h"
#include "../vector.h"

namespace cs1c
{
class Polyline: public Shape
{
public:
    Polyline(QPainter* pPainter, int ID =-1);
    Polyline(int numOfPoints);
    ~Polyline() override;
    virtual void draw(QPaintDevice* pDevice) override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
    virtual void operator>>(QTextStream& fileStream) override;
    virtual void setDimensions(int dimensions[], int dimensionCount) override;

    int getPoints(); //function to get the remaining points of the polyline
    void setPoints(int x, int y);
private:

    static const int DEFAULT_NUM_PTS = 8;
    cs1c::vector<QPoint> vPoints;
};
}
#endif // POLYLINE_H

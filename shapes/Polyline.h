#ifndef POLYLINE_H
#define POLYLINE_H
#include "Shape.h"
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
    void move(int x, int y, int points) const; //might need to change int point
    virtual double perimeter() override;
    virtual double area() override;
    virtual void operator>>(QTextStream& fileStream) override;
    virtual void setDimensions(int dimensions[], int dimensionCount) override;

    int getPoints(); //function to get the remaining points of the polyline
    void setPoints(QPoint* remPoints, int numOfPoints);
private:

    static const int DEFAULT_NUM_PTS = 8;
    int numOfPoints;    // variable to find total polyline points
    QPointF arrOfPoints[DEFAULT_NUM_PTS];
    std::vector<QPointF> vPoint;
    QPoint* points;// Used b/c QPainter drawPoly is QPoint*
};
}
#endif // POLYLINE_H

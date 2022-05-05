#ifndef POLYLINE_H
#define POLYLINE_H
#include "shape.h"
const int DEFAULT_NUM_PTS = 5;
class Polyline:public Shape
{
public:
    Polyline(QPaintDevice* device, int ID =-1);
    ~Polyline() override;
    virtual void draw(QPainter *paint) override;
    virtual void move(int x, int y, int points) const; //might need to change int point
    virtual void perimeter() override; //area and perimete do not apply in this case
    virtual void area() override;

    int getPoints();
    void setPoints(QPoint* remPoints,int numOfPoints);
private:
    int numOfPoints; // will need to find total polyline points
    QPoint arrOfPoints[DEFAULT_NUM_PTS];
};
#endif // POLYLINE_H

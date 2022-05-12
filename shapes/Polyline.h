#ifndef POLYLINE_H
#define POLYLINE_H
#include "Shape.h"
namespace cs1c
{
class Polyline: public Shape
{
public:
    Polyline(QPaintDevice* device, int ID =-1);
    ~Polyline() override;
    virtual void draw(QPaintDevice* pDevice) override;
    virtual void move(int x, int y) override;
    void move(int x, int y, int points) const; //might need to change int point
    //virtual double perimeter() override; //area and perimeter probably do not apply in this case
   // virtual double area() override;

    int getPoints(); //function to get the remaining points of the polyline
    void setPoints(QPoint* remPoints,int numOfPoints);
private:
    // Note: Don't place variables in global scope
    static const int DEFAULT_NUM_PTS = 5;
    int numOfPoints; // will need to find total polyline points
    QPoint arrOfPoints[DEFAULT_NUM_PTS];
};
}
#endif // POLYLINE_H

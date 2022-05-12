#ifndef LINE_H
#define LINE_H
#include <QPoint>
#include "shape.h"

class Line : public Shape
{
private:
    int x1, y1, x2, y2;

public:
    Line();
    Line(int, int, int, int);
    virtual ~Line();
    void setStartPoint(int, int);
    void setEndPoint(int, int);
    int getStartX() const;
    int getStartY() const;
    int getEndX() const;
    int getEndY() const;
    virtual void draw(QPaintDevice* pDevice) override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
};
#endif // LINE_H

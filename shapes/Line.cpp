#include "Line.h"

Line::Line()
{
    start.setX(10);
    start.setY(10);
    end.setX(100);
    end.setY(100);
}
//----------------------------------------------------------------------
Line::Line(QPoint start, QPoint end)
{
    this->start = start;
    this->end = end;
}
//----------------------------------------------------------------------
Line::~Line() {}
//----------------------------------------------------------------------
void Line::setStartPoint(int x, int y)
{
    start.setX(x);
    start.setY(y);
}
//----------------------------------------------------------------------
void Line::setEndPoint(int x, int y)
{
    end.setX(x);
    end.setY(y);
}
//----------------------------------------------------------------------
QPoint Line::getPointStart() const
{
    return start;
}
//----------------------------------------------------------------------
QPoint Line::getPointEnd() const
{
    return end;
}
//----------------------------------------------------------------------
void Line::draw(QPainter *paint)
{
    paint->setPen(getPen());
    paint->setBrush(getBrush());
    paint->drawLine(start, end);
}
//----------------------------------------------------------------------
void Line::move(int x, int y)
{
    // Give moveStart/moveEnd original coordinates
    QPoint moveStart = getPointStart();
    QPoint moveEnd = getPointEnd();

    int newStartX = moveStart.x();
    int newStartY = moveStart.y();

    int newEndX = moveEnd.x();
    int newEndY = moveEnd.y();

    int endX = moveStart.x() + newEndX;
    int endY = moveStart.y() + newEndY;

    setStartPoint(newStartX, newStartY);
    setEndPoint(endX, endY);
}
//----------------------------------------------------------------------
double Line::perimeter()
{
    return 0; // There is no perimeter for a line
}
//----------------------------------------------------------------------
double Line::area()
{
    return 0; // There is no area for a line
}
//----------------------------------------------------------------------

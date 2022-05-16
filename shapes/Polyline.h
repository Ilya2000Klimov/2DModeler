#ifndef POLYLINE_H
#define POLYLINE_H
#include <QPoint>
#include <QVector>
#include "Shape.h"
//!A Polyine class
/*!
A class header file to construct a polyline
*/
namespace cs1c
{
class Polyline : public Shape
{
private:
    QVector<QPoint> vPoints; /*!< Points of the polyline */

public:
    //! A default constructor.
    /*!
    */
    Polyline();
    //! An alternate constructor.
    /*!
    */
    Polyline(QPainter* pPainter);
    //! An alternate constructor.
    /*!
    The points of the polyline is initialized in this constructor
    */
    Polyline(QVector<QPoint> vPoints);
    //! A deconstructor.
    /*!
    Polyline object destroyed
    */
    virtual ~Polyline();
    //! A mutator function
    /*!
    The QPoints are set by passing the x,y coordinates in the function
    */
    void setPoints(int, int);
    //! An accessor function
    /*!
    Returns the coordinate points of the polyline
    */
    QVector<QPoint>& getPoints();
    //! A mutator function
    /*!
    */
    virtual void setDimensions(int dimensions[], int dimensionCount) override;
    //! A draw function
    /*!
    Function draws the polyline
    */
    virtual void draw(QPaintDevice *device) override;
    //! A move function
    /*!
    Function moves the polyline
    */
    virtual void move(int x, int y) override;
    //! A perimeter function
    /*!
    Function returns the perimeter of the polyline
    */
    virtual double perimeter() override;
    //! An area function
    /*!
    Function returns the area of the polyline
    */
    virtual double area() override;
};
}
#endif // POLYLINE_H

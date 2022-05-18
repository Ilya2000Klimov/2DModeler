#ifndef POLYGON_H
#define POLYGON_H
#include <QPoint>
#include <QVector>
#include "Shape.h"
#include "../vector.h"
//!A Polygon class
/*!
A class header file to construct a polygon
*/
namespace cs1c
{
class Polygon : public Shape
{
private:
    QVector<QPoint> vPoints; /*!< Points of the polygon */

public:
    //! A default constructor.
    /*!
    */
    Polygon();
    //!An alternate constructor.
    /*!
    */
    Polygon(QPainter* pPainter);
    //! An alternate constructor.
    /*!
    The points of the polygon is initialized with the constructor
    */
    Polygon(QVector<QPoint> vPoint);
    //! A destructor
    /*!
    Polygon object destroyed
    */
    virtual ~Polygon();
    //! A mutator function
    /*!
    The QPoints are set by passing the x,y coordinates in the function
    */
    void setPoints(int, int);
    //! An accessor function
    /*!
    Returns the coordinate points of the polygon
    */
    QVector<QPoint>& getPoints();
    //! A print function
    /*!
    Function draws the polygon
    */
    void operator>>(QTextStream& fileStream) override;
    //! A mutator function
    /*!
    */
    virtual void setDimensions(int dimensions[], int dimensionCount) override;
    //! A draw function
    /*!
    Function draws the polygon
    */
    virtual void draw(QPaintDevice *device) const override;
    //! A move function
    /*!
    Function to move the polygon
    */
    virtual void move(int x, int y) override;
    //! A perimeter function
    /*!
    Function returns the perimeter of the polygon
    */
    virtual double perimeter() override;
    //! An area function
    /*!
    Function returns the area of the polygon
    */
    virtual double area() override;
};
}
#endif // POLYGON_H

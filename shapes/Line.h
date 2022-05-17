#ifndef LINE_H
#define LINE_H
#include <QPoint>
#include "Shape.h"
//!A Line class
/*!
A class header file to construct a line
*/
namespace cs1c
{
class Line : public Shape
{
private:
    int x1, y1, x2, y2; /*!< The x,y coordinates of the first point, and the x,y coord. of the end point */

public:
    //!A default constructor.
    /*!
    */
    Line();
    //!An alternate constructor.
    /*!
    */
    Line(QPainter* pPainter);
    //!An alternate constructor.
    /*!
    The x,y coordinates of the start point, and the x,y coord. of the end point is passed as parmeter and initialized.
    */
    //Line(int, int, int, int); // constructor for dialog.cpp

    Line(QPainter* pPainter, int, int, int, int);
    //!A destructor.
    /*!
    Line object destroyed
    */
    virtual ~Line();
    //!A mutator function
    /*!
    The function sets the start point coordinates as the int x, y values passed in the parameter
    */
    void setStartPoint(int, int);
    //!A mutator function
    /*!
    The function sets the end point coordinates as the int x, y values passed in the parameter
    */
    void setEndPoint(int, int);
    //!An accessor function
    /*!
    Returns the start point's x-coordinate
    */
    int getStartX() const;
    //!An accessor function
    /*!
    Returns the start point's y-coordinate
    */
    int getStartY() const;
    //!An accessor function
    /*!
    Returns the end point's x-coordinate
    */
    int getEndX() const;
    //!An accessor function
    /*!
    Returns the end point's y-coordinate
    */
    int getEndY() const;
    //!A draw function
    /*!
    Function to draw the line
    */
    virtual void draw(QPaintDevice* pDevice) override;
    //!A move function
    /*!
    Function to move the line
    */
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
    virtual void operator>>(QTextStream& fileStream) override;
    virtual void setDimensions(int dimensions[], int dimensionCount) override;
};
}
#endif // LINE_H

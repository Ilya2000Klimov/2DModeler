#ifndef SHAPE_H
#define SHAPE_H
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QPaintDevice>
#include <QTextStream>

//!  A shape class. 
/*!
  A class header file for the shape class. Other shapes are derived from this class
*/
namespace cs1c
{
//    //! An enum
//    /*!
//        Contains the types of shapes
//    */
//    enum ShapeType {
//        Line,       /*!< Enum value Line. */
//        Polyline,   /*!< Enum value Polyline. */
//        Polygon,    /*!< Enum value Polygon. */
//        Rectangle,  /*!< Enum value Rectangle. */
//        Square,     /*!< Enum value Square. */
//        Ellipse,    /*!< Enum value Ellipse. */
//        Circle,     /*!< Enum value Circle. */
//        Text        /*!< Enum value Text. */
//    };
class Shape
{
private:
    int shapeID;
    QPen pen;
    QBrush brush;
    // shapeType shape;

protected:
    QPainter** p_pPaint;

public:
    //! A default constructor.
    /*!
    A default constructor to initiallize the private variables to zero
    */
    Shape();
    //! An alternate constructor.
    /*!
    An alternate constructor where QPainter pointer is passed as parameter
    */
    Shape(QPainter** p_pPainter);
    //! An alternate constructor.
    /*!
    An alternate constructor where the shape ID, and the QPen and QBrish objects are passed as parameter
    */
    Shape(int shapeID, QPen pen, QBrush brush);
    //! An copy constructor.
    /*!
    An const reference of another object is passed as parameter
    */
    Shape (const Shape& copy) = delete;
    //!An assignment operator
    /*!
    */
    Shape& operator=(const Shape& copy) = delete;
    //! A setter function
    /*!
    ID is passed as parameter in the function
    */
    void setID(int ID);
    //void setShape(shapeType s);
    void setPen(QColor color, int width, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join);
    void setBrush(QColor color, Qt::BrushStyle style);
    //! A destructor
    /*!
    Destroys shape
    */
    virtual ~Shape();
    //! A pure virtual function
    /*!
    Used to draw shape object.
    */
    virtual void draw(QPaintDevice* pDevice) const = 0;
    //! A pure virtual function
    /*!
    Used to move shape object. 
    */
    virtual void move(int x, int y) = 0;
    //! A pure virtual function
    /*!
    Used calculate perimeter of a shape object and returns perimeter
    */
    virtual double perimeter() = 0;
    //! A pure virtual function
    /*!
    Used to calculate area of the shpae object and returns the area
    */
    virtual double area() = 0;
    int getID() const;
    //shapeType getShapeType() const;
    const QPen& getPen() const;
    const QBrush& getBrush() const;
    // Overloaded operators
    //*! An overloaded equality operator
    /*!
    */
    bool operator==(const Shape& ID);
    //*! An overloaded lesser than operator
    /*!
    */
    bool operator<(const Shape& ID);
    // SERIALIZE
//    virtual ShapeType type() const = 0;
    virtual void operator>>(QTextStream& fileStream) = 0;
    virtual void setDimensions(int dimensions[], int dimensionCount) = 0;
};
}
#endif // SHAPE_H


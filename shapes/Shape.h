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
    //! An enum
    /*!
        Contains the types of shapes
    */
    enum ShapeType {
        Line,       /*!< Enum value Line. */
        Polyline,   /*!< Enum value Polyline. */
        Polygon,    /*!< Enum value Polygon. */
        Rectangle,  /*!< Enum value Rectangle. */
        Square,     /*!< Enum value Square. */
        Ellipse,    /*!< Enum value Ellipse. */
        Circle,     /*!< Enum value Circle. */
        Text        /*!< Enum value Text. */
    };
class Shape
{
private:
    int shapeID;
    QPen pen;
    QBrush brush;
    // shapeType shape;

protected:
    QPainter *paint;

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
    Shape(QPainter* pPainter);
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
    Shape& operator=(const Shape& copy) = delete; // assignment operator
    void setID(int ID);
    //void setShape(shapeType s);
    void setPen(QColor color, int width, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join);
    void setBrush(QColor color, Qt::BrushStyle style);
    virtual ~Shape();
    virtual void draw(QPaintDevice* pDevice) = 0;
    virtual void move(int x, int y) = 0;
    virtual double perimeter() = 0;
    virtual double area() = 0;
    int getID() const;
    //shapeType getShapeType() const;
    QPen& getPen();
    QBrush& getBrush();
    // Overloaded operators
    bool operator==(const Shape& ID);
    bool operator<(const Shape& ID);
    // SERIALIZE
    virtual ShapeType type() const = 0;
    virtual void operator>>(QTextStream& fileStream) = 0;
    virtual void setDimensions(int dimensions[], int dimensionCount) = 0;
};
}
#endif // SHAPE_H


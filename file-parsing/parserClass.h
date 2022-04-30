#ifndef PARSER_H
#define PARSER_H
#include "QFile"
#include "QMetaEnum"

#include "ShapeListingSpecification.h"
#include "Shape.h"
#include "vector"

namespace cs1c
{
    class ShapeParser
    {
        // Register class with qt meta type system
        //Q_GADGET
    private:
        // QMetaEnum creation necessary for switching on
        // parsed ShapeType enum property via keyToValue func
        //QMetaEnum metaShapeTypeEnum = QMetaEnum::fromType<slp::ShapeType>();
        bool validateFile(QFile&);
    public:
        // Register enum with qt meta type system
        //Q_ENUM(slp::ShapeType)
        ShapeParser(QPainter*);
        // parseShape
        // Input: A valid QFile reference; validation required
        // Output: vector containing all shapes described in Input
        std::vector<Shape> parseShape(QFile&);
        //void parseFile(std::vector<Shape>&);
    };
}
#endif // PARSER_H

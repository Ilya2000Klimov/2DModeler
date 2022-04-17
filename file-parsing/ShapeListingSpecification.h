#ifndef PARSERCONSTANTS_H
#define PARSERCONSTANTS_H
#include "QMetaEnum"

// Shape Listing Profile (SLP) Specification
//
// Note: A ShapeType property must always follow a ShapeID property.
namespace slp
{
    // Register namespace with qt meta type system
    // this is necessary for creating a QMetaEnum
    Q_NAMESPACE

    /// Char lengths of property names in file
    // Comma Divisions
    const int COMMA_DIVISION_LENGTH = 2;
    // Shape fields
    const int SHAPE_ID_LENGTH = 8;
    const int SHAPE_TYPE_LENGTH = 11;
    const int SHAPE_DIMENSION_LENGTH = 17;
    // Pen fields
    const int PEN_COLOR_LENGTH = 10;
    const int PEN_WIDTH_LENGTH = 10;
    const int PEN_STYLE_LENGTH = 10;
    const int PEN_CAP_STYLE_LENGTH = 13;
    const int PEN_JOIN_STYLE_LENGTH = 14;
    // Brush fields
    const int BRUSH_COLOR_LENGTH = 12;
    const int BRUSH_STYLE_LENGTH = 12;
    // Text fields
    const int TEXT_STRING_LENGTH = 11;
    const int TEXT_COLOR_LENGTH = 11;
    const int TEXT_ALIGNMENT_LENGTH = 15;
    const int TEXT_POINT_SIZE_LENGTH = 15;
    const int TEXT_FONT_FAMILY_LENGTH = 16;
    const int TEXT_FONT_STYLE_LENGTH = 15;
    const int TEXT_FONT_WEIGHT_LENGTH = 16;


    enum ShapeType {
        Line,
        Polyline,
        Polygon,
        Rectangle,
        Square,
        Ellipse,
        Circle,
        Text
    };
    // Register enum with qt meta type system
    // this will permit switching on string input
    // for "ShapeType" property data.
    Q_ENUM_NS(ShapeType)
}

#endif // PARSERCONSTANTS_H

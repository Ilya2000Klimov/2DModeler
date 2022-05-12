#ifndef PARSERCONSTANTS_H
#define PARSERCONSTANTS_H
#include "../shapes/AllShapes.h"// Include all shape headers
#include "QString"
#include "QHash"
#include "QPainter"
#include "QColor"
#include "QPen"
#include "QBrush"
#include "QFont"
#include "QFlags"

namespace cs1c
{
    class Line;
    class Polyline;
    class Polygon;
    class Rectangle;
    class Square;
    class Ellipse;
    class Circle;
    class Text;
}

// Shape Listing Profile (SLP) Specification
//
// Note: Shape properties are expected to be in order and separated by newlines.

namespace slp
{
    QHash<QString, cs1c::Shape*> getShapeTypeResolver(QPainter*);
    QHash<QString, QColor> getColorResolver();
    QHash<QString, Qt::PenStyle> getPenStyleResolver();
    QHash<QString, Qt::PenCapStyle> getPenCapStyleResolver();
    QHash<QString, Qt::PenJoinStyle> getPenJoinStyleResolver();
    QHash<QString, Qt::BrushStyle> getBrushStyleResolver();
    QHash<QString, Qt::Alignment> getAlignmentFlagResolver();
    QHash<QString, QFont::Style> getFontStyleResolver();
    QHash<QString, QFont::Weight> getFontWeightResolver();


    // Register namespace with qt meta type system
    // this is necessary for creating a QMetaEnum
    //Q_NAMESPACE

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
    // From file
    enum PropertyType
    {
        ShapeId,
        ShapeType,
        ShapeDimensions,
        PenColor,
        PenWidth,
        PenStyle,
        PenCapStyle,
        PenJoinStyle,
        BrushColor,
        BrushStyle,
        TextString,
        TextColor,
        TextAlignment,
        TextPointSize,
        TextFontFamily,
        TextFontStyle,
        TextFontWeight
    };

    // From file to object
//    enum ShapeType {
//        Line,
//        Polyline,
//        Polygon,
//        Rectangle,
//        Square,
//        Ellipse,
//        Circle,
//        Text
//    };
    // Must be created after pPainter is instantiated (in main)
    QHash<QString, cs1c::Shape*> shapeTypeResolver;// = getShapeTypeResolver(pPainter);
    QHash<QString, QColor> colorResolver = getColorResolver();
    QHash<QString, Qt::PenStyle> penStyleResolver = getPenStyleResolver();
    QHash<QString, Qt::PenCapStyle> penCapStyleResolver = getPenCapStyleResolver();
    QHash<QString, Qt::PenJoinStyle> penJoinStyleResolver = getPenJoinStyleResolver();
    QHash<QString, Qt::BrushStyle> brushStyleResolver = getBrushStyleResolver();
    QHash<QString, Qt::Alignment> alignmentFlagResolver = getAlignmentFlagResolver();
    QHash<QString, QFont::Style> fontStyleResolver = getFontStyleResolver();
    QHash<QString, QFont::Weight> fontWeightResolver = getFontWeightResolver();


    // Instantiating QHashes for String Litteral to Named Type conversion
    QHash<QString, cs1c::Shape*> getShapeTypeResolver(QPainter* pPainter)
    {
        QHash<QString, cs1c::Shape*> shapeTypeResolver;
        shapeTypeResolver.reserve(8);
        // QHashes cannot receive input, so all concrete
        // shapes must have constructors with non-variable input
        // ex: pPainter does not differ between shapes
        shapeTypeResolver["Line"] = new cs1c::Line(pPainter);
        shapeTypeResolver["Polyline"] = new cs1c::Polyline(pPainter);
        shapeTypeResolver["Polygon"] = new cs1c::Polygon(pPainter);
        shapeTypeResolver["Rectangle"] = new cs1c::Rectangle(pPainter);
        shapeTypeResolver["Square"] = new cs1c::Rectangle(pPainter);
        shapeTypeResolver["Ellipse"] = new cs1c::Ellipse(pPainter);
        shapeTypeResolver["Circle"] = new cs1c::Ellipse(pPainter);
        shapeTypeResolver["Text"] = new cs1c::Text(pPainter);
        return shapeTypeResolver;
    }
    QHash<QString, QColor> getColorResolver()
    {
        QHash<QString, QColor> colorResolver;
        colorResolver.reserve(9);
        colorResolver["white"] = QColor(Qt::white);
        colorResolver["black"] = QColor(Qt::black);
        colorResolver["red"] = QColor(Qt::red);
        colorResolver["green"] = QColor(Qt::green);
        colorResolver["blue"] = QColor(Qt::blue);
        colorResolver["cyan"] = QColor(Qt::cyan);
        colorResolver["magenta"] = QColor(Qt::magenta);
        colorResolver["yellow"] = QColor(Qt::yellow);
        colorResolver["gray"] = QColor(Qt::gray);
        return colorResolver;
    }
    QHash<QString, Qt::PenStyle> getPenStyleResolver()
    {
        QHash<QString, Qt::PenStyle> penStyleResolver;
        penStyleResolver.reserve(6);
        penStyleResolver["NoPen"] = Qt::PenStyle::NoPen;
        penStyleResolver["SolidLine"] = Qt::PenStyle::SolidLine;
        penStyleResolver["DashedLine"] = Qt::PenStyle::DashLine;
        penStyleResolver["DotLine"] = Qt::PenStyle::DotLine;
        penStyleResolver["DashDotLine"] = Qt::PenStyle::DashDotLine;
        penStyleResolver["DashDotDotLine"] = Qt::PenStyle::DashDotDotLine;
        return penStyleResolver;
    }
    QHash<QString, Qt::PenCapStyle> getPenCapStyleResolver()
    {
        QHash<QString, Qt::PenCapStyle> penCapStyleResolver;
        penCapStyleResolver.reserve(6);
        penCapStyleResolver["FlatCap"] = Qt::PenCapStyle::FlatCap;
        penCapStyleResolver["SquareCap"] = Qt::PenCapStyle::SquareCap;
        penCapStyleResolver["RoundCap"] = Qt::PenCapStyle::RoundCap;
        return penCapStyleResolver;
    }
    QHash<QString, Qt::PenJoinStyle> getPenJoinStyleResolver()
    {
        QHash<QString, Qt::PenJoinStyle> penJoinStyleResolver;
        penJoinStyleResolver.reserve(3);
        penJoinStyleResolver["MiterJoin"] = Qt::PenJoinStyle::MiterJoin;
        penJoinStyleResolver["BevelJoin"] = Qt::PenJoinStyle::BevelJoin;
        penJoinStyleResolver["RoundJoin"] = Qt::PenJoinStyle::RoundJoin;
        return penJoinStyleResolver;
    }
    QHash<QString, Qt::BrushStyle> getBrushStyleResolver()
    {
        QHash<QString, Qt::BrushStyle> brushStyleResolver;
        brushStyleResolver.reserve(4);
        brushStyleResolver["SolidPattern"] = Qt::BrushStyle::SolidPattern;
        brushStyleResolver["HorPattern"] = Qt::BrushStyle::HorPattern;
        brushStyleResolver["VerPattern"] = Qt::BrushStyle::VerPattern;
        brushStyleResolver["NoBrush"] = Qt::BrushStyle::NoBrush;
        return brushStyleResolver;
    }
    QHash<QString, Qt::Alignment> getAlignmentFlagResolver()
    {
        QHash<QString, Qt::Alignment> alignmentFlagResolver;
        alignmentFlagResolver.reserve(5);
        alignmentFlagResolver["AlignLeft"] = Qt::AlignmentFlag::AlignLeft;
        alignmentFlagResolver["AlignRight"] = Qt::AlignmentFlag::AlignRight;
        alignmentFlagResolver["AlignTop"] = Qt::AlignmentFlag::AlignTop;
        alignmentFlagResolver["AlignBottom"] = Qt::AlignmentFlag::AlignBottom;
        alignmentFlagResolver["AlignCenter"] = Qt::AlignmentFlag::AlignCenter;
        return alignmentFlagResolver;
    }
    QHash<QString, QFont::Style> getFontStyleResolver()
    {
        QHash<QString, QFont::Style> fontStyleResolver;
        fontStyleResolver.reserve(3);
        fontStyleResolver["StyleNormal"] = QFont::Style::StyleNormal;
        fontStyleResolver["StyleItalic"] = QFont::Style::StyleItalic;
        fontStyleResolver["StyleOblique"] = QFont::Style::StyleOblique;
        return fontStyleResolver;
    }
    QHash<QString, QFont::Weight> getFontWeightResolver()
    {
        QHash<QString, QFont::Weight> fontWeightResolver;
        fontWeightResolver.reserve(4);
        fontWeightResolver["Thin"] = QFont::Weight::Thin;
        fontWeightResolver["Light"] = QFont::Weight::Light;
        fontWeightResolver["Normal"] = QFont::Weight::Normal;
        fontWeightResolver["Bold"] = QFont::Weight::Bold;
        return fontWeightResolver;
    }

    // Register enum with qt meta type system
    // this will permit switching on string input
    // for "PropertyType" property data.
    //Q_ENUM_NS(PropertyType)
}

#endif // PARSERCONSTANTS_H

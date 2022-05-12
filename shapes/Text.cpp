#include "Text.h"
#include "../file-parsing/ShapeListingSpecification.h"

cs1c::Text::Text() : Shape()
{
    textFormat = QTextOption();
    font = QFont();
    textString = "";
}
cs1c::Text::Text(QPainter* pPainter) : Shape(pPainter)
{
    textFormat = QTextOption();
    font = QFont();
    textString = "";
}
cs1c::Text::Text(QFont font) : Shape()
{
    textFormat = QTextOption();
    this->font = font;
    textString = "";
}
cs1c::Text::~Text()
{
    
}
void cs1c::Text::setAlignment(Qt::Alignment textAlignment)
{
    textFormat.setAlignment(textAlignment);
}
Qt::Alignment cs1c::Text::getAlignment()
{
    return textFormat.alignment();
}
void cs1c::Text::setFont(QFont font)
{
    this->font = font;
}
QFont cs1c::Text::getFont() const
{
    return font;
}
void cs1c::Text::setText(QString text)
{
    textString = text;
}
QString cs1c::Text::getText() const
{
    return textString;
}
void cs1c::Text::draw(QPaintDevice* pDevice) //override
{
    // TODO: use consistent names
    paint->begin(pDevice);
    paint->setFont(font);
    paint->setPen(getPen());
    paint->drawText(textBounds, textString, textFormat);
    paint->end();
}

void cs1c::Text::move(int x, int y) //override
{
    textBounds.moveTo(x, y);
}
double cs1c::Text::perimeter() //override
{
    return 2* (textBounds.width() + textBounds.height());
}
double cs1c::Text::area() //override
{
    return textBounds.width() * textBounds.height();
}
QTextStream& cs1c::operator<<(QTextStream& fileStream, cs1c::Text& textShape)
{
    fileStream << "\nShapeId: " << textShape.getID()
        << "\nShapeType: Text"
        << "\nShapeDimensions: " << textShape.textBounds.x() << ", " << textShape.textBounds.y()
            << ", " << textShape.textBounds.height() << ", " << textShape.textBounds.width()
        << "\nTextString: " << textShape.textString
        << "\nTextColor: blue" << slp::colorResolver.key(textShape.getPen().color())
        << "\nTextAlignment: " << slp::alignmentFlagResolver.key(textShape.textFormat.alignment())
        << "\nTextPointSize: " << textShape.font.pointSize()
        << "\nTextFontFamily: " << textShape.font.family()
        << "\nTextFontStyle: " << slp::fontStyleResolver.key(textShape.font.style())
        << "\nTextFontWeight: " << slp::fontWeightResolver.key(textShape.font.weight());
}

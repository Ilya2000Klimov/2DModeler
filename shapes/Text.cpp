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
void cs1c::Text::operator>>(QTextStream& fileStream)
{
    fileStream << "\nShapeId: " << this->getID()
        << "\nShapeType: Text"
        << "\nShapeDimensions: " << this->textBounds.x() << ", " << this->textBounds.y()
            << ", " << this->textBounds.height() << ", " << this->textBounds.width()
        << "\nTextString: " << this->textString
        << "\nTextColor: " << slp::colorResolver.key(this->getPen().color())
        << "\nTextAlignment: " << slp::alignmentFlagResolver.key(this->textFormat.alignment())
        << "\nTextPointSize: " << this->font.pointSize()
        << "\nTextFontFamily: " << this->font.family()
        << "\nTextFontStyle: " << slp::fontStyleResolver.key(this->font.style())
        << "\nTextFontWeight: " << slp::fontWeightResolver.key(this->font.weight());
}
void cs1c::Text::setDimensions(int dimensions[])
{
	for(int i = 0; i < 4; i++)
		x = dimensions[i];
}


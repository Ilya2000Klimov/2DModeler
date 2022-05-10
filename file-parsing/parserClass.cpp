#include "parserClass.h"
#include "ShapeListingSpecification.h"// include file format information
#include "AllShapes.h"// Include all shape headers

#include "QMetaEnum"

// Helper function prototype
QString getPropertyData(QTextStream&);


// validateFile
bool cs1c::ShapeParser::validateFile(QFile& file)
{
    //QFile file(filePath);
    // is file NOT accessible for reading?
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }
    return true;
}

// Constructor
cs1c::ShapeParser::ShapeParser(QPainter* pPainter)
{
    slp::shapeTypeResolver = slp::getShapeTypeResolver(pPainter);
}
// parseShape
std::vector<Shape> cs1c::ShapeParser::parseShape(QFile& file)
{
    // shape container to be returned
    std::vector<Shape> shapeList;
    //Shape& currentShape;
    // class for streaming data from a text file
    QTextStream in(&file);

    // Strings to be processed
    QStringList dimensionList;
    QString shapeType;
    // Processed generic Shape properties
    int shapeId = 0;
    int* shapeDimensions;

    // so long as the file has not reached its end
    while (!in.valueEnd()) {
        // For each shape listed:
        in.readLine();

        // Get properties of all shapes

        shapeId = getPropertyData(in).toInt();
        shapeType = getPropertyData(in);
        dimensionList = getPropertyData(in).split(", ");

        // Create new shape from file
        auto currentShape = slp::shapeTypeResolver.value(shapeType);
        //shapeList.push_back(slp::shapeTypeResolver.value(shapeType));
        // Convenient access to working shape
        //Shape& currentShape = shapeList.back();

        // ===============
        // For all Shapes
        // ===============
        // ID
        currentShape.setID(shapeId);

        // Dimensions
        shapeDimensions = new int[dimensionList.size()]{};
        for(int i = 0; i < dimensionList.size(); i++)//QStringList::iterator itDimension = dimensionList.begin(); itDimension != dimensionList.end(); ++itDimension)
        {
            shapeDimensions[i] = dimensionList.value(i).toInt();
        }
        currentShape.setDimensions(shapeDimensions);

        // =========================
        // For Text only properties
        // =========================
        if(shapeType.contains("Text"))
        {
            QString textString = getPropertyData(in);
            QColor textColor = slp::globalColorResolver.value(getPropertyData(in));
            Qt::AlignmentFlag textAlignment = slp::alignmentFlagResolver.value(getPropertyData(in));
            int textPointSize = getPropertyData(in).toInt();
            QString textFontFamily = getPropertyData(in);

            QFont textFont(textFontFamily);
            textFont.setStyle(slp::globalColorResolver.value(getPropertyData(in)));
            textFont.setWeight(slp::fontWeightResolver.value(getPropertyData(in)));

            // Apply text properties from file
            currentShape.setText(textString);
            currentShape.setPen(textColor, textAlignment, textPointSize);
            currentShape.setFont(textFont);
        }
        // ============================
        // Surface and Line properties
        // ============================
        else
        {
            QColor penColor = slp::globalColorResolver.value(getPropertyData(in));
            int penWidth = getPropertyData(in).toInt();
            Qt::PenStyle penStyle = slp::penStyleResolver.value(getPropertyData(in));
            Qt::PenCapStyle penCapStyle = slp::penCapStyleResolver.value(getPropertyData(in));
            Qt::PenJoinStyle penJoinStyle = slp::penJoinStyleResolver.value(getPropertyData(in));

            // Apply pen properties from file
            currentShape.setPen(
                        penColor,
                        penWidth,
                        penStyle,
                        penCapStyle,
                        penJoinStyle
                        );
            // ============================
            // For Surface only properties
            // ============================
            if(!shapeType.contains("Line"))
            {
                QColor brushColor = slp::globalColorResolver.value(getPropertyData(in));
                Qt::BrushStyle brushStyle = slp::brushStyleResolver.value(getPropertyData(in));

                // Apply brush properties from file
                currentShape.setBrush(brushColor, brushStyle);
            }
        }
        shapeList.push_back(currentShape);
    }
    return shapeList;
}

QString getPropertyData(QTextStream& fileStream)
{
    return fileStream.readLine().split(": ").back();
}

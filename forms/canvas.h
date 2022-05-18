#ifndef CANVAS_H
#define CANVAS_H
#include <QWidget>
#include <QObject>
#include <QPainter>
#include <QPaintDevice>
//#include <QtGui>
#include "shapes/AllShapes.h"
//#include "shapes/Line.h"
//#include "shapes/Circle.h"
//#include "shapes/Rectangle.h"
//#include "shapes/Square.h"
//#include "shapes/Ellipse.h"

class QPaintEvent;

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    // ptr to new QPainter obj every paintEvent()
    QPainter* pPaint;
    cs1c::vector<cs1c::Shape*> vShapeList;

signals:

};

#endif // CANVAS_H


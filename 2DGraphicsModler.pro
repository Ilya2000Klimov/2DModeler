QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canvas.cpp \
    file-parsing/ShapeListingSpecification.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    serializepreview.cpp \
    shapes/Circle.cpp \
    shapes/Ellipse.cpp \
    shapes/Line.cpp \
    shapes/Polygon.cpp \
    shapes/Polyline.cpp \
    shapes/Rectangle.cpp \
    shapes/Shape.cpp \
    shapes/Square.cpp \
    shapes/Text.cpp \
    file-parsing/parserClass.cpp
    file-parsing/ShapeListingSpecification.cpp

HEADERS += \
    canvas.h \
    login.h \
    mainwindow.h \
    serializepreview.h \
    ui_login.h \
    ui_mainwindow.h \
    vector.h \
    shapes/AllShapes.h \
    shapes/Circle.h \
    shapes/Ellipse.h \
    shapes/Line.h \
    shapes/Polygon.h \
    shapes/Polyline.h \
    shapes/Rectangle.h \
    shapes/Shape.h \
    shapes/Square.h \
    shapes/Text.h \
    file-parsing/parserClass.h \
    file-parsing/ShapeListingSpecification.h

FORMS += \
    login.ui \
    mainwindow.ui \
    serializepreview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vector.h"
#include "file-parsing/parserClass.h"
#include "shapes/Shape.h"
#include "dialog.h"
#include "login.h"
#include "canvas.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAdd_Line_triggered();

    void on_actionAdd_Polyline_triggered();

    void on_actionLogin_triggered();

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

private:
    Ui::MainWindow *ui;
    Login* uiLogin;
    Canvas* uiCanvas;
    QPainter** p_pPaint;
    cs1c::ShapeParser shapeParser;
    cs1c::vector<cs1c::Shape*>* pShapeList;
};
#endif // MAINWINDOW_H

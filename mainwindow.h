#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vector.h"
#include "shapes/Shape.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
public slots:
    void login_clicked();
private:
    Ui::MainWindow *ui;
    cs1c::vector<cs1c::Shape*> vShapeList;
};
#endif // MAINWINDOW_H

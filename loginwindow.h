#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

extern bool admin;

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void enterButtonClicked();

    void adminButtonClicked();

    void guestButtonClicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H

#include "loginwindow.h"
#include "ui_loginwindow.h"


LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::enterButtonClicked()
{
    if (ui->usernameInput->toPlainText() == "Admin" &&
        ui->passwordInput->toPlainText() == "Password")
    {
        admin = true;
    }
    else
    {
        admin = false;
    }
}

void LoginWindow::adminButtonClicked()
{
    if(admin)
    {
    this->close();
    }
}

void LoginWindow::guestButtonClicked()
{
    if(!admin)
    {
    this->close();
    }
}

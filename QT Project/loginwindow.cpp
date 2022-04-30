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
        QMessageBox::warning(this, "Login", "Welcome, administrator");
    }
    else
    {
        admin = false;
        QMessageBox::warning(this, "Login", "Username or password incorrect");
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

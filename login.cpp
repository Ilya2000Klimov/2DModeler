#include "Login.h"


login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::enterButtonClicked()
{
    if (ui->userNameInput->toPlainText() == "Admin" &&
        ui->passwordInput->toPlainText() == "Password")
    {
        ui->errorMessage->setText("Welcome, Administrator");

        admin = true;
    }
    else
    {
        ui->errorMessage->setText("Incorrect user name or password");
    }

}

void login::adminButtonClicked()
{
    if(admin)
    {
    this->close();
    {
    else
    {
        ui->errorMessage->setText("Sorry, name and password required for admin access");
    }
}

void login::guestButtonClicked()
{
    this->close();
}

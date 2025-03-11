#include "loginwindow.h"
#include "function_for_client.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    connect(ui->toolButton_then0, &QToolButton::clicked, this, &LoginWindow::on_toolButton_then0_clicked);
    connect(ui->toolButton_then1, &QToolButton::clicked, this, &LoginWindow::on_toolButton_then1_clicked);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_toolButton_then0_clicked()
{
    emit returnToMainWindow();
}

void LoginWindow::on_toolButton_then1_clicked()
{
    if (auth(ui->lineEdit_login->text(), ui->lineEdit_password->text()))
        emit goToDriverCompanionWindow();
    else
        clear();
}

void LoginWindow::clear()
{
    ui->lineEdit_login->setText("");
    ui->lineEdit_password->setText("");
}

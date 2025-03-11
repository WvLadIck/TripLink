#include "registrationwindow.h"
#include "ui_registrationwindow.h"
#include "function_for_client.h"

RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);
    connect(ui->toolButton_then0, &QToolButton::clicked, this, &RegistrationWindow::on_toolButton_then0_clicked);
    connect(ui->toolButton_then1, &QToolButton::clicked, this, &RegistrationWindow::on_toolButton_then1_clicked);
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

void RegistrationWindow::on_toolButton_then0_clicked()
{
    emit returnToMainWindow();
}

void RegistrationWindow::on_toolButton_then1_clicked()
{
    if (reg(ui->lineEdit_login->text(), ui->lineEdit_password->text(), ui->lineEdit_name->text(), ui->lineEdit_phone->text()))
    {
        emit goToDriverCompanionWindow();
    }
    else
        clear();
}

void RegistrationWindow::clear()
{
    ui->lineEdit_login->setText("");
    ui->lineEdit_password->setText("");
    ui->lineEdit_phone->setText("");
    ui->lineEdit_name->setText("");
}

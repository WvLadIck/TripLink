#include "registrationwindow.h"
#include "ui_registrationwindow.h"
#include "function_for_client.h"
#include "networkclient.h"
#include <QMessageBox>

RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);
    connect(ui->toolButton_then0, &QToolButton::clicked, this, &RegistrationWindow::on_toolButton_then0_clicked);
    //connect(ui->toolButton_then1, &QToolButton::clicked, this, &RegistrationWindow::on_toolButton_then1_clicked);

    // Подключаемся к сигналам NetworkClient
    NetworkClient& client = NetworkClient::getInstance();
    connect(&client, &NetworkClient::regSuccess, this, &RegistrationWindow::onRegSuccess);
    connect(&client, &NetworkClient::regFailed, this, &RegistrationWindow::onRegFailed);
    connect(&client, &NetworkClient::error, this, &RegistrationWindow::onError);
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
    qDebug() << "Registration button clicked!"; // Добавляем логирование
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    QString email = ui->lineEdit_phone->text(); // Используем поле email
    QString command = QString("reg&%1&%2&%3\r\n").arg(login, password, email); // Добавляем \r\n
    NetworkClient::getInstance().sendMessage(command);
}

void RegistrationWindow::onRegSuccess(const QString& login)
{
    QMessageBox::information(this, "Success", "Registration successful!");
    QMessageBox::information(this, "Success", "Registration successful!");
    emit goToDriverCompanionWindow();
}

void RegistrationWindow::onRegFailed()
{
    QMessageBox::warning(this, "Error", "Registration failed. Login already exists or invalid data.");
    clear();
}

void RegistrationWindow::onError(const QString& message)
{
    QMessageBox::critical(this, "Error", "Error: " + message);
}

void RegistrationWindow::clear()
{
    ui->lineEdit_login->setText("");
    ui->lineEdit_password->setText("");
    ui->lineEdit_phone->setText("");
}

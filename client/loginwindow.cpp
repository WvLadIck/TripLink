/**
 * @file loginwindow.cpp
 * @brief Файл реализации класса LoginWindow.
 */

#include "loginwindow.h"
#include "function_for_client.h"
#include "ui_loginwindow.h"
#include "networkclient.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    connect(ui->toolButton_then0, &QToolButton::clicked, this, &LoginWindow::on_toolButton_then0_clicked);
    //connect(ui->toolButton_then1, &QToolButton::clicked, this, &LoginWindow::on_toolButton_then1_clicked);
    // Подключаемся к сигналам NetworkClient
    NetworkClient& client = NetworkClient::getInstance();
    connect(&client, &NetworkClient::authSuccess, this, &LoginWindow::onAuthSuccess);
    connect(&client, &NetworkClient::authFailed, this, &LoginWindow::onAuthFailed);
    connect(&client, &NetworkClient::error, this, &LoginWindow::onError);
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
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    QString command = QString("auth&%1&%2\r\n").arg(login, password); // Добавляем \r\n
    NetworkClient::getInstance().sendMessage(command);
}

void LoginWindow::onAuthSuccess()
{
    QMessageBox::information(this, "Success", "Authentication successful!");
    emit goToDriverCompanionWindow();
}

void LoginWindow::onAuthFailed()
{
    QMessageBox::warning(this, "Error", "Authentication failed. Invalid login or password.");
    clear();
}

void LoginWindow::onError(const QString& message)
{
    QMessageBox::critical(this, "Error", "Error: " + message);
}

void LoginWindow::clear()
{
    ui->lineEdit_login->setText("");
    ui->lineEdit_password->setText("");
}

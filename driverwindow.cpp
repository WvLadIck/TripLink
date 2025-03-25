#include "driverwindow.h"
#include "ui_driverwindow.h"
#include "networkclient.h" // Подключаем NetworkClient

DriverWindow::DriverWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DriverWindow)
{
    ui->setupUi(this);
    connect(ui->toolButton_then0, &QToolButton::clicked, this, &DriverWindow::on_toolButton_then0_clicked);
    //connect(ui->toolButton_then1, &QToolButton::clicked, this, &DriverWindow::on_toolButton_then1_clicked);
}

DriverWindow::~DriverWindow()
{
    delete ui;
}

void DriverWindow::on_toolButton_then0_clicked()
{
    emit returnToPreviousWindow();
}

void DriverWindow::on_toolButton_then1_clicked()
{
    // Получаем данные из полей
    QString from = ui->lineEdit_from->text();
    QString to = ui->lineEdit_where->text();
    QString time = ui->lineEdit_time->text();

    // Получаем логин текущего пользователя (предполагаем, что он сохранен в NetworkClient)
    QString login = NetworkClient::getInstance().getLogin();

    // Формируем команду для отправки на сервер
    QString command = QString("trip&%1&%2&%3&%4\r\n").arg(login, from, to, time);

    // Отправляем команду на сервер через NetworkClient
    NetworkClient::getInstance().sendMessage(command);

    emit goToFinishWindow(); //  Отправляем сигнал goToFinishWindow
}

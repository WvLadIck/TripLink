// driverwindow.cpp
#include "driverwindow.h"
#include "ui_driverwindow.h"
#include "networkclient.h" // Подключаем NetworkClient
#include <QDebug>
#include <QDateTime> // Подключаем QDateTime

DriverWindow::DriverWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DriverWindow)
{
    ui->setupUi(this);

    connect(ui->toolButton_then0, &QToolButton::clicked, this, &DriverWindow::on_toolButton_then0_clicked);
    //connect(ui->toolButton_then1, &QToolButton::clicked, this, &DriverWindow::on_toolButton_then1_clicked); // Подключаем кнопку
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

    // Получаем дату и время из QDateTimeEdit
    QDateTime dateTime = ui->dateTimeEdit->dateTime();
    QString time = dateTime.toString("yyyy-MM-dd HH:mm:ss"); // Форматируем дату и время

    // Получаем логин текущего пользователя (предполагаем, что он сохранен в NetworkClient)
    QString login = NetworkClient::getInstance().getLogin();

    // Проверяем, что логин не пустой
    if (login.isEmpty()) {
        qDebug() << "Login is empty! Trip not created.";
        return; // Выходим из функции, если логин пустой
    }

    // Логируем значение логина для отладки
    qDebug() << "Login:" << login;

    // Формируем команду для отправки на сервер
    QString command = QString("trip&%1&%2&%3&%4\r\n").arg(login, from, to, time);

    // Отправляем команду на сервер через NetworkClient
    NetworkClient::getInstance().sendMessage(command);

    emit goToFinishWindow(); //  Отправляем сигнал goToFinishWindow
}

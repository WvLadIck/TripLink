/**
 * @file carwindow.cpp
 * @brief Файл реализации класса CarWindow.
 */

#include "carwindow.h"
#include "ui_carwindow.h"
#include "networkclient.h"
#include <QMessageBox>

CarWindow::CarWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarWindow)
{
    ui->setupUi(this);
    connect(ui->toolButton_then0, &QToolButton::clicked, this, &CarWindow::on_toolButton_then0_clicked);
    connect(ui->toolButton_then1, &QToolButton::clicked, this, &CarWindow::on_toolButton_then1_clicked);
    currentTripId = -1; // Инициализируем ID поездки
}

CarWindow::~CarWindow()
{
    delete ui;
}

void CarWindow::setTripId(int tripId)
{
    currentTripId = tripId;
}

void CarWindow::on_toolButton_then0_clicked()
{
    emit returnToPreviousWindow();
}

void CarWindow::on_toolButton_then1_clicked()
{
    emit goToFinishWindow(); // Переходим в FinishWindow при нажатии на >
}

void CarWindow::displayTripInfo(const QVariantMap& tripInfo)
{
    currentTrip = tripInfo; // Сохраняем информацию о поездке

    // Формируем строку для отображения информации о водителе и времени
    QString info = QString("Водитель: %1\nEmail: %2\nВремя: %3")
                       .arg(tripInfo["driver_login"].toString())
                       .arg(tripInfo["driver_email"].toString())
                       .arg(tripInfo["time"].toString());

    // Отображаем информацию в QLabel (замените "ui->label_time" на имя вашего QLabel)
    ui->label_time->setText(info);
}

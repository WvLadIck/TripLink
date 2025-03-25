#include "companionwindow.h"
#include "ui_companionwindow.h"
#include "networkclient.h"
#include <QMessageBox>
#include <QDebug>

CompanionWindow::CompanionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompanionWindow)
{
    ui->setupUi(this);
    connect(ui->toolButton_then0, &QToolButton::clicked, this, &CompanionWindow::on_toolButton_then0_clicked);
    //connect(ui->toolButton_then1, &QToolButton::clicked, this, &CompanionWindow::on_toolButton_then1_clicked);
}

CompanionWindow::~CompanionWindow()
{
    delete ui;
}

void CompanionWindow::on_toolButton_then0_clicked()
{
    emit returnToPreviousWindow();
}

void CompanionWindow::on_toolButton_then1_clicked()
{
    QString from = ui->lineEdit_from->text();
    QString to = ui->lineEdit_to->text();
    // Формируем команду для отправки на сервер
    QString command = QString("find&%1&%2\r\n").arg(from, to);
    // Отправляем команду на сервер через NetworkClient
    NetworkClient::getInstance().sendMessage(command);
}

void CompanionWindow::handleFindTripResponse(const QString& message)
{
    // Отключаем сигнал readyRead, чтобы избежать повторной обработки
    //disconnect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &CompanionWindow::handleFindTripResponse);

    if (message == "find-\r\n") {
        QMessageBox::warning(this, "Trip not found", "No trips found for the specified locations.");
        emit tripNotFound();
    } else if (message.startsWith("find+")) {
        // Обрабатываем список поездок
        QStringList tripsData = message.split("&");
        availableTrips.clear();
        for (int i = 1; i < tripsData.size(); ++i) {
            QStringList tripInfo = tripsData[i].split("$");
            if (tripInfo.size() == 4) {
                QVariantMap trip;
                trip["id"] = tripInfo[0].toInt();
                trip["driver_login"] = tripInfo[1];
                trip["driver_email"] = tripInfo[2];
                trip["time"] = tripInfo[3];
                availableTrips.append(trip);
            }
        }
        if (availableTrips.isEmpty()) {
            QMessageBox::warning(this, "Trip not found", "No trips found for the specified locations.");
            emit tripNotFound();
            return;
        }
        // Переходим к окну выбора поездки (CarWindow) и передаем ID первой поездки
        emit goToCarWindow(availableTrips[0]["id"].toInt());
    }
}

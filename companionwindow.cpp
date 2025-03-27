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
    connect(ui->toolButton_then1, &QToolButton::clicked, this, &CompanionWindow::on_toolButton_then1_clicked);
}

CompanionWindow::~CompanionWindow()
{
    delete ui;
}

QVector<QVariantMap> CompanionWindow::getAvailableTrips() const
{
    return availableTrips;
}

void CompanionWindow::on_toolButton_then0_clicked()
{
    emit returnToPreviousWindow();
}

void CompanionWindow::on_toolButton_then1_clicked()
{
    qDebug() << "on_toolButton_then1_clicked() called";
    qDebug() << "Number of available trips: " << availableTrips.size();

    if (!isSearchPerformed) {
        // Выполняем поиск поездок
        QString from = ui->lineEdit_from->text();
        QString to = ui->lineEdit_to->text();
        QString command = QString("find&%1&%2\r\n").arg(from, to);
        NetworkClient::getInstance().sendMessage(command);
        connect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &CompanionWindow::handleFindTripResponse);
        isSearchPerformed = true; // Устанавливаем состояние
    } else {
        // Проверяем доступность поездки перед бронированием
        if (availableTrips.isEmpty()) {
            QMessageBox::warning(this, "Error", "No trips available.");
            emit goToDriverCompanionWindow();
            return;
        }

        // Получаем ID первой поездки
        selectedTripId = availableTrips[0]["id"].toInt();

        // Отправляем запрос на сервер для проверки доступности поездки
        QString command = QString("check_trip&%1\r\n").arg(selectedTripId); // Добавляем новую команду
        NetworkClient::getInstance().sendMessage(command);
        connect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &CompanionWindow::handleCheckTripResponse);
    }
}

void CompanionWindow::handleFindTripResponse(const QString& message)
{
    // Отключаем сигнал readyRead, чтобы избежать повторной обработки
    disconnect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &CompanionWindow::handleFindTripResponse);

    if (message == "find-\r\n") {
        QMessageBox::warning(this, "Trip not found", "No trips found for the specified locations.");
        emit goToDriverCompanionWindow(); // Возвращаемся в DriverCompanionWindow
        availableTrips.clear();
        isSearchPerformed = false; // Сбрасываем состояние
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
            emit goToDriverCompanionWindow(); // Возвращаемся в DriverCompanionWindow
            availableTrips.clear();
            isSearchPerformed = false; // Сбрасываем состояние
            return;
        }
    }
}

void CompanionWindow::handleBookTripResponse(const QString& message)
{
    // Отключаем сигнал readyRead, чтобы избежать повторной обработки
    disconnect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &CompanionWindow::handleBookTripResponse);

    if (message == "book+\r\n") {
        QMessageBox::information(this, "Success", "Trip booked successfully!");

        // Находим информацию о забронированной поездке
        QVariantMap tripInfo;
        for (const auto& trip : availableTrips) {
            if (trip["id"].toInt() == selectedTripId) {
                tripInfo = trip;
                break;
            }
        }

        // Переходим в CarWindow и передаем информацию о поездке
        emit goToCarWindow(selectedTripId, tripInfo);
        isSearchPerformed = false; // Сбрасываем состояние
    } else {
        QMessageBox::warning(this, "Error", "Failed to book trip.");
        isSearchPerformed = false; // Сбрасываем состояние
    }
}

void CompanionWindow::handleCheckTripResponse(const QString& message)
{
    // Отключаем сигнал readyRead, чтобы избежать повторной обработки
    disconnect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &CompanionWindow::handleCheckTripResponse);

    if (message == "check_trip+\r\n") {
        // Поездка доступна, бронируем
        // Получаем логин текущего пользователя
        QString login = NetworkClient::getInstance().getLogin();

        // Формируем команду для бронирования поездки
        QString command = QString("book&%1&%2\r\n").arg(selectedTripId).arg(login);

        // Отправляем команду на сервер
        NetworkClient::getInstance().sendMessage(command);

        // Подключаем сигнал readyRead к слоту обработки ответа о бронировании
        connect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &CompanionWindow::handleBookTripResponse);
    } else {
        // Поездка уже забронирована
        QMessageBox::warning(this, "Error", "This trip is already booked by another user.");
        isSearchPerformed = false; // Сбрасываем состояние
    }
}

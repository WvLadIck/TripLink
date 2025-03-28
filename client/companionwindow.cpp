/**
 * @file companionwindow.cpp
 * @brief Файл реализации класса CompanionWindow.
 */

#include "companionwindow.h"
#include "ui_companionwindow.h"
#include "networkclient.h"
#include <QMessageBox>
#include <QDebug>
#include <QListWidgetItem>

CompanionWindow::CompanionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompanionWindow)
{
    ui->setupUi(this);
    connect(ui->toolButton_then0, &QToolButton::clicked, this, &CompanionWindow::on_toolButton_then0_clicked);
    //connect(ui->toolButton_then1, &QToolButton::clicked, this, &CompanionWindow::on_toolButton_then1_clicked);
    connect(ui->listWidget_info, &QListWidget::itemClicked, this, &CompanionWindow::on_listWidget_info_itemClicked); // Подключаем сигнал выбора поездки
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

    QString from = ui->lineEdit_from->text().trimmed();
    QString to = ui->lineEdit_to->text().trimmed();

    if (from.isEmpty() || to.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните поля 'Откуда' и 'Куда'.");
        return;
    }

    if (!isSearchPerformed) {
        // Выполняем поиск поездок
        QString command = QString("find&%1&%2\r\n").arg(from, to);
        NetworkClient::getInstance().sendMessage(command);
        connect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &CompanionWindow::handleFindTripResponse);
        isSearchPerformed = true; // Устанавливаем состояние
    } else {
        // Бронируем выбранную поездку
        if (selectedTripId == -1) {
            QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите поездку из списка.");
            return;
        }

        // Получаем логин текущего пользователя
        QString login = NetworkClient::getInstance().getLogin();

        if (login.isEmpty()) {
            QMessageBox::warning(this, "Ошибка", "Не удалось получить логин пользователя. Пожалуйста, авторизуйтесь.");
            return;
        }

        // Формируем команду для бронирования поездки
        QString command = QString("book&%1&%2\r\n").arg(selectedTripId).arg(login);

        // Отправляем команду на сервер
        NetworkClient::getInstance().sendMessage(command);

        // Подключаем сигнал readyRead к слоту обработки ответа о бронировании
        disconnect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &CompanionWindow::handleFindTripResponse);
        connect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &CompanionWindow::handleBookTripResponse);
    }
}

void CompanionWindow::handleFindTripResponse(const QString& message)
{
    // Отключаем сигнал readyRead, чтобы избежать повторной обработки
    disconnect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &CompanionWindow::handleFindTripResponse);

    if (message == "find-\r\n") {
        QMessageBox::warning(this, "Поездка не найдена", "Нет поездок по заданному направлению.");
        emit goToDriverCompanionWindow(); // Возвращаемся в DriverCompanionWindow
        availableTrips.clear();
        isSearchPerformed = false; // Сбрасываем состояние
        ui->listWidget_info->clear(); // Очищаем список поездок
    } else if (message.startsWith("find+")) {
        // Обрабатываем список поездок
        QStringList tripsData = message.split("&");
        availableTrips.clear();
        ui->listWidget_info->clear(); // Очищаем список поездок

        for (int i = 1; i < tripsData.size(); ++i) {
            QStringList tripInfo = tripsData[i].split("$");
            if (tripInfo.size() == 4) {
                QVariantMap trip;
                trip["id"] = tripInfo[0].toInt();
                trip["driver_login"] = tripInfo[1];
                trip["driver_email"] = tripInfo[2];
                trip["time"] = tripInfo[3];
                availableTrips.append(trip);

                // Добавляем информацию о поездке в QListWidget
                QString itemText = QString("Водитель: %1, Время: %2").arg(trip["driver_login"].toString(), trip["time"].toString());
                QListWidgetItem *item = new QListWidgetItem(itemText);
                item->setData(Qt::UserRole, trip["id"].toInt()); // Сохраняем ID поездки в data
                ui->listWidget_info->addItem(item);
            }
        }

        if (availableTrips.isEmpty()) {
            QMessageBox::warning(this, "Поездка не найдена", "Нет поездок по заданному направлению.");
            emit goToDriverCompanionWindow(); // Возвращаемся в DriverCompanionWindow
            availableTrips.clear();
            isSearchPerformed = false; // Сбрасываем состояние
            ui->listWidget_info->clear(); // Очищаем список поездок
            return;
        }
    }
}

void CompanionWindow::handleBookTripResponse(const QString& message)
{
    // Отключаем сигнал readyRead, чтобы избежать повторной обработки
    disconnect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &CompanionWindow::handleBookTripResponse);

    if (message == "book+\r\n") {
        QMessageBox::information(this, "Успех", "Поездка успешно забронирована!");

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
        selectedTripId = -1; // Сбрасываем ID выбранной поездки
        ui->listWidget_info->clear(); // Очищаем список поездок
    } else if (message == "book_already_booked\r\n") {
        QMessageBox::warning(this, "Ошибка", "Эта поездка уже забронирована другим пользователем.");
        isSearchPerformed = false;
        selectedTripId = -1; // Сбрасываем ID выбранной поездки
    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось забронировать поездку.");
        isSearchPerformed = false; // Сбрасываем состояние
        selectedTripId = -1; // Сбрасываем ID выбранной поездки
    }
}

void CompanionWindow::on_listWidget_info_itemClicked(QListWidgetItem *item)
{
    selectedTripId = item->data(Qt::UserRole).toInt();
    qDebug() << "Выбрана поездка с ID:" << selectedTripId;
}

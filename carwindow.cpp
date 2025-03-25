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
    if (currentTripId == -1) {
        QMessageBox::warning(this, "Error", "Trip ID is not set.");
        return;
    }

    // Получаем логин текущего пользователя
    QString login = NetworkClient::getInstance().getLogin();

    // Формируем команду для отправки на сервер
    QString command = QString("book&%1&%2\r\n").arg(currentTripId).arg(login);

    // Отправляем команду на сервер через NetworkClient
    NetworkClient::getInstance().sendMessage(command);

    // Подключаем сигнал readyRead к слоту обработки ответа
    //connect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &CarWindow::handleBookTripResponse); // REMOVED

}

void CarWindow::handleBookTripResponse(const QString& response)
{
    // Отключаем сигнал readyRead, чтобы избежать повторной обработки
    //disconnect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &CarWindow::handleBookTripResponse); // REMOVED

    if (response == "book+\r\n") {
        QMessageBox::information(this, "Success", "Trip booked successfully!");
        emit goToFinishWindow();
    } else {
        QMessageBox::warning(this, "Error", "Failed to book trip.");
    }
}

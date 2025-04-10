#include "feetback.h"
#include "ui_feetback.h"
#include "networkclient.h" // Подключаем NetworkClient

#include <QMessageBox>
#include <QTimer>

Tpips::Tpips(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tpips)
{
    ui->setupUi(this);
    connect(ui->toolButton_0, &QToolButton::clicked, this, &Tpips::on_toolButton_0_clicked); // Подключение для кнопки <
    //connect(ui->toolButton_1, &QToolButton::clicked, this, &Tpips::on_toolButton_1_clicked); // Подключение для кнопки >
}

Tpips::~Tpips()
{
    delete ui;
}

void Tpips::on_toolButton_0_clicked()
{
    emit finished(); // Emit сигнал для возврата
}

void Tpips::on_toolButton_1_clicked()
{
    // Получаем данные из полей
    QString login = ui->lineEdit_name->text();
    QString review = ui->lineEdit_feetback->text();
    int rating = ui->spinBox_rating->value();

    // Получаем ID пользователя по логину (нужно будет отправить запрос на сервер)
    // Временное значение, пока не реализован запрос ID
    int tripId = 1; // Замените на реальный tripId, полученный от сервера

    // Формируем команды для отправки на сервер
    QString ratingCommand = QString("rating&%1&%2\r\n").arg(tripId).arg(rating);
    QString reviewCommand = QString("review&%1&%2\r\n").arg(tripId).arg(review);

    // Отправляем команду rating на сервер через NetworkClient
    NetworkClient::getInstance().sendMessage(ratingCommand);

    // Добавляем задержку перед отправкой команды review
    QTimer::singleShot(100, [this, reviewCommand]() {
        // Отправляем команду review на сервер через NetworkClient
        NetworkClient::getInstance().sendMessage(reviewCommand);

        // После отправки команды, переходим на следующее окно
        emit goToDriverCompanionWindow();
    });
}

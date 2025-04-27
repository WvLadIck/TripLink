#include "blacklistadd.h"
#include "ui_blacklistadd.h"
#include "networkclient.h"
#include <QTcpSocket>
#include <QMessageBox>

BlacklistAdd::BlacklistAdd(const QString& login, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BlacklistAdd),
    login(login)
{
    ui->setupUi(this);
    loginLineEdit = ui->lineEdit_login;
    sendButton = ui->pushButton;    // Кнопка отправки

    connect(sendButton, &QPushButton::clicked, this, &BlacklistAdd::on_pushButton_clicked);

}

BlacklistAdd::~BlacklistAdd()
{
    delete ui;
}

void BlacklistAdd::on_pushButton_clicked()
{
    static bool isProcessing = false;  // Флаг, чтобы избежать повторного вызова

    if (isProcessing) {
        return;  // Если уже обрабатывается, выходим
    }

    isProcessing = true;  // Устанавливаем флаг, что процесс начался

    QString block_login = loginLineEdit->text().trimmed();


    if (block_login.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите логин пользователя.");
        return;
        isProcessing = false;
    }


    QString currentLogin = NetworkClient::getInstance().getLogin();

    // Строка отправки
    QString command = QString("addblacklist&%1&%2\r\n").arg(currentLogin).arg(block_login);
    qDebug() << "Sending command:" << command;
    // Отправляем команду
    NetworkClient::getInstance().sendMessage(command);
    isProcessing = false;
    disconnect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &BlacklistAdd::addBlacklistResponse);
    connect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &BlacklistAdd::addBlacklistResponse);
}

void BlacklistAdd::addBlacklistResponse(const QString& message)
{
    qDebug() << "Received message:" << message;  // Выводим все сообщение для проверки

    if (message.startsWith("blacklistadd+")) {
        qDebug() << "получили, работаем";
        QMessageBox::information(this, "Успех", "Пользователь добавлен в черный список!");
        accept();  // Закрытие окна
    }
}


#include "blacklist.h"
#include "ui_blacklist.h"
#include "networkclient.h"
#include "blacklistadd.h"
#include <QDebug>


Blacklist::Blacklist(const QString& login, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Blacklist),
    login(login)
{
    ui->setupUi(this);

    // Соединяем сигнал получения данных с сервером с обработчиком
    connect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &Blacklist::onBlacklistResponse);
}

Blacklist::~Blacklist()
{
    delete ui;
}

void Blacklist::on_getBlacklistButton_clicked()
{

    if (!login.isEmpty()) {
        qDebug() << "Login: " << login;
    } else {
        qDebug() << "Login is empty!";
    }

    QString command = QString("blacklist&%1\r\n").arg(NetworkClient::getInstance().getLogin());
    NetworkClient::getInstance().sendMessage(command);

    disconnect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &Blacklist::onBlacklistResponse);
    connect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &Blacklist::onBlacklistResponse);
}

void Blacklist::onBlacklistResponse(const QString& message)
{
    if (message.startsWith("blacklist+")) {
        QStringList blacklistData = message.split("&");
        for (int i = 1; i < blacklistData.size(); i += 2) {
            QString name = blacklistData[i];     // ФИО
            QString login = blacklistData[i + 1]; // Логин

            // Создаем элементы списка для ФИО и логина
            QListWidgetItem *nameItem = new QListWidgetItem(name);
            ui->listWidget->addItem(nameItem);

            QListWidgetItem *loginItem = new QListWidgetItem(login);
            ui->listWidget_2->addItem(loginItem);
        }
    }
}



// Слот для открытия окна добавления в черный список
void Blacklist::on_addButton_clicked()
{
    BlacklistAdd *addWindow = new BlacklistAdd(login, this);
    addWindow->exec();  // Открываем окно модально
    this->close();
}


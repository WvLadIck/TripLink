#include "profile.h"
#include "ui_profile.h"
#include "networkclient.h"
#include <QDebug>
#include <QListWidgetItem> // Добавляем заголовочный файл для QListWidgetItem

Profile::Profile(const QString& login, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Profile),
    login(login)
{
    ui->setupUi(this);
}

Profile::~Profile()
{
    delete ui;
}

void Profile::on_toolButton_0_clicked()
{
    emit finished();

}

void Profile::on_pushButton_clicked(){
    // Создаем элемент списка и устанавливаем текст
    QListWidgetItem *item = new QListWidgetItem(NetworkClient::getInstance().getLogin());

    // Добавляем элемент в QListWidget
    ui->listWidget_2->addItem(item);

    // Проверяем, что логин не пустой
    if (!login.isEmpty()) {
        qDebug() << "Login: " << login;
    } else {
        qDebug() << "Login is empty!";
    }

    QString command = QString("profile&%1\r\n").arg(NetworkClient::getInstance().getLogin());
    NetworkClient::getInstance().sendMessage(command);

    disconnect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &Profile::ProfileResponse);
    connect(&NetworkClient::getInstance(), &NetworkClient::readyRead, this, &Profile::ProfileResponse);
}

void Profile::ProfileResponse(const QString& message){

    if (message.startsWith("profile+")) {

        QStringList ProfileData = message.split("&");
        QString name = ProfileData[1];
        QString email = ProfileData[2];

        // Создаем элемент списка и устанавливаем текст
        QListWidgetItem *c_name = new QListWidgetItem(name);
        // Добавляем элемент в QListWidget
        ui->listWidget_1->addItem(c_name);

        // Создаем элемент списка и устанавливаем текст
        QListWidgetItem *c_email = new QListWidgetItem(email);
        // Добавляем элемент в QListWidget
        ui->listWidget_3->addItem(c_email);
    }
}

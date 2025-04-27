#include "profile.h"
#include "ui_profile.h"
#include "networkclient.h"
#include "blacklist.h"
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
    QListWidgetItem *item = new QListWidgetItem(NetworkClient::getInstance().getLogin());
    ui->listWidget_2->addItem(item);

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

void Profile::ProfileResponse(const QString& message)
{
    if (message.startsWith("profile+")) {
        QStringList ProfileData = message.split("&");
        QString name = ProfileData[1];
        QString email = ProfileData[2];

        QListWidgetItem *c_name = new QListWidgetItem(name);
        ui->listWidget_1->addItem(c_name);

        QListWidgetItem *c_email = new QListWidgetItem(email);
        ui->listWidget_3->addItem(c_email);
    }
}

// Новый слот для кнопки перехода в окно черного списка
void Profile::on_pushButton_2_clicked()
{
    Blacklist* blacklistWindow = new Blacklist(login, this);  // Создаем окно черного списка
    blacklistWindow->exec();  // Показываем окно
    this->close();
}


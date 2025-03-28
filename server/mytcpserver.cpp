/**
 * @file mytcpserver.cpp
 * @brief Реализация класса MyTcpServer, реализующего TCP-сервер.
 */

#include "mytcpserver.h"
#include "serverfunction.h"
#include "database.h"
#include <QDebug>
#include <QCoreApplication>


MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 6000)){
        qDebug() << "server is not started";
    } else {
        qDebug() << "server is started";
    }
    // Инициализация базы данных при запуске сервера
    Database::getInstance().createTable();
}


void MyTcpServer::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection();
    mTcpSocket->write("Hello, World!!! I am echo server!\r\n");

    connect(mTcpSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
}

void MyTcpServer::slotServerRead()
{
    while (mTcpSocket->bytesAvailable() > 0)
    {
        QByteArray array = mTcpSocket->readAll();
        QString message = QString::fromUtf8(array).trimmed(); // Убираем лишние пробелы и переводы строк
        qDebug() << "Received message:" << message;

        if (message.startsWith("auth&")) {
            ServerFunction::handleAuth(mTcpSocket, message);
        } else if (message.startsWith("reg&")) {
            ServerFunction::handleReg(mTcpSocket, message);
        } else if (message.startsWith("stat&")) {
            ServerFunction::handleStat(mTcpSocket, message);
        } else if (message.startsWith("check&")) {
            ServerFunction::handleCheck(mTcpSocket, message);
        } else if (message.startsWith("trip&")) {
            ServerFunction::handleTrip(mTcpSocket, message);
        } else if (message.startsWith("rating&")) {
            ServerFunction::handleRating(mTcpSocket, message);
        } else if (message.startsWith("review&")) { // Обработка команды review
            ServerFunction::handleReview(mTcpSocket, message);
        } else if (message.startsWith("find&")) {
            ServerFunction::handleFindTrip(mTcpSocket, message);
        } else if (message.startsWith("book&")) {
            ServerFunction::handleBookTrip(mTcpSocket, message);
        } else {
            mTcpSocket->write("Unknown command\r\n");
        }
    }
}

void MyTcpServer::slotClientDisconnected()
{
    mTcpSocket->close();
}

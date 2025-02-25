
#include "mytcpserver.h"
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
    while(mTcpSocket->bytesAvailable() > 0)
    {
        QByteArray array = mTcpSocket->readAll();
        QString message = QString::fromUtf8(array);

        // Обработка команд
        if (message.startsWith("auth&")) {
            QStringList parts = message.split("&");
            if (parts.size() == 3) {
                QString login = parts[1];
                QString password = parts[2];
                mTcpSocket->write(QString("auth+&%1").arg(login).toUtf8());
            } else {
                mTcpSocket->write("auth-\r\n");
            }
        } else if (message.startsWith("reg&")) {
            QStringList parts = message.split("&");
            if (parts.size() == 4) {
                QString login = parts[1];
                QString password = parts[2];
                QString email = parts[3];

                mTcpSocket->write(QString("reg+&%1").arg(login).toUtf8());
            } else {
                mTcpSocket->write("reg-\r\n");
            }
        } else if (message.startsWith("stat&")) {
            QStringList parts = message.split("&");
            if (parts.size() == 2) {
                QString login = parts[1];
                mTcpSocket->write("stat&3$6&21\r\n");
                mTcpSocket->write("stat&0&3&-4\r\n");
            } else {
                mTcpSocket->write("stat-\r\n");
            }
        } else if (message.startsWith("check&")) {
            QStringList parts = message.split("&");
            if (parts.size() == 4) {
                QString taskNumber = parts[1];
                QString variant = parts[2];
                QString answer = parts[3];
                mTcpSocket->write("check+\r\n");
            } else {
                mTcpSocket->write("check-\r\n");
            }
        } else {
            mTcpSocket->write("Unknown command\r\n");
        }
    }
}

void MyTcpServer::slotClientDisconnected()
{
    mTcpSocket->close();
}

#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>

MyTcpServer::MyTcpServer() : mTcpServer(new QTcpServer(this))
{
    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if (!mTcpServer->listen(QHostAddress::Any, 6000)) {
        qDebug() << "Server is not started";
    } else {
        qDebug() << "Server is started";
    }
}

void MyTcpServer::slotNewConnection()
{
    QTcpSocket *socket = mTcpServer->nextPendingConnection();

    socket->write("Hello, World!!! I am echo server!\r\n");

    connect(socket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(socket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);

    Sockets.push_back(socket);
    qDebug() << "Client connected:" << socket->socketDescriptor();
}

void MyTcpServer::slotServerRead()
{
    QTcpSocket *senderSocket = qobject_cast<QTcpSocket*>(sender());
    if (senderSocket)
    {
        while (senderSocket->bytesAvailable() > 0)
        {
            QByteArray array = senderSocket->readAll();
            QString message = QString::fromUtf8(array);

            // Обработка команд
            if (message.startsWith("auth&")) {
                QStringList parts = message.split("&");
                if (parts.size() == 3) {
                    QString login = parts[1];
                    QString password = parts[2];
                    senderSocket->write(QString("auth+&%1").arg(login).toUtf8());
                } else {
                    senderSocket->write("auth-\r\n");
                }
            } else if (message.startsWith("reg&")) {
                QStringList parts = message.split("&");
                if (parts.size() == 4) {
                    QString login = parts[1];
                    QString password = parts[2];
                    QString email = parts[3];

                    senderSocket->write(QString("reg+&%1").arg(login).toUtf8());
                } else {
                    senderSocket->write("reg-\r\n");
                }
            } else if (message.startsWith("stat&")) {
                QStringList parts = message.split("&");
                if (parts.size() == 2) {
                    QString login = parts[1];
                    senderSocket->write("stat&3$6&21\r\n");
                    senderSocket->write("stat&0&3&-4\r\n");
                } else {
                    senderSocket->write("stat-\r\n");
                }
            } else if (message.startsWith("check&")) {
                QStringList parts = message.split("&");
                if (parts.size() == 4) {
                    QString taskNumber = parts[1];
                    QString variant = parts[2];
                    QString answer = parts[3];
                    senderSocket->write("check+\r\n");
                } else {
                    senderSocket->write("check-\r\n");
                }
            } else {
                senderSocket->write("Unknown command\r\n");
            }
        }
    }
}

void MyTcpServer::slotClientDisconnected()
{
    QTcpSocket *senderSocket = qobject_cast<QTcpSocket*>(sender());
    if (senderSocket) {
        Sockets.removeOne(senderSocket);
        senderSocket->deleteLater();
        qDebug() << "Client disconnected";
    }
}

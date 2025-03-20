#include "networkclient.h"
#include <QDebug>

NetworkClient::NetworkClient() : socket(new QTcpSocket(this)), isConnected(false)
{
    connect(socket, &QTcpSocket::connected, this, &NetworkClient::connectedToServer);
    connect(socket, &QTcpSocket::disconnected, this, &NetworkClient::disconnectedFromServer);
    connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::error), this, &NetworkClient::socketError);
    connect(socket, &QTcpSocket::readyRead, this, &NetworkClient::readyRead);
}

NetworkClient::~NetworkClient()
{
    if (socket->isOpen()) {
        socket->close();
    }
    socket->deleteLater();
}

void NetworkClient::connectToServer(const QString& host, quint16 port)
{
    if (isConnected) {
        qDebug() << "Already connected to server.";
        return;
    }

    serverHost = host;
    serverPort = port;
    socket->connectToHost(host, port);
}

void NetworkClient::sendMessage(const QString& message)
{
    if (!isConnected) {
        emit error("Not connected to server.");
        return;
    }

    QByteArray data = message.toUtf8();
    socket->write(data);
    socket->flush();
}

void NetworkClient::connectedToServer()
{
    isConnected = true;
    qDebug() << "Connected to server:" << serverHost << ":" << serverPort;
    emit connectionStatusChanged(true);
}

void NetworkClient::disconnectedFromServer()
{
    isConnected = false;
    qDebug() << "Disconnected from server:" << serverHost << ":" << serverPort;
    emit connectionStatusChanged(false);
}

void NetworkClient::socketError(QAbstractSocket::SocketError socketError)
{
    isConnected = false;
    QString errorMessage;
    switch (socketError) {
    case QAbstractSocket::HostNotFoundError:
        errorMessage = "Host not found";
        break;
    case QAbstractSocket::ConnectionRefusedError:
        errorMessage = "Connection refused";
        break;
    default:
        errorMessage = "Socket error: " + socket->errorString();
        break;
    }
    qDebug() << errorMessage;
    emit error(errorMessage);
}

void NetworkClient::readyRead()
{
    QByteArray data = socket->readAll();
    QString message = QString::fromUtf8(data);
    qDebug() << "Received:" << message;
    // Здесь можно добавить логику обработки полученных данных
}

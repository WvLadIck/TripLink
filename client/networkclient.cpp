#include "networkclient.h"
#include <QDebug>

// Реализация приватного конструктора класса NetworkClient
NetworkClient::NetworkClient() : socket(new QTcpSocket(this)), isConnected(false), login("")
{
    // Подключаем сигналы сокета к слотам NetworkClient
    connect(socket, &QTcpSocket::connected, this, &NetworkClient::connectedToServer);
    // При подключении сокета вызываем слот connectedToServer
    connect(socket, &QTcpSocket::disconnected, this, &NetworkClient::disconnectedFromServer);
    // При отключении сокета вызываем слот disconnectedFromServer
    connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::errorOccurred), this, &NetworkClient::socketError);
    // При возникновении ошибки сокета вызываем слот socketError

    //connect(socket, &QTcpSocket::readyRead, this, &NetworkClient::readyRead); // REMOVED
    connect(socket, &QTcpSocket::readyRead, this, &NetworkClient::_readyRead); // Подключаем к приватному слоту

    // При поступлении данных от сервера вызываем слот readyRead
}

// Реализация деструктора класса NetworkClient
NetworkClient::~NetworkClient()
{
    if (socket->isOpen()) {
        socket->close();
    }
    socket->deleteLater();
}

// Реализация метода подключения к серверу
void NetworkClient::connectToServer(const QString& host, quint16 port)
{
    qDebug() << "Connecting to server:" << host << ":" << port; // Добавляем логирование
    // Проверяем, не подключены ли мы уже к серверу
    if (isConnected) {
        qDebug() << "Already connected to server.";
        return;
    }
    serverHost = host;
    serverPort = port;
    socket->connectToHost(host, port);
}


// Реализация метода отправки сообщения на сервер
void NetworkClient::sendMessage(const QString& message)
{
    // Проверяем, подключены ли мы к серверу
    if (!isConnected) {
        emit error("Not connected to server."); // Испускаем сигнал об ошибке
        return;
    }
    QByteArray data = message.toUtf8();
    socket->write(data);
    socket->flush();
}

// Реализация слота, вызываемого при успешном подключении к серверу
void NetworkClient::connectedToServer()
{
    isConnected = true;
    // Выводим сообщение в консоль
    qDebug() << "Connected to server:" << serverHost << ":" << serverPort;
    // Испускаем сигнал об изменении статуса соединения
    emit connectionStatusChanged(true);
}

// Реализация слота, вызываемого при отключении от сервера
void NetworkClient::disconnectedFromServer()
{
    // Устанавливаем флаг подключения в false
    isConnected = false;
    // Выводим сообщение в консоль
    qDebug() << "Disconnected from server:" << serverHost << ":" << serverPort;
    // Испускаем сигнал об изменении статуса соединения
    emit connectionStatusChanged(false);
}

// Реализация слота, вызываемого при возникновении ошибки сокета
void NetworkClient::socketError(QAbstractSocket::SocketError socketError)
{
    // Устанавливаем флаг подключения в false
    isConnected = false;
    // Определяем сообщение об ошибке в зависимости от типа ошибки
    QString errorMessage;
    switch (socketError) {
    case QAbstractSocket::HostNotFoundError:
        errorMessage = "Host not found"; // Хост не найден
        break;
    case QAbstractSocket::ConnectionRefusedError:
        errorMessage = "Connection refused"; // Соединение отклонено
        break;
    default:
        errorMessage = "Socket error: " + socket->errorString(); // Другая ошибка сокета
        break;
    }
    // Выводим сообщение об ошибке в консоль
    qDebug() << errorMessage;
    // Испускаем сигнал об ошибке
    emit error(errorMessage);
}

// Реализация слота, вызываемого при поступлении данных от сервера
//void NetworkClient::readyRead(const QString& message) // REMOVED
void NetworkClient::_readyRead()
{
    // Считываем все доступные данные из сокета
    QByteArray data = socket->readAll();
    // Преобразуем данные в строку
    QString message = QString::fromUtf8(data);
    // Выводим полученное сообщение в консоль
    qDebug() << "Received:" << message;

    if (message.startsWith("auth+")) {
        QString login = message.split("&").at(1).trimmed();
        this->login = login;
        emit authSuccess();
    } else if (message == "auth-") {
        emit authFailed();
    } else if (message.startsWith("reg+")) {
        QString login = message.split("&").at(1).trimmed();
        this->login = login; // Сохраняем логин после регистрации
        emit regSuccess();
    } else if (message == "reg-") {
        emit regFailed();
    }

    emit readyRead(message); // Изменено: передаем сообщение
}

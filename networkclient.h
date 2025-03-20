#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

class NetworkClient : public QObject
{
    Q_OBJECT

public:
    // Статический метод для получения единственного экземпляра синглтона
    static NetworkClient& getInstance()
    {
        static NetworkClient instance; // Создается только один раз
        return instance;
    }

    // Запрещаем создание копий и присваивание
    NetworkClient(NetworkClient const&) = delete;
    void operator=(NetworkClient const&) = delete;

    // Методы для работы с клиентом
    void connectToServer(const QString& host, quint16 port);
    void sendMessage(const QString& message);

signals:
    void connectionStatusChanged(bool connected);
    void error(const QString& message);

private slots:
    void connectedToServer();
    void disconnectedFromServer();
    void socketError(QAbstractSocket::SocketError socketError);
    void readyRead();

private:
    NetworkClient(); // Приватный конструктор
    ~NetworkClient() override;

    QTcpSocket* socket;
    QString serverHost;
    quint16 serverPort;
    bool isConnected;
};

#endif // NETWORKCLIENT_H

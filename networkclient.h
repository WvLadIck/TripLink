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
        static NetworkClient instance; // Создается только один раз при первом вызове
        return instance;
    }

    // Запрещаем создание копий и присваивание, чтобы гарантировать единственность экземпляра
    NetworkClient(NetworkClient const&) = delete;
    void operator=(NetworkClient const&) = delete;

    // Методы для работы с клиентом
    void connectToServer(const QString& host, quint16 port); // Подключение к серверу
    void sendMessage(const QString& message);                 // Отправка сообщения на сервер

    // Метод для получения логина текущего пользователя
    QString getLogin() const { return login; }

signals:
    void connectionStatusChanged(bool connected); // Сигнал об изменении статуса соединения (подключен/отключен)
    void error(const QString& message);           // Сигнал об ошибке
    void authSuccess(); // Сигнал об успешной авторизации (передаем логин)
    void authFailed();  // Сигнал о неудачной авторизации
    void regSuccess();  // Сигнал об успешной регистрации (передаем логин)
    void regFailed();   // Сигнал о неудачной регистрации

private slots:
    void connectedToServer();    // Слот, вызываемый при успешном подключении к серверу
    void disconnectedFromServer(); // Слот, вызываемый при отключении от сервера
    void socketError(QAbstractSocket::SocketError socketError); // Слот, вызываемый при возникновении ошибки сокета
    void readyRead();            // Слот, вызываемый при поступлении данных от сервера

private:
    NetworkClient(); // Приватный конструктор, чтобы нельзя было создать экземпляр класса напрямую
    ~NetworkClient() override; // Деструктор
    QTcpSocket* socket;   // Указатель на сокет для обмена данными с сервером
    QString serverHost;
    quint16 serverPort;
    bool isConnected;
    QString login; // Добавляем поле для хранения логина текущего пользователя
};

#endif // NETWORKCLIENT_H

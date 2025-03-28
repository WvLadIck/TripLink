/**
 * @file networkclient.h
 * @brief Заголовочный файл класса RegistrationWindow для работы с сетевым клиентом.
 */
#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

/**
 * @class NetworkClient
 * @brief Класс для работы с сетевым клиентом.
 *
 * Этот класс реализует взаимодействие с сервером через TCP-сокет.
 * Он реализует синглтон, обеспечивая наличие только одного экземпляра класса в процессе.
 * Основные функции: подключение к серверу, отправка сообщений, обработка ошибок, получение данных.
 */
class NetworkClient : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Метод для получения экземпляра синглтона.
     * @return Экземпляр класса NetworkClient.
     */
    static NetworkClient& getInstance()
    {
        static NetworkClient instance;
        return instance;
    }

    // Запрещаем создание копий и присваивание, чтобы гарантировать единственность экземпляра
    NetworkClient(NetworkClient const&) = delete;
    void operator=(NetworkClient const&) = delete;

    /**
     * @brief Метод для подключения к серверу.
     * @param host Адрес хоста.
     * @param port Порт для подключения.
     */
    void connectToServer(const QString& host, quint16 port);
    /**
     * @brief Метод для отправки сообщения на сервер.
     * @param message Сообщение для отправки.
     */
    void sendMessage(const QString& message);

    /**
     * @brief Метод для получения логина текущего пользователя.
     * @return Логин текущего пользователя.
     */
    QString getLogin() const { return login; }

    signals:
    /**
     * @brief Сигнал о статусе соединения.
     * @param connected Статус подключения (true - подключено, false - отключено).
     */
    void connectionStatusChanged(bool connected);

    /**
     * @brief Сигнал об ошибке.
     * @param message Сообщение об ошибке.
     */
    void error(const QString& message);

    /**
     * @brief Сигнал об успешной авторизации.
     */
    void authSuccess();

    /**
     * @brief Сигнал о неудачной авторизации.
     */
    void authFailed();

    /**
     * @brief Сигнал об успешной регистрации.
     */
    void regSuccess();

    /**
     * @brief Сигнал о неудачной регистрации.
     */
    void regFailed();

    /**
     * @brief Сигнал для получения сообщения от сервера.
     * @param message Сообщение.
     */
    void readyRead(const QString& message);

    /**
     * @brief Сигнал для получения ответа на запрос о бронировании поездки.
     * @param response Ответ сервера.
     */
    void bookTripResponse(const QString& response);

public slots:
    /**
     * @brief Слот, вызываемый при успешном подключении к серверу.
     */
    void connectedToServer();

    /**
     * @brief Слот, вызываемый при отключении от сервера.
     */
    void disconnectedFromServer();

    /**
     * @brief Слот для обработки ошибки сокета.
     * @param socketError Тип ошибки сокета.
     */
    void socketError(QAbstractSocket::SocketError socketError);

    /**
     * @brief Слот для обработки входящих данных от сервера.
     */
    void _readyRead();

private:
    /**
     * @brief Приватный конструктор для синглтона.
     */
    NetworkClient();

    /**
     * @brief Деструктор.
     */
    ~NetworkClient() override;

    QTcpSocket* socket; /**< Указатель на сокет для взаимодействия с сервером. */
    QString serverHost; /**< Адрес хоста сервера. */
    quint16 serverPort; /**< Порт сервера. */
    bool isConnected; /**< Флаг подключения. */
    QString login; /**< Логин текущего пользователя. */
};

#endif // NETWORKCLIENT_H

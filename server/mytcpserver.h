/**
 * @file mytcpserver.h
 * @brief Заголовочный файл для класса MyTcpServer, реализующего TCP-сервер.
 */

 #ifndef MYTCPSERVER_H
 #define MYTCPSERVER_H
 
 #include <QObject>
 #include <QTcpServer>
 #include <QTcpSocket>
 
 /**
  * @class MyTcpServer
  * @brief Класс, реализующий TCP-сервер для обработки входящих соединений и команд.
  */
 class MyTcpServer : public QObject
 {
     Q_OBJECT
 public:
     /**
      * @brief Конструктор класса MyTcpServer.
      * @param parent Указатель на родительский объект (по умолчанию nullptr).
      * 
      * Инициализирует сервер и начинает прослушивание порта 6000.
      */
     explicit MyTcpServer(QObject *parent = nullptr);
 
 public slots:
     /**
      * @brief Слот, вызываемый при новом входящем соединении.
      * 
      * Принимает соединение, отправляет приветственное сообщение клиенту
      * и подключает обработчики событий для чтения данных и отключения клиента.
      */
     void slotNewConnection();
 
     /**
      * @brief Слот для обработки входящих сообщений от клиента.
      * 
      * Обрабатывает команды от клиента, передавая их соответствующим функциям.
      */
     void slotServerRead();
 
     /**
      * @brief Слот, вызываемый при отключении клиента.
      * 
      * Закрывает соединение с клиентом.
      */
     void slotClientDisconnected();
 
 private:
     QTcpServer *mTcpServer; ///< Указатель на объект TCP-сервера.
     QTcpSocket *mTcpSocket; ///< Указатель на объект TCP-соединения с клиентом.
 };
 
 #endif // MYTCPSERVER_H
 
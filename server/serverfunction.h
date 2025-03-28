/**
 * @file serverfunction.h
 * @brief Объявление класса ServerFunction, содержащего обработчики команд сервера.
 */

 #ifndef SERVERFUNCTION_H
 #define SERVERFUNCTION_H
 
 #include <QTcpSocket>
 #include <QString>
 
 /**
  * @class ServerFunction
  * @brief Класс, содержащий статические методы для обработки команд, получаемых сервером.
  */
 class ServerFunction
 {
 public:
     /**
      * @brief Обрабатывает команду аутентификации пользователя.
      * @param socket Указатель на сокет клиента.
      * @param message Сообщение с данными для аутентификации.
      */
     static void handleAuth(QTcpSocket* socket, const QString& message);
 
     /**
      * @brief Обрабатывает команду регистрации нового пользователя.
      * @param socket Указатель на сокет клиента.
      * @param message Сообщение с данными для регистрации.
      */
     static void handleReg(QTcpSocket* socket, const QString& message);
 
     /**
      * @brief Обрабатывает команду получения статистики поездок пользователя.
      * @param socket Указатель на сокет клиента.
      * @param message Сообщение с логином пользователя.
      */
     static void handleStat(QTcpSocket* socket, const QString& message);
 
     /**
      * @brief Обрабатывает команду проверки задания.
      * @param socket Указатель на сокет клиента.
      * @param message Сообщение с параметрами проверки.
      */
     static void handleCheck(QTcpSocket* socket, const QString& message);
 
     /**
      * @brief Обрабатывает команду создания поездки.
      * @param socket Указатель на сокет клиента.
      * @param message Сообщение с данными о поездке.
      */
     static void handleTrip(QTcpSocket* socket, const QString& message);
 
     /**
      * @brief Обрабатывает команду сохранения рейтинга поездки.
      * @param socket Указатель на сокет клиента.
      * @param message Сообщение с ID поездки и рейтингом.
      */
     static void handleRating(QTcpSocket* socket, const QString& message);
 
     /**
      * @brief Обрабатывает команду сохранения отзыва о поездке.
      * @param socket Указатель на сокет клиента.
      * @param message Сообщение с ID поездки и отзывом.
      */
     static void handleReview(QTcpSocket* socket, const QString& message);
 
     /**
      * @brief Обрабатывает команду поиска поездок по заданным направлениям.
      * @param socket Указатель на сокет клиента.
      * @param message Сообщение с пунктами отправления и назначения.
      */
     static void handleFindTrip(QTcpSocket* socket, const QString& message);
 
     /**
      * @brief Обрабатывает команду бронирования поездки.
      * @param socket Указатель на сокет клиента.
      * @param message Сообщение с ID поездки и логином пассажира.
      */
     static void handleBookTrip(QTcpSocket* socket, const QString& message);
 };
 
 #endif // SERVERFUNCTION_H
 
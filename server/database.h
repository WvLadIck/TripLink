/**
 * @file database.h
 * @brief Заголовочный файл класса Database для работы с базой данных.
 */

 #ifndef DATABASE_H
 #define DATABASE_H
 
 #include <QObject>
 #include <QSqlDatabase>
 #include <QSqlQuery>
 #include <QSqlError>
 #include <QVector>
 #include <QVariant>
 
 /**
  * @class Database
  * @brief Класс для управления базой данных, реализующий паттерн Singleton.
  */
 class Database : public QObject
 {
     Q_OBJECT
 
 public:
     /**
      * @brief Получает единственный экземпляр класса Database.
      * @return Ссылка на экземпляр класса Database.
      */
     static Database& getInstance();
 
     /**
      * @brief Создает таблицы в базе данных, если они не существуют.
      * @return true, если таблицы успешно созданы, false в случае ошибки.
      */
     bool createTable();
 
     /**
      * @brief Добавляет нового пользователя в базу данных.
      * @param userData Список данных пользователя (логин, пароль, email).
      * @return true, если пользователь успешно добавлен, false в случае ошибки.
      */
     bool addUser(const QStringList& userData);
 
     /**
      * @brief Проверяет существование пользователя в базе данных.
      * @param login Логин пользователя.
      * @param password Пароль пользователя.
      * @return true, если пользователь найден, false в противном случае.
      */
     bool checkUser(const QString& login, const QString& password);
 
     /**
      * @brief Сохраняет поездку в базе данных.
      * @param userId ID пользователя (водителя).
      * @param from Место отправления.
      * @param to Место назначения.
      * @param time Время отправления.
      * @return true, если поездка успешно сохранена, false в случае ошибки.
      */
     bool saveTrip(int userId, const QString& from, const QString& to, const QString& time);
 
     /**
      * @brief Сохраняет рейтинг поездки.
      * @param tripId ID поездки.
      * @param rating Оценка поездки (число).
      * @return true, если рейтинг успешно сохранен, false в случае ошибки.
      */
     bool saveRating(int tripId, int rating);
 
     /**
      * @brief Сохраняет отзыв о поездке.
      * @param tripId ID поездки.
      * @param review Текст отзыва.
      * @return true, если отзыв успешно сохранен, false в случае ошибки.
      */
     bool saveReview(int tripId, const QString& review);
 
     /**
      * @brief Получает список поездок пользователя по его логину.
      * @param login Логин пользователя.
      * @return Вектор поездок, представленный в виде QVariant.
      */
     QVector<QVariant> getTrips(const QString& login);
 
     /**
      * @brief Получает средний рейтинг пользователя.
      * @param userId ID пользователя.
      * @return Средний рейтинг пользователя или 0.0 в случае ошибки.
      */
     double getUserRating(int userId);
 
     /**
      * @brief Ищет поездки по заданным местам отправления и назначения.
      * @param from Место отправления.
      * @param to Место назначения.
      * @return Вектор найденных поездок в виде QVariantMap.
      */
     QVector<QVariantMap> findTrips(const QString& from, const QString& to);
 
     /**
      * @brief Бронирует поездку для пассажира.
      * @param tripId ID поездки.
      * @param passengerLogin Логин пассажира.
      * @return true, если бронирование успешно, false в случае ошибки.
      */
     bool bookTrip(int tripId, const QString& passengerLogin);
 
 private:
     /**
      * @brief Приватный конструктор класса Database.
      * @param parent Указатель на родительский объект.
      */
     Database(QObject* parent = nullptr);
 
     /**
      * @brief Запрещаем копирование экземпляра класса.
      */
     Database(const Database&) = delete;
 
     /**
      * @brief Запрещаем присваивание экземпляра класса.
      */
     Database& operator=(const Database&) = delete;
 
     QSqlDatabase db; ///< Объект базы данных.
 };
 
 #endif // DATABASE_H
 
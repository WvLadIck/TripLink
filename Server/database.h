#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVector>
#include <QVariant>

class Database : public QObject
{
    Q_OBJECT

public:
    static Database& getInstance(); // метод для получения экземпляра синглтона
    bool createTable();
    bool addUser(const QStringList& userData);
    bool checkUser(const QString& login, const QString& password);
    bool saveTrip(int userId, const QString& from, const QString& to, const QString& time);
    bool saveRating(int tripId, int rating);
    bool saveReview(int tripId, const QString& review); // Добавляем объявление метода saveReview
    QVector<QVariant> getTrips(const QString& login);
    double getUserRating(int userId);
    QVector<QVariantMap> findTrips(const QString& from, const QString& to);
    bool bookTrip(int tripId, const QString& passengerLogin);
    QList<QString> getUserProfile(const QString& login);
    QVector<QString> getBlacklist(const QString& login);

private:
    Database(QObject* parent = nullptr); // приватный конструктор
    Database(const Database&) = delete; // запрет копирования
    Database& operator=(const Database&) = delete; // запрет присваивания

    QSqlDatabase db;
};

#endif // DATABASE_H

/**
 * @file database.cpp
 * @brief Реализация класса Database для работы с базой данных.
 */
#include "database.h"
#include <QDebug>


Database& Database::getInstance()
{
    static Database instance;
    return instance;
}


Database::Database(QObject* parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("server.db");

    if (!db.open()) {
        qDebug() << "Error: Could not open database.";
    } else {
        qDebug() << "Database opened successfully.";
    }
}


bool Database::createTable()
{
    QSqlQuery query;
    bool success = query.exec("CREATE TABLE IF NOT EXISTS users ("
                              "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                              "login TEXT UNIQUE NOT NULL, "
                              "password TEXT NOT NULL, "
                              "email TEXT NOT NULL)");

    if (!success) {
        qDebug() << "Error creating users table:" << query.lastError();
        return false;
    }

    success = query.exec("CREATE TABLE IF NOT EXISTS trips ("
                         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "user_id INTEGER NOT NULL, "
                         "from_location TEXT NOT NULL, "
                         "to_location TEXT NOT NULL, "
                         "time TEXT NOT NULL, "
                         "rating INTEGER, "
                         "review TEXT, "  // Новый столбец для отзыва
                         "passenger_login TEXT,"
                         "FOREIGN KEY(user_id) REFERENCES users(id))");

    if (!success) {
        qDebug() << "Error creating trips table:" << query.lastError();
        return false;
    }

    return true;
}


bool Database::addUser(const QStringList& userData)
{
    if (userData.size() != 3) return false;

    QSqlQuery query;
    query.prepare("INSERT INTO users (login, password, email) VALUES (:login, :password, :email)");
    query.bindValue(":login", userData[0]);
    query.bindValue(":password", userData[1]);
    query.bindValue(":email", userData[2]);

    if (!query.exec()) {
        qDebug() << "Error adding user:" << query.lastError();
        return false;
    }

    return true;
}


bool Database::checkUser(const QString& login, const QString& password)
{
    QSqlQuery query;
    query.prepare("SELECT id FROM users WHERE login = :login AND password = :password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Error checking user:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        qDebug() << "User found:" << login;
        return true;
    } else {
        qDebug() << "User not found:" << login;
        return false;
    }
}


bool Database::saveTrip(int userId, const QString& from, const QString& to, const QString& time)
{
    QSqlQuery query;
    query.prepare("INSERT INTO trips (user_id, from_location, to_location, time) VALUES (:user_id, :from, :to, :time)");
    query.bindValue(":user_id", userId);
    query.bindValue(":from", from);
    query.bindValue(":to", to);
    query.bindValue(":time", time);  // Добавляем время
    query.bindValue(":rating", 0);  // Начальное значение для рейтинга
    query.bindValue(":review", ""); // Начальное значение для отзыва
    if (!query.exec()) {
        qDebug() << "Error saving trip:" << query.lastError();
        return false;
    }

    return true;
}


bool Database::saveRating(int tripId, int rating)
{
    QSqlQuery query;
    query.prepare("UPDATE trips SET rating = :rating WHERE id = :tripId");
    query.bindValue(":rating", rating);
    query.bindValue(":tripId", tripId);

    if (!query.exec()) {
        qDebug() << "Error saving rating:" << query.lastError().text(); // Логируем текст ошибки
        return false;
    }

        qDebug() << "Saving rating:" << rating << "for tripId:" << tripId;
    return true;
}
    

bool Database::saveReview(int tripId, const QString& review)
    {
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT id FROM trips WHERE id = :tripId");
        checkQuery.bindValue(":tripId", tripId);

        if (!checkQuery.exec() || !checkQuery.next()) {
            qDebug() << "Trip with id" << tripId << "does not exist.";
            return false;
        }

        QSqlQuery query;
        query.prepare("UPDATE trips SET review = :review WHERE id = :tripId");
        query.bindValue(":review", review);
        query.bindValue(":tripId", tripId);

        if (!query.exec()) {
            qDebug() << "Error saving review:" << query.lastError();
            return false;
        }
            qDebug() << "Saving review:" << review << "for tripId:" << tripId;
        return true;
    }
    

QVector<QVariantMap> Database::findTrips(const QString& from, const QString& to)
    {
        QVector<QVariantMap> result;
        QSqlQuery query;
        query.prepare("SELECT t.id, u.login, u.email, t.time FROM trips t "
                      "JOIN users u ON t.user_id = u.id "
                      "WHERE t.from_location = :from AND t.to_location = :to");
        query.bindValue(":from", from);
        query.bindValue(":to", to);

        if (!query.exec()) {
            qDebug() << "Error finding trips:" << query.lastError();
            return result;
        }

        while (query.next()) {
            QVariantMap trip;
            trip["id"] = query.value(0);
            trip["driver_login"] = query.value(1);
            trip["driver_email"] = query.value(2);
            trip["time"] = query.value(3);
            result.append(trip);
        }

        return result;
    }


bool Database::bookTrip(int tripId, const QString& passengerLogin) {
        qDebug() << "Booking trip ID:" << tripId << "for passenger:" << passengerLogin;

        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT passenger_login FROM trips WHERE id = :tripId");
        checkQuery.bindValue(":tripId", tripId);

        if (!checkQuery.exec()) {
            qDebug() << "Check query error:" << checkQuery.lastError().text();
            return false;
        }

        if (checkQuery.next()) {
            QString currentPassenger = checkQuery.value(0).toString();
            qDebug() << "Current passenger:" << currentPassenger;
            if (!currentPassenger.isEmpty()) {
                qDebug() << "Trip is already booked by:" << currentPassenger;
                return false;
            }
        }

        QSqlQuery query;
        query.prepare("UPDATE trips SET passenger_login = :passenger WHERE id = :tripId");
        query.bindValue(":passenger", passengerLogin);
        query.bindValue(":tripId", tripId);

        if (!query.exec()) {
            qDebug() << "Update error:" << query.lastError().text();  // Важно: выведет конкретную SQL-ошибку
            return false;
        }

        qDebug() << "Booking successful!";
        return true;
    }


QVector<QVariant> Database::getTrips(const QString& login)
{
    QVector<QVariant> trips;
    QSqlQuery query;
    query.prepare("SELECT from_location, to_location, time FROM trips WHERE user_id = (SELECT id FROM users WHERE login = :login)");
    query.bindValue(":login", login);

    if (!query.exec()) {
        qDebug() << "Error getting trips:" << query.lastError();
        return trips;
    }

    while (query.next()) {
        QVariantMap trip;
        trip["from"] = query.value(0);
        trip["to"] = query.value(1);
        trip["time"] = query.value(2);  // Добавляем время
        trips.append(trip);
    }

    return trips;

}


double Database::getUserRating(int userId)

{
    QSqlQuery query;
    query.prepare("SELECT AVG(rating) FROM trips WHERE user_id = :user_id");
    query.bindValue(":user_id", userId);

    if (!query.exec()) {
        qDebug() << "Error getting user rating:" << query.lastError();
        return 0.0;
    }

    if (query.next()) {
        return query.value(0).toDouble();
    }

    return 0.0;
}

/**
 * @file serverfunction.cpp
 * @brief Реализация класса ServerFunction, содержащего обработчики команд сервера.
 */

#include "serverfunction.h"
#include "database.h"
#include <QStringList>

void ServerFunction::handleAuth(QTcpSocket* socket, const QString& message)
{
    QString trimmedMessage = message.trimmed(); // Убираем лишние пробелы и переводы строк
    QStringList parts = trimmedMessage.split("&");

    if (parts.size() == 3) {
        QString login = parts[1];
        QString password = parts[2];
        bool authSuccess = Database::getInstance().checkUser(login, password);

        if (authSuccess) {
            socket->write(QString("auth+&%1\r\n").arg(login).toUtf8());
        } else {
            socket->write("auth-\r\n");
        }
    } else {
        socket->write("auth-\r\n");
    }
}

void ServerFunction::handleReg(QTcpSocket* socket, const QString& message)
{
    QStringList parts = message.split("&");
    if (parts.size() == 4) {
        QString login = parts[1];
        QString password = parts[2];
        QString email = parts[3];
        QStringList userData = {login, password, email};
        bool regSuccess = Database::getInstance().addUser(userData);
        if (regSuccess) {
            socket->write(QString("reg+&%1\r\n").arg(login).toUtf8());
        } else {
            socket->write("reg-\r\n");
        }
    } else {
        socket->write("reg-\r\n");
    }
}

void ServerFunction::handleStat(QTcpSocket* socket, const QString& message)
{
    QStringList parts = message.split("&");
    if (parts.size() == 2) {
        QString login = parts[1];
        QVector<QVariant> trips = Database::getInstance().getTrips(login);
        QString response = "stat&";
        for (const QVariant& trip : trips) {
            QVariantMap tripMap = trip.toMap();
            response += tripMap["from"].toString() + "$" + tripMap["to"].toString() + "$" + tripMap["time"].toString() + "&";  // Добавляем время
        }
        response += "\r\n";
        socket->write(response.toUtf8());
    } else {
        socket->write("stat-\r\n");
    }
}

void ServerFunction::handleCheck(QTcpSocket* socket, const QString& message)
{
    QStringList parts = message.split("&");
    if (parts.size() == 4) {
        QString taskNumber = parts[1];
        QString variant = parts[2];
        QString answer = parts[3];
        // Здесь можно добавить логику проверки ответа
        socket->write("check+\r\n");
    } else {
        socket->write("check-\r\n");
    }
}
void ServerFunction::handleTrip(QTcpSocket* socket, const QString& message)
{
    QStringList parts = message.split("&");
    if (parts.size() == 5) {  // Теперь ожидаем 5 частей: команда, логин, откуда, куда, время
        QString login = parts[1];
        QString from = parts[2];
        QString to = parts[3];
        QString time = parts[4];  // Получаем время

        // Получаем ID пользователя по логину
        QSqlQuery query;
        query.prepare("SELECT id FROM users WHERE login = :login");
        query.bindValue(":login", login);

        if (!query.exec()) {
            qDebug() << "Error getting user ID:" << query.lastError();
            socket->write("trip-\r\n");
            return;
        }

        if (query.next()) {
            int userId = query.value(0).toInt();
            bool success = Database::getInstance().saveTrip(userId, from, to, time);  // Передаем время

            if (success) {
                socket->write("trip+\r\n");
            } else {
                socket->write("trip-\r\n");
            }
        } else {
            socket->write("trip-\r\n");
        }
    } else {
        socket->write("trip-\r\n");
    }
}
void ServerFunction::handleRating(QTcpSocket* socket, const QString& message)
{
    QString trimmedMessage = message.trimmed(); // Убираем лишние пробелы и переводы строк
    QStringList parts = trimmedMessage.split("&");

    if (parts.size() == 3) {  // Ожидаем команду, ID поездки и рейтинг
        int tripId = parts[1].toInt();
        int rating = parts[2].toInt();

        qDebug() << "Parsed tripId:" << tripId << "and rating:" << rating;

        bool success = Database::getInstance().saveRating(tripId, rating);

        if (success) {
            socket->write("rating+\r\n");
        } else {
            socket->write("rating-\r\n");
        }
    } else {
        socket->write("rating-\r\n");
    }
}
void ServerFunction::handleReview(QTcpSocket* socket, const QString& message)
{
    QStringList parts = message.split("&");
    if (parts.size() == 3) {  // Ожидаем команду, ID поездки и отзыв
        int tripId = parts[1].toInt();
        QString review = parts[2];

        qDebug() << "Parsed tripId:" << tripId << "and review:" << review;

        bool success = Database::getInstance().saveReview(tripId, review);

        if (success) {
            socket->write("review+\r\n");
        } else {
            socket->write("review-\r\n");
        }
    } else {
        socket->write("review-\r\n");
    }
}
void ServerFunction::handleFindTrip(QTcpSocket* socket, const QString& message)
{
    QStringList parts = message.split("&");
    if (parts.size() == 3) {
        QString from = parts[1];
        QString to = parts[2];

        auto trips = Database::getInstance().findTrips(from, to);

        if (trips.isEmpty()) {
            socket->write("find-\r\n");
        } else {
            QString response = "find+";
            for (const auto& trip : trips) {
                response += QString("&%1$%2$%3$%4")
                .arg(trip["id"].toString())
                    .arg(trip["driver_login"].toString())
                    .arg(trip["driver_email"].toString())
                    .arg(trip["time"].toString());
            }
            response += "\r\n";
            socket->write(response.toUtf8());
        }
    } else {
        socket->write("find-\r\n");
    }
}

void ServerFunction::handleBookTrip(QTcpSocket* socket, const QString& message)
{
    QStringList parts = message.split("&");
    if (parts.size() == 3) {
        int tripId = parts[1].toInt();
        QString passengerLogin = parts[2]; // Логин пассажира из сообщения

        bool success = Database::getInstance().bookTrip(tripId, passengerLogin);

        if (success) {
            socket->write("book+\r\n");
        } else {
            // Проверяем, была ли поездка уже забронирована
            QSqlQuery checkQuery;
            checkQuery.prepare("SELECT passenger_login FROM trips WHERE id = :tripId");
            checkQuery.bindValue(":tripId", tripId);

            if (checkQuery.exec() && checkQuery.next()) {
                QString currentPassenger = checkQuery.value(0).toString();
                if (!currentPassenger.isEmpty()) {
                    socket->write("book_already_booked\r\n"); // Специальное сообщение о том, что поездка уже забронирована
                    return;
                }
            }
            socket->write("book-\r\n"); // Общая ошибка
        }
    } else {
        socket->write("book-\r\n");
    }
}

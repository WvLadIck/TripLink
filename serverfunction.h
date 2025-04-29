#ifndef SERVERFUNCTION_H
#define SERVERFUNCTION_H

#include <QTcpSocket>
#include <QString>

class ServerFunction
{
public:
    static void handleAuth(QTcpSocket* socket, const QString& message);
    static void handleReg(QTcpSocket* socket, const QString& message);
    static void handleStat(QTcpSocket* socket, const QString& message);
    static void handleCheck(QTcpSocket* socket, const QString& message);
    static void handleTrip(QTcpSocket* socket, const QString& message);
};

#endif // SERVERFUNCTION_H

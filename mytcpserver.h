#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    MyTcpServer();

private:
    QTcpServer *mTcpServer;
    QVector<QTcpSocket*> Sockets;

public slots:
    void slotNewConnection(); // Обратите внимание, что здесь убран аргумент
    void slotServerRead();
    void slotClientDisconnected();
};

#endif // MYTCPSERVER_H

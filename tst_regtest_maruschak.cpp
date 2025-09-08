#include <QtTest>
#include <QSignalSpy>
#include <QTcpSocket>
#include <QCoreApplication>
#include <QDateTime>

#include "../TripLink2_0/TripLink/server/serverfunction.h"
#include "../TripLink2_0/TripLink/server/database.h"

class TestReg : public QObject
{
    Q_OBJECT

public:
    TestReg();
    ~TestReg();

private slots:
    void testSuccessfulReg();
    void testFailedReg();
    void testInvalidEmail();

private:
    QTcpSocket* testSocket;
    Database* db; // Теперь Database известен
    QCoreApplication* app;
    QString testUser = "testuser_" + QString::number(QDateTime::currentSecsSinceEpoch());
    QString testPass = "testpass";
    QString testEmail = "test_" + QString::number(QDateTime::currentSecsSinceEpoch()) + "@example.com";
};

TestReg::TestReg() {
    int argc = 0;
    char** argv = nullptr;
    app = new QCoreApplication(argc, argv);

    testSocket = new QTcpSocket(this);
    testSocket->connectToHost("localhost", 6000);
    if (!testSocket->waitForConnected(1000)) {
        QFAIL("Не удалось подключиться к серверу!");
    }

    // Считываем приветственное сообщение
    if (!testSocket->waitForReadyRead(1000)) {
        QFAIL("Не удалось прочитать приветственное сообщение от сервера!");
    }
    testSocket->readAll(); // Игнорируем приветственное сообщение
}

TestReg::~TestReg() {
    testSocket->disconnectFromHost();
    testSocket->waitForDisconnected();
    delete testSocket;
    delete app;
}

void TestReg::testSuccessfulReg()
{
    QByteArray message = QString("reg&%1&%2&%3\r\n").arg(testUser).arg(testPass).arg(testEmail).toUtf8();
    testSocket->write(message);

    // Увеличиваем время ожидания
    if (!testSocket->waitForReadyRead(5000)) {
        QFAIL("No response from server");
    }

    QByteArray response = testSocket->readAll();
    QString responseStr = QString::fromUtf8(response).trimmed();
    QString firstLine = responseStr.split('\n').first().trimmed();

    QVERIFY2(firstLine.startsWith("reg+&"),
             qPrintable(QString("Registration should be successful. Actual response: '%1'").arg(responseStr)));
    QVERIFY2(firstLine.contains(testUser),
             qPrintable(QString("Response should contain username. Actual response: '%1'").arg(responseStr)));
}

void TestReg::testFailedReg()
{
    // Попытка регистрации с уже существующим логином
    QByteArray message = QString("reg&%1&%2&%3\r\n").arg(testUser).arg(testPass).arg(testEmail).toUtf8();
    testSocket->write(message);

    // Увеличиваем время ожидания
    if (!testSocket->waitForReadyRead(5000)) {
        QFAIL("No response from server");
    }

    QByteArray response = testSocket->readAll();
    QString responseStr = QString::fromUtf8(response).trimmed();
    QString firstLine = responseStr.split('\n').first().trimmed();

    QCOMPARE(firstLine, QString("reg-"));
}

void TestReg::testInvalidEmail()
{
    QByteArray message = QString("reg&%1&%2&invalid_email\r\n").arg(testUser).arg(testPass).toUtf8();
    testSocket->write(message);

    // Увеличиваем время ожидания
    if (!testSocket->waitForReadyRead(5000)) {
        QFAIL("No response from server");
    }

    QByteArray response = testSocket->readAll();
    QString responseStr = QString::fromUtf8(response).trimmed();
    QString firstLine = responseStr.split('\n').first().trimmed();

    QCOMPARE(firstLine, QString("reg_invalid_email"));
}

QTEST_GUILESS_MAIN(TestReg)
#include "tst_regtest.moc"

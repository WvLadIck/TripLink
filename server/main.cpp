/**
 * @file main.cpp
 * @brief Главный файл приложения, запускающий TCP сервер.
 */

 #include <QCoreApplication>
 #include "mytcpserver.h"
 
 int main(int argc, char *argv[])
 {
     QCoreApplication a(argc, argv);
     MyTcpServer server;
     return a.exec();
 }
 
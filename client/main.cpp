#include "managerform.h"
#include <QApplication>

/**
 * @file main.cpp
 * @brief Главный файл приложения.
 * 
 * Этот файл инициализирует приложение, создаёт главное окно и запускает основной цикл обработки событий.
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    ManagerForm w;
    
    return a.exec();
}


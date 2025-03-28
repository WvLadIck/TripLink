/**
 * @file function_for_client.cpp
 * @brief Файл реализации функций авторизации и регистрации.
 */

#include "function_for_client.h"

bool auth(QString login, QString password) {
    if (login == "user" && password == "123")
        return true;
    else
        return false;
}

bool reg(QString login, QString password, QString name, QString phone) {
    if ((login != "user" || password != "123") && name != "" && phone != "")
        return true;
    else
        return false;
}

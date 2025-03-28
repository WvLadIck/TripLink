/**
 * @file function_for_client.h
 * @brief Заголовочный файл с функциями авторизации и регистрации.
 */

#ifndef FUNCTION_FOR_CLIENT_H
#define FUNCTION_FOR_CLIENT_H

#include <QString>

/**
 * @brief Функция для авторизации пользователя.
 * 
 * Проверяет введенные логин и пароль.
 * @param login Логин пользователя.
 * @param password Пароль пользователя.
 * @return true, если авторизация успешна, иначе false.
 */
bool auth(QString login, QString password);

/**
 * @brief Функция для регистрации нового пользователя.
 * 
 * Проверяет введенные данные для регистрации пользователя.
 * @param login Логин пользователя.
 * @param password Пароль пользователя.
 * @param name Имя пользователя.
 * @param phone Телефон пользователя.
 * @return true, если регистрация успешна, иначе false.
 */
bool reg(QString login, QString password, QString name, QString phone);

#endif // FUNCTION_FOR_CLIENT_H

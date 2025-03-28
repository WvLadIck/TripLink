/**
 * @file loginwindow.h
 * @brief Заголовочный файл класса LoginWindow, реализующего окно авторизации.
 */

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "function_for_client.h"
#include "networkclient.h"
namespace Ui {
    class LoginWindow;
}

/**
 * @class LoginWindow
 * @brief Класс окна авторизации.
 * 
 * Этот класс реализует окно авторизации, которое позволяет пользователю вводить логин и пароль.
 * После успешной или неудачной авторизации генерируются соответствующие сигналы.
 */
class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса LoginWindow.
     * 
     * Инициализирует интерфейс и подключает сигналы для обработки событий авторизации.
     * @param parent Родительский элемент (по умолчанию nullptr).
     */
    explicit LoginWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса LoginWindow.
     * 
     * Освобождает ресурсы, связанные с интерфейсом окна.
     */
    ~LoginWindow();

signals:
    /**
     * @brief Сигнал для возврата в главное окно.
     */
    void returnToMainWindow();

    /**
     * @brief Сигнал для перехода к окну "DriverCompanionWindow".
     */
    void goToDriverCompanionWindow();

private slots:
    /**
     * @brief Слот для обработки нажатия кнопки возврата в главное окно.
     */
    void on_toolButton_then0_clicked();

    /**
     * @brief Слот для отправки данных авторизации на сервер.
     */
    void on_toolButton_then1_clicked();

    /**
     * @brief Слот для обработки успешной авторизации.
     * 
     * Показывает сообщение об успешной авторизации и генерирует сигнал для перехода к следующему окну.
     */
    void onAuthSuccess();

    /**
     * @brief Слот для обработки неудачной авторизации.
     * 
     * Показывает сообщение о неудачной авторизации и очищает поля ввода.
     */
    void onAuthFailed();

    /**
     * @brief Слот для обработки ошибок.
     * 
     * Показывает сообщение с описанием ошибки.
     */
    void onError(const QString& message);

private:
    Ui::LoginWindow *ui; /**< Указатель на интерфейс окна авторизации. */
    
    /**
     * @brief Очищает поля ввода.
     */
    void clear();
};

#endif // LOGINWINDOW_H

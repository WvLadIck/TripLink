/**
 * @file registrationwindow.h
 * @brief Заголовочный файл класса RegistrationWindow для реализации окна регистрации.
 */
#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include "function_for_client.h"
#include "networkclient.h" // Добавляем заголовочный файл

namespace Ui {
class RegistrationWindow;
}

/**
 * @class RegistrationWindow
 * @brief Класс окна регистрации пользователя.
 *
 * Этот класс реализует окно, которое позволяет пользователю зарегистрироваться в системе.
 * Он включает обработку ввода логина, пароля и email, а также взаимодействует с сервером для выполнения регистрации.
 */
class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор.
     * @param parent Родительский элемент (по умолчанию nullptr).
     */
    explicit RegistrationWindow(QWidget *parent = nullptr);
    /**
     * @brief Деструктор.
     */
    ~RegistrationWindow();

signals:
    /**
     * @brief Сигнал для возврата на главное окно.
     */
    void returnToMainWindow();
    /**
     * @brief Сигнал для перехода в окно водителя-сопутника.
     */
    void goToDriverCompanionWindow();

private slots:
    /**
     * @brief Слот для обработки нажатия на кнопку для возврата на главное окно.
     */
    void on_toolButton_then0_clicked();
    /**
     * @brief Слот для обработки нажатия на кнопку регистрации.
     */
    void on_toolButton_then1_clicked();
    /**
     * @brief Слот, вызываемый при успешной регистрации.
     */
    void onRegSuccess(); 
    /**
     * @brief Слот, вызываемый при неудачной регистрации.
     */
    void onRegFailed();
    /**
     * @brief Слот для обработки ошибок, связанных с регистрацией.
     * @param message Сообщение об ошибке.
     */
    void onError(const QString& message); 

private:
    Ui::RegistrationWindow *ui; /**< Указатель на пользовательский интерфейс окна регистрации. */
    /**
     * @brief Очистка полей ввода.
     */
    void clear();
};

#endif // REGISTRATIONWINDOW_H

/**
 * @file managerform.h
 * @brief Заголовочный файл класса ManagerForm для управления окнами приложения.
 */

#ifndef MANAGERFORM_H
#define MANAGERFORM_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QMap>
#include "mainwindow.h"
#include "loginwindow.h"
#include "registrationwindow.h"
#include "drivercompanionwindow.h"
#include "companionwindow.h"
#include "driverwindow.h"
#include "carwindow.h"
#include "finishwindow.h"
#include "networkclient.h"
#include "feetback.h"

/**
 * @class ManagerForm
 * @brief Класс, управляющий окнами приложения.
 *
 * Этот класс реализует главный менеджер, который управляет навигацией между различными окнами в приложении.
 * Он организует взаимодействие с окнами, такими как: вход, регистрация, водитель, компаньон, и т.д.
 */
class ManagerForm : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор.
     * @param parent Родительский элемент (по умолчанию nullptr).
     */
    explicit ManagerForm(QWidget *parent = nullptr);

    /**
     * @brief Деструктор.
     */
    ~ManagerForm();

private slots:
    /**
     * @brief Слот для отображения окна входа.
     */
    void showLoginWindow();

    /**
     * @brief Слот для отображения окна регистрации.
     */
    void showRegistrationWindow();

    /**
     * @brief Слот для отображения окна водителя-сопутника.
     */
    void showDriverCompanionWindow();

    /**
     * @brief Слот для отображения окна компаньона.
     */
    void showCompanionWindow();

    /**
     * @brief Слот для отображения окна водителя.
     */
    void showDriverWindow();

    /**
     * @brief Слот для отображения окна с информацией о машине.
     * @param tripId ID поездки.
     * @param tripInfo Информация о поездке.
     */
    void showCarWindow(int tripId, QVariantMap tripInfo);

    /**
     * @brief Слот для обработки возврата на предыдущее окно.
     */
    void handleReturnToPrevious();

    /**
     * @brief Слот для отображения окна завершения.
     */
    void showFinishWindow();

    /**
     * @brief Слот для отображения главного окна из окна завершения.
     */
    void showMainWindowFromFinish();

    /**
     * @brief Слот для изменения статуса подключения.
     * @param connected Статус подключения.
     */
    void onConnectionStatusChanged(bool connected);

    /**
     * @brief Слот для отображения окна отзывов.
     */
    void showFeedbackWindow();

    /**
     * @brief Слот для отображения окна водителя-сопутника из окна компаньона.
     */
    void showDriverCompanionWindowFromCompanion();

private:
    MainWindow *Main_Window; /**< Указатель на главное окно. */
    LoginWindow *Login_Window; /**< Указатель на окно входа. */
    RegistrationWindow *Reg_Window; /**< Указатель на окно регистрации. */
    DriverCompanionWindow *Drive_Comp_Window; /**< Указатель на окно водителя-сопутника. */
    CompanionWindow *Comp
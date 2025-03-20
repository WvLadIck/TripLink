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
#include "networkclient.h" // Добавляем заголовочный файл

class ManagerForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManagerForm(QWidget *parent = nullptr);
    ~ManagerForm();

private slots:
    void showLoginWindow();
    void showRegistrationWindow();
    void showDriverCompanionWindow();
    void showCompanionWindow();
    void showDriverWindow();
    void showCarWindow();
    void handleReturnToPrevious();
    void showFinishWindow();
    void showMainWindowFromFinish();
    void onConnectionStatusChanged(bool connected); // Новый слот

private:
    MainWindow *Main_Window;
    LoginWindow *Login_Window;
    RegistrationWindow *Reg_Window;
    DriverCompanionWindow *Drive_Comp_Window;
    CompanionWindow *Companion_Window;
    DriverWindow *Driver_Window;
    CarWindow *Car_Window;
    FinishWindow * Finish_Window;

    QMap<QWidget*, QWidget*> windowMap; // Упрощенная карта
};

#endif // MANAGERFORM_H

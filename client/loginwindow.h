#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "function_for_client.h"
#include "profile.h"
#include "networkclient.h" // Добавляем заголовочный файл

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

signals:
    void returnToMainWindow();
    void goToDriverCompanionWindow();

private slots:
    void on_toolButton_then0_clicked();
    void on_toolButton_then1_clicked();
    void onAuthSuccess(); // Изменяем слот для получения логина
    void onAuthFailed();  // Новый слот для обработки неудачной авторизации
    void onError(const QString& message); // Новый слот для обработки ошибок

private:
    Ui::LoginWindow *ui;
    void clear();
};

#endif // LOGINWINDOW_H

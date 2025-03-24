#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include "function_for_client.h"
#include "networkclient.h" // Добавляем заголовочный файл

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr);
    ~RegistrationWindow();

signals:
    void returnToMainWindow();
    void goToDriverCompanionWindow();

private slots:
    void on_toolButton_then0_clicked();
    void on_toolButton_then1_clicked();
    void onRegSuccess(); // Новый слот для обработки успешной регистрации
    void onRegFailed();  // Новый слот для обработки неудачной регистрации
    void onError(const QString& message); // Новый слот для обработки ошибок

private:
    Ui::RegistrationWindow *ui;
    void clear();
};

#endif // REGISTRATIONWINDOW_H

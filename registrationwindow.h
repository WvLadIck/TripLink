#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include "function_for_client.h"

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
    //void on_pushButton_return_clicked(); //Удалено
    //void on_pushButton_reg_clicked(); //Удалено

private:
    Ui::RegistrationWindow *ui;
    void clear();
};

#endif // REGISTRATIONWINDOW_H

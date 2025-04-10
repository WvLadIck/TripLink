#ifndef DRIVERCOMPANIONWINDOW_H
#define DRIVERCOMPANIONWINDOW_H

#include <QDialog>

namespace Ui {
class DriverCompanionWindow;
}

class DriverCompanionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DriverCompanionWindow(QWidget *parent = nullptr);
    ~DriverCompanionWindow();

signals:
    void returnToPreviousWindow();
    void goToCompanionWindow();
    void goToDriverWindow();
    void goToFeedbackWindow();
    void goToProfileWindow();

private slots:
    void on_toolButton_then0_clicked();
    void on_pushButton_companion_clicked();
    void on_pushButton_driver_clicked();
    void on_pushButton_feetback_clicked();
    void on_pushButton_profile_clicked();

private:
    Ui::DriverCompanionWindow *ui;
};

#endif // DRIVERCOMPANIONWINDOW_H

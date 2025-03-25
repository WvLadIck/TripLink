#ifndef DRIVERWINDOW_H
#define DRIVERWINDOW_H

#include <QDialog>
#include "networkclient.h" // Добавляем заголовочный файл NetworkClient

namespace Ui {
class DriverWindow;
}

class DriverWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DriverWindow(QWidget *parent = nullptr);
    ~DriverWindow();

signals:
    void returnToPreviousWindow();
    void goToFinishWindow();

private slots:
    void on_toolButton_then0_clicked();
    void on_toolButton_then1_clicked();

private:
    Ui::DriverWindow *ui;
};

#endif // DRIVERWINDOW_H

#ifndef CARWINDOW_H
#define CARWINDOW_H

#include <QDialog>

namespace Ui {
class CarWindow;
}

class CarWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CarWindow(QWidget *parent = nullptr);
    ~CarWindow();

signals:
    void returnToPreviousWindow();
    void goToFinishWindow(); //  Сигнал для перехода к FinishWindow

private slots:
    void on_toolButton_then0_clicked();
    void on_toolButton_then1_clicked(); //  Теперь будет отправлять сигнал goToFinishWindow

private:
    Ui::CarWindow *ui;
};

#endif // CARWINDOW_H

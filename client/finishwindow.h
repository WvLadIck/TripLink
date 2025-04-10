#ifndef FINISHWINDOW_H
#define FINISHWINDOW_H

#include <QDialog>

namespace Ui {
class FinishWindow;
}

class FinishWindow : public QDialog
{
    Q_OBJECT

signals:
    void returnToMainWindow();

public:
    explicit FinishWindow(QWidget *parent = nullptr);
    ~FinishWindow();

private slots:
    void on_pushButton_home_clicked(); //  Добавьте этот слот


private:
    Ui::FinishWindow *ui;
};

#endif // FINISHWINDOW_H

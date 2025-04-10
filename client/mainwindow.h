#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void loginButtonClicked();
    void registrationButtonClicked();

private slots:
    void on_pushButton_auth_clicked();
    void on_pushButton_reg_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

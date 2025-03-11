#ifndef COMPANIONWINDOW_H
#define COMPANIONWINDOW_H

#include <QDialog>

namespace Ui {
class CompanionWindow;
}

class CompanionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CompanionWindow(QWidget *parent = nullptr);
    ~CompanionWindow();

signals:
    void returnToPreviousWindow();
    void goToCarWindow();

private slots:
    void on_toolButton_then0_clicked();
    void on_toolButton_then1_clicked();

private:
    Ui::CompanionWindow *ui;
};

#endif // COMPANIONWINDOW_H

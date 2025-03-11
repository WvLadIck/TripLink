#ifndef FINISHWINDOW_H
#define FINISHWINDOW_H

#include <QDialog>

namespace Ui {
class FinishWindow;
}

class FinishWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FinishWindow(QWidget *parent = nullptr);
    ~FinishWindow();

private:
    Ui::FinishWindow *ui;
};

#endif // FINISHWINDOW_H

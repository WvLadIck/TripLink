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
    void setTripId(int tripId);

signals:
    void returnToPreviousWindow();
    void goToFinishWindow();

public slots:
    void on_toolButton_then0_clicked();
    void on_toolButton_then1_clicked();
    void handleBookTripResponse(const QString& response);

private:
    Ui::CarWindow *ui;
    int currentTripId;
};

#endif // CARWINDOW_H

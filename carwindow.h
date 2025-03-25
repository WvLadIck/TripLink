#ifndef CARWINDOW_H
#define CARWINDOW_H

#include <QDialog>
#include <QVariantMap> // Добавляем для хранения информации о поездке

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
    void displayTripInfo(const QVariantMap& tripInfo); // Новый слот для отображения информации

private:
    Ui::CarWindow *ui;
    int currentTripId;
    QVariantMap currentTrip; // Добавляем для хранения информации о текущей поездке
};

#endif // CARWINDOW_H

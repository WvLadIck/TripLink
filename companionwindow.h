#ifndef COMPANIONWINDOW_H
#define COMPANIONWINDOW_H

#include <QDialog>
#include <QVector>
#include <QVariantMap>

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
    void goToCarWindow(int tripId); // Передаем ID поездки
    void tripNotFound();

public slots:
    void on_toolButton_then0_clicked();
    void on_toolButton_then1_clicked();
    void handleFindTripResponse(const QString& message);

private:
    Ui::CompanionWindow *ui;
    QVector<QVariantMap> availableTrips; // Список доступных поездок
};

#endif // COMPANIONWINDOW_H

#ifndef COMPANIONWINDOW_H
#define COMPANIONWINDOW_H

#include <QDialog>
#include <QVector>
#include <QVariantMap>
#include <QListWidgetItem> // Добавляем этот заголовочный файл

namespace Ui {
class CompanionWindow;
}

class CompanionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CompanionWindow(QWidget *parent = nullptr);
    ~CompanionWindow();

    QVector<QVariantMap> getAvailableTrips() const; // Добавляем геттер

signals:
    void returnToPreviousWindow();
    void goToCarWindow(int tripId, QVariantMap tripInfo); // Передаем ID поездки и информацию о поездке
    void tripNotFound();
    void goToDriverCompanionWindow(); // Сигнал для возврата в DriverCompanionWindow

public slots:
    void on_toolButton_then0_clicked();
    void on_toolButton_then1_clicked();
    void handleFindTripResponse(const QString& message);
    void handleBookTripResponse(const QString& message); // Новый слот для обработки ответа о бронировании
    void on_listWidget_info_itemClicked(QListWidgetItem *item); // Новый слот для выбора поездки

private:
    Ui::CompanionWindow *ui;
    QVector<QVariantMap> availableTrips; // Список доступных поездок
    int selectedTripId = -1; // ID выбранной поездки
    bool isSearchPerformed = false; // Добавляем состояние
};

#endif // COMPANIONWINDOW_H

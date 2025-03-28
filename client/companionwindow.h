/**
 * @file companionwindow.h
 * @brief Заголовочный файл класса CompanionWindow, реализующего окно для выбора и бронирования поездок пассажиром.
 */

#ifndef COMPANIONWINDOW_H
#define COMPANIONWINDOW_H

#include <QDialog>
#include <QVector>
#include <QVariantMap>
#include <QListWidgetItem> 

namespace Ui {
class CompanionWindow;
}

/**
 * @brief Класс CompanionWindow представляет окно для выбора и бронирования поездок пассажиром.
 * Окно позволяет искать доступные поездки, выбирать их и бронировать.
 */
class CompanionWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор CompanionWindow.
     * @param parent Указатель на родительский виджет.
     */
    explicit CompanionWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор CompanionWindow.
     */
    ~CompanionWindow();

    /**
     * @brief Получить доступные поездки.
     * @return Вектор с данными доступных поездок.
     */
    QVector<QVariantMap> getAvailableTrips() const;

signals:
    /**
     * @brief Сигнал для возврата на предыдущий экран.
     */
    void returnToPreviousWindow();

    /**
     * @brief Сигнал для перехода на экран с информацией о выбранной поездке.
     * @param tripId ID выбранной поездки.
     * @param tripInfo Информация о поездке.
     */
    void goToCarWindow(int tripId, QVariantMap tripInfo);

    /**
     * @brief Сигнал, если поездка не найдена.
     */
    void tripNotFound();

    /**
     * @brief Сигнал для возврата на экран DriverCompanionWindow.
     */
    void goToDriverCompanionWindow();

public slots:
    /**
     * @brief Обработчик события нажатия на кнопку "then0".
     */
    void on_toolButton_then0_clicked();

    /**
     * @brief Обработчик события нажатия на кнопку "then1".
     */
    void on_toolButton_then1_clicked();

    /**
     * @brief Слот для обработки ответа на запрос о поиске поездки.
     * @param message Ответ от сервера.
     */
    void handleFindTripResponse(const QString& message);

    /**
     * @brief Слот для обработки ответа на запрос о бронировании поездки.
     * @param message Ответ от сервера.
     */
    void handleBookTripResponse(const QString& message);

    /**
     * @brief Обработчик события выбора поездки из списка.
     * @param item Элемент списка, соответствующий выбранной поездке.
     */
    void on_listWidget_info_itemClicked(QListWidgetItem *item);

private:
    Ui::CompanionWindow *ui; ///< Указатель на пользовательский интерфейс.
    QVector<QVariantMap> availableTrips; ///< Список доступных поездок.
    int selectedTripId = -1; ///< ID выбранной поездки.
    bool isSearchPerformed = false; ///< Состояние выполнения поиска.
};

#endif // COMPANIONWINDOW_H
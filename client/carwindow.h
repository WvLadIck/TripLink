/**
 * @file carwindow.h
 * @brief Заголовочный файл класса CarWindow, реализующего окно с информацией о доступных поездках.
 */

#ifndef CARWINDOW_H
#define CARWINDOW_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class CarWindow;
}

/**
 * @brief Класс CarWindow представляет окно с информацией о поездках.
 * Окно отображает информацию о доступных поездках и предоставляет возможность выбрать поездку.
 */
class CarWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор CarWindow.
     * @param parent Указатель на родительский виджет.
     */
    explicit CarWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор CarWindow.
     */
    ~CarWindow();

    /**
     * @brief Установить ID поездки.
     * @param tripId ID поездки.
     */
    void setTripId(int tripId);

signals:
    /**
     * @brief Сигнал для возврата на предыдущий экран.
     */
    void returnToPreviousWindow();

    /**
     * @brief Сигнал для перехода на экран завершения.
     */
    void goToFinishWindow();

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
     * @brief Слот для отображения информации о поездке.
     * @param tripInfo Информация о поездке.
     */
    void displayTripInfo(const QVariantMap& tripInfo);

private:
    Ui::CarWindow *ui; ///< Указатель на пользовательский интерфейс.
    int currentTripId; ///< ID текущей поездки.
    QVariantMap currentTrip; ///< Информация о текущей поездке.
};

#endif // CARWINDOW_H
/**
 * @file drivercompanionwindow.h
 * @brief Заголовочный файл класса DriverCompanionWindow, реализующего окно выбора роли (пассажир, водитель).
 */

#ifndef DRIVERCOMPANIONWINDOW_H
#define DRIVERCOMPANIONWINDOW_H

#include <QDialog>

namespace Ui {
class DriverCompanionWindow;
}

/**
 * @brief Класс DriverCompanionWindow представляет окно для выбора роли водителя, пассажира, или оставления отзыва.
 * Окно предоставляет возможность возврата на предыдущий экран или перехода к различным экранам.
 */
class DriverCompanionWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор DriverCompanionWindow.
     * @param parent Указатель на родительский виджет.
     */
    explicit DriverCompanionWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор DriverCompanionWindow.
     */
    ~DriverCompanionWindow();

signals:
    /**
     * @brief Сигнал для возврата на предыдущий экран.
     */
    void returnToPreviousWindow();

    /**
     * @brief Сигнал для перехода на экран с компаньоном.
     */
    void goToCompanionWindow();

    /**
     * @brief Сигнал для перехода на экран водителя.
     */
    void goToDriverWindow();

    /**
     * @brief Сигнал для перехода на экран отзывов.
     */
    void goToFeedbackWindow();

private slots:
    /**
     * @brief Обработчик события нажатия на кнопку "then0".
     */
    void on_toolButton_then0_clicked();

    /**
     * @brief Обработчик события нажатия на кнопку "companion".
     */
    void on_pushButton_companion_clicked();

    /**
     * @brief Обработчик события нажатия на кнопку "driver".
     */
    void on_pushButton_driver_clicked();

    /**
     * @brief Обработчик события нажатия на кнопку "feedback".
     */
    void on_pushButton_feetback_clicked();

private:
    Ui::DriverCompanionWindow *ui; ///< Указатель на пользовательский интерфейс.
};

#endif // DRIVERCOMPANIONWINDOW_H
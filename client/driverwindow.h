/**
 * @file driverwindow.h
 * @brief Заголовочный файл класса DriverWindow, реализующего окно для водителя.
 */


#ifndef DRIVERWINDOW_H
#define DRIVERWINDOW_H

#include <QDialog>
#include "networkclient.h" // Добавляем заголовочный файл NetworkClient

namespace Ui {
class DriverWindow;
}

/**
 * @brief Класс для представления окна водителя.
 *
 * Этот класс реализует окно водителя, позволяя ему создавать поездки и отправлять данные на сервер.
 */
class DriverWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса DriverWindow.
     * 
     * Инициализирует окно водителя.
     * 
     * @param parent Указатель на родительский виджет (по умолчанию nullptr).
     */
    explicit DriverWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса DriverWindow.
     * 
     * Удаляет все ресурсы, связанные с окном водителя.
     */
    ~DriverWindow();

signals:
    /**
     * @brief Сигнал для возвращения на предыдущее окно.
     */
    void returnToPreviousWindow();

    /**
     * @brief Сигнал для перехода на окно завершения.
     */
    void goToFinishWindow();

private slots:
    /**
     * @brief Обработчик клика по кнопке.
     * 
     * Возвращает пользователя на предыдущее окно.
     */
    void on_toolButton_then0_clicked();

    /**
     * @brief Обработчик клика по кнопке.
     * 
     * Создает поездку и отправляет данные на сервер.
     */
    void on_toolButton_then1_clicked();

private:
    Ui::DriverWindow *ui; /**< Указатель на пользовательский интерфейс. */
};

#endif // DRIVERWINDOW_H
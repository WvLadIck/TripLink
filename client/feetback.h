/**
 * @file feetback.h
 * @brief Заголовочный файл класса Tpips, реализующего возможность оставления отзывов и рейтинга поездок.
 */

#ifndef FEETBACK_H
#define FEETBACK_H

#include <QDialog>
#include "networkclient.h" // Добавляем заголовочный файл NetworkClient

namespace Ui {
    class Tpips;
}

/**
 * @class Tpips
 * @brief Класс окна обратной связи.
 * 
 * Этот класс реализует окно для ввода отзывов и оценки, а также отправки этих данных на сервер.
 */
class Tpips : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса Tpips.
     * 
     * Инициализирует интерфейс окна обратной связи и подключает сигналы для обработки действий пользователя.
     * @param parent Родительский элемент (по умолчанию nullptr).
     */
    explicit Tpips(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса Tpips.
     * 
     * Освобождает ресурсы, связанные с интерфейсом окна обратной связи.
     */
    ~Tpips();

signals:
    /**
     * @brief Сигнал для завершения работы и возврата.
     */
    void finished();

    /**
     * @brief Сигнал для перехода в окно "DriverCompanionWindow".
     */
    void goToDriverCompanionWindow();

private slots:
    /**
     * @brief Слот для обработки нажатия кнопки "Менее".
     * 
     * Отправляет данные на сервер и инициирует переход к следующему окну.
     */
    void on_toolButton_0_clicked();

    /**
     * @brief Слот для обработки нажатия кнопки "Более".
     * 
     * Отправляет отзыв и рейтинг на сервер.
     */
    void on_toolButton_1_clicked();

private:
    Ui::Tpips *ui; /**< Указатель на интерфейс окна обратной связи. */
};

#endif // FEETBACK_H
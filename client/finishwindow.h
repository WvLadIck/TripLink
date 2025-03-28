/**
 * @file finishwindow.h
 * @brief Заголовочный файл класса FinishWindow, реализующего окно завершения.
 */

#ifndef FINISHWINDOW_H
#define FINISHWINDOW_H

#include <QDialog>

namespace Ui {
    class FinishWindow;
}

/**
 * @class FinishWindow
 * @brief Класс окна завершения.
 * 
 * Этот класс реализует окно завершения, которое позволяет пользователю вернуться на главный экран.
 */
class FinishWindow : public QDialog
{
    Q_OBJECT

signals:
    /**
     * @brief Сигнал для возврата на главное окно.
     */
    void returnToMainWindow();

public:
    /**
     * @brief Конструктор класса FinishWindow.
     * 
     * Инициализирует интерфейс окна завершения.
     * @param parent Родительский элемент (по умолчанию nullptr).
     */
    explicit FinishWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса FinishWindow.
     * 
     * Освобождает ресурсы, связанные с интерфейсом окна завершения.
     */
    ~FinishWindow();

private slots:
    /**
     * @brief Слот для обработки нажатия кнопки возврата на главный экран.
     */
    void on_pushButton_home_clicked();

private:
    Ui::FinishWindow *ui; /**< Указатель на интерфейс окна завершения. */
};

#endif // FINISHWINDOW_H
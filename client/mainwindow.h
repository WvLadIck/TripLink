/**
 * @file mainwindow.h
 * @brief Заголовочный файл класса MainWindow, реализующего главное окно приложения.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>

namespace Ui {
    class MainWindow;
}

/**
 * @class MainWindow
 * @brief Класс главного окна приложения.
 *
 * Этот класс реализует главное окно приложения с двумя кнопками: для входа и для регистрации.
 * При нажатии на соответствующие кнопки генерируются сигналы для перехода к окнам авторизации или регистрации.
 * Также устанавливается соединение с сервером при инициализации окна.
 */
class MainWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса MainWindow.
     * 
     * Создает главное окно приложения, инициализирует элементы интерфейса и устанавливает соединение с сервером.
     * @param parent Родительский элемент (по умолчанию nullptr).
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса MainWindow.
     * 
     * Освобождает ресурсы, связанные с интерфейсом главного окна.
     */
    ~MainWindow();

signals:
    /**
     * @brief Сигнал, генерируемый при нажатии кнопки входа.
     */
    void loginButtonClicked();

    /**
     * @brief Сигнал, генерируемый при нажатии кнопки регистрации.
     */
    void registrationButtonClicked();

private slots:
    /**
     * @brief Слот, вызываемый при нажатии на кнопку входа.
     * 
     * Генерирует сигнал loginButtonClicked для перехода к окну авторизации.
     */
    void on_pushButton_auth_clicked();

    /**
     * @brief Слот, вызываемый при нажатии на кнопку регистрации.
     * 
     * Генерирует сигнал registrationButtonClicked для перехода к окну регистрации.
     */
    void on_pushButton_reg_clicked();

private:
    Ui::MainWindow *ui; /**< Указатель на интерфейс главного окна, сгенерированный с помощью Qt Designer. */
};

#endif // MAINWINDOW_H

/**
 * @file managerform.cpp
 * @brief Файл реализации класса ManagerForm.
 */

#include "managerform.h"
#include "networkclient.h"

ManagerForm::ManagerForm(QWidget *parent)
    : QMainWindow(parent)
{
    // Инициализация окон
    this->Main_Window = new MainWindow;
    this->Login_Window = new LoginWindow;
    this->Reg_Window = new RegistrationWindow;
    this->Drive_Comp_Window = new DriverCompanionWindow;
    this->Companion_Window = new CompanionWindow;
    this->Driver_Window = new DriverWindow;
    this->Car_Window = new CarWindow;
    this->Finish_Window = new FinishWindow;
    this->Feedback_Window = new Tpips; // Инициализация окна отзывов

    // Подключения сигналов и слотов
    connect(Main_Window, &MainWindow::loginButtonClicked, this, &ManagerForm::showLoginWindow);
    connect(Main_Window, &MainWindow::registrationButtonClicked, this, &ManagerForm::showRegistrationWindow);
    connect(Login_Window, &LoginWindow::returnToMainWindow, this, &ManagerForm::handleReturnToPrevious);
    connect(Reg_Window, &RegistrationWindow::returnToMainWindow, this, &ManagerForm::handleReturnToPrevious);
    connect(Login_Window, &LoginWindow::goToDriverCompanionWindow, this, &ManagerForm::showDriverCompanionWindow);
    connect(Reg_Window, &RegistrationWindow::goToDriverCompanionWindow, this, &ManagerForm::showDriverCompanionWindow);
    connect(Drive_Comp_Window, &DriverCompanionWindow::goToCompanionWindow, this, &ManagerForm::showCompanionWindow);
    connect(Drive_Comp_Window, &DriverCompanionWindow::goToDriverWindow, this, &ManagerForm::showDriverWindow);
    connect(Drive_Comp_Window, &DriverCompanionWindow::goToFeedbackWindow, this, &ManagerForm::showFeedbackWindow); // Подключение сигнала для окна отзывов

    // Добавляем обработку сигнала returnToPreviousWindow для каждого окна
    connect(Drive_Comp_Window, &DriverCompanionWindow::returnToPreviousWindow, this, &ManagerForm::handleReturnToPrevious);
    connect(Companion_Window, &CompanionWindow::returnToPreviousWindow, this, &ManagerForm::handleReturnToPrevious);
    connect(Driver_Window, &DriverWindow::returnToPreviousWindow, this, &ManagerForm::handleReturnToPrevious);
    connect(Car_Window, &CarWindow::returnToPreviousWindow, this, &ManagerForm::handleReturnToPrevious);
    connect(Feedback_Window, &Tpips::finished, this, &ManagerForm::handleReturnToPrevious); // Подключение сигнала finished для окна отзывов
    connect(Feedback_Window, &Tpips::goToDriverCompanionWindow, this, &ManagerForm::showDriverCompanionWindow); // Подключение сигнала для перехода в DriverCompanionWindow

    connect(&NetworkClient::getInstance(), &NetworkClient::readyRead, Companion_Window, &CompanionWindow::handleFindTripResponse);


    // Подключения для перехода к CarWindow (только от CompanionWindow)
    connect(Companion_Window, &CompanionWindow::goToCarWindow, this, &ManagerForm::showCarWindow);
    connect(Companion_Window, &CompanionWindow::tripNotFound, this, [this]() {
        Companion_Window->show();
    });

    connect(Companion_Window, &CompanionWindow::goToDriverCompanionWindow, this, &ManagerForm::showDriverCompanionWindowFromCompanion);

    // Подключения для перехода к FinishWindow
    connect(Driver_Window, &DriverWindow::goToFinishWindow, this, &ManagerForm::showFinishWindow);
    connect(Car_Window, &CarWindow::goToFinishWindow, this, &ManagerForm::showFinishWindow);
    connect(Finish_Window, &FinishWindow::returnToMainWindow, this, &ManagerForm::showMainWindowFromFinish);

    // Инициализируем карту соответствия окон
    windowMap[Login_Window] = Main_Window;
    windowMap[Reg_Window] = Main_Window;
    windowMap[Drive_Comp_Window] = nullptr; //  Будет установлено при переходе
    windowMap[Companion_Window] = Drive_Comp_Window;
    windowMap[Driver_Window] = Drive_Comp_Window;
    windowMap[Car_Window] = Companion_Window;
    windowMap[Feedback_Window] = Drive_Comp_Window; // Устанавливаем предыдущее окно для окна отзывов
    windowMap[Finish_Window] = nullptr;

    // Скрытие окон при запуске (кроме главного)
    Login_Window->hide();
    Reg_Window->hide();
    Drive_Comp_Window->hide();
    Companion_Window->hide();
    Driver_Window->hide();
    Car_Window->hide();
    Finish_Window->hide(); // Скрываем FinishWindow
    Feedback_Window->hide(); // Скрываем окно отзывов
    this->Main_Window->show(); // Отображаем главное окно

    // Инициализация и подключение NetworkClient
    NetworkClient& client = NetworkClient::getInstance();
    connect(&client, &NetworkClient::connectionStatusChanged, this, &ManagerForm::onConnectionStatusChanged);
    connect(&client, &NetworkClient::error, [](const QString& message){
        qDebug() << "Network error:" << message;
    });
}

ManagerForm::~ManagerForm() {}

void ManagerForm::showLoginWindow()
{
    Main_Window->hide();
    Login_Window->show();
    windowMap[Login_Window] = Main_Window; // Запоминаем предыдущее окно
}

void ManagerForm::showRegistrationWindow()
{
    Main_Window->hide();
    Reg_Window->show();
    windowMap[Reg_Window] = Main_Window; // Запоминаем предыдущее окно
}

void ManagerForm::showDriverCompanionWindow()
{
    QWidget* senderWidget = qobject_cast<QWidget*>(sender());
    if (senderWidget == Login_Window) {
        Login_Window->hide();
        windowMap[Drive_Comp_Window] = Login_Window; // Запоминаем предыдущее окно
    } else if (senderWidget == Reg_Window) {
        Reg_Window->hide();
        windowMap[Drive_Comp_Window] = Reg_Window; // Запоминаем предыдущее окно
    } else if (senderWidget == Feedback_Window) {
        Feedback_Window->hide();
        windowMap[Drive_Comp_Window] = Feedback_Window; // Запоминаем предыдущее окно
    }
    Drive_Comp_Window->show();
}

void ManagerForm::showDriverWindow()
{
    Drive_Comp_Window->hide();
    Driver_Window->show();
    windowMap[Driver_Window] = Drive_Comp_Window; // Запоминаем предыдущее окно
}

// void ManagerForm::showCarWindow(int tripId)
// {
//     Car_Window->setTripId(tripId);
//     windowMap[Car_Window] = Companion_Window; //  Устанавливаем предыдущее окно для CarWindow
//     Companion_Window->hide(); // Закрываем CompanionWindow, а не close()
//     Car_Window->show();
// }

void ManagerForm::showFinishWindow()
{
    QWidget* senderWidget = qobject_cast<QWidget*>(sender());
    if (senderWidget == Driver_Window) {
        Driver_Window->close(); // Закрываем DriverWindow
    } else if (senderWidget == Car_Window) {
        Car_Window->close(); // Закрываем CarWindow
    }
    Finish_Window->show();
}

void ManagerForm::handleReturnToPrevious()
{
    QWidget* senderWidget = qobject_cast<QWidget*>(sender());
    senderWidget->hide();
    //  Ищем предыдущее окно в карте
    QMap<QWidget*, QWidget*>::iterator i = windowMap.begin();
    while (i != windowMap.end()) {
        if (i.key() == senderWidget) {
            QWidget* prevWindow = i.value();
            if (prevWindow) {
                prevWindow->show();
                return; //  Выходим из функции
            } else {
                // Если предыдущее окно не найдено, возвращаемся к главному
                Main_Window->show();
                return; //  Выходим из функции
            }
        }
        ++i;
    }
    // Если окно не найдено в карте, возвращаемся к главному
    Main_Window->show();
}

void ManagerForm::showMainWindowFromFinish()
{
    Finish_Window->hide(); // Скрываем FinishWindow
    Main_Window->show();   // Отображаем MainWindow
}

void ManagerForm::onConnectionStatusChanged(bool connected)
{
    if (connected) {
        qDebug() << "Connected to server!";
    } else {
        qDebug() << "Disconnected from server!";
    }
}

void ManagerForm::showFeedbackWindow()
{
    Drive_Comp_Window->hide();
    Feedback_Window->show();
    windowMap[Feedback_Window] = Drive_Comp_Window; // Запоминаем предыдущее окно
}


void ManagerForm::showCompanionWindow()
{
    Drive_Comp_Window->hide();
    Companion_Window->show();
    windowMap[Companion_Window] = Drive_Comp_Window; // Запоминаем предыдущее окно
}

void ManagerForm::showDriverCompanionWindowFromCompanion()
{
    Companion_Window->hide();
    Drive_Comp_Window->show();
    windowMap[Drive_Comp_Window] = Companion_Window; // Запоминаем предыдущее окно
}

void ManagerForm::showCarWindow(int tripId, QVariantMap tripInfo)
{
    Car_Window->setTripId(tripId);
    windowMap[Car_Window] = Companion_Window; //  Устанавливаем предыдущее окно для CarWindow
    Companion_Window->hide(); // Закрываем CompanionWindow, а не close()

    // Отображаем информацию о поездке в CarWindow
    Car_Window->displayTripInfo(tripInfo);

    Car_Window->show();
}

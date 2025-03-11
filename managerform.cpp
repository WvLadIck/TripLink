#include "managerform.h"

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

    // Подключения сигналов и слотов
    connect(Main_Window, &MainWindow::loginButtonClicked, this, &ManagerForm::showLoginWindow);
    connect(Main_Window, &MainWindow::registrationButtonClicked, this, &ManagerForm::showRegistrationWindow);

    connect(Login_Window, &LoginWindow::returnToMainWindow, this, &ManagerForm::handleReturnToPrevious);
    connect(Reg_Window, &RegistrationWindow::returnToMainWindow, this, &ManagerForm::handleReturnToPrevious);

    connect(Login_Window, &LoginWindow::goToDriverCompanionWindow, this, &ManagerForm::showDriverCompanionWindow);
    connect(Reg_Window, &RegistrationWindow::goToDriverCompanionWindow, this, &ManagerForm::showDriverCompanionWindow);

    connect(Drive_Comp_Window, &DriverCompanionWindow::goToCompanionWindow, this, &ManagerForm::showCompanionWindow);
    connect(Drive_Comp_Window, &DriverCompanionWindow::goToDriverWindow, this, &ManagerForm::showDriverWindow);

    // Добавляем обработку сигнала returnToPreviousWindow для каждого окна
    connect(Drive_Comp_Window, &DriverCompanionWindow::returnToPreviousWindow, this, &ManagerForm::handleReturnToPrevious);
    connect(Companion_Window, &CompanionWindow::returnToPreviousWindow, this, &ManagerForm::handleReturnToPrevious);
    connect(Driver_Window, &DriverWindow::returnToPreviousWindow, this, &ManagerForm::handleReturnToPrevious);
    connect(Car_Window, &CarWindow::returnToPreviousWindow, this, &ManagerForm::handleReturnToPrevious);

    // Подключения для перехода к CarWindow (только от CompanionWindow)
    connect(Companion_Window, &CompanionWindow::goToCarWindow, this, &ManagerForm::showCarWindow);

    // Подключения для перехода к FinishWindow
    connect(Driver_Window, &DriverWindow::goToFinishWindow, this, &ManagerForm::showFinishWindow);
    connect(Car_Window, &CarWindow::goToFinishWindow, this, &ManagerForm::showFinishWindow);

    // Инициализируем карту соответствия окон
    windowMap[Login_Window] = Main_Window;
    windowMap[Reg_Window] = Main_Window;
    windowMap[Drive_Comp_Window] = nullptr; //  Будет установлено при переходе
    windowMap[Companion_Window] = Drive_Comp_Window;
    windowMap[Driver_Window] = Drive_Comp_Window;
    windowMap[Car_Window] = Companion_Window;
    windowMap[Finish_Window] = nullptr; // FinishWindow не имеет "предыдущего" окна

    // Скрытие окон при запуске (кроме главного)
    Login_Window->hide();
    Reg_Window->hide();
    Drive_Comp_Window->hide();
    Companion_Window->hide();
    Driver_Window->hide();
    Car_Window->hide();
    Finish_Window->hide(); // Скрываем FinishWindow

    this->Main_Window->show(); // Отображаем главное окно
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
    }
    Drive_Comp_Window->show();
}

void ManagerForm::showCompanionWindow()
{
    Drive_Comp_Window->hide();
    Companion_Window->show();
    windowMap[Companion_Window] = Drive_Comp_Window; // Запоминаем предыдущее окно
}

void ManagerForm::showDriverWindow()
{
    Drive_Comp_Window->hide();
    Driver_Window->show();
    windowMap[Driver_Window] = Drive_Comp_Window; // Запоминаем предыдущее окно
}

void ManagerForm::showCarWindow()
{
    // Теперь CarWindow открывается только из CompanionWindow
    windowMap[Car_Window] = Companion_Window; //  Устанавливаем предыдущее окно для CarWindow
    Companion_Window->hide(); // Закрываем CompanionWindow, а не close()
    Car_Window->show();
}

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

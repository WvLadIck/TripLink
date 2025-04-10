#include "drivercompanionwindow.h"
#include "ui_drivercompanionwindow.h"

DriverCompanionWindow::DriverCompanionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DriverCompanionWindow)
{
    ui->setupUi(this);
    connect(ui->toolButton_then0, &QToolButton::clicked, this, &DriverCompanionWindow::on_toolButton_then0_clicked);
    connect(ui->pushButton_companion, &QPushButton::clicked, this, &DriverCompanionWindow::on_pushButton_companion_clicked);
    connect(ui->pushButton_driver, &QPushButton::clicked, this, &DriverCompanionWindow::on_pushButton_driver_clicked);
    connect(ui->pushButton_feetback, &QPushButton::clicked, this, &DriverCompanionWindow::on_pushButton_feetback_clicked); // Подключение для кнопки отзывов
    connect(ui->toolButton_then1, &QToolButton::clicked, this, &DriverCompanionWindow::on_toolButton_then0_clicked); // Подключение для кнопки >
    connect(ui->pushButton_profile, &QPushButton::clicked, this, &DriverCompanionWindow::on_pushButton_profile_clicked);
}

DriverCompanionWindow::~DriverCompanionWindow()
{
    delete ui;
}

void DriverCompanionWindow::on_toolButton_then0_clicked()
{
    emit returnToPreviousWindow();
}

void DriverCompanionWindow::on_pushButton_companion_clicked()
{
    emit goToCompanionWindow();
}

void DriverCompanionWindow::on_pushButton_driver_clicked()
{
    emit goToDriverWindow();
}

void DriverCompanionWindow::on_pushButton_profile_clicked()
{
    emit goToProfileWindow();
}

void DriverCompanionWindow::on_pushButton_feetback_clicked()
{
    emit goToFeedbackWindow(); // Emit сигнал для открытия окна отзывов
}

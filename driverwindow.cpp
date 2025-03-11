#include "driverwindow.h"
#include "ui_driverwindow.h"

DriverWindow::DriverWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DriverWindow)
{
    ui->setupUi(this);
    connect(ui->toolButton_then0, &QToolButton::clicked, this, &DriverWindow::on_toolButton_then0_clicked);
    connect(ui->toolButton_then1, &QToolButton::clicked, this, &DriverWindow::on_toolButton_then1_clicked);
}

DriverWindow::~DriverWindow()
{
    delete ui;
}

void DriverWindow::on_toolButton_then0_clicked()
{
    emit returnToPreviousWindow();
}

void DriverWindow::on_toolButton_then1_clicked()
{
    emit goToFinishWindow(); //  Отправляем сигнал goToFinishWindow
}

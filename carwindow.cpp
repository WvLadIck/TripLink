#include "carwindow.h"
#include "ui_carwindow.h"

CarWindow::CarWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CarWindow)
{
    ui->setupUi(this);
    connect(ui->toolButton_then0, &QToolButton::clicked, this, &CarWindow::on_toolButton_then0_clicked);
    connect(ui->toolButton_then1, &QToolButton::clicked, this, &CarWindow::on_toolButton_then1_clicked);
}

CarWindow::~CarWindow()
{
    delete ui;
}

void CarWindow::on_toolButton_then0_clicked()
{
    emit returnToPreviousWindow();
}

void CarWindow::on_toolButton_then1_clicked()
{
    emit goToFinishWindow(); //  Отправляем сигнал goToFinishWindow
}

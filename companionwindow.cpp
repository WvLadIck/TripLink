#include "companionwindow.h"
#include "ui_companionwindow.h"

CompanionWindow::CompanionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompanionWindow)
{
    ui->setupUi(this);
    connect(ui->toolButton_then0, &QToolButton::clicked, this, &CompanionWindow::on_toolButton_then0_clicked);
    connect(ui->toolButton_then1, &QToolButton::clicked, this, &CompanionWindow::on_toolButton_then1_clicked);
}

CompanionWindow::~CompanionWindow()
{
    delete ui;
}

void CompanionWindow::on_toolButton_then0_clicked()
{
    emit returnToPreviousWindow();
}

void CompanionWindow::on_toolButton_then1_clicked()
{
    emit goToCarWindow();
}

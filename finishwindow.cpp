#include "finishwindow.h"
#include "ui_finishwindow.h"

FinishWindow::FinishWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FinishWindow)
{
    ui->setupUi(this);
}

FinishWindow::~FinishWindow()
{
    delete ui;
}

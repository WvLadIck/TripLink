#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_auth, &QPushButton::clicked, this, &MainWindow::on_pushButton_auth_clicked);
    connect(ui->pushButton_reg, &QPushButton::clicked, this, &MainWindow::on_pushButton_reg_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_auth_clicked()
{
    emit loginButtonClicked();
}

void MainWindow::on_pushButton_reg_clicked()
{
    emit registrationButtonClicked();
}

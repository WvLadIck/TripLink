#include "feetback.h"
#include "ui_feetback.h"

Tpips::Tpips(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Tpips)
{
    ui->setupUi(this);
    connect(ui->toolButton_0, &QToolButton::clicked, this, &Tpips::on_toolButton_0_clicked); // Подключение для кнопки <
    connect(ui->toolButton_1, &QToolButton::clicked, this, &Tpips::on_toolButton_1_clicked); // Подключение для кнопки >
}

Tpips::~Tpips()
{
    delete ui;
}

void Tpips::on_toolButton_0_clicked()
{
    emit finished(); // Emit сигнал для возврата
}

void Tpips::on_toolButton_1_clicked()
{
    emit finished(); // Emit сигнал для возврата
}

#ifndef FEETBACK_H
#define FEETBACK_H

#include <QDialog>

namespace Ui {
class Tpips;
}

class Tpips : public QDialog
{
    Q_OBJECT

public:
    explicit Tpips(QWidget *parent = nullptr);
    ~Tpips();

signals:
    void finished(); // Сигнал для возврата

private slots:
    void on_toolButton_0_clicked(); // Слот для кнопки <
    void on_toolButton_1_clicked(); // Слот для кнопки >

private:
    Ui::Tpips *ui;
};

#endif // FEETBACK_H

#ifndef BLACKLISTADD_H
#define BLACKLISTADD_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class BlacklistAdd;
}

class BlacklistAdd : public QDialog
{
    Q_OBJECT

public:
    explicit BlacklistAdd(const QString& login, QWidget *parent = nullptr);
    ~BlacklistAdd();

private slots:
    void on_pushButton_clicked();
    void addBlacklistResponse(const QString& message);

private:
    Ui::BlacklistAdd *ui;
    QLineEdit *loginLineEdit;  // Поле для ввода логина
    QPushButton *sendButton;   // Кнопка отправки
    QString login;
};

#endif // BLACKLISTADD_H

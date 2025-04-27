#ifndef BLACKLIST_H
#define BLACKLIST_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class Blacklist;
}

class Blacklist : public QDialog
{
    Q_OBJECT

public:
    explicit Blacklist(const QString& login, QWidget *parent = nullptr);
    ~Blacklist();

private slots:
    void on_getBlacklistButton_clicked();
    void onBlacklistResponse(const QString& message);
    void on_addButton_clicked();

private:
    Ui::Blacklist *ui;
    QString login; // Добавляем поле для хранения логина
};

#endif // BLACKLIST_H

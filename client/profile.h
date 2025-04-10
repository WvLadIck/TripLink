#ifndef PROFILE_H
#define PROFILE_H

#include <QLabel>
#include <QDialog>

namespace Ui {
class Profile;
}

class Profile : public QDialog
{
    Q_OBJECT

public:
    explicit Profile(const QString& login, QWidget *parent = nullptr);
    ~Profile() override;

signals:
    void finished();
    void goToDriverCompanionWindow();

private slots:
    void on_toolButton_0_clicked();
    void on_pushButton_clicked();
    void ProfileResponse(const QString& message);

private:
    Ui::Profile *ui;
    QString login; // Добавляем поле для хранения логина
};

#endif // PROFILE_H

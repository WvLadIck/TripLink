/********************************************************************************
** Form generated from reading UI file 'blacklistadd.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLACKLISTADD_H
#define UI_BLACKLISTADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlacklistAdd
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_login;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;

    void setupUi(QDialog *BlacklistAdd)
    {
        if (BlacklistAdd->objectName().isEmpty())
            BlacklistAdd->setObjectName(QString::fromUtf8("BlacklistAdd"));
        BlacklistAdd->resize(468, 223);
        BlacklistAdd->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);\n"
"font: 700 14pt \"Linux Libertine G\";"));
        layoutWidget = new QWidget(BlacklistAdd);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 107, 411, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_login = new QLineEdit(layoutWidget);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));

        horizontalLayout->addWidget(lineEdit_login);

        label = new QLabel(BlacklistAdd);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 30, 161, 18));
        pushButton = new QPushButton(BlacklistAdd);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 106, 34));
        label_2 = new QLabel(BlacklistAdd);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 321, 18));

        retranslateUi(BlacklistAdd);

        QMetaObject::connectSlotsByName(BlacklistAdd);
    } // setupUi

    void retranslateUi(QDialog *BlacklistAdd)
    {
        BlacklistAdd->setWindowTitle(QCoreApplication::translate("BlacklistAdd", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("BlacklistAdd", "\320\247\320\265\321\200\320\275\321\213\320\271 \321\201\320\277\320\270\321\201\320\276\320\272", nullptr));
        pushButton->setText(QCoreApplication::translate("BlacklistAdd", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("BlacklistAdd", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\273\320\276\320\263\320\270\320\275 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BlacklistAdd: public Ui_BlacklistAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLACKLISTADD_H

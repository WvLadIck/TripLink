/********************************************************************************
** Form generated from reading UI file 'registrationwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONWINDOW_H
#define UI_REGISTRATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegistrationWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_then0;
    QVBoxLayout *verticalLayout;
    QLabel *label_reg;
    QFormLayout *formLayout;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_phone;
    QLineEdit *lineEdit_phone;
    QLabel *label_login;
    QLineEdit *lineEdit_login;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QCheckBox *checkBox_drivers;
    QToolButton *toolButton_then1;

    void setupUi(QDialog *RegistrationWindow)
    {
        if (RegistrationWindow->objectName().isEmpty())
            RegistrationWindow->setObjectName("RegistrationWindow");
        RegistrationWindow->resize(400, 300);
        RegistrationWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);\n"
"font: 700 14pt \"Linux Libertine G\";"));
        verticalLayout_2 = new QVBoxLayout(RegistrationWindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        toolButton_then0 = new QToolButton(RegistrationWindow);
        toolButton_then0->setObjectName("toolButton_then0");
        toolButton_then0->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);"));

        horizontalLayout_2->addWidget(toolButton_then0);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_reg = new QLabel(RegistrationWindow);
        label_reg->setObjectName("label_reg");
        label_reg->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Linux Libertine G\";"));

        verticalLayout->addWidget(label_reg, 0, Qt::AlignHCenter);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_name = new QLabel(RegistrationWindow);
        label_name->setObjectName("label_name");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_name);

        lineEdit_name = new QLineEdit(RegistrationWindow);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_name);

        label_phone = new QLabel(RegistrationWindow);
        label_phone->setObjectName("label_phone");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_phone);

        lineEdit_phone = new QLineEdit(RegistrationWindow);
        lineEdit_phone->setObjectName("lineEdit_phone");
        lineEdit_phone->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_phone);

        label_login = new QLabel(RegistrationWindow);
        label_login->setObjectName("label_login");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_login);

        lineEdit_login = new QLineEdit(RegistrationWindow);
        lineEdit_login->setObjectName("lineEdit_login");
        lineEdit_login->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_login);

        label_password = new QLabel(RegistrationWindow);
        label_password->setObjectName("label_password");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_password);

        lineEdit_password = new QLineEdit(RegistrationWindow);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_password);

        checkBox_drivers = new QCheckBox(RegistrationWindow);
        checkBox_drivers->setObjectName("checkBox_drivers");
        checkBox_drivers->setStyleSheet(QString::fromUtf8("check_Box-color: rgb(224, 202, 180);"));

        formLayout->setWidget(4, QFormLayout::FieldRole, checkBox_drivers);


        verticalLayout->addLayout(formLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        toolButton_then1 = new QToolButton(RegistrationWindow);
        toolButton_then1->setObjectName("toolButton_then1");
        toolButton_then1->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);"));

        horizontalLayout_2->addWidget(toolButton_then1);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(RegistrationWindow);

        QMetaObject::connectSlotsByName(RegistrationWindow);
    } // setupUi

    void retranslateUi(QDialog *RegistrationWindow)
    {
        RegistrationWindow->setWindowTitle(QCoreApplication::translate("RegistrationWindow", "Dialog", nullptr));
        toolButton_then0->setText(QCoreApplication::translate("RegistrationWindow", "<", nullptr));
        label_reg->setText(QCoreApplication::translate("RegistrationWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label_name->setText(QCoreApplication::translate("RegistrationWindow", "\320\244\320\230\320\236", nullptr));
        label_phone->setText(QCoreApplication::translate("RegistrationWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        label_login->setText(QCoreApplication::translate("RegistrationWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_password->setText(QCoreApplication::translate("RegistrationWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        checkBox_drivers->setText(QCoreApplication::translate("RegistrationWindow", "\320\257\320\262\320\273\321\217\321\216\321\201\321\214 \320\262\320\276\320\264\320\270\321\202\320\265\320\273\320\265\320\274", nullptr));
        toolButton_then1->setText(QCoreApplication::translate("RegistrationWindow", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationWindow: public Ui_RegistrationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONWINDOW_H

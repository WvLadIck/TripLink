/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_then0;
    QVBoxLayout *verticalLayout;
    QLabel *label_auth;
    QFormLayout *formLayout;
    QLabel *label_login;
    QLineEdit *lineEdit_login;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QToolButton *toolButton_then1;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(400, 300);
        LoginWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);\n"
"font: 700 14pt \"Linux Libertine G\";"));
        verticalLayout_2 = new QVBoxLayout(LoginWindow);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton_then0 = new QToolButton(LoginWindow);
        toolButton_then0->setObjectName(QString::fromUtf8("toolButton_then0"));
        toolButton_then0->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);"));

        horizontalLayout->addWidget(toolButton_then0);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_auth = new QLabel(LoginWindow);
        label_auth->setObjectName(QString::fromUtf8("label_auth"));
        label_auth->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Linux Libertine G\";"));

        verticalLayout->addWidget(label_auth, 0, Qt::AlignHCenter);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_login = new QLabel(LoginWindow);
        label_login->setObjectName(QString::fromUtf8("label_login"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_login);

        lineEdit_login = new QLineEdit(LoginWindow);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));
        lineEdit_login->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_login);

        label_password = new QLabel(LoginWindow);
        label_password->setObjectName(QString::fromUtf8("label_password"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_password);

        lineEdit_password = new QLineEdit(LoginWindow);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_password);


        verticalLayout->addLayout(formLayout);


        horizontalLayout->addLayout(verticalLayout);

        toolButton_then1 = new QToolButton(LoginWindow);
        toolButton_then1->setObjectName(QString::fromUtf8("toolButton_then1"));
        toolButton_then1->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);"));

        horizontalLayout->addWidget(toolButton_then1);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Dialog", nullptr));
        toolButton_then0->setText(QCoreApplication::translate("LoginWindow", "<", nullptr));
        label_auth->setText(QCoreApplication::translate("LoginWindow", "\320\222\321\205\320\276\320\264", nullptr));
        label_login->setText(QCoreApplication::translate("LoginWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_password->setText(QCoreApplication::translate("LoginWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        toolButton_then1->setText(QCoreApplication::translate("LoginWindow", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

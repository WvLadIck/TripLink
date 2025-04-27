/********************************************************************************
** Form generated from reading UI file 'drivercompanionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRIVERCOMPANIONWINDOW_H
#define UI_DRIVERCOMPANIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DriverCompanionWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_then0;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_profile;
    QLabel *label_whois;
    QPushButton *pushButton_companion;
    QPushButton *pushButton_driver;
    QPushButton *pushButton_feetback;
    QToolButton *toolButton_then1;

    void setupUi(QDialog *DriverCompanionWindow)
    {
        if (DriverCompanionWindow->objectName().isEmpty())
            DriverCompanionWindow->setObjectName(QString::fromUtf8("DriverCompanionWindow"));
        DriverCompanionWindow->resize(400, 300);
        DriverCompanionWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);\n"
"font: 700 14pt \"Linux Libertine G\";"));
        verticalLayout_2 = new QVBoxLayout(DriverCompanionWindow);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton_then0 = new QToolButton(DriverCompanionWindow);
        toolButton_then0->setObjectName(QString::fromUtf8("toolButton_then0"));
        toolButton_then0->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);"));

        horizontalLayout->addWidget(toolButton_then0);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_profile = new QPushButton(DriverCompanionWindow);
        pushButton_profile->setObjectName(QString::fromUtf8("pushButton_profile"));

        verticalLayout->addWidget(pushButton_profile);

        label_whois = new QLabel(DriverCompanionWindow);
        label_whois->setObjectName(QString::fromUtf8("label_whois"));
        label_whois->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Linux Libertine G\";"));

        verticalLayout->addWidget(label_whois, 0, Qt::AlignHCenter);

        pushButton_companion = new QPushButton(DriverCompanionWindow);
        pushButton_companion->setObjectName(QString::fromUtf8("pushButton_companion"));
        pushButton_companion->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        verticalLayout->addWidget(pushButton_companion);

        pushButton_driver = new QPushButton(DriverCompanionWindow);
        pushButton_driver->setObjectName(QString::fromUtf8("pushButton_driver"));
        pushButton_driver->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        verticalLayout->addWidget(pushButton_driver);

        pushButton_feetback = new QPushButton(DriverCompanionWindow);
        pushButton_feetback->setObjectName(QString::fromUtf8("pushButton_feetback"));
        pushButton_feetback->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        verticalLayout->addWidget(pushButton_feetback);


        horizontalLayout->addLayout(verticalLayout);

        toolButton_then1 = new QToolButton(DriverCompanionWindow);
        toolButton_then1->setObjectName(QString::fromUtf8("toolButton_then1"));
        toolButton_then1->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);"));

        horizontalLayout->addWidget(toolButton_then1);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(DriverCompanionWindow);

        QMetaObject::connectSlotsByName(DriverCompanionWindow);
    } // setupUi

    void retranslateUi(QDialog *DriverCompanionWindow)
    {
        DriverCompanionWindow->setWindowTitle(QCoreApplication::translate("DriverCompanionWindow", "Dialog", nullptr));
        toolButton_then0->setText(QCoreApplication::translate("DriverCompanionWindow", "<", nullptr));
        pushButton_profile->setText(QCoreApplication::translate("DriverCompanionWindow", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        label_whois->setText(QCoreApplication::translate("DriverCompanionWindow", "\320\232\320\265\320\274 \320\262\321\213 \321\217\320\262\320\273\321\217\320\265\321\202\320\265\321\201\321\214?", nullptr));
        pushButton_companion->setText(QCoreApplication::translate("DriverCompanionWindow", "\320\237\320\260\321\201\321\201\320\260\320\266\320\270\321\200", nullptr));
        pushButton_driver->setText(QCoreApplication::translate("DriverCompanionWindow", "\320\222\320\276\320\264\320\270\321\202\320\265\320\273\321\214", nullptr));
        pushButton_feetback->setText(QCoreApplication::translate("DriverCompanionWindow", "\320\236\321\202\320\267\321\213\320\262 \320\270 \321\200\320\265\320\271\321\202\320\270\320\275\320\263", nullptr));
        toolButton_then1->setText(QCoreApplication::translate("DriverCompanionWindow", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DriverCompanionWindow: public Ui_DriverCompanionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRIVERCOMPANIONWINDOW_H

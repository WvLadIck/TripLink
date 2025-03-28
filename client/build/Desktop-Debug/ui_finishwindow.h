/********************************************************************************
** Form generated from reading UI file 'finishwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINISHWINDOW_H
#define UI_FINISHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FinishWindow
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QPushButton *pushButton_home;

    void setupUi(QDialog *FinishWindow)
    {
        if (FinishWindow->objectName().isEmpty())
            FinishWindow->setObjectName(QString::fromUtf8("FinishWindow"));
        FinishWindow->resize(400, 300);
        FinishWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);"));
        verticalLayout = new QVBoxLayout(FinishWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(FinishWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);\n"
"font: 700 25pt \"Linux Libertine G\";"));

        verticalLayout_2->addWidget(label, 0, Qt::AlignHCenter);

        pushButton_home = new QPushButton(FinishWindow);
        pushButton_home->setObjectName(QString::fromUtf8("pushButton_home"));
        pushButton_home->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);\n"
"font: 700 14pt \"Linux Libertine G\";"));

        verticalLayout_2->addWidget(pushButton_home);


        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(FinishWindow);

        QMetaObject::connectSlotsByName(FinishWindow);
    } // setupUi

    void retranslateUi(QDialog *FinishWindow)
    {
        FinishWindow->setWindowTitle(QCoreApplication::translate("FinishWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FinishWindow", "\320\245\320\276\321\200\320\276\321\210\320\265\320\271 \320\264\320\276\321\200\320\276\320\263\320\270!", nullptr));
        pushButton_home->setText(QCoreApplication::translate("FinishWindow", "\320\235\320\260 \320\263\320\273\320\260\320\262\320\275\321\213\320\271 \321\215\320\272\321\200\320\260\320\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FinishWindow: public Ui_FinishWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINISHWINDOW_H

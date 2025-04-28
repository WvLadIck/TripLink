/********************************************************************************
** Form generated from reading UI file 'finishwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINISHWINDOW_H
#define UI_FINISHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FinishWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QDialog *FinishWindow)
    {
        if (FinishWindow->objectName().isEmpty())
            FinishWindow->setObjectName("FinishWindow");
        FinishWindow->resize(400, 300);
        FinishWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);"));
        verticalLayout = new QVBoxLayout(FinishWindow);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(FinishWindow);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);\n"
"font: 700 25pt \"Linux Libertine G\";"));

        verticalLayout->addWidget(label, 0, Qt::AlignmentFlag::AlignHCenter);


        retranslateUi(FinishWindow);

        QMetaObject::connectSlotsByName(FinishWindow);
    } // setupUi

    void retranslateUi(QDialog *FinishWindow)
    {
        FinishWindow->setWindowTitle(QCoreApplication::translate("FinishWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FinishWindow", "\320\245\320\276\321\200\320\276\321\210\320\265\320\271 \320\264\320\276\321\200\320\276\320\263\320\270!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FinishWindow: public Ui_FinishWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINISHWINDOW_H

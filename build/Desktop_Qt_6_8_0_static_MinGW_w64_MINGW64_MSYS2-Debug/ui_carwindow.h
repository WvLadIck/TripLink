/********************************************************************************
** Form generated from reading UI file 'carwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARWINDOW_H
#define UI_CARWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CarWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_then0;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_info;
    QLabel *label_conp;
    QLabel *label_time;
    QComboBox *comboBox_drive;
    QToolButton *toolButton_then1;

    void setupUi(QDialog *CarWindow)
    {
        if (CarWindow->objectName().isEmpty())
            CarWindow->setObjectName("CarWindow");
        CarWindow->resize(400, 300);
        CarWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);\n"
"font: 700 14pt \"Linux Libertine G\";"));
        verticalLayout_3 = new QVBoxLayout(CarWindow);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        toolButton_then0 = new QToolButton(CarWindow);
        toolButton_then0->setObjectName("toolButton_then0");
        toolButton_then0->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);"));

        horizontalLayout_2->addWidget(toolButton_then0);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_info = new QLabel(CarWindow);
        label_info->setObjectName("label_info");
        label_info->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Linux Libertine G\";"));

        verticalLayout_2->addWidget(label_info, 0, Qt::AlignmentFlag::AlignHCenter);

        label_conp = new QLabel(CarWindow);
        label_conp->setObjectName("label_conp");
        label_conp->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Linux Libertine G\";"));

        verticalLayout_2->addWidget(label_conp, 0, Qt::AlignmentFlag::AlignHCenter);

        label_time = new QLabel(CarWindow);
        label_time->setObjectName("label_time");

        verticalLayout_2->addWidget(label_time);

        comboBox_drive = new QComboBox(CarWindow);
        comboBox_drive->setObjectName("comboBox_drive");
        comboBox_drive->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        verticalLayout_2->addWidget(comboBox_drive);


        horizontalLayout_2->addLayout(verticalLayout_2);

        toolButton_then1 = new QToolButton(CarWindow);
        toolButton_then1->setObjectName("toolButton_then1");
        toolButton_then1->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);\n"
""));

        horizontalLayout_2->addWidget(toolButton_then1);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(CarWindow);

        QMetaObject::connectSlotsByName(CarWindow);
    } // setupUi

    void retranslateUi(QDialog *CarWindow)
    {
        CarWindow->setWindowTitle(QCoreApplication::translate("CarWindow", "Dialog", nullptr));
        toolButton_then0->setText(QCoreApplication::translate("CarWindow", "<", nullptr));
        label_info->setText(QCoreApplication::translate("CarWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\264\320\273\321\217", nullptr));
        label_conp->setText(QCoreApplication::translate("CarWindow", "\320\277\320\260\321\201\321\201\320\260\320\266\320\270\321\200\320\260", nullptr));
        label_time->setText(QCoreApplication::translate("CarWindow", "\320\222\320\276\320\264\320\270\321\202\320\265\320\273\321\214 \320\270 \320\262\321\200\320\265\320\274\321\217", nullptr));
        toolButton_then1->setText(QCoreApplication::translate("CarWindow", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CarWindow: public Ui_CarWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARWINDOW_H

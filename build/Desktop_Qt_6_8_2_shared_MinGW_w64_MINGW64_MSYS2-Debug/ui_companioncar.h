/********************************************************************************
** Form generated from reading UI file 'companioncar.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPANIONCAR_H
#define UI_COMPANIONCAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CompanionCar
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_then0;
    QVBoxLayout *verticalLayout;
    QLabel *label_info;
    QLabel *label_companion;
    QLabel *label_driver;
    QComboBox *comboBox_drivertime;
    QToolButton *toolButton_then1;

    void setupUi(QDialog *CompanionCar)
    {
        if (CompanionCar->objectName().isEmpty())
            CompanionCar->setObjectName("CompanionCar");
        CompanionCar->resize(400, 300);
        CompanionCar->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Linux Libertine G\";\n"
"background-color: rgb(235, 220, 206);"));
        verticalLayout_2 = new QVBoxLayout(CompanionCar);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        toolButton_then0 = new QToolButton(CompanionCar);
        toolButton_then0->setObjectName("toolButton_then0");
        toolButton_then0->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        horizontalLayout->addWidget(toolButton_then0);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_info = new QLabel(CompanionCar);
        label_info->setObjectName("label_info");
        label_info->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Linux Libertine G\";\n"
"background-color: rgb(235, 220, 206);"));

        verticalLayout->addWidget(label_info, 0, Qt::AlignHCenter);

        label_companion = new QLabel(CompanionCar);
        label_companion->setObjectName("label_companion");
        label_companion->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Linux Libertine G\";"));

        verticalLayout->addWidget(label_companion, 0, Qt::AlignHCenter);

        label_driver = new QLabel(CompanionCar);
        label_driver->setObjectName("label_driver");

        verticalLayout->addWidget(label_driver, 0, Qt::AlignHCenter);

        comboBox_drivertime = new QComboBox(CompanionCar);
        comboBox_drivertime->setObjectName("comboBox_drivertime");
        comboBox_drivertime->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        verticalLayout->addWidget(comboBox_drivertime);


        horizontalLayout->addLayout(verticalLayout);

        toolButton_then1 = new QToolButton(CompanionCar);
        toolButton_then1->setObjectName("toolButton_then1");
        toolButton_then1->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        horizontalLayout->addWidget(toolButton_then1);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(CompanionCar);

        QMetaObject::connectSlotsByName(CompanionCar);
    } // setupUi

    void retranslateUi(QDialog *CompanionCar)
    {
        CompanionCar->setWindowTitle(QCoreApplication::translate("CompanionCar", "Dialog", nullptr));
        toolButton_then0->setText(QCoreApplication::translate("CompanionCar", "<", nullptr));
        label_info->setText(QCoreApplication::translate("CompanionCar", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\264\320\273\321\217", nullptr));
        label_companion->setText(QCoreApplication::translate("CompanionCar", "\320\277\320\260\321\201\321\201\320\260\320\266\320\270\321\200\320\260", nullptr));
        label_driver->setText(QCoreApplication::translate("CompanionCar", "\320\222\320\276\320\264\320\270\321\202\320\265\320\273\321\214 \320\270 \320\262\321\200\320\265\320\274\321\217", nullptr));
        toolButton_then1->setText(QCoreApplication::translate("CompanionCar", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CompanionCar: public Ui_CompanionCar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPANIONCAR_H

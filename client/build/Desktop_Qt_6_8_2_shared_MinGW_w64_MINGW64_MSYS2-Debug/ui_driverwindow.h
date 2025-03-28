/********************************************************************************
** Form generated from reading UI file 'driverwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRIVERWINDOW_H
#define UI_DRIVERWINDOW_H

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

class Ui_DriverWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *toolButton_then0;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFormLayout *formLayout;
    QLabel *label_where;
    QLineEdit *lineEdit_where;
    QLabel *label_place;
    QLineEdit *lineEdit_place;
    QLabel *label_time;
    QLineEdit *lineEdit_time;
    QToolButton *toolButton_then1;

    void setupUi(QDialog *DriverWindow)
    {
        if (DriverWindow->objectName().isEmpty())
            DriverWindow->setObjectName("DriverWindow");
        DriverWindow->resize(466, 300);
        DriverWindow->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Linux Libertine G\";\n"
"background-color: rgb(235, 220, 206);"));
        verticalLayout_2 = new QVBoxLayout(DriverWindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        toolButton_then0 = new QToolButton(DriverWindow);
        toolButton_then0->setObjectName("toolButton_then0");
        toolButton_then0->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);\n"
""));

        horizontalLayout_4->addWidget(toolButton_then0);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(DriverWindow);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 700 18pt \"Linux Libertine G\";"));

        verticalLayout->addWidget(label);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_where = new QLabel(DriverWindow);
        label_where->setObjectName("label_where");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_where);

        lineEdit_where = new QLineEdit(DriverWindow);
        lineEdit_where->setObjectName("lineEdit_where");
        lineEdit_where->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_where);

        label_place = new QLabel(DriverWindow);
        label_place->setObjectName("label_place");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_place);

        lineEdit_place = new QLineEdit(DriverWindow);
        lineEdit_place->setObjectName("lineEdit_place");
        lineEdit_place->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_place);

        label_time = new QLabel(DriverWindow);
        label_time->setObjectName("label_time");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_time);

        lineEdit_time = new QLineEdit(DriverWindow);
        lineEdit_time->setObjectName("lineEdit_time");
        lineEdit_time->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_time);


        verticalLayout->addLayout(formLayout);


        horizontalLayout_4->addLayout(verticalLayout);

        toolButton_then1 = new QToolButton(DriverWindow);
        toolButton_then1->setObjectName("toolButton_then1");
        toolButton_then1->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);"));

        horizontalLayout_4->addWidget(toolButton_then1);


        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(DriverWindow);

        QMetaObject::connectSlotsByName(DriverWindow);
    } // setupUi

    void retranslateUi(QDialog *DriverWindow)
    {
        DriverWindow->setWindowTitle(QCoreApplication::translate("DriverWindow", "Dialog", nullptr));
        toolButton_then0->setText(QCoreApplication::translate("DriverWindow", "<", nullptr));
        label->setText(QCoreApplication::translate("DriverWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276\321\202 \320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\217", nullptr));
        label_where->setText(QCoreApplication::translate("DriverWindow", "\320\232\321\203\320\264\320\260 \320\265\320\264\320\265\321\202\320\265", nullptr));
        label_place->setText(QCoreApplication::translate("DriverWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\274\320\265\321\201\321\202", nullptr));
        label_time->setText(QCoreApplication::translate("DriverWindow", "\320\222\321\200\320\265\320\274\321\217 \320\277\320\276\320\265\320\267\320\264\320\272\320\270", nullptr));
        toolButton_then1->setText(QCoreApplication::translate("DriverWindow", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DriverWindow: public Ui_DriverWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRIVERWINDOW_H

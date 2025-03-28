/********************************************************************************
** Form generated from reading UI file 'companionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPANIONWINDOW_H
#define UI_COMPANIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CompanionWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_then0;
    QVBoxLayout *verticalLayout;
    QLabel *label_where;
    QFormLayout *formLayout;
    QLabel *label_from;
    QLabel *label_to;
    QLineEdit *lineEdit_from;
    QLineEdit *lineEdit_to;
    QListWidget *listWidget_info;
    QLabel *label_info;
    QToolButton *toolButton_then1;

    void setupUi(QDialog *CompanionWindow)
    {
        if (CompanionWindow->objectName().isEmpty())
            CompanionWindow->setObjectName(QString::fromUtf8("CompanionWindow"));
        CompanionWindow->resize(400, 300);
        CompanionWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);\n"
"font: 700 14pt \"Linux Libertine G\";"));
        verticalLayout_2 = new QVBoxLayout(CompanionWindow);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton_then0 = new QToolButton(CompanionWindow);
        toolButton_then0->setObjectName(QString::fromUtf8("toolButton_then0"));
        toolButton_then0->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);"));

        horizontalLayout->addWidget(toolButton_then0);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_where = new QLabel(CompanionWindow);
        label_where->setObjectName(QString::fromUtf8("label_where"));
        label_where->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Linux Libertine G\";"));

        verticalLayout->addWidget(label_where, 0, Qt::AlignHCenter);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_from = new QLabel(CompanionWindow);
        label_from->setObjectName(QString::fromUtf8("label_from"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_from);

        label_to = new QLabel(CompanionWindow);
        label_to->setObjectName(QString::fromUtf8("label_to"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_to);

        lineEdit_from = new QLineEdit(CompanionWindow);
        lineEdit_from->setObjectName(QString::fromUtf8("lineEdit_from"));
        lineEdit_from->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_from);

        lineEdit_to = new QLineEdit(CompanionWindow);
        lineEdit_to->setObjectName(QString::fromUtf8("lineEdit_to"));
        lineEdit_to->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_to);

        listWidget_info = new QListWidget(CompanionWindow);
        listWidget_info->setObjectName(QString::fromUtf8("listWidget_info"));

        formLayout->setWidget(2, QFormLayout::FieldRole, listWidget_info);

        label_info = new QLabel(CompanionWindow);
        label_info->setObjectName(QString::fromUtf8("label_info"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_info);


        verticalLayout->addLayout(formLayout);


        horizontalLayout->addLayout(verticalLayout);

        toolButton_then1 = new QToolButton(CompanionWindow);
        toolButton_then1->setObjectName(QString::fromUtf8("toolButton_then1"));
        toolButton_then1->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);"));

        horizontalLayout->addWidget(toolButton_then1);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(CompanionWindow);

        QMetaObject::connectSlotsByName(CompanionWindow);
    } // setupUi

    void retranslateUi(QDialog *CompanionWindow)
    {
        CompanionWindow->setWindowTitle(QCoreApplication::translate("CompanionWindow", "Dialog", nullptr));
        toolButton_then0->setText(QCoreApplication::translate("CompanionWindow", "<", nullptr));
        label_where->setText(QCoreApplication::translate("CompanionWindow", "\320\232\321\203\320\264\320\260 \320\270 \320\276\321\202\320\272\321\203\320\264\320\260?", nullptr));
        label_from->setText(QCoreApplication::translate("CompanionWindow", "\320\236\321\202\320\272\321\203\320\264\320\260", nullptr));
        label_to->setText(QCoreApplication::translate("CompanionWindow", "\320\232\321\203\320\264\320\260", nullptr));
        label_info->setText(QCoreApplication::translate("CompanionWindow", "\320\222\320\276\320\264\320\270\321\202\320\265\320\273\321\214, \320\264\320\260\321\202\320\260", nullptr));
        toolButton_then1->setText(QCoreApplication::translate("CompanionWindow", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CompanionWindow: public Ui_CompanionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPANIONWINDOW_H

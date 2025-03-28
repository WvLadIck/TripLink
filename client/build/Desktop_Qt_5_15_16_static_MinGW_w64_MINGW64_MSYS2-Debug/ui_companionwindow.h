/********************************************************************************
** Form generated from reading UI file 'companionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPANIONWINDOW_H
#define UI_COMPANIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
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
    QLabel *label_town;
    QComboBox *comboBox_town;
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

        verticalLayout->addWidget(label_where, 0, Qt::AlignmentFlag::AlignHCenter);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_town = new QLabel(CompanionWindow);
        label_town->setObjectName(QString::fromUtf8("label_town"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_town);

        comboBox_town = new QComboBox(CompanionWindow);
        comboBox_town->setObjectName(QString::fromUtf8("comboBox_town"));
        comboBox_town->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox_town);


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
        label_where->setText(QCoreApplication::translate("CompanionWindow", "\320\232\321\203\320\264\320\260 \320\265\320\264\320\265\320\274?", nullptr));
        label_town->setText(QCoreApplication::translate("CompanionWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\263\320\276\321\200\320\276\320\264", nullptr));
        toolButton_then1->setText(QCoreApplication::translate("CompanionWindow", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CompanionWindow: public Ui_CompanionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPANIONWINDOW_H

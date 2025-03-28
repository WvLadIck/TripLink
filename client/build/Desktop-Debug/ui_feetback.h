/********************************************************************************
** Form generated from reading UI file 'feetback.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEETBACK_H
#define UI_FEETBACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Tpips
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_0;
    QVBoxLayout *verticalLayout;
    QLabel *label_ratingfeetback;
    QFormLayout *formLayout;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_feetback;
    QLineEdit *lineEdit_feetback;
    QLabel *label_rating;
    QSpinBox *spinBox_rating;
    QToolButton *toolButton_1;

    void setupUi(QDialog *Tpips)
    {
        if (Tpips->objectName().isEmpty())
            Tpips->setObjectName(QString::fromUtf8("Tpips"));
        Tpips->resize(400, 300);
        Tpips->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Linux Libertine G\";\n"
"background-color: rgb(235, 220, 206);"));
        verticalLayout_2 = new QVBoxLayout(Tpips);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton_0 = new QToolButton(Tpips);
        toolButton_0->setObjectName(QString::fromUtf8("toolButton_0"));
        toolButton_0->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);"));

        horizontalLayout->addWidget(toolButton_0);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_ratingfeetback = new QLabel(Tpips);
        label_ratingfeetback->setObjectName(QString::fromUtf8("label_ratingfeetback"));
        label_ratingfeetback->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Linux Libertine G\";"));

        verticalLayout->addWidget(label_ratingfeetback, 0, Qt::AlignHCenter);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_name = new QLabel(Tpips);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_name);

        lineEdit_name = new QLineEdit(Tpips);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_name);

        label_feetback = new QLabel(Tpips);
        label_feetback->setObjectName(QString::fromUtf8("label_feetback"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_feetback);

        lineEdit_feetback = new QLineEdit(Tpips);
        lineEdit_feetback->setObjectName(QString::fromUtf8("lineEdit_feetback"));
        lineEdit_feetback->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_feetback);

        label_rating = new QLabel(Tpips);
        label_rating->setObjectName(QString::fromUtf8("label_rating"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_rating);

        spinBox_rating = new QSpinBox(Tpips);
        spinBox_rating->setObjectName(QString::fromUtf8("spinBox_rating"));
        spinBox_rating->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox_rating);


        verticalLayout->addLayout(formLayout);


        horizontalLayout->addLayout(verticalLayout);

        toolButton_1 = new QToolButton(Tpips);
        toolButton_1->setObjectName(QString::fromUtf8("toolButton_1"));
        toolButton_1->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);"));

        horizontalLayout->addWidget(toolButton_1);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Tpips);

        QMetaObject::connectSlotsByName(Tpips);
    } // setupUi

    void retranslateUi(QDialog *Tpips)
    {
        Tpips->setWindowTitle(QCoreApplication::translate("Tpips", "Dialog", nullptr));
        toolButton_0->setText(QCoreApplication::translate("Tpips", "<", nullptr));
        label_ratingfeetback->setText(QCoreApplication::translate("Tpips", "\320\240\320\265\320\271\321\202\320\270\320\275\320\263 \320\270 \320\276\321\202\320\267\321\213\320\262", nullptr));
        label_name->setText(QCoreApplication::translate("Tpips", "\320\244\320\230\320\236", nullptr));
        label_feetback->setText(QCoreApplication::translate("Tpips", "\320\236\321\202\320\267\321\213\320\262", nullptr));
        label_rating->setText(QCoreApplication::translate("Tpips", "\320\240\320\265\320\271\321\202\320\270\320\275\320\263", nullptr));
        toolButton_1->setText(QCoreApplication::translate("Tpips", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tpips: public Ui_Tpips {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEETBACK_H

/********************************************************************************
** Form generated from reading UI file 'profile.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILE_H
#define UI_PROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Profile
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_0;
    QVBoxLayout *verticalLayout;
    QLabel *label_ratingfeetback;
    QPushButton *pushButton;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QListWidget *listWidget_2;
    QLabel *label_3;
    QListWidget *listWidget_3;
    QListWidget *listWidget_1;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Profile)
    {
        if (Profile->objectName().isEmpty())
            Profile->setObjectName(QString::fromUtf8("Profile"));
        Profile->resize(554, 444);
        Profile->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);\n"
"font: 700 14pt \"Linux Libertine G\";"));
        layoutWidget = new QWidget(Profile);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 16, 501, 291));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_0 = new QToolButton(layoutWidget);
        toolButton_0->setObjectName(QString::fromUtf8("toolButton_0"));
        toolButton_0->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);"));

        horizontalLayout->addWidget(toolButton_0);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(7);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_ratingfeetback = new QLabel(layoutWidget);
        label_ratingfeetback->setObjectName(QString::fromUtf8("label_ratingfeetback"));
        label_ratingfeetback->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Linux Libertine G\";"));

        verticalLayout->addWidget(label_ratingfeetback, 0, Qt::AlignHCenter);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        verticalLayout->addWidget(pushButton);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(3);
        formLayout->setVerticalSpacing(3);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        listWidget_2 = new QListWidget(layoutWidget);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, listWidget_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        listWidget_3 = new QListWidget(layoutWidget);
        listWidget_3->setObjectName(QString::fromUtf8("listWidget_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, listWidget_3);

        listWidget_1 = new QListWidget(layoutWidget);
        listWidget_1->setObjectName(QString::fromUtf8("listWidget_1"));

        formLayout->setWidget(0, QFormLayout::FieldRole, listWidget_1);


        verticalLayout->addLayout(formLayout);


        horizontalLayout->addLayout(verticalLayout);

        pushButton_2 = new QPushButton(Profile);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 340, 461, 26));

        retranslateUi(Profile);

        QMetaObject::connectSlotsByName(Profile);
    } // setupUi

    void retranslateUi(QDialog *Profile)
    {
        Profile->setWindowTitle(QCoreApplication::translate("Profile", "Dialog", nullptr));
        toolButton_0->setText(QCoreApplication::translate("Profile", "<", nullptr));
        label_ratingfeetback->setText(QCoreApplication::translate("Profile", "\320\222\320\260\321\210 \320\277\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        pushButton->setText(QCoreApplication::translate("Profile", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        label->setText(QCoreApplication::translate("Profile", "\320\244\320\230\320\236", nullptr));
        label_2->setText(QCoreApplication::translate("Profile", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_3->setText(QCoreApplication::translate("Profile", "Email", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Profile", "\320\247\320\265\321\200\320\275\321\213\320\271 \321\201\320\277\320\270\321\201\320\276\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Profile: public Ui_Profile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_H

/********************************************************************************
** Form generated from reading UI file 'blacklist.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLACKLIST_H
#define UI_BLACKLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Blacklist
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget_2;
    QListWidget *listWidget;
    QToolButton *toolButton_0;
    QLabel *label;
    QPushButton *getBlacklistButton;
    QPushButton *addButton;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *Blacklist)
    {
        if (Blacklist->objectName().isEmpty())
            Blacklist->setObjectName(QString::fromUtf8("Blacklist"));
        Blacklist->resize(468, 385);
        Blacklist->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);\n"
"font: 700 14pt \"Linux Libertine G\";"));
        layoutWidget = new QWidget(Blacklist);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 107, 411, 271));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget_2 = new QListWidget(layoutWidget);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));

        horizontalLayout->addWidget(listWidget_2);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout->addWidget(listWidget);

        toolButton_0 = new QToolButton(layoutWidget);
        toolButton_0->setObjectName(QString::fromUtf8("toolButton_0"));
        toolButton_0->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);"));

        horizontalLayout->addWidget(toolButton_0);

        label = new QLabel(Blacklist);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 30, 161, 18));
        getBlacklistButton = new QPushButton(Blacklist);
        getBlacklistButton->setObjectName(QString::fromUtf8("getBlacklistButton"));
        getBlacklistButton->setGeometry(QRect(320, 20, 107, 34));
        addButton = new QPushButton(Blacklist);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(30, 20, 106, 34));
        label_2 = new QLabel(Blacklist);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 80, 66, 18));
        label_3 = new QLabel(Blacklist);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 80, 66, 18));

        retranslateUi(Blacklist);

        QMetaObject::connectSlotsByName(Blacklist);
    } // setupUi

    void retranslateUi(QDialog *Blacklist)
    {
        Blacklist->setWindowTitle(QCoreApplication::translate("Blacklist", "Dialog", nullptr));
        toolButton_0->setText(QCoreApplication::translate("Blacklist", "<", nullptr));
        label->setText(QCoreApplication::translate("Blacklist", "\320\247\320\265\321\200\320\275\321\213\320\271 \321\201\320\277\320\270\321\201\320\276\320\272", nullptr));
        getBlacklistButton->setText(QCoreApplication::translate("Blacklist", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        addButton->setText(QCoreApplication::translate("Blacklist", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("Blacklist", "\320\273\320\276\320\263\320\270\320\275", nullptr));
        label_3->setText(QCoreApplication::translate("Blacklist", "\320\244\320\230\320\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Blacklist: public Ui_Blacklist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLACKLIST_H

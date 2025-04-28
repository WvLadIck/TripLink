/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_triplink;
    QPushButton *pushButton_auth;
    QPushButton *pushButton_reg;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 220, 206);\n"
"font: 700 14pt \"Linux Libertine G\";"));
        horizontalLayout = new QHBoxLayout(MainWindow);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_triplink = new QLabel(MainWindow);
        label_triplink->setObjectName("label_triplink");
        label_triplink->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Linux Libertine G\";"));

        verticalLayout->addWidget(label_triplink, 0, Qt::AlignHCenter);

        pushButton_auth = new QPushButton(MainWindow);
        pushButton_auth->setObjectName("pushButton_auth");
        pushButton_auth->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        verticalLayout->addWidget(pushButton_auth);

        pushButton_reg = new QPushButton(MainWindow);
        pushButton_reg->setObjectName("pushButton_reg");
        pushButton_reg->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 202, 180);"));

        verticalLayout->addWidget(pushButton_reg);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Dialog", nullptr));
        label_triplink->setText(QCoreApplication::translate("MainWindow", "TripLink", nullptr));
        pushButton_auth->setText(QCoreApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264", nullptr));
        pushButton_reg->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'MainDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDIALOG_H
#define UI_MAINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainDialog
{
public:
    QVBoxLayout *vboxLayout;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout;
    QWidget *shadowinnerbg3;
    QWidget *pannel;
    QHBoxLayout *pannelLayout;
    TitlebarWidget *titlebar;
    QWidget *extendbar;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnTheme;

    void setupUi(QWidget *MainDialog)
    {
        if (MainDialog->objectName().isEmpty())
            MainDialog->setObjectName(QStringLiteral("MainDialog"));
        MainDialog->resize(950, 600);
        MainDialog->setMinimumSize(QSize(950, 600));
        MainDialog->setStyleSheet(QString::fromUtf8("QWidget#MainDialog{\n"
"    font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size:12px;\n"
"}\n"
"\n"
"QPushButton#btnTheme{  \n"
"	font-size:12px;\n"
"}"));
        vboxLayout = new QVBoxLayout(MainDialog);
        vboxLayout->setSpacing(0);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(MainDialog);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        shadowbg->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(shadowbg);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        shadowinnerbg3 = new QWidget(shadowbg);
        shadowinnerbg3->setObjectName(QStringLiteral("shadowinnerbg3"));
        shadowinnerbg3->setStyleSheet(QStringLiteral(""));
        pannel = new QWidget(shadowinnerbg3);
        pannel->setObjectName(QStringLiteral("pannel"));
        pannel->setGeometry(QRect(0, 0, 890, 568));
        pannel->setMinimumSize(QSize(90, 0));
        pannel->setStyleSheet(QStringLiteral(""));
        pannelLayout = new QHBoxLayout(pannel);
        pannelLayout->setSpacing(0);
        pannelLayout->setContentsMargins(11, 11, 11, 11);
        pannelLayout->setObjectName(QStringLiteral("pannelLayout"));
        pannelLayout->setContentsMargins(0, 0, 0, 0);
        titlebar = new TitlebarWidget(shadowinnerbg3);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setGeometry(QRect(0, 0, 150, 27));
        titlebar->setMinimumSize(QSize(150, 0));
        titlebar->setMaximumSize(QSize(150, 16777215));
        titlebar->setStyleSheet(QStringLiteral(""));
        extendbar = new QWidget(shadowinnerbg3);
        extendbar->setObjectName(QStringLiteral("extendbar"));
        extendbar->setGeometry(QRect(10, 10, 50, 27));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(extendbar->sizePolicy().hasHeightForWidth());
        extendbar->setSizePolicy(sizePolicy);
        extendbar->setMinimumSize(QSize(50, 27));
        extendbar->setMaximumSize(QSize(50, 27));
        extendbar->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(extendbar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnTheme = new QPushButton(extendbar);
        btnTheme->setObjectName(QStringLiteral("btnTheme"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnTheme->sizePolicy().hasHeightForWidth());
        btnTheme->setSizePolicy(sizePolicy1);
        btnTheme->setMinimumSize(QSize(50, 27));
        btnTheme->setMaximumSize(QSize(50, 27));
        btnTheme->setFlat(true);

        horizontalLayout->addWidget(btnTheme);


        verticalLayout->addWidget(shadowinnerbg3);


        vboxLayout->addWidget(shadowbg);


        retranslateUi(MainDialog);

        QMetaObject::connectSlotsByName(MainDialog);
    } // setupUi

    void retranslateUi(QWidget *MainDialog)
    {
        MainDialog->setWindowTitle(QApplication::translate("MainDialog", "MainDialog", 0));
        btnTheme->setText(QApplication::translate("MainDialog", "\344\270\273\351\242\230", 0));
    } // retranslateUi

};

namespace Ui {
    class MainDialog: public Ui_MainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDIALOG_H

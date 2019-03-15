/********************************************************************************
** Form generated from reading UI file 'ErCodeDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERCODEDIALOG_H
#define UI_ERCODEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ErCodeDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout_4;
    TitlebarWidget *titlebar;
    QWidget *widget_ercode;
    QVBoxLayout *verticalLayout_3;
    QLabel *avarercode;

    void setupUi(QWidget *ErCodeDialog)
    {
        if (ErCodeDialog->objectName().isEmpty())
            ErCodeDialog->setObjectName(QStringLiteral("ErCodeDialog"));
        ErCodeDialog->resize(217, 218);
        ErCodeDialog->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QWidget#widget_ercode{\n"
"    background-color: #ECECEC;\n"
"}\n"
"\n"
"QPushButton#pushButton_close{\n"
"	height:25px;\n"
"	width:25px;\n"
"	border-image: url(:/Images/close_mini_normal.png);\n"
"}\n"
"QPushButton#pushButton_close:hover{\n"
"	border-image: url(:/Images/close_mini_normal.png);\n"
"}\n"
"QPushButton#closeBtnBar:pressed{\n"
"	border-image: url(:/Images/close_mini_normal.png);\n"
"}\n"
"\n"
"\n"
""));
        verticalLayout_2 = new QVBoxLayout(ErCodeDialog);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(ErCodeDialog);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        verticalLayout = new QVBoxLayout(shadowbg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        verticalLayout_4 = new QVBoxLayout(shadowinnerbg);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(1, 1, 1, 1);
        titlebar = new TitlebarWidget(shadowinnerbg);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 0));
        titlebar->setMaximumSize(QSize(284, 30));

        verticalLayout_4->addWidget(titlebar);

        widget_ercode = new QWidget(shadowinnerbg);
        widget_ercode->setObjectName(QStringLiteral("widget_ercode"));
        verticalLayout_3 = new QVBoxLayout(widget_ercode);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        avarercode = new QLabel(widget_ercode);
        avarercode->setObjectName(QStringLiteral("avarercode"));
        avarercode->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(avarercode);


        verticalLayout_4->addWidget(widget_ercode);


        verticalLayout->addWidget(shadowinnerbg);


        verticalLayout_2->addWidget(shadowbg);


        retranslateUi(ErCodeDialog);

        QMetaObject::connectSlotsByName(ErCodeDialog);
    } // setupUi

    void retranslateUi(QWidget *ErCodeDialog)
    {
        ErCodeDialog->setWindowTitle(QApplication::translate("ErCodeDialog", "Form", 0));
        avarercode->setText(QApplication::translate("ErCodeDialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class ErCodeDialog: public Ui_ErCodeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERCODEDIALOG_H

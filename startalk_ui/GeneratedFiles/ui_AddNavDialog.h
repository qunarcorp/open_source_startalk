/********************************************************************************
** Form generated from reading UI file 'AddNavDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNAVDIALOG_H
#define UI_ADDNAVDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_AddNavDialog
{
public:
    QWidget *widget;
    TitlebarWidget *titlebar;
    QWidget *widget_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_Cmpurl;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbt_cancel;
    QPushButton *pbt_ok;

    void setupUi(QWidget *AddNavDialog)
    {
        if (AddNavDialog->objectName().isEmpty())
            AddNavDialog->setObjectName(QStringLiteral("AddNavDialog"));
        AddNavDialog->resize(500, 170);
        AddNavDialog->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QWidget#widget\n"
"{\n"
"	border:1px solid #D1D1D1;\n"
"  	background: #ECECEC;\n"
"	\n"
"}\n"
"\n"
"\n"
"QPushButton#pbt_cancel{\n"
"    color: #666666;\n"
"	background-color: #FFFFFF;\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton#pbt_ok\n"
"{\n"
"	color: #666666;\n"
"	border:none;\n"
"	background-color: #3dbbca;\n"
"}\n"
"\n"
"QPushButton#pbt_cancel:hover,QPushButton#pbt_ok:hover {\n"
"    color: #FFFFFF;\n"
"	background-color: #3dbbca;\n"
"}\n"
"QPushButton#pbt_cancel:pressed, QPushButton#pbt_ok:press{\n"
"\n"
"    color: #FFFFFF;\n"
"	background-color: #1194a4;\n"
"}\n"
"QPushButton#pbt_cancel:checked,QPushButton#pbt_ok:checked{\n"
"\n"
"    color: #FFFFFF;\n"
"	background-color: #1ba9ba;\n"
"}\n"
"QLineEdit{\n"
"	color:  #333333;\n"
"	background:#AAffffff;	\n"
"	font: 14px;\n"
"	border: 1px solid #FFFFFF;\n"
"}\n"
"\n"
"QLineEdit:hover{\n"
"	border: 1px solid #65e1f6;\n"
"}\n"
"QLineEdit:focus{\n"
"	border: "
                        "1px solid #65e1f6;\n"
"}"));
        widget = new QWidget(AddNavDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 500, 170));
        titlebar = new TitlebarWidget(widget);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setGeometry(QRect(0, 0, 500, 30));
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(0, 30, 500, 100));
        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(0, 0, 500, 40));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(20, 17, 80, 0);
        label = new QLabel(widget_5);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(400, 30));
        label->setMaximumSize(QSize(400, 30));

        horizontalLayout_3->addWidget(label);

        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(0, 40, 500, 65));
        horizontalLayout_2 = new QHBoxLayout(widget_6);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(50, 0, 80, 0);
        label_2 = new QLabel(widget_6);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setMaximumSize(QSize(60, 16777215));
        label_2->setSizeIncrement(QSize(0, 0));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_Cmpurl = new QLineEdit(widget_6);
        lineEdit_Cmpurl->setObjectName(QStringLiteral("lineEdit_Cmpurl"));
        lineEdit_Cmpurl->setMinimumSize(QSize(360, 28));
        lineEdit_Cmpurl->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_2->addWidget(lineEdit_Cmpurl);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(0, 130, 491, 41));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setSpacing(50);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 80, 10);
        horizontalSpacer = new QSpacerItem(208, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbt_cancel = new QPushButton(widget_4);
        pbt_cancel->setObjectName(QStringLiteral("pbt_cancel"));
        pbt_cancel->setMinimumSize(QSize(50, 23));
        pbt_cancel->setFlat(true);

        horizontalLayout->addWidget(pbt_cancel);

        pbt_ok = new QPushButton(widget_4);
        pbt_ok->setObjectName(QStringLiteral("pbt_ok"));
        pbt_ok->setMinimumSize(QSize(50, 23));
        pbt_ok->setFlat(true);

        horizontalLayout->addWidget(pbt_ok);


        retranslateUi(AddNavDialog);

        QMetaObject::connectSlotsByName(AddNavDialog);
    } // setupUi

    void retranslateUi(QWidget *AddNavDialog)
    {
        AddNavDialog->setWindowTitle(QApplication::translate("AddNavDialog", "Form", 0));
        label->setText(QApplication::translate("AddNavDialog", "\350\276\223\345\205\245\345\237\237\345\220\215\345\277\253\346\215\267\346\267\273\345\212\240\345\257\274\350\210\252\344\277\241\346\201\257", 0));
        label_2->setText(QApplication::translate("AddNavDialog", "\345\205\254\345\217\270\345\237\237\345\220\215:", 0));
        lineEdit_Cmpurl->setPlaceholderText(QApplication::translate("AddNavDialog", "\350\257\267\350\276\223\345\205\245\345\237\237\345\220\215\357\274\214\345\246\202qunar.com", 0));
        pbt_cancel->setText(QApplication::translate("AddNavDialog", "\345\217\226\346\266\210", 0));
        pbt_ok->setText(QApplication::translate("AddNavDialog", "\346\267\273\345\212\240", 0));
    } // retranslateUi

};

namespace Ui {
    class AddNavDialog: public Ui_AddNavDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNAVDIALOG_H

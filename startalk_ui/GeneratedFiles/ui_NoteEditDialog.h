/********************************************************************************
** Form generated from reading UI file 'NoteEditDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEEDITDIALOG_H
#define UI_NOTEEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TitlebarWidget.h>
#include "webview.h"

QT_BEGIN_NAMESPACE

class Ui_NoteEditDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout_3;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout_2;
    TitlebarWidget *titlebar;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    webview *webView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbt_cancel;
    QPushButton *pbt_ok;

    void setupUi(QDialog *NoteEditDialog)
    {
        if (NoteEditDialog->objectName().isEmpty())
            NoteEditDialog->setObjectName(QStringLiteral("NoteEditDialog"));
        NoteEditDialog->resize(630, 580);
        NoteEditDialog->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QWidget#NoteEditDialog{\n"
"    background-color: #ECECEC;\n"
"}\n"
"\n"
"QPushButton#pbt_cancel{\n"
"    color: #666666;\n"
"	background-color: #FFFFFF;\n"
"	border:none;\n"
"}\n"
"QPushButton#pbt_ok{\n"
"    color: #FFFFFF;\n"
"	background-color: #3dbbca;\n"
"	border:none;\n"
"}\n"
"QPushButton#pbt_cancel:hover,#pbt_ok:hover {\n"
"    color: #FFFFFF;\n"
"	background-color: #3dbbca;\n"
"}\n"
"QPushButton#pbt_cancel:pressed,#pbt_ok:pressed{\n"
"\n"
"    color: #FFFFFF;\n"
"	background-color: #1194a4;\n"
"}\n"
"QPushButton#pbt_cancel:checked, #pbt_ok:checked{\n"
"\n"
"    color: #FFFFFF;\n"
"	background-color: #1ba9ba;\n"
"}\n"
""));
        verticalLayout_4 = new QVBoxLayout(NoteEditDialog);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(NoteEditDialog);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        verticalLayout_3 = new QVBoxLayout(shadowbg);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        verticalLayout_2 = new QVBoxLayout(shadowinnerbg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        titlebar = new TitlebarWidget(shadowinnerbg);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 30));
        titlebar->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(titlebar);

        widget_2 = new QWidget(shadowinnerbg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        webView = new webview(widget_2);
        webView->setObjectName(QStringLiteral("webView"));

        verticalLayout->addWidget(webView);


        verticalLayout_2->addWidget(widget_2);

        widget = new QWidget(shadowinnerbg);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 45));
        widget->setMaximumSize(QSize(16777215, 45));
        widget->setSizeIncrement(QSize(0, 0));
        widget->setBaseSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 30, 0);
        horizontalSpacer = new QSpacerItem(401, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbt_cancel = new QPushButton(widget);
        pbt_cancel->setObjectName(QStringLiteral("pbt_cancel"));
        pbt_cancel->setMinimumSize(QSize(60, 22));
        pbt_cancel->setFlat(true);

        horizontalLayout->addWidget(pbt_cancel);

        pbt_ok = new QPushButton(widget);
        pbt_ok->setObjectName(QStringLiteral("pbt_ok"));
        pbt_ok->setMinimumSize(QSize(60, 22));
        pbt_ok->setFlat(true);

        horizontalLayout->addWidget(pbt_ok);


        verticalLayout_2->addWidget(widget);


        verticalLayout_3->addWidget(shadowinnerbg);


        verticalLayout_4->addWidget(shadowbg);


        retranslateUi(NoteEditDialog);

        QMetaObject::connectSlotsByName(NoteEditDialog);
    } // setupUi

    void retranslateUi(QDialog *NoteEditDialog)
    {
        NoteEditDialog->setWindowTitle(QApplication::translate("NoteEditDialog", "Dialog", 0));
        pbt_cancel->setText(QApplication::translate("NoteEditDialog", "\345\217\226\346\266\210", 0));
        pbt_ok->setText(QApplication::translate("NoteEditDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class NoteEditDialog: public Ui_NoteEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEEDITDIALOG_H

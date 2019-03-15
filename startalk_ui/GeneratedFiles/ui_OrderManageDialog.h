/********************************************************************************
** Form generated from reading UI file 'OrderManageDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERMANAGEDIALOG_H
#define UI_ORDERMANAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TitlebarWidget.h>
#include "webview.h"

QT_BEGIN_NAMESPACE

class Ui_OrderManageDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout_2;
    TitlebarWidget *titlebar;
    QWidget *titlepanel;
    QLabel *lbTitle;
    QPushButton *btnMenu;
    QPushButton *btnBack;
    QProgressBar *pbLoad;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    webview *webView;

    void setupUi(QDialog *OrderManageDialog)
    {
        if (OrderManageDialog->objectName().isEmpty())
            OrderManageDialog->setObjectName(QStringLiteral("OrderManageDialog"));
        OrderManageDialog->resize(637, 584);
        OrderManageDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    border: 1px solid #000000;\n"
"}\n"
"\n"
"QWidget#toolbar\n"
"{\n"
"	background:#A0666666;\n"
"	border:none;\n"
"}\n"
"QLabel#lbTitle\n"
"{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#666666;\n"
"	font-size:14px;\n"
"}\n"
"QPushButton\n"
"{\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton#btnMenu\n"
"{\n"
"	image:url(:/Images/menu_normal.png);\n"
"}\n"
"QPushButton#btnMenu:hover\n"
"{\n"
"	image:url(:/Images/menu_hover.png);\n"
"}\n"
"QPushButton#btnBack\n"
"{\n"
"	image:url(:/Images/back_normal.png);\n"
"}\n"
"QPushButton#btnBack:hover\n"
"{\n"
"	image:url(:/Images/back_hover.png);\n"
"}\n"
"QWidget#titlepanel\n"
"{\n"
"	background:#FFFFFF;\n"
"}\n"
"\n"
"QProgressBar\n"
"{\n"
"	border:none;\n"
"}\n"
""));
        horizontalLayout_2 = new QHBoxLayout(OrderManageDialog);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(OrderManageDialog);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        verticalLayout = new QVBoxLayout(shadowbg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        shadowinnerbg->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(shadowinnerbg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        titlebar = new TitlebarWidget(shadowinnerbg);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 28));
        titlebar->setMaximumSize(QSize(16777215, 28));

        verticalLayout_2->addWidget(titlebar);

        titlepanel = new QWidget(shadowinnerbg);
        titlepanel->setObjectName(QStringLiteral("titlepanel"));
        titlepanel->setMinimumSize(QSize(0, 42));
        titlepanel->setMaximumSize(QSize(16777215, 32));
        lbTitle = new QLabel(titlepanel);
        lbTitle->setObjectName(QStringLiteral("lbTitle"));
        lbTitle->setGeometry(QRect(0, 0, 54, 16));
        lbTitle->setAlignment(Qt::AlignCenter);
        btnMenu = new QPushButton(titlepanel);
        btnMenu->setObjectName(QStringLiteral("btnMenu"));
        btnMenu->setGeometry(QRect(470, 10, 22, 28));
        btnMenu->setMinimumSize(QSize(22, 28));
        btnMenu->setMaximumSize(QSize(22, 28));
        btnBack = new QPushButton(titlepanel);
        btnBack->setObjectName(QStringLiteral("btnBack"));
        btnBack->setGeometry(QRect(170, 10, 22, 28));
        btnBack->setMinimumSize(QSize(22, 28));
        btnBack->setMaximumSize(QSize(22, 28));
        pbLoad = new QProgressBar(titlepanel);
        pbLoad->setObjectName(QStringLiteral("pbLoad"));
        pbLoad->setGeometry(QRect(200, 0, 118, 2));
        pbLoad->setMinimumSize(QSize(0, 2));
        pbLoad->setMaximumSize(QSize(16777215, 2));
        pbLoad->setValue(0);
        pbLoad->setAlignment(Qt::AlignCenter);
        pbLoad->setTextVisible(false);

        verticalLayout_2->addWidget(titlepanel);

        widget_2 = new QWidget(shadowinnerbg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        webView = new webview(widget_2);
        webView->setObjectName(QStringLiteral("webView"));

        horizontalLayout->addWidget(webView);


        verticalLayout_2->addWidget(widget_2);


        verticalLayout->addWidget(shadowinnerbg);


        horizontalLayout_2->addWidget(shadowbg);


        retranslateUi(OrderManageDialog);

        QMetaObject::connectSlotsByName(OrderManageDialog);
    } // setupUi

    void retranslateUi(QDialog *OrderManageDialog)
    {
        OrderManageDialog->setWindowTitle(QApplication::translate("OrderManageDialog", "Dialog", 0));
        lbTitle->setText(QString());
        btnMenu->setText(QString());
        btnBack->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OrderManageDialog: public Ui_OrderManageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERMANAGEDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'WebloginWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBLOGINWIDGET_H
#define UI_WEBLOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"
#include "webview.h"

QT_BEGIN_NAMESPACE

class Ui_WebloginWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *dialogbg;
    QVBoxLayout *verticalLayout_2;
    TitlebarWidget *widgettitlebar;
    QWidget *widget_webview;
    webview *webView;
    QPushButton *login;

    void setupUi(QWidget *WebloginWidget)
    {
        if (WebloginWidget->objectName().isEmpty())
            WebloginWidget->setObjectName(QStringLiteral("WebloginWidget"));
        WebloginWidget->setEnabled(true);
        WebloginWidget->resize(346, 628);
        WebloginWidget->setStyleSheet(QLatin1String("QPushButton#login\n"
"{\n"
"	border:none;\n"
"	background:#A01ba9ba;\n"
"	color:#EFEFEF;\n"
"}\n"
"\n"
"QPushButton#login:hover\n"
"{\n"
"	background:#A03dbbca;\n"
"}\n"
"\n"
"QPushButton#login:disabled\n"
"{\n"
"	background:#A0A8A8A8;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(WebloginWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        dialogbg = new QWidget(WebloginWidget);
        dialogbg->setObjectName(QStringLiteral("dialogbg"));
        verticalLayout_2 = new QVBoxLayout(dialogbg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widgettitlebar = new TitlebarWidget(dialogbg);
        widgettitlebar->setObjectName(QStringLiteral("widgettitlebar"));
        widgettitlebar->setMinimumSize(QSize(0, 28));
        widgettitlebar->setMaximumSize(QSize(16777215, 28));

        verticalLayout_2->addWidget(widgettitlebar);

        widget_webview = new QWidget(dialogbg);
        widget_webview->setObjectName(QStringLiteral("widget_webview"));
        webView = new webview(widget_webview);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setGeometry(QRect(0, 0, 346, 600));
        login = new QPushButton(widget_webview);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(100, 560, 231, 28));
        login->setMinimumSize(QSize(0, 28));
        login->setMaximumSize(QSize(16777215, 28));

        verticalLayout_2->addWidget(widget_webview);


        verticalLayout_3->addWidget(dialogbg);


        retranslateUi(WebloginWidget);

        QMetaObject::connectSlotsByName(WebloginWidget);
    } // setupUi

    void retranslateUi(QWidget *WebloginWidget)
    {
        WebloginWidget->setWindowTitle(QApplication::translate("WebloginWidget", "Form", 0));
        login->setText(QApplication::translate("WebloginWidget", "\347\231\273\351\231\206\345\220\216\357\274\214\345\246\202\346\236\234\346\234\252\350\207\252\345\212\250\350\267\263\350\275\254\357\274\214\350\257\267\347\202\271\345\207\273\346\255\244\345\244\204", 0));
    } // retranslateUi

};

namespace Ui {
    class WebloginWidget: public Ui_WebloginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBLOGINWIDGET_H

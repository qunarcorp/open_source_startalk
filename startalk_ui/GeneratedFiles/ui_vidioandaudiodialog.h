/********************************************************************************
** Form generated from reading UI file 'vidioandaudiodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDIOANDAUDIODIALOG_H
#define UI_VIDIOANDAUDIODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TitlebarWidget.h>
#include "LocalManDialog.h"
#include "webview.h"

QT_BEGIN_NAMESPACE

class Ui_VidioAndAudioDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout_2;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout_3;
    TitlebarWidget *titlebar;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    webview *webView;

    void setupUi(LocalManDialog *VidioAndAudioDialog)
    {
        if (VidioAndAudioDialog->objectName().isEmpty())
            VidioAndAudioDialog->setObjectName(QStringLiteral("VidioAndAudioDialog"));
        VidioAndAudioDialog->resize(630, 580);
        VidioAndAudioDialog->setMinimumSize(QSize(630, 580));
        verticalLayout = new QVBoxLayout(VidioAndAudioDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(VidioAndAudioDialog);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        verticalLayout_2 = new QVBoxLayout(shadowbg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        verticalLayout_3 = new QVBoxLayout(shadowinnerbg);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(1, 1, 1, 1);
        titlebar = new TitlebarWidget(shadowinnerbg);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 30));
        titlebar->setMaximumSize(QSize(16777215, 30));

        verticalLayout_3->addWidget(titlebar);

        widget_2 = new QWidget(shadowinnerbg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        webView = new webview(widget_2);
        webView->setObjectName(QStringLiteral("webView"));

        horizontalLayout->addWidget(webView);


        verticalLayout_3->addWidget(widget_2);


        verticalLayout_2->addWidget(shadowinnerbg);


        verticalLayout->addWidget(shadowbg);


        retranslateUi(VidioAndAudioDialog);

        QMetaObject::connectSlotsByName(VidioAndAudioDialog);
    } // setupUi

    void retranslateUi(LocalManDialog *VidioAndAudioDialog)
    {
        VidioAndAudioDialog->setWindowTitle(QApplication::translate("VidioAndAudioDialog", "VidioAndAudioDialog", 0));
    } // retranslateUi

};

namespace Ui {
    class VidioAndAudioDialog: public Ui_VidioAndAudioDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDIOANDAUDIODIALOG_H

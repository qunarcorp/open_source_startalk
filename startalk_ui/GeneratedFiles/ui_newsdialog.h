/********************************************************************************
** Form generated from reading UI file 'newsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSDIALOG_H
#define UI_NEWSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "LocalManDialog.h"
#include "draggablewebview.h"

QT_BEGIN_NAMESPACE

class Ui_NewsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wb;
    QVBoxLayout *verticalLayout_2;
    QWidget *titlebarWidget;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *headerimage;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *name;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *noticy;
    QWidget *webviewFrame;
    QHBoxLayout *horizontalLayout;
    DraggableWebView *webView;

    void setupUi(QWidget *NewsDialog)
    {
        if (NewsDialog->objectName().isEmpty())
            NewsDialog->setObjectName(QStringLiteral("NewsDialog"));
        NewsDialog->resize(752, 560);
        verticalLayout = new QVBoxLayout(NewsDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wb = new QWidget(NewsDialog);
        wb->setObjectName(QStringLiteral("wb"));
        verticalLayout_2 = new QVBoxLayout(wb);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 2);
        titlebarWidget = new QWidget(wb);
        titlebarWidget->setObjectName(QStringLiteral("titlebarWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titlebarWidget->sizePolicy().hasHeightForWidth());
        titlebarWidget->setSizePolicy(sizePolicy);
        titlebarWidget->setMinimumSize(QSize(0, 60));
        titlebarWidget->setMaximumSize(QSize(16777215, 60));
        titlebarWidget->setStyleSheet(QStringLiteral(""));
        horizontalLayout_6 = new QHBoxLayout(titlebarWidget);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 10, 0);
        widget_2 = new QWidget(titlebarWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 60));
        widget_2->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_7 = new QHBoxLayout(widget_2);
        horizontalLayout_7->setSpacing(10);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(10, 5, 7, 5);
        headerimage = new QPushButton(widget_2);
        headerimage->setObjectName(QStringLiteral("headerimage"));
        headerimage->setMinimumSize(QSize(50, 50));
        headerimage->setMaximumSize(QSize(50, 50));
        headerimage->setFlat(true);

        horizontalLayout_7->addWidget(headerimage);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 1, 5, 2);
        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_10 = new QHBoxLayout(widget_6);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        name = new QLabel(widget_6);
        name->setObjectName(QStringLiteral("name"));
        name->setStyleSheet(QStringLiteral("font: bold 14px;"));
        name->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        name->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_10->addWidget(name);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(widget_6);

        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_9 = new QHBoxLayout(widget_5);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        noticy = new QLabel(widget_5);
        noticy->setObjectName(QStringLiteral("noticy"));
        noticy->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_9->addWidget(noticy);


        verticalLayout_3->addWidget(widget_5);


        horizontalLayout_7->addWidget(widget_4);


        horizontalLayout_6->addWidget(widget_2);


        verticalLayout_2->addWidget(titlebarWidget);

        webviewFrame = new QWidget(wb);
        webviewFrame->setObjectName(QStringLiteral("webviewFrame"));
        horizontalLayout = new QHBoxLayout(webviewFrame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        webView = new DraggableWebView(webviewFrame);
        webView->setObjectName(QStringLiteral("webView"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
        webView->setSizePolicy(sizePolicy1);
        webView->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(webView);


        verticalLayout_2->addWidget(webviewFrame);


        verticalLayout->addWidget(wb);


        retranslateUi(NewsDialog);

        QMetaObject::connectSlotsByName(NewsDialog);
    } // setupUi

    void retranslateUi(QWidget *NewsDialog)
    {
        NewsDialog->setWindowTitle(QApplication::translate("NewsDialog", "NewsDialog", 0));
        name->setText(QString());
        noticy->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewsDialog: public Ui_NewsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSDIALOG_H

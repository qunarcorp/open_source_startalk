/********************************************************************************
** Form generated from reading UI file 'NotifyWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTIFYWINDOW_H
#define UI_NOTIFYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_NotifyWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout_4;
    QWidget *shadowinnerbg;
    QWidget *contentpanel;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *content_image;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *content_id;
    QLabel *content_msg_1;
    QLabel *content_msg_2;
    TitlebarWidget *Title_bar;

    void setupUi(QWidget *NotifyWindow)
    {
        if (NotifyWindow->objectName().isEmpty())
            NotifyWindow->setObjectName(QStringLiteral("NotifyWindow"));
        NotifyWindow->resize(278, 88);
        NotifyWindow->setMinimumSize(QSize(278, 88));
        NotifyWindow->setMaximumSize(QSize(278, 88));
        NotifyWindow->setCursor(QCursor(Qt::ArrowCursor));
        NotifyWindow->setStyleSheet(QString::fromUtf8("QWidget#NotifyWindow\n"
"{\n"
"	font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"}\n"
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
"QProgressBar{\n"
"	min-height:1px;\n"
"	max-height:1px;\n"
"}\n"
"QProgressBar::chunk {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,\n"
"		stop:0 #36CAD8,\n"
"		stop:0.7 #36CAD8,\n"
"		stop:1 #36CAD800);\n"
"}\n"
"QWidget#content_id,QWidget#content_msg_1,QWidget#content_msg_2\n"
"{\n"
"	font-size:12px;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(NotifyWindow);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(NotifyWindow);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        shadowbg->setMinimumSize(QSize(278, 88));
        shadowbg->setMaximumSize(QSize(278, 88));
        shadowbg->setStyleSheet(QStringLiteral(""));
        verticalLayout_4 = new QVBoxLayout(shadowbg);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        shadowinnerbg->setMinimumSize(QSize(262, 72));
        shadowinnerbg->setMaximumSize(QSize(262, 72));
        contentpanel = new QWidget(shadowinnerbg);
        contentpanel->setObjectName(QStringLiteral("contentpanel"));
        contentpanel->setGeometry(QRect(1, 1, 262, 72));
        contentpanel->setMinimumSize(QSize(262, 72));
        contentpanel->setMaximumSize(QSize(262, 72));
        horizontalLayout = new QHBoxLayout(contentpanel);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(contentpanel);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(68, 72));
        widget->setMaximumSize(QSize(68, 72));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(16, 16, 13, 16);
        content_image = new QLabel(widget);
        content_image->setObjectName(QStringLiteral("content_image"));
        content_image->setMinimumSize(QSize(40, 40));
        content_image->setMaximumSize(QSize(40, 40));
        content_image->setTextFormat(Qt::AutoText);
        content_image->setScaledContents(false);
        content_image->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        content_image->setWordWrap(false);

        verticalLayout->addWidget(content_image);


        horizontalLayout->addWidget(widget);

        widget_3 = new QWidget(contentpanel);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(190, 72));
        widget_3->setMaximumSize(QSize(190, 72));
        widget_3->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 13, 0, 13);
        content_id = new QLabel(widget_3);
        content_id->setObjectName(QStringLiteral("content_id"));
        content_id->setMinimumSize(QSize(140, 14));
        content_id->setMaximumSize(QSize(140, 14));
        content_id->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(content_id);

        content_msg_1 = new QLabel(widget_3);
        content_msg_1->setObjectName(QStringLiteral("content_msg_1"));
        content_msg_1->setMinimumSize(QSize(154, 14));
        content_msg_1->setMaximumSize(QSize(184, 14));
        content_msg_1->setWordWrap(false);

        verticalLayout_2->addWidget(content_msg_1);

        content_msg_2 = new QLabel(widget_3);
        content_msg_2->setObjectName(QStringLiteral("content_msg_2"));
        content_msg_2->setMinimumSize(QSize(154, 14));
        content_msg_2->setMaximumSize(QSize(184, 14));
        content_msg_2->setWordWrap(false);

        verticalLayout_2->addWidget(content_msg_2);


        horizontalLayout->addWidget(widget_3);

        Title_bar = new TitlebarWidget(shadowinnerbg);
        Title_bar->setObjectName(QStringLiteral("Title_bar"));
        Title_bar->setGeometry(QRect(7, 0, 251, 27));
        Title_bar->setMinimumSize(QSize(20, 27));
        Title_bar->setMaximumSize(QSize(16777215, 27));

        verticalLayout_4->addWidget(shadowinnerbg);


        verticalLayout_3->addWidget(shadowbg);


        retranslateUi(NotifyWindow);

        QMetaObject::connectSlotsByName(NotifyWindow);
    } // setupUi

    void retranslateUi(QWidget *NotifyWindow)
    {
        NotifyWindow->setWindowTitle(QApplication::translate("NotifyWindow", "NodifyWindow", 0));
        content_image->setText(QString());
        content_id->setText(QApplication::translate("NotifyWindow", "TextLabel", 0));
        content_msg_1->setText(QApplication::translate("NotifyWindow", "TextLabel", 0));
        content_msg_2->setText(QApplication::translate("NotifyWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class NotifyWindow: public Ui_NotifyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTIFYWINDOW_H

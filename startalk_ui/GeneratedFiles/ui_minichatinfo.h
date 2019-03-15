/********************************************************************************
** Form generated from reading UI file 'minichatinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINICHATINFO_H
#define UI_MINICHATINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MiniChatInfo
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *sp;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *header;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *title;
    QSpacerItem *verticalSpacer;
    QLabel *desc;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *time;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *unread;

    void setupUi(QWidget *MiniChatInfo)
    {
        if (MiniChatInfo->objectName().isEmpty())
            MiniChatInfo->setObjectName(QStringLiteral("MiniChatInfo"));
        MiniChatInfo->resize(372, 62);
        MiniChatInfo->setMinimumSize(QSize(0, 60));
        MiniChatInfo->setMaximumSize(QSize(16777215, 666666));
        MiniChatInfo->setStyleSheet(QString::fromUtf8("QWidget{\n"
"    background-color: #00000000;\n"
"}\n"
" \n"
"QWidget#sp\n"
"{\n"
"	border:1px solid #D7D8D9;\n"
"}\n"
"\n"
"QLabel#time{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 12px;\n"
"    color: #333333;\n"
"}\n"
"\n"
"QLabel#title{\n"
"		font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 14px;\n"
"    color: #333333;\n"
"}\n"
"\n"
"QLabel#desc{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 12px;\n"
"    color: #666666;\n"
"}\n"
"\n"
"QLabel#unread{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    font-size: 12px;\n"
"    padding:-5px;\n"
"    color: #FFFFFF;\n"
"    border-image: url(:Images/tipsIcon.png) 8 8 8 8;\n"
"    border-top: 8px transparent;\n"
"    border-bottom: 8px transparent;\n"
"    border-right: 8px transparent;\n"
"    border-left: 8px transparent;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(MiniChatInfo);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        sp = new QWidget(MiniChatInfo);
        sp->setObjectName(QStringLiteral("sp"));
        sp->setMinimumSize(QSize(0, 1));
        sp->setMaximumSize(QSize(16777215, 1));

        verticalLayout_3->addWidget(sp);

        widget_4 = new QWidget(MiniChatInfo);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(0, 60));
        widget_4->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(9, 0, 20, 0);
        header = new QLabel(widget_4);
        header->setObjectName(QStringLiteral("header"));
        header->setMinimumSize(QSize(50, 50));
        header->setMaximumSize(QSize(50, 50));
        header->setProperty("flat", QVariant(true));

        horizontalLayout_3->addWidget(header);

        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 0, 5, 0);
        title = new QLabel(widget_2);
        title->setObjectName(QStringLiteral("title"));
        title->setMinimumSize(QSize(0, 27));
        title->setMaximumSize(QSize(16777215, 27));
        title->setStyleSheet(QStringLiteral(""));
        title->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        title->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(title);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        desc = new QLabel(widget_2);
        desc->setObjectName(QStringLiteral("desc"));
        desc->setMinimumSize(QSize(0, 27));
        desc->setMaximumSize(QSize(16777215, 27));
        desc->setStyleSheet(QStringLiteral(""));
        desc->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        desc->setWordWrap(false);
        desc->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(desc);


        horizontalLayout_3->addWidget(widget_2);

        horizontalSpacer = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        widget = new QWidget(widget_4);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 0));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 5);
        time = new QLabel(widget);
        time->setObjectName(QStringLiteral("time"));
        time->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        verticalLayout_2->addWidget(time);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(23, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        unread = new QLabel(widget_3);
        unread->setObjectName(QStringLiteral("unread"));
        unread->setMinimumSize(QSize(0, 0));
        unread->setMaximumSize(QSize(20000, 20));
        unread->setStyleSheet(QStringLiteral(""));
        unread->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        unread->setProperty("flat", QVariant(true));

        horizontalLayout_2->addWidget(unread);


        verticalLayout_2->addWidget(widget_3);


        horizontalLayout_3->addWidget(widget);


        verticalLayout_3->addWidget(widget_4);


        retranslateUi(MiniChatInfo);

        QMetaObject::connectSlotsByName(MiniChatInfo);
    } // setupUi

    void retranslateUi(QWidget *MiniChatInfo)
    {
        MiniChatInfo->setWindowTitle(QApplication::translate("MiniChatInfo", "MiniChatInfo", 0));
        header->setText(QString());
        title->setText(QString());
        desc->setText(QString());
        time->setText(QString());
        unread->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MiniChatInfo: public Ui_MiniChatInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINICHATINFO_H

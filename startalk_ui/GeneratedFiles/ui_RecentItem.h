/********************************************************************************
** Form generated from reading UI file 'RecentItem.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECENTITEM_H
#define UI_RECENTITEM_H

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
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_recentitem
{
public:
    QWidget *ri_panel;
    QHBoxLayout *horizontalLayout;
    StaticLabel *header;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *titleimage;
    QLabel *title;
    QLabel *desc;
    QLabel *unreadimg;
    QLabel *unread;
    QWidget *leftext;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnClose;
    QPushButton *btnMark;
    QSpacerItem *horizontalSpacer;
    QLabel *unread_tip;

    void setupUi(QWidget *recentitem)
    {
        if (recentitem->objectName().isEmpty())
            recentitem->setObjectName(QStringLiteral("recentitem"));
        recentitem->resize(258, 60);
        recentitem->setMinimumSize(QSize(40, 60));
        recentitem->setMaximumSize(QSize(16777215, 60));
        recentitem->setStyleSheet(QLatin1String("QLabel#unread{\n"
"	\n"
"	font-size:11px;\n"
"    min-width:15px;\n"
"	min-height:15px;\n"
"	max-height:15px;\n"
"    color: #FFFFFF;\n"
"    background:#F55F56;\n"
"    border-radius:7px;\n"
"    padding-left:4px;\n"
"    padding-right:4px;\n"
"}\n"
"\n"
"QLabel#unread_tip{\n"
"    min-width:8px;\n"
"	min-height:8px;\n"
"    color: #FFFFFF;\n"
"    background:#F55F56;\n"
"    border-radius:4px;\n"
"    padding-left:4px;\n"
"    padding-right:4px;\n"
"}\n"
"\n"
"\n"
"QPushButton\n"
"{\n"
"		border:none;                             \n"
"		background-color:#A01ba9ba;     \n"
"}\n"
"QPushButton:hover\n"
"{\n"
"		border:none;                             \n"
"		background-color:#A03dbbca;     \n"
"}\n"
"\n"
"\n"
"QLabel#title\n"
"{\n"
"	border:none;\n"
"    font-size:14px;\n"
"	color:#CFCFCF;\n"
"}\n"
"QLabel#desc\n"
"{\n"
"	font-size:12px;\n"
"	color:#F8F8FF;\n"
"}\n"
""));
        ri_panel = new QWidget(recentitem);
        ri_panel->setObjectName(QStringLiteral("ri_panel"));
        ri_panel->setGeometry(QRect(0, 0, 251, 60));
        ri_panel->setMinimumSize(QSize(40, 60));
        ri_panel->setMaximumSize(QSize(16777215, 60));
        ri_panel->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(ri_panel);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 0, 0);
        header = new StaticLabel(ri_panel);
        header->setObjectName(QStringLiteral("header"));
        header->setMinimumSize(QSize(40, 40));
        header->setMaximumSize(QSize(40, 40));
        header->setStyleSheet(QStringLiteral(""));
        header->setProperty("flat", QVariant(true));

        horizontalLayout->addWidget(header);

        widget_2 = new QWidget(ri_panel);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 0, 0, 0);
        widget = new QWidget(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(16777215, 27));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMaximumSize(QSize(16, 27));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 10, 0, 0);
        titleimage = new QLabel(widget_3);
        titleimage->setObjectName(QStringLiteral("titleimage"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleimage->sizePolicy().hasHeightForWidth());
        titleimage->setSizePolicy(sizePolicy);
        titleimage->setMaximumSize(QSize(15, 15));
        titleimage->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        titleimage->setMargin(0);
        titleimage->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_2->addWidget(titleimage);


        horizontalLayout_3->addWidget(widget_3);

        title = new QLabel(widget);
        title->setObjectName(QStringLiteral("title"));
        sizePolicy.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy);
        title->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        title->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_3->addWidget(title);


        verticalLayout->addWidget(widget);

        desc = new QLabel(widget_2);
        desc->setObjectName(QStringLiteral("desc"));
        desc->setStyleSheet(QStringLiteral(""));
        desc->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        desc->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(desc);


        horizontalLayout->addWidget(widget_2);

        unreadimg = new QLabel(ri_panel);
        unreadimg->setObjectName(QStringLiteral("unreadimg"));
        unreadimg->setMaximumSize(QSize(0, 16777215));
        unreadimg->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(unreadimg);

        unread = new QLabel(recentitem);
        unread->setObjectName(QStringLiteral("unread"));
        unread->setGeometry(QRect(10, 10, 25, 15));
        sizePolicy.setHeightForWidth(unread->sizePolicy().hasHeightForWidth());
        unread->setSizePolicy(sizePolicy);
        unread->setMinimumSize(QSize(23, 15));
        unread->setStyleSheet(QStringLiteral(""));
        unread->setAlignment(Qt::AlignCenter);
        unread->setProperty("flat", QVariant(true));
        leftext = new QWidget(recentitem);
        leftext->setObjectName(QStringLiteral("leftext"));
        leftext->setGeometry(QRect(0, 0, 64, 60));
        leftext->setMinimumSize(QSize(0, 60));
        horizontalLayout_2 = new QHBoxLayout(leftext);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnClose = new QPushButton(leftext);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setMinimumSize(QSize(28, 60));
        btnClose->setMaximumSize(QSize(28, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/close-hover.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon);
        btnClose->setFlat(true);

        horizontalLayout_2->addWidget(btnClose);

        btnMark = new QPushButton(leftext);
        btnMark->setObjectName(QStringLiteral("btnMark"));
        btnMark->setMinimumSize(QSize(28, 0));
        btnMark->setMaximumSize(QSize(28, 60));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/tip.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMark->setIcon(icon1);
        btnMark->setIconSize(QSize(12, 12));

        horizontalLayout_2->addWidget(btnMark);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        unread_tip = new QLabel(recentitem);
        unread_tip->setObjectName(QStringLiteral("unread_tip"));
        unread_tip->setGeometry(QRect(10, 40, 8, 8));
        sizePolicy.setHeightForWidth(unread_tip->sizePolicy().hasHeightForWidth());
        unread_tip->setSizePolicy(sizePolicy);
        unread_tip->setMinimumSize(QSize(8, 8));
        unread_tip->setMaximumSize(QSize(8, 8));
        unread_tip->setStyleSheet(QStringLiteral(""));
        unread_tip->setAlignment(Qt::AlignCenter);
        unread_tip->setProperty("flat", QVariant(true));

        retranslateUi(recentitem);

        QMetaObject::connectSlotsByName(recentitem);
    } // setupUi

    void retranslateUi(QWidget *recentitem)
    {
        recentitem->setWindowTitle(QApplication::translate("recentitem", "TitlebarWidget", 0));
        header->setText(QString());
        titleimage->setText(QString());
        title->setText(QString());
        desc->setText(QString());
        unreadimg->setText(QString());
        unread->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnClose->setToolTip(QApplication::translate("recentitem", "\345\205\263\351\227\255", 0));
#endif // QT_NO_TOOLTIP
        btnClose->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMark->setToolTip(QApplication::translate("recentitem", "\345\244\207\346\263\250", 0));
#endif // QT_NO_TOOLTIP
        btnMark->setText(QString());
        btnMark->setShortcut(QApplication::translate("recentitem", "Ctrl+S", 0));
        unread_tip->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class recentitem: public Ui_recentitem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECENTITEM_H

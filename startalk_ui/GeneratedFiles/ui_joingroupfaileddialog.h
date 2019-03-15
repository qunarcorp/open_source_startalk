/********************************************************************************
** Form generated from reading UI file 'joingroupfaileddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOINGROUPFAILEDDIALOG_H
#define UI_JOINGROUPFAILEDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_JoinGroupFailedDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *dialogborderback;
    QVBoxLayout *verticalLayout;
    TitlebarWidget *titlebar;
    QListWidget *listWidget;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *JoinGroupFailedDialog)
    {
        if (JoinGroupFailedDialog->objectName().isEmpty())
            JoinGroupFailedDialog->setObjectName(QStringLiteral("JoinGroupFailedDialog"));
        JoinGroupFailedDialog->resize(250, 276);
        JoinGroupFailedDialog->setStyleSheet(QLatin1String("QListWidget{\n"
"	border:none;\n"
"	background:#00000000;\n"
"}\n"
"\n"
"QListWidget:Item{\n"
"	border:none;\n"
"	background:#00000000;\n"
"}\n"
"\n"
"QListWidget:Item:select{\n"
"	border:none;\n"
"	background:#00000000;\n"
"}\n"
"QPushButton{\n"
"	 border-radius: 0px;\n"
"    color:#FFFFFF;\n"
"    background-color:#3DCE3D;\n"
"	max-height:26px;\n"
"	min-height:26px;\n"
"	max-width:70px;\n"
"	min-width:70px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    background-color:#38C738;\n"
"}\n"
"QPushButton#ok:pressed{\n"
"    background-color:#2FB82F;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(JoinGroupFailedDialog);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        dialogborderback = new QWidget(JoinGroupFailedDialog);
        dialogborderback->setObjectName(QStringLiteral("dialogborderback"));
        dialogborderback->setMinimumSize(QSize(250, 0));
        dialogborderback->setMaximumSize(QSize(250, 16777215));
        verticalLayout = new QVBoxLayout(dialogborderback);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titlebar = new TitlebarWidget(dialogborderback);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 27));
        titlebar->setMaximumSize(QSize(16777215, 27));

        verticalLayout->addWidget(titlebar);

        listWidget = new QListWidget(dialogborderback);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        listWidget->setLayoutMode(QListView::SinglePass);
        listWidget->setViewMode(QListView::ListMode);
        listWidget->setSelectionRectVisible(false);

        verticalLayout->addWidget(listWidget);

        widget_3 = new QWidget(dialogborderback);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 5, 10, 10);
        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(70, 26));
        pushButton->setMaximumSize(QSize(70, 26));
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addWidget(widget_3);


        horizontalLayout_2->addWidget(dialogborderback);


        retranslateUi(JoinGroupFailedDialog);

        QMetaObject::connectSlotsByName(JoinGroupFailedDialog);
    } // setupUi

    void retranslateUi(QWidget *JoinGroupFailedDialog)
    {
        JoinGroupFailedDialog->setWindowTitle(QApplication::translate("JoinGroupFailedDialog", "JoinGroupFailedDialog", 0));
        pushButton->setText(QApplication::translate("JoinGroupFailedDialog", "\345\205\250\351\203\250\351\207\215\350\257\225", 0));
    } // retranslateUi

};

namespace Ui {
    class JoinGroupFailedDialog: public Ui_JoinGroupFailedDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOINGROUPFAILEDDIALOG_H

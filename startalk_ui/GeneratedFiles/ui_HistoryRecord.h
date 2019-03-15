/********************************************************************************
** Form generated from reading UI file 'HistoryRecord.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYRECORD_H
#define UI_HISTORYRECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <webview.h>
#include "Tableview.h"
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_HistoryRecordDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    TitlebarWidget *titleBar;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *Edit_Relation;
    QLabel *label_2;
    QLineEdit *Edit_Msg;
    QPushButton *pushbtn_search;
    QPushButton *pushbtn_clear;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    TableView *tableView;
    webview *webView;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *labelInfor;
    QPushButton *PbSearchAbove;
    QPushButton *PbSearchNext;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbBegin;
    QPushButton *pbblow;
    QPushButton *pbnext;
    QPushButton *pbEnd;

    void setupUi(QWidget *HistoryRecordDialog)
    {
        if (HistoryRecordDialog->objectName().isEmpty())
            HistoryRecordDialog->setObjectName(QStringLiteral("HistoryRecordDialog"));
        HistoryRecordDialog->resize(719, 586);
        HistoryRecordDialog->setMinimumSize(QSize(719, 586));
        HistoryRecordDialog->setStyleSheet(QLatin1String("QDialog {\n"
"    border: 1px solid #000000;\n"
"   background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #FFFFFF, stop: 0.1 #A3A6A9,\n"
"                                 stop: 0.9 #A3A6A9, stop: 1.0 #FFFFFF);\n"
"}\n"
"TableView::item::selected\n"
"{\n"
"	color:white;\n"
"	background:blue;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(HistoryRecordDialog);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(HistoryRecordDialog);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        titleBar = new TitlebarWidget(widget_4);
        titleBar->setObjectName(QStringLiteral("titleBar"));
        titleBar->setMinimumSize(QSize(0, 25));

        verticalLayout_2->addWidget(titleBar);

        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(6, 10, 6, 0);
        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        Edit_Relation = new QLineEdit(groupBox);
        Edit_Relation->setObjectName(QStringLiteral("Edit_Relation"));

        horizontalLayout_2->addWidget(Edit_Relation);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        Edit_Msg = new QLineEdit(groupBox);
        Edit_Msg->setObjectName(QStringLiteral("Edit_Msg"));

        horizontalLayout_2->addWidget(Edit_Msg);

        pushbtn_search = new QPushButton(groupBox);
        pushbtn_search->setObjectName(QStringLiteral("pushbtn_search"));
        pushbtn_search->setFlat(true);

        horizontalLayout_2->addWidget(pushbtn_search);

        pushbtn_clear = new QPushButton(groupBox);
        pushbtn_clear->setObjectName(QStringLiteral("pushbtn_clear"));
        pushbtn_clear->setFlat(true);

        horizontalLayout_2->addWidget(pushbtn_clear);


        verticalLayout_4->addWidget(groupBox);

        splitter = new QSplitter(widget_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setMinimumSize(QSize(0, 0));
        splitter->setOrientation(Qt::Vertical);
        splitter->setChildrenCollapsible(false);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new TableView(widget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setMinimumSize(QSize(707, 150));
        tableView->setProperty("showGrid", QVariant(true));

        verticalLayout->addWidget(tableView);

        splitter->addWidget(widget);
        webView = new webview(splitter);
        webView->setObjectName(QStringLiteral("webView"));
        splitter->addWidget(webView);

        verticalLayout_4->addWidget(splitter);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelInfor = new QLabel(widget_3);
        labelInfor->setObjectName(QStringLiteral("labelInfor"));

        horizontalLayout->addWidget(labelInfor);

        PbSearchAbove = new QPushButton(widget_3);
        PbSearchAbove->setObjectName(QStringLiteral("PbSearchAbove"));
        PbSearchAbove->setMinimumSize(QSize(45, 20));
        PbSearchAbove->setFlat(true);

        horizontalLayout->addWidget(PbSearchAbove);

        PbSearchNext = new QPushButton(widget_3);
        PbSearchNext->setObjectName(QStringLiteral("PbSearchNext"));
        PbSearchNext->setMinimumSize(QSize(45, 20));
        PbSearchNext->setFlat(true);

        horizontalLayout->addWidget(PbSearchNext);

        horizontalSpacer = new QSpacerItem(346, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbBegin = new QPushButton(widget_3);
        pbBegin->setObjectName(QStringLiteral("pbBegin"));
        pbBegin->setMinimumSize(QSize(45, 20));
        pbBegin->setFlat(true);

        horizontalLayout->addWidget(pbBegin);

        pbblow = new QPushButton(widget_3);
        pbblow->setObjectName(QStringLiteral("pbblow"));
        pbblow->setFlat(true);

        horizontalLayout->addWidget(pbblow);

        pbnext = new QPushButton(widget_3);
        pbnext->setObjectName(QStringLiteral("pbnext"));
        pbnext->setFlat(true);

        horizontalLayout->addWidget(pbnext);

        pbEnd = new QPushButton(widget_3);
        pbEnd->setObjectName(QStringLiteral("pbEnd"));
        pbEnd->setFlat(true);

        horizontalLayout->addWidget(pbEnd);


        verticalLayout_4->addWidget(widget_3);


        verticalLayout_2->addWidget(widget_2);


        verticalLayout_3->addWidget(widget_4);


        retranslateUi(HistoryRecordDialog);

        QMetaObject::connectSlotsByName(HistoryRecordDialog);
    } // setupUi

    void retranslateUi(QWidget *HistoryRecordDialog)
    {
        HistoryRecordDialog->setWindowTitle(QApplication::translate("HistoryRecordDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("HistoryRecordDialog", "\346\237\245\346\211\276\346\235\241\344\273\266", 0));
        label->setText(QApplication::translate("HistoryRecordDialog", "\350\201\224\347\263\273\344\272\272:", 0));
        label_2->setText(QApplication::translate("HistoryRecordDialog", "\346\266\210\346\201\257\345\206\205\345\256\271:", 0));
        pushbtn_search->setText(QApplication::translate("HistoryRecordDialog", "\346\237\245\346\211\276", 0));
        pushbtn_clear->setText(QApplication::translate("HistoryRecordDialog", "\346\270\205\351\231\244", 0));
        labelInfor->setText(QString());
        PbSearchAbove->setText(QApplication::translate("HistoryRecordDialog", "\344\270\212\344\270\200\346\235\241", 0));
        PbSearchNext->setText(QApplication::translate("HistoryRecordDialog", "\344\270\213\344\270\200\346\235\241", 0));
        pbBegin->setText(QApplication::translate("HistoryRecordDialog", "\351\246\226\351\241\265", 0));
        pbblow->setText(QApplication::translate("HistoryRecordDialog", "\344\270\212\351\241\265", 0));
        pbnext->setText(QApplication::translate("HistoryRecordDialog", "\344\270\213\351\241\265", 0));
        pbEnd->setText(QApplication::translate("HistoryRecordDialog", "\345\260\276\351\241\265", 0));
    } // retranslateUi

};

namespace Ui {
    class HistoryRecordDialog: public Ui_HistoryRecordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYRECORD_H

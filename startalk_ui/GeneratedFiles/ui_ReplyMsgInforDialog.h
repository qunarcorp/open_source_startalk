/********************************************************************************
** Form generated from reading UI file 'ReplyMsgInforDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLYMSGINFORDIALOG_H
#define UI_REPLYMSGINFORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReplayMsgInforDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *dialogbg;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QListWidget *Replylistgroup;
    QPushButton *pbSetting;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QListWidget *ReplylistMsg;

    void setupUi(QWidget *ReplayMsgInforDialog)
    {
        if (ReplayMsgInforDialog->objectName().isEmpty())
            ReplayMsgInforDialog->setObjectName(QStringLiteral("ReplayMsgInforDialog"));
        ReplayMsgInforDialog->resize(550, 400);
        ReplayMsgInforDialog->setMinimumSize(QSize(550, 400));
        ReplayMsgInforDialog->setMaximumSize(QSize(16777215, 16777214));
        ReplayMsgInforDialog->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QDialog#ReplayMsgInforDialog{\n"
"	border: 1px solid #3A3A3A;\n"
"	background:#EEF0F0F0;\n"
"	border-radius: 0px;\n"
"}\n"
"\n"
"\n"
"\n"
"QListWidget{\n"
"border: none;\n"
"background:#00000000;\n"
"alternate-background-color: #EEF5F5F5;\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"	border: 1px solid #3A3A3A;\n"
"	color:white;\n"
"	background:#888dd9;\n"
" }\n"
"QListWidget::item:hover {\n"
"	border: 1px solid #3A3A3A;\n"
"	color:white;\n"
"	background:#888dd9;\n"
" }\n"
"QListWidget::item:selected:!active {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #ABAFE5, stop: 1 #8588B2);\n"
" }\n"
" \n"
" QListWidget::item:selected:active {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #6a6ea9, stop: 1 #888dd9);\n"
" }\n"
"\n"
"QListWidget#Replylistgroup,#ReplylistMsg{\n"
"background:#00000000;\n"
""
                        "alternate-background-color: #EEF5F5F5;\n"
"}\n"
"\n"
"QPushButton#pbSetting {\n"
"    border : 1px solid #00000000;\n"
"	background:#1ba9ba;\n"
"}\n"
"\n"
"QPushButton#pbSetting:hover {\n"
"	background:#3dbbca;\n"
"}\n"
"QPushButton#pbSetting:pressed {\n"
"	background:#1194a4;\n"
"}"));
        verticalLayout = new QVBoxLayout(ReplayMsgInforDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        dialogbg = new QWidget(ReplayMsgInforDialog);
        dialogbg->setObjectName(QStringLiteral("dialogbg"));
        dialogbg->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(dialogbg);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        widget_2 = new QWidget(dialogbg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(140, 0));
        widget_2->setMaximumSize(QSize(140, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, -1, 0);
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 28));
        label->setMaximumSize(QSize(16777215, 28));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        Replylistgroup = new QListWidget(widget_2);
        Replylistgroup->setObjectName(QStringLiteral("Replylistgroup"));
        Replylistgroup->setAlternatingRowColors(true);

        verticalLayout_2->addWidget(Replylistgroup);

        pbSetting = new QPushButton(widget_2);
        pbSetting->setObjectName(QStringLiteral("pbSetting"));
        pbSetting->setMinimumSize(QSize(0, 28));
        pbSetting->setMaximumSize(QSize(16777215, 28));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/mainpanel_setting_normal.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSetting->setIcon(icon);
        pbSetting->setFlat(true);

        verticalLayout_2->addWidget(pbSetting);


        horizontalLayout->addWidget(widget_2);

        widget_3 = new QWidget(dialogbg);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 28));
        label_2->setMaximumSize(QSize(16777215, 28));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        ReplylistMsg = new QListWidget(widget_3);
        ReplylistMsg->setObjectName(QStringLiteral("ReplylistMsg"));
        ReplylistMsg->setStyleSheet(QStringLiteral(""));
        ReplylistMsg->setAlternatingRowColors(true);

        verticalLayout_3->addWidget(ReplylistMsg);


        horizontalLayout->addWidget(widget_3);


        verticalLayout->addWidget(dialogbg);


        retranslateUi(ReplayMsgInforDialog);

        QMetaObject::connectSlotsByName(ReplayMsgInforDialog);
    } // setupUi

    void retranslateUi(QWidget *ReplayMsgInforDialog)
    {
        ReplayMsgInforDialog->setWindowTitle(QApplication::translate("ReplayMsgInforDialog", "Dialog", 0));
        label->setText(QApplication::translate("ReplayMsgInforDialog", "\345\210\206\347\273\204", 0));
        pbSetting->setText(QApplication::translate("ReplayMsgInforDialog", "\347\274\226\350\276\221\345\277\253\346\215\267\345\233\236\345\244\215\350\257\255", 0));
        label_2->setText(QApplication::translate("ReplayMsgInforDialog", "\345\277\253\346\215\267\345\233\236\345\244\215\350\257\255", 0));
    } // retranslateUi

};

namespace Ui {
    class ReplayMsgInforDialog: public Ui_ReplayMsgInforDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLYMSGINFORDIALOG_H

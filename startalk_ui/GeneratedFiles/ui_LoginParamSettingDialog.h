/********************************************************************************
** Form generated from reading UI file 'LoginParamSettingDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPARAMSETTINGDIALOG_H
#define UI_LOGINPARAMSETTINGDIALOG_H

#include <QPromptEdit.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_LoginParamSettingDialog
{
public:
    QVBoxLayout *verticalLayout;
    TitlebarWidget *titlebar;
    QVBoxLayout *verticalLayout_3;
    QWidget *content;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QWidget *w_envpanel;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *cb_pbenable;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *cb_betaenable;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLineEdit *le_navurl;
    QWidget *previews;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QClearableEdit *le_xmpphost;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QClearableEdit *le_xmppport;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QClearableEdit *le_domain;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QClearableEdit *le_httphost;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QClearableEdit *le_filehost;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbt_NavManager;
    QSpacerItem *horizontalSpacer;
    QPushButton *reset;
    QPushButton *preview;
    QPushButton *apply;

    void setupUi(QWidget *LoginParamSettingDialog)
    {
        if (LoginParamSettingDialog->objectName().isEmpty())
            LoginParamSettingDialog->setObjectName(QStringLiteral("LoginParamSettingDialog"));
        LoginParamSettingDialog->resize(420, 286);
        LoginParamSettingDialog->setMinimumSize(QSize(420, 0));
        LoginParamSettingDialog->setMaximumSize(QSize(420, 16777215));
        LoginParamSettingDialog->setStyleSheet(QLatin1String("QLineEdit{\n"
"	color:  #333333;\n"
"	background:#AAffffff;	\n"
"	font: 14px;\n"
"	border: 1px solid #FFFFFF;\n"
"}\n"
"\n"
"QLineEdit:hover{\n"
"	border: 1px solid #65e1f6;\n"
"}\n"
"QLineEdit:focus{\n"
"	border: 1px solid #65e1f6;\n"
"}\n"
"\n"
"\n"
"QPushButton#apply,QPushButton#preview,QPushButton#pbt_NavManager\n"
"{\n"
"	background:#1ba9ba;\n"
"	color:#efefef;\n"
"	border:none;\n"
"}\n"
"QPushButton#apply:hover,QPushButton#preview:hover,QPushButton#pbt_NavManager:hover\n"
"{\n"
"	background:#3dbbca;\n"
"}\n"
"\n"
"QPushButton#reset\n"
"{\n"
"	background:#f5f5f5;\n"
"	color:#666666;\n"
"	border:1px solid #e5e5e5;\n"
"}\n"
"QPushButton#reset:hover\n"
"{\n"
"	background:#ffffff;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(LoginParamSettingDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titlebar = new TitlebarWidget(LoginParamSettingDialog);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titlebar->sizePolicy().hasHeightForWidth());
        titlebar->setSizePolicy(sizePolicy);
        titlebar->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(titlebar);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(titlebar);

        content = new QWidget(LoginParamSettingDialog);
        content->setObjectName(QStringLiteral("content"));
        verticalLayout_2 = new QVBoxLayout(content);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(content);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(10, 10, 20, 0);
        w_envpanel = new QWidget(widget);
        w_envpanel->setObjectName(QStringLiteral("w_envpanel"));
        verticalLayout_5 = new QVBoxLayout(w_envpanel);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_10 = new QWidget(w_envpanel);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        widget_10->setMinimumSize(QSize(0, 28));
        widget_10->setMaximumSize(QSize(16777215, 28));
        widget_10->setSizeIncrement(QSize(0, 0));
        horizontalLayout_7 = new QHBoxLayout(widget_10);
        horizontalLayout_7->setSpacing(10);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget_10);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(90, 28));
        label_6->setMaximumSize(QSize(16777215, 28));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_6);

        horizontalSpacer_2 = new QSpacerItem(264, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        cb_pbenable = new QCheckBox(widget_10);
        cb_pbenable->setObjectName(QStringLiteral("cb_pbenable"));

        horizontalLayout_7->addWidget(cb_pbenable);


        verticalLayout_5->addWidget(widget_10);

        widget_11 = new QWidget(w_envpanel);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        widget_11->setMinimumSize(QSize(0, 28));
        widget_11->setMaximumSize(QSize(16777215, 28));
        widget_11->setSizeIncrement(QSize(0, 28));
        horizontalLayout_8 = new QHBoxLayout(widget_11);
        horizontalLayout_8->setSpacing(10);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget_11);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(90, 28));
        label_7->setMaximumSize(QSize(16777215, 28));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_7);

        horizontalSpacer_3 = new QSpacerItem(264, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        cb_betaenable = new QCheckBox(widget_11);
        cb_betaenable->setObjectName(QStringLiteral("cb_betaenable"));

        horizontalLayout_8->addWidget(cb_betaenable);


        verticalLayout_5->addWidget(widget_11);

        widget_12 = new QWidget(w_envpanel);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setMinimumSize(QSize(0, 28));
        widget_12->setMaximumSize(QSize(16777215, 28));
        widget_12->setSizeIncrement(QSize(0, 28));
        horizontalLayout_9 = new QHBoxLayout(widget_12);
        horizontalLayout_9->setSpacing(10);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget_12);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(90, 28));
        label_8->setMaximumSize(QSize(16777215, 28));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_8);

        le_navurl = new QLineEdit(widget_12);
        le_navurl->setObjectName(QStringLiteral("le_navurl"));
        le_navurl->setMinimumSize(QSize(0, 28));
        le_navurl->setClearButtonEnabled(false);

        horizontalLayout_9->addWidget(le_navurl);


        verticalLayout_5->addWidget(widget_12);


        verticalLayout_4->addWidget(w_envpanel);

        previews = new QWidget(widget);
        previews->setObjectName(QStringLiteral("previews"));
        verticalLayout_6 = new QVBoxLayout(previews);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(previews);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_4);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(90, 28));
        label->setMaximumSize(QSize(16777215, 28));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        le_xmpphost = new QClearableEdit(widget_4);
        le_xmpphost->setObjectName(QStringLiteral("le_xmpphost"));
        le_xmpphost->setMinimumSize(QSize(0, 28));
        le_xmpphost->setReadOnly(true);
        le_xmpphost->setClearButtonEnabled(false);

        horizontalLayout_2->addWidget(le_xmpphost);


        verticalLayout_6->addWidget(widget_4);

        widget_5 = new QWidget(previews);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(90, 28));
        label_2->setMaximumSize(QSize(16777215, 28));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_2);

        le_xmppport = new QClearableEdit(widget_5);
        le_xmppport->setObjectName(QStringLiteral("le_xmppport"));
        le_xmppport->setMinimumSize(QSize(0, 28));
        le_xmppport->setReadOnly(true);

        horizontalLayout_3->addWidget(le_xmppport);


        verticalLayout_6->addWidget(widget_5);

        widget_6 = new QWidget(previews);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(90, 28));
        label_3->setMaximumSize(QSize(16777215, 28));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_3);

        le_domain = new QClearableEdit(widget_6);
        le_domain->setObjectName(QStringLiteral("le_domain"));
        le_domain->setMinimumSize(QSize(0, 28));
        le_domain->setReadOnly(true);

        horizontalLayout_4->addWidget(le_domain);


        verticalLayout_6->addWidget(widget_6);

        widget_7 = new QWidget(previews);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget_7);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(90, 28));
        label_4->setMaximumSize(QSize(16777215, 28));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_4);

        le_httphost = new QClearableEdit(widget_7);
        le_httphost->setObjectName(QStringLiteral("le_httphost"));
        le_httphost->setMinimumSize(QSize(0, 28));
        le_httphost->setReadOnly(true);

        horizontalLayout_5->addWidget(le_httphost);


        verticalLayout_6->addWidget(widget_7);

        widget_8 = new QWidget(previews);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        horizontalLayout_6 = new QHBoxLayout(widget_8);
        horizontalLayout_6->setSpacing(10);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget_8);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(90, 28));
        label_5->setMaximumSize(QSize(16777215, 28));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_5);

        le_filehost = new QClearableEdit(widget_8);
        le_filehost->setObjectName(QStringLiteral("le_filehost"));
        le_filehost->setMinimumSize(QSize(0, 28));
        le_filehost->setReadOnly(true);

        horizontalLayout_6->addWidget(le_filehost);


        verticalLayout_6->addWidget(widget_8);


        verticalLayout_4->addWidget(previews);


        verticalLayout_2->addWidget(widget);

        widget_3 = new QWidget(content);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 10, 20, 10);
        pbt_NavManager = new QPushButton(widget_3);
        pbt_NavManager->setObjectName(QStringLiteral("pbt_NavManager"));
        pbt_NavManager->setMinimumSize(QSize(70, 28));
        pbt_NavManager->setMaximumSize(QSize(16777215, 28));
        pbt_NavManager->setFlat(true);

        horizontalLayout->addWidget(pbt_NavManager);

        horizontalSpacer = new QSpacerItem(300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        reset = new QPushButton(widget_3);
        reset->setObjectName(QStringLiteral("reset"));
        reset->setMinimumSize(QSize(70, 28));
        reset->setFlat(true);

        horizontalLayout->addWidget(reset);

        preview = new QPushButton(widget_3);
        preview->setObjectName(QStringLiteral("preview"));
        preview->setMinimumSize(QSize(70, 28));
        preview->setMaximumSize(QSize(70, 28));
        preview->setCheckable(true);

        horizontalLayout->addWidget(preview);

        apply = new QPushButton(widget_3);
        apply->setObjectName(QStringLiteral("apply"));
        apply->setMinimumSize(QSize(70, 28));

        horizontalLayout->addWidget(apply);


        verticalLayout_2->addWidget(widget_3);


        verticalLayout->addWidget(content);


        retranslateUi(LoginParamSettingDialog);

        QMetaObject::connectSlotsByName(LoginParamSettingDialog);
    } // setupUi

    void retranslateUi(QWidget *LoginParamSettingDialog)
    {
        LoginParamSettingDialog->setWindowTitle(QApplication::translate("LoginParamSettingDialog", "LoginParamSettingDialog", 0));
        label_6->setText(QApplication::translate("LoginParamSettingDialog", "\345\274\200\345\220\257pb\345\215\217\350\256\256:", 0));
        cb_pbenable->setText(QString());
        label_7->setText(QApplication::translate("LoginParamSettingDialog", "\345\274\200\345\220\257beta\347\216\257\345\242\203:", 0));
        cb_betaenable->setText(QString());
        label_8->setText(QApplication::translate("LoginParamSettingDialog", "\345\257\274\350\210\252\345\234\260\345\235\200:", 0));
        le_navurl->setPlaceholderText(QApplication::translate("LoginParamSettingDialog", "\345\257\274\350\210\252\345\234\260\345\235\200", 0));
        label->setText(QApplication::translate("LoginParamSettingDialog", "XmppHost:", 0));
        le_xmpphost->setPlaceholderText(QApplication::translate("LoginParamSettingDialog", "\346\266\210\346\201\257\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", 0));
        label_2->setText(QApplication::translate("LoginParamSettingDialog", "XmppPort:", 0));
        le_xmppport->setPlaceholderText(QApplication::translate("LoginParamSettingDialog", "\346\266\210\346\201\257\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", 0));
        label_3->setText(QApplication::translate("LoginParamSettingDialog", "Domain:", 0));
        le_domain->setPlaceholderText(QApplication::translate("LoginParamSettingDialog", "\346\266\210\346\201\257\346\234\215\345\212\241\345\231\250\345\220\216\347\274\200", 0));
        label_4->setText(QApplication::translate("LoginParamSettingDialog", "API Host:", 0));
        le_httphost->setPlaceholderText(QApplication::translate("LoginParamSettingDialog", "http\346\216\245\345\217\243\345\234\260\345\235\200", 0));
        label_5->setText(QApplication::translate("LoginParamSettingDialog", "\346\226\207\344\273\266\346\234\215\345\212\241Host:", 0));
        le_filehost->setPlaceholderText(QApplication::translate("LoginParamSettingDialog", "\346\226\207\344\273\266\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", 0));
        pbt_NavManager->setText(QApplication::translate("LoginParamSettingDialog", "\345\257\274\350\210\252\347\256\241\347\220\206", 0));
        reset->setText(QApplication::translate("LoginParamSettingDialog", "\351\207\215\347\275\256", 0));
        preview->setText(QApplication::translate("LoginParamSettingDialog", "\351\242\204\350\247\210", 0));
        apply->setText(QApplication::translate("LoginParamSettingDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginParamSettingDialog: public Ui_LoginParamSettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPARAMSETTINGDIALOG_H

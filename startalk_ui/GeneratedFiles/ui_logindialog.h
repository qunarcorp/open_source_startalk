/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "LocalManDialog.h"
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout1;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout;
    QWidget *dialogbg1;
    QVBoxLayout *verticalLayout_9;
    TitlebarWidget *titlebarWidget;
    QWidget *enablePanel;
    QVBoxLayout *verticalLayout_6;
    QWidget *normalpanel;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_4;
    QPushButton *loginpic;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *cbxPresence;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_5;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_8;
    QWidget *usernamePanel;
    QLineEdit *username;
    QPushButton *select_account;
    QWidget *passwordPanel;
    QLineEdit *password;
    QPushButton *closeEye;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *remember;
    QCheckBox *autologin;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *submit;
    QSpacerItem *horizontalSpacer;
    QWidget *tippannel;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *otherlogin;
    QLabel *logininfo;
    QLabel *label_ver;
    QPushButton *pbtercode;
    QPushButton *loginsetting;

    void setupUi(LocalManDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(434, 332);
        verticalLayout_2 = new QVBoxLayout(LoginDialog);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(LoginDialog);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(shadowbg->sizePolicy().hasHeightForWidth());
        shadowbg->setSizePolicy(sizePolicy);
        verticalLayout1 = new QVBoxLayout(shadowbg);
        verticalLayout1->setSpacing(0);
        verticalLayout1->setContentsMargins(11, 11, 11, 11);
        verticalLayout1->setObjectName(QStringLiteral("verticalLayout1"));
        verticalLayout1->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        shadowinnerbg->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(shadowinnerbg);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        dialogbg1 = new QWidget(shadowinnerbg);
        dialogbg1->setObjectName(QStringLiteral("dialogbg1"));
        dialogbg1->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
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
"QLabel#errmsg{\n"
"	font: bold 14px;	\n"
"	color: rgb(255, 255, 255);	\n"
"}\n"
"QWidget#dialogbg1{   \n"
"	background-image: url(:/Images/bg.png);\n"
"}\n"
"QCheckBox{\n"
"	color:#666666;\n"
"	font: bold 14px;	\n"
"}\n"
"QPushButton#loginpic\n"
"{\n"
"	border:1px solid #FFFFFF;\n"
"	background:#AAffffff;\n"
"}\n"
"\n"
"\n"
"QPushButton#submit{\n"
"	color: #FFFFFF;\n"
"	background-color: #FFB03f;\n"
"	font: bold 18px;\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton#submit:hover{\n"
"	background-color: #FFBd5f;\n"
"}\n"
"\n"
"QPushButton#submit:pressed{\n"
"	background-color: #F99e1b;\n"
"}\n"
"QPushButton#submit:disabled{\n"
"	background-color: #9B9B9B;\n"
"}\n"
"QLabel#logininfo\n"
"{\n"
"	color:#666666;\n"
"}\n"
"\n"
"\n"
"QComboBox {\n"
"    border: 1px solid gray;\n"
""
                        "    border-radius: 3px;\n"
"    padding: 1px 18px 1px 3px;\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background: white;\n"
"}\n"
"\n"
"QComboBox:!editable, QComboBox::drop-down:editable {\n"
"     background: #AAFFFFFF;\n"
"}\n"
"\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"\n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QPushButton#otherlogin\n"
"{\n"
"	text-align:left;\n"
"	color:#666666;\n"
"	text-decoration: underline;\n"
"	border:none;\n"
"}\n"
"QPushButton#otherlogin:hover\n"
"{\n"
"	color:#1ba9ba;\n"
"}\n"
"QPushButton#loginsetting\n"
"{\n"
"	image:url(:/Images/Setting_Default.png);\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton#loginsetting:hover\n"
"{\n"
"	image:url(:/Images/Setting_Selected.png);\n"
"}\n"
""
                        "\n"
"QWidget#otherlogin,QWidget#logininfo\n"
"{\n"
"	font-size:12px;\n"
"}\n"
"\n"
"QPushButton#pbtercode\n"
"{\n"
"	image:url(:/Images/icon/ercode.png);\n"
"	border:none;\n"
"}\n"
"QPushButton#pbtercode:hover\n"
"{\n"
"	image:url(:/Images/icon/ercode_hover.png);\n"
"}\n"
"QLabel#label_ver\n"
"{\n"
"	border:none;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	font-size: 10px;\n"
"}"));
        verticalLayout_9 = new QVBoxLayout(dialogbg1);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        titlebarWidget = new TitlebarWidget(dialogbg1);
        titlebarWidget->setObjectName(QStringLiteral("titlebarWidget"));
        titlebarWidget->setMinimumSize(QSize(0, 27));
        titlebarWidget->setMaximumSize(QSize(16777215, 27));

        verticalLayout_9->addWidget(titlebarWidget);

        enablePanel = new QWidget(dialogbg1);
        enablePanel->setObjectName(QStringLiteral("enablePanel"));
        verticalLayout_6 = new QVBoxLayout(enablePanel);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        normalpanel = new QWidget(enablePanel);
        normalpanel->setObjectName(QStringLiteral("normalpanel"));
        normalpanel->setMinimumSize(QSize(382, 242));
        verticalLayout_3 = new QVBoxLayout(normalpanel);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 121, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        widget_2 = new QWidget(normalpanel);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 18, 0, 0);
        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMaximumSize(QSize(146, 16777215));
        verticalLayout_4 = new QVBoxLayout(widget_5);
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(50, 0, 0, 0);
        loginpic = new QPushButton(widget_5);
        loginpic->setObjectName(QStringLiteral("loginpic"));
        loginpic->setMinimumSize(QSize(96, 96));
        loginpic->setMaximumSize(QSize(96, 96));
        loginpic->setIconSize(QSize(96, 96));
        loginpic->setFlat(false);

        verticalLayout_4->addWidget(loginpic);

        widget = new QWidget(widget_5);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(96, 0));
        widget->setMaximumSize(QSize(96, 16777215));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        cbxPresence = new QComboBox(widget);
        cbxPresence->setObjectName(QStringLiteral("cbxPresence"));
        cbxPresence->setMinimumSize(QSize(0, 0));
        cbxPresence->setMaximumSize(QSize(0, 16777215));
        cbxPresence->setStyleSheet(QStringLiteral(""));

        horizontalLayout_5->addWidget(cbxPresence);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_4->addWidget(widget);


        horizontalLayout->addWidget(widget_5);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        verticalLayout_5 = new QVBoxLayout(widget_6);
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(20, 0, 20, 0);
        widget_3 = new QWidget(widget_6);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 96));
        widget_3->setMaximumSize(QSize(16777215, 96));
        verticalLayout_7 = new QVBoxLayout(widget_3);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_5 = new QSpacerItem(20, 59, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_5);

        widget_8 = new QWidget(widget_3);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        verticalLayout_8 = new QVBoxLayout(widget_8);
        verticalLayout_8->setSpacing(1);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        usernamePanel = new QWidget(widget_8);
        usernamePanel->setObjectName(QStringLiteral("usernamePanel"));
        usernamePanel->setMinimumSize(QSize(0, 28));
        username = new QLineEdit(usernamePanel);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(0, 0, 125, 28));
        username->setMinimumSize(QSize(0, 28));
        username->setCursorMoveStyle(Qt::LogicalMoveStyle);
        username->setClearButtonEnabled(false);
        select_account = new QPushButton(usernamePanel);
        select_account->setObjectName(QStringLiteral("select_account"));
        select_account->setGeometry(QRect(200, 0, 28, 24));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/icon/commen/select_downhover.png"), QSize(), QIcon::Normal, QIcon::Off);
        select_account->setIcon(icon);
        select_account->setCheckable(true);
        select_account->setFlat(true);

        verticalLayout_8->addWidget(usernamePanel);

        passwordPanel = new QWidget(widget_8);
        passwordPanel->setObjectName(QStringLiteral("passwordPanel"));
        passwordPanel->setMinimumSize(QSize(0, 28));
        password = new QLineEdit(passwordPanel);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(0, 0, 125, 28));
        password->setMinimumSize(QSize(0, 28));
        password->setEchoMode(QLineEdit::Password);
        password->setClearButtonEnabled(false);
        closeEye = new QPushButton(passwordPanel);
        closeEye->setObjectName(QStringLiteral("closeEye"));
        closeEye->setGeometry(QRect(199, 2, 28, 24));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/eye.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeEye->setIcon(icon1);
        closeEye->setCheckable(true);
        closeEye->setFlat(true);

        verticalLayout_8->addWidget(passwordPanel);


        verticalLayout_7->addWidget(widget_8);


        verticalLayout_5->addWidget(widget_3);

        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setMinimumSize(QSize(0, 20));
        horizontalLayout_2 = new QHBoxLayout(widget_7);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        remember = new QCheckBox(widget_7);
        remember->setObjectName(QStringLiteral("remember"));

        horizontalLayout_2->addWidget(remember);

        autologin = new QCheckBox(widget_7);
        autologin->setObjectName(QStringLiteral("autologin"));

        horizontalLayout_2->addWidget(autologin);


        verticalLayout_5->addWidget(widget_7);


        horizontalLayout->addWidget(widget_6);


        verticalLayout_3->addWidget(widget_2);

        widget_4 = new QWidget(normalpanel);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        submit = new QPushButton(widget_4);
        submit->setObjectName(QStringLiteral("submit"));
        submit->setMinimumSize(QSize(180, 35));
        submit->setMaximumSize(QSize(180, 35));
        submit->setFlat(true);

        horizontalLayout_3->addWidget(submit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_3->addWidget(widget_4);


        verticalLayout_6->addWidget(normalpanel);

        tippannel = new QWidget(enablePanel);
        tippannel->setObjectName(QStringLiteral("tippannel"));
        tippannel->setMaximumSize(QSize(16777215, 20));
        tippannel->setStyleSheet(QStringLiteral(""));
        horizontalLayout_4 = new QHBoxLayout(tippannel);
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(10, 0, 10, 0);
        otherlogin = new QPushButton(tippannel);
        otherlogin->setObjectName(QStringLiteral("otherlogin"));
        otherlogin->setMaximumSize(QSize(50, 70));

        horizontalLayout_4->addWidget(otherlogin);

        logininfo = new QLabel(tippannel);
        logininfo->setObjectName(QStringLiteral("logininfo"));
        logininfo->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_4->addWidget(logininfo);

        label_ver = new QLabel(tippannel);
        label_ver->setObjectName(QStringLiteral("label_ver"));
        label_ver->setMinimumSize(QSize(78, 0));
        label_ver->setMaximumSize(QSize(78, 16777215));
        label_ver->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_ver);

        pbtercode = new QPushButton(tippannel);
        pbtercode->setObjectName(QStringLiteral("pbtercode"));
        pbtercode->setMinimumSize(QSize(20, 20));
        pbtercode->setMaximumSize(QSize(20, 20));
        pbtercode->setFlat(true);

        horizontalLayout_4->addWidget(pbtercode);

        loginsetting = new QPushButton(tippannel);
        loginsetting->setObjectName(QStringLiteral("loginsetting"));
        loginsetting->setMinimumSize(QSize(16, 16));
        loginsetting->setMaximumSize(QSize(16, 16));
        loginsetting->setStyleSheet(QStringLiteral(""));
        loginsetting->setFlat(true);

        horizontalLayout_4->addWidget(loginsetting);


        verticalLayout_6->addWidget(tippannel);


        verticalLayout_9->addWidget(enablePanel);


        verticalLayout->addWidget(dialogbg1);


        verticalLayout1->addWidget(shadowinnerbg);


        verticalLayout_2->addWidget(shadowbg);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(LocalManDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "LoginDialog", 0));
        loginpic->setText(QString());
        username->setPlaceholderText(QApplication::translate("LoginDialog", "\350\264\246\345\217\267", 0));
        select_account->setText(QString());
        password->setPlaceholderText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201", 0));
        closeEye->setText(QString());
        remember->setText(QApplication::translate("LoginDialog", "CheckBox", 0));
        autologin->setText(QApplication::translate("LoginDialog", "CheckBox", 0));
        submit->setText(QApplication::translate("LoginDialog", "PushButton", 0));
        otherlogin->setText(QApplication::translate("LoginDialog", "web\347\231\273\345\275\225", 0));
        logininfo->setText(QString());
        label_ver->setText(QString());
        pbtercode->setText(QString());
        loginsetting->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H

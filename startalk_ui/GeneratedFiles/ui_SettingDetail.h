/********************************************************************************
** Form generated from reading UI file 'SettingDetail.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDETAIL_H
#define UI_SETTINGDETAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "LineEdit.h"
#include "Mycombobox.h"
#include "Myspinbox.h"
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SettingDetail
{
public:
    QHBoxLayout *horizontalLayout_8;
    QWidget *shadowbg;
    QHBoxLayout *horizontalLayout_7;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout;
    TitlebarWidget *titlebar;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QScrollArea *scrollArea;
    QWidget *btnpanel;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_account;
    QPushButton *btn_msgnotice;
    QPushButton *btn_hotkey;
    QPushButton *btn_conversation;
    QPushButton *btn_autoreplay;
    QPushButton *btn_path;
    QPushButton *btn_welcome;
    QPushButton *btn_friends;
    QPushButton *btn_fontsize;
    QPushButton *btn_other;
    QPushButton *btn_version;
    QSpacerItem *verticalSpacer_11;
    QLabel *scrolltip_up;
    QLabel *scrolltip_down;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_6;
    QStackedWidget *stackedWidget;
    QWidget *page_account;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *header;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *name;
    QWidget *funspanel;
    QScrollArea *scrollArea_workstatus;
    QWidget *scrollWorkstatus;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *accountExit;
    QSpacerItem *verticalSpacer;
    QWidget *page_msgnotice;
    QVBoxLayout *verticalLayout_14;
    QWidget *widget_17;
    QCheckBox *messagesound;
    QPushButton *pbVoiceSetting;
    QCheckBox *messagepopup;
    QCheckBox *messagenotice;
    QGroupBox *groupBox;
    QRadioButton *radioButton_anytime;
    QLabel *label_8;
    QRadioButton *radioButton_awaypc;
    MySpinBox *ar_timer_1;
    QPushButton *savepush;
    QLabel *label_9;
    QRadioButton *radioButton_defaultvoice;
    QRadioButton *radioButton_newsetvoice;
    QCheckBox *push_set;
    QCheckBox *QuickReplay;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_hotkey;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_8;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    LineEdit *lineEdit_message;
    LineEdit *lineEdit_screen;
    LineEdit *lineEdit_search;
    QLabel *label_7;
    LineEdit *lineEdit_mbord;
    QRadioButton *radioEnableButton;
    QRadioButton *radioUnEnableButton;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_chat;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_9;
    MyComboBox *SendMessagecombox;
    QLabel *label_18;
    QLabel *label_19;
    MyComboBox *max_session;
    QCheckBox *cbEnableChatLru;
    QLabel *label_20;
    MyComboBox *cbChatLruLimit;
    QLabel *label_6;
    MyComboBox *cbChatHistoryMsgLimit;
    QCheckBox *cbEnableChatHistoryMsg;
    QRadioButton *radioButton_unRead;
    QRadioButton *radioButton_loadAll;
    QSpacerItem *verticalSpacer_4;
    QWidget *page_replay;
    QVBoxLayout *verticalLayout_7;
    QWidget *autoreply;
    QCheckBox *checkBox_busy;
    QCheckBox *checkBox_away;
    QTextEdit *lineEdit_busy;
    QTextEdit *lineEdit_away;
    QSpacerItem *verticalSpacer_5;
    QWidget *page_path;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_10;
    QLabel *label_16;
    QLineEdit *userpath;
    QPushButton *openuserpath;
    QPushButton *changeuserpath;
    QPushButton *defaultpath;
    QWidget *widget_11;
    QLabel *label_17;
    QPushButton *defaultSavepath;
    QPushButton *openuserSavepath;
    QLineEdit *userSaveAspath;
    QPushButton *changeuserSavepath;
    QSpacerItem *verticalSpacer_6;
    QWidget *page_welcome;
    QVBoxLayout *verticalLayout_15;
    QWidget *widget_12;
    QCheckBox *ReplyWelcome_enabled;
    QLineEdit *lineEdit_Rewelcome;
    QRadioButton *ResetRadio;
    QRadioButton *selfsetRadio;
    QTextEdit *selfsetWelcomeEdit;
    QSpacerItem *verticalSpacer_7;
    QWidget *page_friends;
    QVBoxLayout *verticalLayout_10;
    QWidget *widget_13;
    MyComboBox *friendsMode;
    QLabel *friendquest_label;
    QLineEdit *lineEdit_quest;
    QLabel *friendanswer_label;
    QLineEdit *lineEdit_answer;
    QPushButton *pb_friendset;
    QLabel *friendquest_label_2;
    QSpacerItem *verticalSpacer_8;
    QWidget *page_font;
    QVBoxLayout *verticalLayout_11;
    QWidget *widget_14;
    QLabel *label_23;
    QCheckBox *checkBox_fontSize;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pbt_darkclr;
    QLabel *label_13;
    QPushButton *pbt_lightclr;
    QSpacerItem *verticalSpacer_9;
    QWidget *page_version;
    QVBoxLayout *verticalLayout_12;
    QWidget *widget_15;
    QLabel *label_10;
    QLabel *version;
    QPushButton *gengxin;
    QPushButton *collectInfo;
    QPushButton *clearCache;
    QLabel *label_25;
    QLabel *newversion;
    QLabel *version_3;
    QLabel *logcoll_label;
    QSpacerItem *verticalSpacer_10;
    QWidget *page_other;
    QVBoxLayout *verticalLayout_13;
    QWidget *widget_2;
    QCheckBox *cbAutoStartup;
    QCheckBox *cbQuitOnClose;
    QLabel *label;
    QCheckBox *cbNoticeGroupDestroy;
    QWidget *widget_16;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *tbMailSplitDefault;
    QRadioButton *tbMailSplitComma;
    QLabel *label_2;
    MySpinBox *requesttm;
    QCheckBox *cbAutoShake;
    QCheckBox *cbHttpLog;
    QCheckBox *cbEsc_hideChat;
    QCheckBox *cbGroupChatMember_ShowOrHide;
    QCheckBox *cbScrollbarOnblew;
    QWidget *tasktextcolor;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_text;
    QPushButton *pbt_tasktextclr;
    QSpacerItem *verticalSpacer_12;
    QWidget *page_qtalkReplay;
    QWidget *autoreply_qtalk;
    QCheckBox *ar_enabled;
    MySpinBox *ar_timer;
    QLabel *label_15;
    MyComboBox *ar_message;
    QRadioButton *ar_systemmsg;
    QRadioButton *ar_usermsg;
    QTextEdit *ar_usermsgcontent;

    void setupUi(QWidget *SettingDetail)
    {
        if (SettingDetail->objectName().isEmpty())
            SettingDetail->setObjectName(QStringLiteral("SettingDetail"));
        SettingDetail->resize(560, 440);
        SettingDetail->setMinimumSize(QSize(560, 440));
        SettingDetail->setStyleSheet(QString::fromUtf8("QWidget#btnpanel\n"
"{\n"
" 	border-right-width: 1px;\n"
"    border-right-color: darkgray;\n"
"    border-right-style: solid; /* just a single line */\n"
"	background:#00000000;\n"
"}\n"
"\n"
"QScrollArea\n"
"{\n"
"	border:none;\n"
"}\n"
"\n"
"QLabel#scrolltip_up,#scrolltip_down\n"
"{\n"
"	border:none;\n"
"	background:#A01ba9ba;\n"
"	color:#EFEFEf;\n"
"}\n"
"\n"
"\n"
"QWidget#background{\n"
"    background-color:#FFFFFF;\n"
"    border-radius: 4px;\n"
"	    font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"	border:1px solid #DADADA80\n"
"}\n"
"\n"
"QLabel{\n"
"    font-size:12px;\n"
"\n"
"    color:#000000;\n"
"}\n"
"\n"
"\n"
"QLabel#title{\n"
"    font: bold 14px;\n"
"}\n"
"\n"
"\n"
"QLabel#header{\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QLabel#sp_0,#sp_5{\n"
"    border:1px solid #D6D6D6;\n"
"}\n"
"QLabel#sp_1{\n"
"    border:1px solid #D6D6D6;\n"
"}\n"
"QLabel#sp_2{\n"
"    border:1px solid #D6D6D6;\n"
"}\n"
"QLabel#sp_3,#sp_autoreply{\n"
"    border:1px solid #D6D6D6;\n"
"}\n"
"QLabel#s"
                        "p_6,#sp_7,#sp_8,#sp_9,#sp_10,#sp_11{\n"
"    border:1px solid #D6D6D6;\n"
"}\n"
"QPushButton#accountExit{\n"
"    border:1px solid #EBEBEB;\n"
"    background-color:#FFFFFF;\n"
"}\n"
"\n"
"QPushButton#accountExit:hover{\n"
"    border:1px solid #EBEBEB;\n"
"    background-color:#EBEBEB;\n"
"}\n"
"\n"
"\n"
"QPushButton#accountExit:pressed{\n"
"    border:1px solid #D6D6D6;\n"
"    background-color:#D6D6D6;\n"
"}\n"
"\n"
"QPushButton#clearCache,#collectInfo,#yijian,#openuserpath,#changeuserpath,#defaultpath,#openuserSavepath,#changeuserSavepath,#defaultSavepath,#pb_friendset\n"
"{\n"
"    border:1px solid #EBEBEB;\n"
"    background-color:#FFFFFF;\n"
"}\n"
"\n"
"QPushButton#clearCache:hover,#collectInfo:hover,#yijian:hover,#openuserpath:hover,#changeuserpath:hover,#defaultpath:hover,#openuserSavepath:hover,#changeuserSavepath:hover,#defaultSavepath:hover,#pb_friendset:hover{\n"
"    border:1px solid #EBEBEB;\n"
"    background-color:#EBEBEB;\n"
"}\n"
"\n"
"\n"
"QPushButton#clearCache:pressed,#collectInfo:pressed"
                        ",#yijian:pressed,#openuserpath:pressed,#changeuserpath:pressed,#defaultpath:pressed,#openuserSavepath:pressed,#changeuserSavepath:pressed,#defaultSavepath:pressed,#pb_friendset:pressed{\n"
"    border:1px solid #D6D6D6;\n"
"    background-color:#D6D6D6;\n"
"}\n"
"\n"
"QPushButton#close{\n"
"	height:27px;\n"
"	width:30px;\n"
"	background:#00000000;\n"
"	border-image: url(:/Images/close_normal.png); \n"
"}\n"
"QPushButton#close:hover{\n"
"	background:#F25561;\n"
"	border-image: url(:/Images/close_hover.png);  \n"
"}\n"
"QPushButton#close:pressed{\n"
"	background:#E74450;\n"
"	border-image: url(:/Images/close_hover.png);  \n"
"}\n"
"\n"
"QLabel#sp_3{\n"
"    border:1px solid #D6D6D6;\n"
"}\n"
"QLineEdit\n"
"{\n"
"	border:1px solid #D6D6D6;\n"
"    background-color:#FFFFFF;\n"
"}\n"
"QLineEdit:hover{\n"
"    border-radius: 2px;\n"
"    border:1px solid #EBEBEB;\n"
"    background-color:#EBEBEB;\n"
"}\n"
"\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"    border:1px solid #4F9AD4;\n"
"    background-color:#FFFFFF;\n"
"}\n"
"\n"
""
                        "QComboBox{\n"
"    border:1px solid #D6D6D6;\n"
"    background-color:#FFFFFF;\n"
"}\n"
"\n"
"QComboBox:disabled{\n"
"    border:1px solid #DEDEDE;\n"
"    background-color:#DEDEDE;\n"
"}\n"
"QLabel#sp_4{\n"
"    border:1px solid #D6D6D6;\n"
"}\n"
"\n"
"QScrollArea#scrollArea{\n"
"	border:none;\n"
"}\n"
"\n"
"QWidget#scrollAreaWidgetContents{\n"
"	background-color:#FFFFFFFF;\n"
"}\n"
"\n"
"QWidget#vline{\n"
"	background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0,  \n"
"                                 stop: 0 #00000000, stop: 0.1 #A3A6A9,  \n"
"                                 stop: 0.9 #A3A6A9, stop: 1.0 #00000000); \n"
"}\n"
"\n"
"\n"
"QTextEdit#ar_usermsgcontent,#selfsetWelcomeEdit\n"
"{\n"
"    border-radius: 2px;\n"
"	border:1px solid #D6D6D6;\n"
"    background-color:#FFFFFF;\n"
"}\n"
"QTextEdit#ar_usermsgcontent:hover,#selfsetWelcomeEdit:hover\n"
"{\n"
"    border:1px solid #EBEBEB;\n"
"    background-color:#EBEBEB;\n"
"}\n"
"\n"
"QTextEdit#ar_usermsgcontent:disabled,#selfsetWelcomeEdit:disabled\n"
"{\n"
""
                        "    border:1px solid #DEDEDE;\n"
"    background-color:#DEDEDE;\n"
"}\n"
"QTextEdit#ar_usermsgcontent:focus,#selfsetWelcomeEdit:focus\n"
"{\n"
"    border:1px solid #4F9AD4;\n"
"    background-color:#FFFFFF;\n"
"}\n"
"\n"
"\n"
"QPushButton#gengxin{\n"
"border-radius: 2px;\n"
"    border:1px solid #EBEBEB;\n"
"    background-color:#FFFFFF;\n"
"	color:#0000FF;\n"
"	text-decoration:underline;\n"
"}\n"
"\n"
"QPushButton#gengxin:hover{\n"
"    background-color:#EBEBEB;\n"
"}\n"
"\n"
"\n"
"QPushButton#gengxin:pressed{\n"
"    border:1px solid #D6D6D6;\n"
"    background-color:#D6D6D6;\n"
"}\n"
"\n"
"QComboBox {\n"
"    border: 1px solid #EBEBEB;\n"
"    border-radius: 0px;\n"
"    padding: 1px 18px 1px 3px;\n"
"}\n"
"\n"
"QComboBox:!editable, QComboBox::drop-down:editable {\n"
"     background: #AAFFFFFF;\n"
"}\n"
"\n"
"QComboBox:on { /* shift the text when the popup opens */\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcont"
                        "rol-position: top right;\n"
"    width: 15px;\n"
"	border-left-width: 1px;\n"
"    border-left-color: #EBEBEB;\n"
"    border-left-style: solid; /* just a single line */\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/Images/jietu_normal.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}\n"
"\n"
"QLabel#newversion{\n"
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
"QPushButton#savepush{\n"
"    border:1px solid #EBEBEB;\n"
"    background-color:#FFFFFF;\n"
"}\n"
"\n"
"QPushButton#savepush:hover{\n"
"    border:1px solid #EBEBEB;\n"
"    background-color:#EBEBEB;\n"
"}\n"
"\n"
"\n"
"QPushButton#savepush:pressed{\n"
"    border:1px solid #D6D6D6;\n"
"    background-color:#D6D6D6;\n"
"}\n"
"\n"
"QPushButton#pbVoiceSetting{\n"
"    bor"
                        "der:1px solid #EBEBEB;\n"
"    background-color:#FFFFFF;\n"
"}\n"
"\n"
"QPushButton#pbVoiceSetting:hover{\n"
"    border:1px solid #EBEBEB;\n"
"    background-color:#EBEBEB;\n"
"}\n"
"\n"
"\n"
"QPushButton#pbVoiceSetting:pressed{\n"
"    border:1px solid #D6D6D6;\n"
"    background-color:#D6D6D6;\n"
"}\n"
"\n"
"QPushButton#pbt_tasktextclr\n"
"{\n"
"	border:none;\n"
"}\n"
"QPushButton#pbt_tasktextclr:disabled\n"
"{\n"
"	background-color:#666666;\n"
"}"));
        horizontalLayout_8 = new QHBoxLayout(SettingDetail);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(SettingDetail);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        horizontalLayout_7 = new QHBoxLayout(shadowbg);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        shadowinnerbg->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(shadowinnerbg);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        titlebar = new TitlebarWidget(shadowinnerbg);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 28));
        titlebar->setMaximumSize(QSize(16777215, 28));

        verticalLayout->addWidget(titlebar);

        widget = new QWidget(shadowinnerbg);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(100, 0));
        widget_3->setMaximumSize(QSize(100, 16777215));
        scrollArea = new QScrollArea(widget_3);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 100, 341));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(100, 0));
        scrollArea->setMaximumSize(QSize(100, 16777215));
        scrollArea->setStyleSheet(QStringLiteral("background:#00000000;"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        btnpanel = new QWidget();
        btnpanel->setObjectName(QStringLiteral("btnpanel"));
        btnpanel->setGeometry(QRect(0, 0, 100, 341));
        btnpanel->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"	border:none;\n"
"	border-right-width: 2px;\n"
"    border-right-color: #00000000;\n"
"    border-right-style: solid; /* just a single line */\n"
"	color:#333333;\n"
"	font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"	color:#1ba9ba;\n"
"	border-right-width: 2px;\n"
"    border-right-color: #1ba9ba;\n"
"    border-right-style: solid; /* just a single line */\n"
"	\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(btnpanel);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 10, 0, 0);
        btn_account = new QPushButton(btnpanel);
        btn_account->setObjectName(QStringLiteral("btn_account"));
        btn_account->setCursor(QCursor(Qt::PointingHandCursor));
        btn_account->setCheckable(true);
        btn_account->setAutoExclusive(true);
        btn_account->setFlat(true);

        verticalLayout_2->addWidget(btn_account);

        btn_msgnotice = new QPushButton(btnpanel);
        btn_msgnotice->setObjectName(QStringLiteral("btn_msgnotice"));
        btn_msgnotice->setCursor(QCursor(Qt::PointingHandCursor));
        btn_msgnotice->setCheckable(true);
        btn_msgnotice->setAutoExclusive(true);
        btn_msgnotice->setFlat(true);

        verticalLayout_2->addWidget(btn_msgnotice);

        btn_hotkey = new QPushButton(btnpanel);
        btn_hotkey->setObjectName(QStringLiteral("btn_hotkey"));
        btn_hotkey->setCursor(QCursor(Qt::PointingHandCursor));
        btn_hotkey->setCheckable(true);
        btn_hotkey->setAutoExclusive(true);
        btn_hotkey->setFlat(true);

        verticalLayout_2->addWidget(btn_hotkey);

        btn_conversation = new QPushButton(btnpanel);
        btn_conversation->setObjectName(QStringLiteral("btn_conversation"));
        btn_conversation->setCursor(QCursor(Qt::PointingHandCursor));
        btn_conversation->setCheckable(true);
        btn_conversation->setAutoExclusive(true);
        btn_conversation->setFlat(true);

        verticalLayout_2->addWidget(btn_conversation);

        btn_autoreplay = new QPushButton(btnpanel);
        btn_autoreplay->setObjectName(QStringLiteral("btn_autoreplay"));
        btn_autoreplay->setCursor(QCursor(Qt::PointingHandCursor));
        btn_autoreplay->setCheckable(true);
        btn_autoreplay->setAutoExclusive(true);
        btn_autoreplay->setFlat(true);

        verticalLayout_2->addWidget(btn_autoreplay);

        btn_path = new QPushButton(btnpanel);
        btn_path->setObjectName(QStringLiteral("btn_path"));
        btn_path->setCursor(QCursor(Qt::PointingHandCursor));
        btn_path->setCheckable(true);
        btn_path->setAutoExclusive(true);
        btn_path->setFlat(true);

        verticalLayout_2->addWidget(btn_path);

        btn_welcome = new QPushButton(btnpanel);
        btn_welcome->setObjectName(QStringLiteral("btn_welcome"));
        btn_welcome->setCursor(QCursor(Qt::PointingHandCursor));
        btn_welcome->setCheckable(true);
        btn_welcome->setAutoExclusive(true);
        btn_welcome->setFlat(true);

        verticalLayout_2->addWidget(btn_welcome);

        btn_friends = new QPushButton(btnpanel);
        btn_friends->setObjectName(QStringLiteral("btn_friends"));
        btn_friends->setCursor(QCursor(Qt::PointingHandCursor));
        btn_friends->setCheckable(true);
        btn_friends->setAutoExclusive(true);
        btn_friends->setFlat(true);

        verticalLayout_2->addWidget(btn_friends);

        btn_fontsize = new QPushButton(btnpanel);
        btn_fontsize->setObjectName(QStringLiteral("btn_fontsize"));
        btn_fontsize->setCursor(QCursor(Qt::PointingHandCursor));
        btn_fontsize->setCheckable(true);
        btn_fontsize->setAutoExclusive(true);
        btn_fontsize->setFlat(true);

        verticalLayout_2->addWidget(btn_fontsize);

        btn_other = new QPushButton(btnpanel);
        btn_other->setObjectName(QStringLiteral("btn_other"));
        btn_other->setCheckable(true);
        btn_other->setAutoExclusive(true);
        btn_other->setFlat(true);

        verticalLayout_2->addWidget(btn_other);

        btn_version = new QPushButton(btnpanel);
        btn_version->setObjectName(QStringLiteral("btn_version"));
        btn_version->setCursor(QCursor(Qt::PointingHandCursor));
        btn_version->setCheckable(true);
        btn_version->setAutoExclusive(true);
        btn_version->setFlat(true);

        verticalLayout_2->addWidget(btn_version);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_11);

        scrollArea->setWidget(btnpanel);
        scrolltip_up = new QLabel(widget_3);
        scrolltip_up->setObjectName(QStringLiteral("scrolltip_up"));
        scrolltip_up->setGeometry(QRect(9, 341, 82, 16));
        scrolltip_up->setAlignment(Qt::AlignCenter);
        scrolltip_down = new QLabel(widget_3);
        scrolltip_down->setObjectName(QStringLiteral("scrolltip_down"));
        scrolltip_down->setGeometry(QRect(9, 323, 82, 16));
        scrolltip_down->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_6 = new QHBoxLayout(widget_4);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(widget_4);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral("subcontrol-position: center;"));
        page_account = new QWidget();
        page_account->setObjectName(QStringLiteral("page_account"));
        page_account->setStyleSheet(QStringLiteral("aline:center;"));
        verticalLayout_4 = new QVBoxLayout(page_account);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(20, 50, 0, 0);
        widget_5 = new QWidget(page_account);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        header = new QLabel(widget_5);
        header->setObjectName(QStringLiteral("header"));
        header->setMinimumSize(QSize(90, 90));
        header->setMaximumSize(QSize(90, 90));

        horizontalLayout_2->addWidget(header);


        verticalLayout_4->addWidget(widget_5);

        widget_6 = new QWidget(page_account);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_3 = new QHBoxLayout(widget_6);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        name = new QLabel(widget_6);
        name->setObjectName(QStringLiteral("name"));
        name->setMinimumSize(QSize(0, 22));
        name->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(name);


        verticalLayout_4->addWidget(widget_6);

        funspanel = new QWidget(page_account);
        funspanel->setObjectName(QStringLiteral("funspanel"));
        funspanel->setMinimumSize(QSize(0, 120));
        funspanel->setStyleSheet(QStringLiteral(""));
        scrollArea_workstatus = new QScrollArea(funspanel);
        scrollArea_workstatus->setObjectName(QStringLiteral("scrollArea_workstatus"));
        scrollArea_workstatus->setGeometry(QRect(0, 0, 422, 120));
        scrollArea_workstatus->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea_workstatus->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_workstatus->setWidgetResizable(false);
        scrollWorkstatus = new QWidget();
        scrollWorkstatus->setObjectName(QStringLiteral("scrollWorkstatus"));
        scrollWorkstatus->setGeometry(QRect(0, 0, 400, 250));
        scrollWorkstatus->setMinimumSize(QSize(0, 250));
        scrollWorkstatus->setMaximumSize(QSize(400, 16777215));
        scrollArea_workstatus->setWidget(scrollWorkstatus);

        verticalLayout_4->addWidget(funspanel);

        widget_7 = new QWidget(page_account);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        horizontalLayout_4 = new QHBoxLayout(widget_7);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        accountExit = new QPushButton(widget_7);
        accountExit->setObjectName(QStringLiteral("accountExit"));
        accountExit->setMinimumSize(QSize(120, 28));
        accountExit->setMaximumSize(QSize(120, 28));
        accountExit->setStyleSheet(QStringLiteral(""));
        accountExit->setFlat(true);

        horizontalLayout_4->addWidget(accountExit);


        verticalLayout_4->addWidget(widget_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        stackedWidget->addWidget(page_account);
        page_msgnotice = new QWidget();
        page_msgnotice->setObjectName(QStringLiteral("page_msgnotice"));
        verticalLayout_14 = new QVBoxLayout(page_msgnotice);
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(50, 50, 10, 0);
        widget_17 = new QWidget(page_msgnotice);
        widget_17->setObjectName(QStringLiteral("widget_17"));
        widget_17->setMinimumSize(QSize(0, 310));
        messagesound = new QCheckBox(widget_17);
        messagesound->setObjectName(QStringLiteral("messagesound"));
        messagesound->setGeometry(QRect(0, 16, 141, 16));
        messagesound->setChecked(true);
        pbVoiceSetting = new QPushButton(widget_17);
        pbVoiceSetting->setObjectName(QStringLiteral("pbVoiceSetting"));
        pbVoiceSetting->setGeometry(QRect(0, 48, 70, 22));
        pbVoiceSetting->setMinimumSize(QSize(70, 22));
        pbVoiceSetting->setMaximumSize(QSize(70, 22));
        pbVoiceSetting->setFlat(true);
        messagepopup = new QCheckBox(widget_17);
        messagepopup->setObjectName(QStringLiteral("messagepopup"));
        messagepopup->setGeometry(QRect(0, 86, 361, 16));
        messagepopup->setChecked(true);
        messagenotice = new QCheckBox(widget_17);
        messagenotice->setObjectName(QStringLiteral("messagenotice"));
        messagenotice->setGeometry(QRect(0, 118, 361, 16));
        messagenotice->setChecked(true);
        groupBox = new QGroupBox(widget_17);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 170, 371, 111));
        radioButton_anytime = new QRadioButton(groupBox);
        radioButton_anytime->setObjectName(QStringLiteral("radioButton_anytime"));
        radioButton_anytime->setGeometry(QRect(30, 40, 311, 16));
        radioButton_anytime->setChecked(true);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(160, 70, 31, 16));
        radioButton_awaypc = new QRadioButton(groupBox);
        radioButton_awaypc->setObjectName(QStringLiteral("radioButton_awaypc"));
        radioButton_awaypc->setGeometry(QRect(30, 70, 171, 16));
        ar_timer_1 = new MySpinBox(groupBox);
        ar_timer_1->setObjectName(QStringLiteral("ar_timer_1"));
        ar_timer_1->setGeometry(QRect(110, 70, 41, 16));
        ar_timer_1->setFocusPolicy(Qt::ClickFocus);
        ar_timer_1->setMinimum(1);
        ar_timer_1->setMaximum(20);
        ar_timer_1->setValue(5);
        savepush = new QPushButton(groupBox);
        savepush->setObjectName(QStringLiteral("savepush"));
        savepush->setGeometry(QRect(254, 80, 81, 23));
        savepush->setFlat(true);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 10, 231, 20));
        radioButton_defaultvoice = new QRadioButton(widget_17);
        radioButton_defaultvoice->setObjectName(QStringLiteral("radioButton_defaultvoice"));
        radioButton_defaultvoice->setGeometry(QRect(110, 50, 121, 16));
        radioButton_defaultvoice->setChecked(false);
        radioButton_newsetvoice = new QRadioButton(widget_17);
        radioButton_newsetvoice->setObjectName(QStringLiteral("radioButton_newsetvoice"));
        radioButton_newsetvoice->setGeometry(QRect(250, 50, 121, 16));
        push_set = new QCheckBox(widget_17);
        push_set->setObjectName(QStringLiteral("push_set"));
        push_set->setEnabled(true);
        push_set->setGeometry(QRect(0, 144, 361, 16));
        push_set->setChecked(false);
        QuickReplay = new QCheckBox(widget_17);
        QuickReplay->setObjectName(QStringLiteral("QuickReplay"));
        QuickReplay->setEnabled(true);
        QuickReplay->setGeometry(QRect(0, 290, 361, 16));
        QuickReplay->setCheckable(true);
        QuickReplay->setChecked(true);

        verticalLayout_14->addWidget(widget_17);

        verticalSpacer_2 = new QSpacerItem(20, 231, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_14->addItem(verticalSpacer_2);

        stackedWidget->addWidget(page_msgnotice);
        page_hotkey = new QWidget();
        page_hotkey->setObjectName(QStringLiteral("page_hotkey"));
        verticalLayout_3 = new QVBoxLayout(page_hotkey);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(70, 50, 0, 0);
        widget_8 = new QWidget(page_hotkey);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setEnabled(true);
        widget_8->setMinimumSize(QSize(0, 160));
        widget_8->setMaximumSize(QSize(500, 180));
        label_3 = new QLabel(widget_8);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 2, 54, 16));
        label_4 = new QLabel(widget_8);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 35, 54, 12));
        label_5 = new QLabel(widget_8);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 65, 54, 12));
        lineEdit_message = new LineEdit(widget_8);
        lineEdit_message->setObjectName(QStringLiteral("lineEdit_message"));
        lineEdit_message->setEnabled(true);
        lineEdit_message->setGeometry(QRect(100, 0, 181, 20));
        lineEdit_message->setReadOnly(true);
        lineEdit_screen = new LineEdit(widget_8);
        lineEdit_screen->setObjectName(QStringLiteral("lineEdit_screen"));
        lineEdit_screen->setEnabled(true);
        lineEdit_screen->setGeometry(QRect(100, 30, 181, 20));
        lineEdit_screen->setReadOnly(true);
        lineEdit_search = new LineEdit(widget_8);
        lineEdit_search->setObjectName(QStringLiteral("lineEdit_search"));
        lineEdit_search->setEnabled(true);
        lineEdit_search->setGeometry(QRect(100, 60, 181, 20));
        lineEdit_search->setReadOnly(true);
        label_7 = new QLabel(widget_8);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 94, 71, 12));
        lineEdit_mbord = new LineEdit(widget_8);
        lineEdit_mbord->setObjectName(QStringLiteral("lineEdit_mbord"));
        lineEdit_mbord->setEnabled(true);
        lineEdit_mbord->setGeometry(QRect(100, 90, 181, 20));
        lineEdit_mbord->setReadOnly(true);
        radioEnableButton = new QRadioButton(widget_8);
        radioEnableButton->setObjectName(QStringLiteral("radioEnableButton"));
        radioEnableButton->setGeometry(QRect(100, 130, 89, 16));
        radioUnEnableButton = new QRadioButton(widget_8);
        radioUnEnableButton->setObjectName(QStringLiteral("radioUnEnableButton"));
        radioUnEnableButton->setGeometry(QRect(210, 130, 89, 16));

        verticalLayout_3->addWidget(widget_8);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        stackedWidget->addWidget(page_hotkey);
        page_chat = new QWidget();
        page_chat->setObjectName(QStringLiteral("page_chat"));
        verticalLayout_6 = new QVBoxLayout(page_chat);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(70, 50, 0, 0);
        widget_9 = new QWidget(page_chat);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setMinimumSize(QSize(0, 250));
        widget_9->setMaximumSize(QSize(16777215, 250));
        SendMessagecombox = new MyComboBox(widget_9);
        SendMessagecombox->setObjectName(QStringLiteral("SendMessagecombox"));
        SendMessagecombox->setGeometry(QRect(100, 0, 181, 22));
        SendMessagecombox->setFocusPolicy(Qt::WheelFocus);
        SendMessagecombox->setEditable(false);
        SendMessagecombox->setFrame(true);
        label_18 = new QLabel(widget_9);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(0, 0, 71, 22));
        label_19 = new QLabel(widget_9);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(0, 34, 71, 22));
        label_19->setMaximumSize(QSize(16777215, 16777215));
        max_session = new MyComboBox(widget_9);
        max_session->setObjectName(QStringLiteral("max_session"));
        max_session->setEnabled(true);
        max_session->setGeometry(QRect(100, 34, 181, 22));
        max_session->setMaximumSize(QSize(16777215, 16777215));
        max_session->setFocusPolicy(Qt::WheelFocus);
        max_session->setMaxVisibleItems(10);
        cbEnableChatLru = new QCheckBox(widget_9);
        cbEnableChatLru->setObjectName(QStringLiteral("cbEnableChatLru"));
        cbEnableChatLru->setGeometry(QRect(100, 150, 191, 22));
        label_20 = new QLabel(widget_9);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(0, 122, 91, 22));
        label_20->setMaximumSize(QSize(16777215, 16777215));
        cbChatLruLimit = new MyComboBox(widget_9);
        cbChatLruLimit->setObjectName(QStringLiteral("cbChatLruLimit"));
        cbChatLruLimit->setEnabled(true);
        cbChatLruLimit->setGeometry(QRect(100, 120, 181, 22));
        cbChatLruLimit->setMaximumSize(QSize(16777215, 16777215));
        cbChatLruLimit->setFocusPolicy(Qt::WheelFocus);
        label_6 = new QLabel(widget_9);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 180, 141, 22));
        cbChatHistoryMsgLimit = new MyComboBox(widget_9);
        cbChatHistoryMsgLimit->setObjectName(QStringLiteral("cbChatHistoryMsgLimit"));
        cbChatHistoryMsgLimit->setEnabled(true);
        cbChatHistoryMsgLimit->setGeometry(QRect(140, 180, 141, 22));
        cbChatHistoryMsgLimit->setMaximumSize(QSize(16777215, 16777215));
        cbChatHistoryMsgLimit->setFocusPolicy(Qt::WheelFocus);
        cbEnableChatHistoryMsg = new QCheckBox(widget_9);
        cbEnableChatHistoryMsg->setObjectName(QStringLiteral("cbEnableChatHistoryMsg"));
        cbEnableChatHistoryMsg->setGeometry(QRect(100, 215, 161, 22));
        radioButton_unRead = new QRadioButton(widget_9);
        radioButton_unRead->setObjectName(QStringLiteral("radioButton_unRead"));
        radioButton_unRead->setGeometry(QRect(0, 65, 271, 16));
        radioButton_loadAll = new QRadioButton(widget_9);
        radioButton_loadAll->setObjectName(QStringLiteral("radioButton_loadAll"));
        radioButton_loadAll->setGeometry(QRect(0, 90, 201, 16));
        radioButton_loadAll->setChecked(true);

        verticalLayout_6->addWidget(widget_9);

        verticalSpacer_4 = new QSpacerItem(20, 209, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);

        stackedWidget->addWidget(page_chat);
        page_replay = new QWidget();
        page_replay->setObjectName(QStringLiteral("page_replay"));
        verticalLayout_7 = new QVBoxLayout(page_replay);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(30, 20, 0, 0);
        autoreply = new QWidget(page_replay);
        autoreply->setObjectName(QStringLiteral("autoreply"));
        autoreply->setMinimumSize(QSize(0, 220));
        autoreply->setMaximumSize(QSize(16777215, 220));
        checkBox_busy = new QCheckBox(autoreply);
        checkBox_busy->setObjectName(QStringLiteral("checkBox_busy"));
        checkBox_busy->setGeometry(QRect(30, 20, 321, 16));
        checkBox_busy->setChecked(false);
        checkBox_away = new QCheckBox(autoreply);
        checkBox_away->setObjectName(QStringLiteral("checkBox_away"));
        checkBox_away->setGeometry(QRect(30, 120, 321, 16));
        checkBox_away->setChecked(false);
        lineEdit_busy = new QTextEdit(autoreply);
        lineEdit_busy->setObjectName(QStringLiteral("lineEdit_busy"));
        lineEdit_busy->setGeometry(QRect(30, 40, 361, 71));
        lineEdit_away = new QTextEdit(autoreply);
        lineEdit_away->setObjectName(QStringLiteral("lineEdit_away"));
        lineEdit_away->setGeometry(QRect(30, 140, 361, 71));

        verticalLayout_7->addWidget(autoreply);

        verticalSpacer_5 = new QSpacerItem(20, 150, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_5);

        stackedWidget->addWidget(page_replay);
        page_path = new QWidget();
        page_path->setObjectName(QStringLiteral("page_path"));
        verticalLayout_8 = new QVBoxLayout(page_path);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(70, 50, 0, 0);
        widget_10 = new QWidget(page_path);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        widget_10->setMinimumSize(QSize(0, 90));
        widget_10->setMaximumSize(QSize(16777215, 90));
        label_16 = new QLabel(widget_10);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(0, 0, 56, 16));
        label_16->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        userpath = new QLineEdit(widget_10);
        userpath->setObjectName(QStringLiteral("userpath"));
        userpath->setGeometry(QRect(110, 0, 260, 21));
        userpath->setReadOnly(true);
        openuserpath = new QPushButton(widget_10);
        openuserpath->setObjectName(QStringLiteral("openuserpath"));
        openuserpath->setGeometry(QRect(100, 30, 75, 25));
        openuserpath->setFlat(true);
        changeuserpath = new QPushButton(widget_10);
        changeuserpath->setObjectName(QStringLiteral("changeuserpath"));
        changeuserpath->setEnabled(true);
        changeuserpath->setGeometry(QRect(190, 30, 75, 25));
        changeuserpath->setFlat(true);
        defaultpath = new QPushButton(widget_10);
        defaultpath->setObjectName(QStringLiteral("defaultpath"));
        defaultpath->setGeometry(QRect(280, 30, 75, 25));
        defaultpath->setFlat(true);

        verticalLayout_8->addWidget(widget_10);

        widget_11 = new QWidget(page_path);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        widget_11->setMinimumSize(QSize(440, 90));
        widget_11->setMaximumSize(QSize(16777215, 90));
        label_17 = new QLabel(widget_11);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(0, 0, 111, 16));
        label_17->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        defaultSavepath = new QPushButton(widget_11);
        defaultSavepath->setObjectName(QStringLiteral("defaultSavepath"));
        defaultSavepath->setGeometry(QRect(280, 30, 75, 25));
        defaultSavepath->setFlat(true);
        openuserSavepath = new QPushButton(widget_11);
        openuserSavepath->setObjectName(QStringLiteral("openuserSavepath"));
        openuserSavepath->setGeometry(QRect(100, 30, 75, 25));
        openuserSavepath->setFlat(true);
        userSaveAspath = new QLineEdit(widget_11);
        userSaveAspath->setObjectName(QStringLiteral("userSaveAspath"));
        userSaveAspath->setGeometry(QRect(110, 0, 260, 21));
        userSaveAspath->setReadOnly(true);
        changeuserSavepath = new QPushButton(widget_11);
        changeuserSavepath->setObjectName(QStringLiteral("changeuserSavepath"));
        changeuserSavepath->setGeometry(QRect(190, 30, 75, 25));
        changeuserSavepath->setFlat(true);

        verticalLayout_8->addWidget(widget_11);

        verticalSpacer_6 = new QSpacerItem(20, 179, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_6);

        stackedWidget->addWidget(page_path);
        page_welcome = new QWidget();
        page_welcome->setObjectName(QStringLiteral("page_welcome"));
        verticalLayout_15 = new QVBoxLayout(page_welcome);
        verticalLayout_15->setSpacing(20);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(10, 10, 0, 0);
        widget_12 = new QWidget(page_welcome);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setMinimumSize(QSize(0, 200));
        widget_12->setMaximumSize(QSize(16777213, 200));
        ReplyWelcome_enabled = new QCheckBox(widget_12);
        ReplyWelcome_enabled->setObjectName(QStringLiteral("ReplyWelcome_enabled"));
        ReplyWelcome_enabled->setGeometry(QRect(10, 20, 131, 16));
        ReplyWelcome_enabled->setChecked(true);
        lineEdit_Rewelcome = new QLineEdit(widget_12);
        lineEdit_Rewelcome->setObjectName(QStringLiteral("lineEdit_Rewelcome"));
        lineEdit_Rewelcome->setGeometry(QRect(90, 50, 201, 21));
        lineEdit_Rewelcome->setReadOnly(true);
        ResetRadio = new QRadioButton(widget_12);
        ResetRadio->setObjectName(QStringLiteral("ResetRadio"));
        ResetRadio->setGeometry(QRect(10, 50, 51, 16));
        ResetRadio->setChecked(false);
        selfsetRadio = new QRadioButton(widget_12);
        selfsetRadio->setObjectName(QStringLiteral("selfsetRadio"));
        selfsetRadio->setGeometry(QRect(10, 125, 61, 16));
        selfsetWelcomeEdit = new QTextEdit(widget_12);
        selfsetWelcomeEdit->setObjectName(QStringLiteral("selfsetWelcomeEdit"));
        selfsetWelcomeEdit->setEnabled(true);
        selfsetWelcomeEdit->setGeometry(QRect(89, 75, 311, 121));

        verticalLayout_15->addWidget(widget_12);

        verticalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_7);

        stackedWidget->addWidget(page_welcome);
        page_friends = new QWidget();
        page_friends->setObjectName(QStringLiteral("page_friends"));
        verticalLayout_10 = new QVBoxLayout(page_friends);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(70, 50, 0, 0);
        widget_13 = new QWidget(page_friends);
        widget_13->setObjectName(QStringLiteral("widget_13"));
        widget_13->setMinimumSize(QSize(0, 121));
        widget_13->setMaximumSize(QSize(16777215, 121));
        friendsMode = new MyComboBox(widget_13);
        friendsMode->setObjectName(QStringLiteral("friendsMode"));
        friendsMode->setGeometry(QRect(100, 0, 131, 22));
        friendsMode->setFocusPolicy(Qt::WheelFocus);
        friendsMode->setFrame(true);
        friendquest_label = new QLabel(widget_13);
        friendquest_label->setObjectName(QStringLiteral("friendquest_label"));
        friendquest_label->setGeometry(QRect(0, 30, 31, 21));
        lineEdit_quest = new QLineEdit(widget_13);
        lineEdit_quest->setObjectName(QStringLiteral("lineEdit_quest"));
        lineEdit_quest->setGeometry(QRect(100, 30, 131, 20));
        friendanswer_label = new QLabel(widget_13);
        friendanswer_label->setObjectName(QStringLiteral("friendanswer_label"));
        friendanswer_label->setGeometry(QRect(0, 60, 31, 21));
        lineEdit_answer = new QLineEdit(widget_13);
        lineEdit_answer->setObjectName(QStringLiteral("lineEdit_answer"));
        lineEdit_answer->setGeometry(QRect(100, 60, 131, 20));
        pb_friendset = new QPushButton(widget_13);
        pb_friendset->setObjectName(QStringLiteral("pb_friendset"));
        pb_friendset->setGeometry(QRect(100, 90, 91, 25));
        pb_friendset->setFlat(true);
        friendquest_label_2 = new QLabel(widget_13);
        friendquest_label_2->setObjectName(QStringLiteral("friendquest_label_2"));
        friendquest_label_2->setGeometry(QRect(0, 0, 91, 21));

        verticalLayout_10->addWidget(widget_13);

        verticalSpacer_8 = new QSpacerItem(20, 182, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_8);

        stackedWidget->addWidget(page_friends);
        page_font = new QWidget();
        page_font->setObjectName(QStringLiteral("page_font"));
        verticalLayout_11 = new QVBoxLayout(page_font);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(70, 50, 0, 0);
        widget_14 = new QWidget(page_font);
        widget_14->setObjectName(QStringLiteral("widget_14"));
        widget_14->setMinimumSize(QSize(0, 160));
        widget_14->setMaximumSize(QSize(16777215, 160));
        label_23 = new QLabel(widget_14);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(0, 0, 56, 16));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBox_fontSize = new QCheckBox(widget_14);
        checkBox_fontSize->setObjectName(QStringLiteral("checkBox_fontSize"));
        checkBox_fontSize->setGeometry(QRect(100, 0, 161, 21));
        label_11 = new QLabel(widget_14);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 40, 361, 16));
        label_12 = new QLabel(widget_14);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 70, 101, 16));
        pbt_darkclr = new QPushButton(widget_14);
        pbt_darkclr->setObjectName(QStringLiteral("pbt_darkclr"));
        pbt_darkclr->setGeometry(QRect(130, 65, 51, 23));
        label_13 = new QLabel(widget_14);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 100, 101, 16));
        pbt_lightclr = new QPushButton(widget_14);
        pbt_lightclr->setObjectName(QStringLiteral("pbt_lightclr"));
        pbt_lightclr->setGeometry(QRect(130, 95, 51, 23));

        verticalLayout_11->addWidget(widget_14);

        verticalSpacer_9 = new QSpacerItem(20, 269, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_9);

        stackedWidget->addWidget(page_font);
        page_version = new QWidget();
        page_version->setObjectName(QStringLiteral("page_version"));
        verticalLayout_12 = new QVBoxLayout(page_version);
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(70, 50, 0, 0);
        widget_15 = new QWidget(page_version);
        widget_15->setObjectName(QStringLiteral("widget_15"));
        widget_15->setMinimumSize(QSize(0, 180));
        widget_15->setMaximumSize(QSize(16777215, 180));
        label_10 = new QLabel(widget_15);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(0, 0, 56, 16));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        version = new QLabel(widget_15);
        version->setObjectName(QStringLiteral("version"));
        version->setGeometry(QRect(100, 0, 91, 21));
        gengxin = new QPushButton(widget_15);
        gengxin->setObjectName(QStringLiteral("gengxin"));
        gengxin->setGeometry(QRect(100, 30, 70, 22));
        gengxin->setMinimumSize(QSize(0, 22));
        gengxin->setMaximumSize(QSize(16777215, 22));
        gengxin->setStyleSheet(QStringLiteral(""));
        gengxin->setFlat(true);
        collectInfo = new QPushButton(widget_15);
        collectInfo->setObjectName(QStringLiteral("collectInfo"));
        collectInfo->setGeometry(QRect(210, 70, 70, 22));
        collectInfo->setMinimumSize(QSize(0, 22));
        collectInfo->setMaximumSize(QSize(16777215, 22));
        clearCache = new QPushButton(widget_15);
        clearCache->setObjectName(QStringLiteral("clearCache"));
        clearCache->setGeometry(QRect(100, 70, 70, 22));
        clearCache->setMinimumSize(QSize(0, 22));
        clearCache->setMaximumSize(QSize(16777215, 22));
        label_25 = new QLabel(widget_15);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(0, 70, 56, 16));
        label_25->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        newversion = new QLabel(widget_15);
        newversion->setObjectName(QStringLiteral("newversion"));
        newversion->setGeometry(QRect(210, 2, 91, 15));
        version_3 = new QLabel(widget_15);
        version_3->setObjectName(QStringLiteral("version_3"));
        version_3->setGeometry(QRect(100, 120, 271, 21));
        logcoll_label = new QLabel(widget_15);
        logcoll_label->setObjectName(QStringLiteral("logcoll_label"));
        logcoll_label->setGeometry(QRect(193, 100, 171, 20));

        verticalLayout_12->addWidget(widget_15);

        verticalSpacer_10 = new QSpacerItem(20, 129, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_10);

        stackedWidget->addWidget(page_version);
        page_other = new QWidget();
        page_other->setObjectName(QStringLiteral("page_other"));
        verticalLayout_13 = new QVBoxLayout(page_other);
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(70, 50, 0, 0);
        widget_2 = new QWidget(page_other);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 565));
        cbAutoStartup = new QCheckBox(widget_2);
        cbAutoStartup->setObjectName(QStringLiteral("cbAutoStartup"));
        cbAutoStartup->setGeometry(QRect(0, 0, 371, 22));
        cbAutoStartup->setChecked(true);
        cbQuitOnClose = new QCheckBox(widget_2);
        cbQuitOnClose->setObjectName(QStringLiteral("cbQuitOnClose"));
        cbQuitOnClose->setGeometry(QRect(0, 30, 371, 22));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 60, 81, 22));
        cbNoticeGroupDestroy = new QCheckBox(widget_2);
        cbNoticeGroupDestroy->setObjectName(QStringLiteral("cbNoticeGroupDestroy"));
        cbNoticeGroupDestroy->setGeometry(QRect(0, 90, 381, 22));
        widget_16 = new QWidget(widget_2);
        widget_16->setObjectName(QStringLiteral("widget_16"));
        widget_16->setGeometry(QRect(80, 60, 118, 22));
        horizontalLayout_5 = new QHBoxLayout(widget_16);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        tbMailSplitDefault = new QRadioButton(widget_16);
        tbMailSplitDefault->setObjectName(QStringLiteral("tbMailSplitDefault"));
        tbMailSplitDefault->setChecked(true);

        horizontalLayout_5->addWidget(tbMailSplitDefault);

        tbMailSplitComma = new QRadioButton(widget_16);
        tbMailSplitComma->setObjectName(QStringLiteral("tbMailSplitComma"));

        horizontalLayout_5->addWidget(tbMailSplitComma);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 253, 81, 22));
        requesttm = new MySpinBox(widget_2);
        requesttm->setObjectName(QStringLiteral("requesttm"));
        requesttm->setGeometry(QRect(90, 253, 42, 22));
        requesttm->setFocusPolicy(Qt::ClickFocus);
        requesttm->setMinimum(0);
        requesttm->setMaximum(10);
        requesttm->setValue(0);
        cbAutoShake = new QCheckBox(widget_2);
        cbAutoShake->setObjectName(QStringLiteral("cbAutoShake"));
        cbAutoShake->setGeometry(QRect(0, 120, 371, 22));
        cbAutoShake->setChecked(true);
        cbHttpLog = new QCheckBox(widget_2);
        cbHttpLog->setObjectName(QStringLiteral("cbHttpLog"));
        cbHttpLog->setEnabled(true);
        cbHttpLog->setGeometry(QRect(0, 148, 371, 22));
        cbHttpLog->setChecked(false);
        cbEsc_hideChat = new QCheckBox(widget_2);
        cbEsc_hideChat->setObjectName(QStringLiteral("cbEsc_hideChat"));
        cbEsc_hideChat->setEnabled(true);
        cbEsc_hideChat->setGeometry(QRect(0, 174, 371, 22));
        cbEsc_hideChat->setChecked(false);
        cbGroupChatMember_ShowOrHide = new QCheckBox(widget_2);
        cbGroupChatMember_ShowOrHide->setObjectName(QStringLiteral("cbGroupChatMember_ShowOrHide"));
        cbGroupChatMember_ShowOrHide->setEnabled(true);
        cbGroupChatMember_ShowOrHide->setGeometry(QRect(0, 200, 371, 22));
        cbGroupChatMember_ShowOrHide->setChecked(false);
        cbScrollbarOnblew = new QCheckBox(widget_2);
        cbScrollbarOnblew->setObjectName(QStringLiteral("cbScrollbarOnblew"));
        cbScrollbarOnblew->setEnabled(true);
        cbScrollbarOnblew->setGeometry(QRect(0, 226, 371, 22));
        cbScrollbarOnblew->setChecked(false);
        tasktextcolor = new QWidget(widget_2);
        tasktextcolor->setObjectName(QStringLiteral("tasktextcolor"));
        tasktextcolor->setGeometry(QRect(0, 280, 200, 23));
        horizontalLayout_9 = new QHBoxLayout(tasktextcolor);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_text = new QLabel(tasktextcolor);
        label_text->setObjectName(QStringLiteral("label_text"));

        horizontalLayout_9->addWidget(label_text);

        pbt_tasktextclr = new QPushButton(tasktextcolor);
        pbt_tasktextclr->setObjectName(QStringLiteral("pbt_tasktextclr"));
        pbt_tasktextclr->setMinimumSize(QSize(50, 23));
        pbt_tasktextclr->setMaximumSize(QSize(50, 23));
        pbt_tasktextclr->setFlat(true);

        horizontalLayout_9->addWidget(pbt_tasktextclr);


        verticalLayout_13->addWidget(widget_2);

        verticalSpacer_12 = new QSpacerItem(20, 329, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_12);

        stackedWidget->addWidget(page_other);
        page_qtalkReplay = new QWidget();
        page_qtalkReplay->setObjectName(QStringLiteral("page_qtalkReplay"));
        autoreply_qtalk = new QWidget(page_qtalkReplay);
        autoreply_qtalk->setObjectName(QStringLiteral("autoreply_qtalk"));
        autoreply_qtalk->setGeometry(QRect(0, 0, 440, 180));
        autoreply_qtalk->setMinimumSize(QSize(0, 180));
        autoreply_qtalk->setMaximumSize(QSize(16777215, 180));
        ar_enabled = new QCheckBox(autoreply_qtalk);
        ar_enabled->setObjectName(QStringLiteral("ar_enabled"));
        ar_enabled->setGeometry(QRect(70, 30, 151, 22));
        ar_enabled->setChecked(true);
        ar_timer = new MySpinBox(autoreply_qtalk);
        ar_timer->setObjectName(QStringLiteral("ar_timer"));
        ar_timer->setGeometry(QRect(144, 30, 42, 22));
        ar_timer->setFocusPolicy(Qt::ClickFocus);
        ar_timer->setMinimum(1);
        ar_timer->setMaximum(20);
        ar_timer->setValue(5);
        label_15 = new QLabel(autoreply_qtalk);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(190, 30, 231, 22));
        ar_message = new MyComboBox(autoreply_qtalk);
        ar_message->setObjectName(QStringLiteral("ar_message"));
        ar_message->setEnabled(true);
        ar_message->setGeometry(QRect(170, 60, 250, 22));
        ar_message->setFocusPolicy(Qt::WheelFocus);
        ar_systemmsg = new QRadioButton(autoreply_qtalk);
        ar_systemmsg->setObjectName(QStringLiteral("ar_systemmsg"));
        ar_systemmsg->setGeometry(QRect(70, 62, 61, 16));
        ar_systemmsg->setChecked(true);
        ar_usermsg = new QRadioButton(autoreply_qtalk);
        ar_usermsg->setObjectName(QStringLiteral("ar_usermsg"));
        ar_usermsg->setGeometry(QRect(70, 89, 89, 16));
        ar_usermsgcontent = new QTextEdit(autoreply_qtalk);
        ar_usermsgcontent->setObjectName(QStringLiteral("ar_usermsgcontent"));
        ar_usermsgcontent->setEnabled(true);
        ar_usermsgcontent->setGeometry(QRect(170, 90, 251, 81));
        stackedWidget->addWidget(page_qtalkReplay);

        horizontalLayout_6->addWidget(stackedWidget);


        horizontalLayout->addWidget(widget_4);


        verticalLayout->addWidget(widget);


        horizontalLayout_7->addWidget(shadowinnerbg);


        horizontalLayout_8->addWidget(shadowbg);


        retranslateUi(SettingDetail);

        SendMessagecombox->setCurrentIndex(0);
        friendsMode->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(SettingDetail);
    } // setupUi

    void retranslateUi(QWidget *SettingDetail)
    {
        SettingDetail->setWindowTitle(QApplication::translate("SettingDetail", "SettingDetail", 0));
        btn_account->setText(QApplication::translate("SettingDetail", "\350\264\246\345\217\267\350\256\276\347\275\256", 0));
        btn_msgnotice->setText(QApplication::translate("SettingDetail", "\346\266\210\346\201\257\351\200\232\347\237\245", 0));
        btn_hotkey->setText(QApplication::translate("SettingDetail", "\347\203\255\351\224\256\350\256\276\347\275\256", 0));
        btn_conversation->setText(QApplication::translate("SettingDetail", "\344\274\232\350\257\235\350\256\276\347\275\256", 0));
        btn_autoreplay->setText(QApplication::translate("SettingDetail", "\350\207\252\345\212\250\345\233\236\345\244\215", 0));
        btn_path->setText(QApplication::translate("SettingDetail", "\346\226\207\344\273\266\347\233\256\345\275\225", 0));
        btn_welcome->setText(QApplication::translate("SettingDetail", "\346\254\242\350\277\216\350\257\255\350\256\276\347\275\256", 0));
        btn_friends->setText(QApplication::translate("SettingDetail", "\345\245\275\345\217\213\351\200\211\351\241\271", 0));
        btn_fontsize->setText(QApplication::translate("SettingDetail", "\345\255\227\345\217\267\345\205\274\345\256\271", 0));
        btn_other->setText(QApplication::translate("SettingDetail", "\345\205\266\344\273\226\350\256\276\347\275\256", 0));
        btn_version->setText(QApplication::translate("SettingDetail", "\347\211\210\346\234\254\344\277\241\346\201\257", 0));
        scrolltip_up->setText(QApplication::translate("SettingDetail", "\345\220\221\344\270\212\346\273\232\345\212\250\346\237\245\347\234\213\346\233\264\345\244\232", 0));
        scrolltip_down->setText(QApplication::translate("SettingDetail", "\345\220\221\344\270\213\346\273\232\345\212\250\346\237\245\347\234\213\346\233\264\345\244\232", 0));
        header->setText(QString());
        name->setText(QApplication::translate("SettingDetail", "Name", 0));
        accountExit->setText(QApplication::translate("SettingDetail", "\351\200\200\345\207\272\347\231\273\345\275\225", 0));
        messagesound->setText(QApplication::translate("SettingDetail", "\345\274\200\345\220\257\346\226\260\346\266\210\346\201\257\345\243\260\351\237\263\346\217\220\351\206\222", 0));
#ifndef QT_NO_TOOLTIP
        pbVoiceSetting->setToolTip(QApplication::translate("SettingDetail", "\347\202\271\345\207\273\350\277\233\350\241\214\350\256\276\346\217\220\347\244\272\351\237\263", 0));
#endif // QT_NO_TOOLTIP
        pbVoiceSetting->setText(QApplication::translate("SettingDetail", "\350\256\276\347\275\256\346\217\220\347\244\272\351\237\263", 0));
#ifndef QT_NO_TOOLTIP
        messagepopup->setToolTip(QApplication::translate("SettingDetail", "\345\275\223\344\274\232\350\257\235\346\241\206\350\242\253\345\205\263\351\227\255\345\220\216\357\274\214\345\217\257\344\273\245\350\207\252\345\212\250\345\274\271\345\207\272", 0));
#endif // QT_NO_TOOLTIP
        messagepopup->setText(QApplication::translate("SettingDetail", "\345\205\201\350\256\270\346\235\245\346\266\210\346\201\257\346\227\266\350\207\252\345\212\250\345\274\271\345\207\272\347\252\227\345\217\243", 0));
#ifndef QT_NO_TOOLTIP
        messagenotice->setToolTip(QApplication::translate("SettingDetail", "\346\230\276\347\244\272\346\266\210\346\201\257\346\217\220\351\206\222\347\252\227\345\217\243", 0));
#endif // QT_NO_TOOLTIP
        messagenotice->setText(QApplication::translate("SettingDetail", "\344\274\232\350\257\235\346\266\210\346\201\257\346\217\220\351\206\222", 0));
        groupBox->setTitle(QString());
        radioButton_anytime->setText(QApplication::translate("SettingDetail", "\351\232\217\346\227\266    \357\274\210\346\227\240\350\256\272\346\230\257\345\220\246\345\234\250\347\272\277\357\274\214\351\203\275\346\216\245\346\224\266push\346\216\250\351\200\201\346\266\210\346\201\257\357\274\211", 0));
        label_8->setText(QApplication::translate("SettingDetail", "\345\210\206\351\222\237", 0));
        radioButton_awaypc->setText(QApplication::translate("SettingDetail", "\347\246\273\345\274\200\347\224\265\350\204\221", 0));
        savepush->setText(QApplication::translate("SettingDetail", "\344\277\235\345\255\230push\350\256\276\347\275\256", 0));
        label_9->setText(QApplication::translate("SettingDetail", "\346\211\213\346\234\272\347\253\257\346\216\245\346\224\266push\346\266\210\346\201\257", 0));
        radioButton_defaultvoice->setText(QApplication::translate("SettingDetail", "\345\220\257\347\224\250\351\273\230\350\256\244\347\232\204\346\217\220\347\244\272\351\237\263", 0));
        radioButton_newsetvoice->setText(QApplication::translate("SettingDetail", "\345\220\257\347\224\250\350\256\276\347\275\256\347\232\204\346\217\220\347\244\272\351\237\263", 0));
#ifndef QT_NO_TOOLTIP
        push_set->setToolTip(QApplication::translate("SettingDetail", "\346\230\276\347\244\272\346\266\210\346\201\257\346\217\220\351\206\222\347\252\227\345\217\243", 0));
#endif // QT_NO_TOOLTIP
        push_set->setText(QApplication::translate("SettingDetail", "\346\211\213\346\234\272\347\253\257\351\232\217\346\227\266\346\224\266push\346\216\250\351\200\201", 0));
#ifndef QT_NO_TOOLTIP
        QuickReplay->setToolTip(QApplication::translate("SettingDetail", "\346\230\276\347\244\272\346\266\210\346\201\257\346\217\220\351\206\222\347\252\227\345\217\243", 0));
#endif // QT_NO_TOOLTIP
        QuickReplay->setText(QApplication::translate("SettingDetail", "\350\207\252\345\212\250\345\233\236\345\244\215\350\257\255\347\233\264\346\216\245\345\217\221\351\200\201", 0));
        label_3->setText(QApplication::translate("SettingDetail", "\346\217\220\345\217\226\346\266\210\346\201\257:", 0));
        label_4->setText(QApplication::translate("SettingDetail", "\345\261\217\345\271\225\346\215\225\346\215\211:", 0));
        label_5->setText(QApplication::translate("SettingDetail", "\346\220\234\347\264\242\344\272\272\345\221\230:", 0));
        label_7->setText(QApplication::translate("SettingDetail", "\347\273\204\347\273\207\346\236\266\346\236\204:", 0));
        radioEnableButton->setText(QApplication::translate("SettingDetail", "\345\220\257\347\224\250\347\203\255\351\224\256", 0));
        radioUnEnableButton->setText(QApplication::translate("SettingDetail", "\347\246\201\347\224\250\347\203\255\351\224\256", 0));
        SendMessagecombox->clear();
        SendMessagecombox->insertItems(0, QStringList()
         << QApplication::translate("SettingDetail", "Enter", 0)
         << QApplication::translate("SettingDetail", "Ctrl+Enter", 0)
         << QApplication::translate("SettingDetail", "Shift+Enter", 0)
        );
        SendMessagecombox->setCurrentText(QApplication::translate("SettingDetail", "Enter", 0));
        label_18->setText(QApplication::translate("SettingDetail", "\345\217\221\351\200\201:", 0));
        label_19->setText(QApplication::translate("SettingDetail", "\346\234\200\345\244\247\344\274\232\350\257\235\346\225\260:", 0));
        max_session->clear();
        max_session->insertItems(0, QStringList()
         << QApplication::translate("SettingDetail", "50", 0)
         << QApplication::translate("SettingDetail", "100", 0)
         << QApplication::translate("SettingDetail", "200", 0)
         << QApplication::translate("SettingDetail", "500", 0)
         << QApplication::translate("SettingDetail", "1000", 0)
         << QApplication::translate("SettingDetail", "2000", 0)
         << QApplication::translate("SettingDetail", "5000", 0)
         << QApplication::translate("SettingDetail", "10000", 0)
        );
        cbEnableChatLru->setText(QApplication::translate("SettingDetail", "\345\220\257\347\224\250\344\274\232\350\257\235\350\207\252\345\212\250\345\233\236\346\224\266", 0));
        label_20->setText(QApplication::translate("SettingDetail", "\346\234\200\345\244\247\344\274\232\350\257\235\347\252\227\345\217\243\346\225\260:", 0));
        cbChatLruLimit->clear();
        cbChatLruLimit->insertItems(0, QStringList()
         << QApplication::translate("SettingDetail", "3", 0)
         << QApplication::translate("SettingDetail", "5", 0)
         << QApplication::translate("SettingDetail", "10", 0)
         << QApplication::translate("SettingDetail", "15", 0)
         << QApplication::translate("SettingDetail", "20", 0)
        );
        label_6->setText(QApplication::translate("SettingDetail", "\350\201\212\345\244\251\345\216\206\345\217\262\346\241\206\345\261\225\347\244\272\344\274\232\350\257\235\346\235\241\346\225\260:", 0));
        cbChatHistoryMsgLimit->clear();
        cbChatHistoryMsgLimit->insertItems(0, QStringList()
         << QApplication::translate("SettingDetail", "15", 0)
         << QApplication::translate("SettingDetail", "30", 0)
         << QApplication::translate("SettingDetail", "50", 0)
         << QApplication::translate("SettingDetail", "70", 0)
         << QApplication::translate("SettingDetail", "100", 0)
         << QApplication::translate("SettingDetail", "200", 0)
        );
        cbEnableChatHistoryMsg->setText(QApplication::translate("SettingDetail", "\345\220\257\347\224\250\345\216\206\345\217\262\346\241\206\345\261\225\347\244\272\344\274\232\350\257\235\346\235\241\346\225\260", 0));
        radioButton_unRead->setText(QApplication::translate("SettingDetail", "\346\234\200\350\277\221\344\274\232\350\257\235\345\210\227\350\241\250\346\241\206\344\270\255\345\217\252\346\230\276\347\244\272\346\234\252\350\257\273\345\222\214\347\275\256\351\241\266\344\274\232\350\257\235", 0));
        radioButton_loadAll->setText(QApplication::translate("SettingDetail", "\346\234\200\350\277\221\344\274\232\350\257\235\345\210\227\350\241\250\346\241\206\344\270\255\345\212\240\350\275\275\346\211\200\346\234\211\344\274\232\350\257\235", 0));
        checkBox_busy->setText(QApplication::translate("SettingDetail", "\345\277\231\347\242\214\347\212\266\346\200\201\357\274\210\345\220\253\347\246\273\345\274\200\347\224\265\350\204\221\347\232\204\346\203\205\345\206\265\357\274\211", 0));
        checkBox_away->setText(QApplication::translate("SettingDetail", "\347\246\273\345\274\200\357\274\214\347\246\273\347\272\277\347\212\266\346\200\201", 0));
        label_16->setText(QApplication::translate("SettingDetail", "\347\224\250\346\210\267\347\233\256\345\275\225", 0));
        openuserpath->setText(QApplication::translate("SettingDetail", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", 0));
        changeuserpath->setText(QApplication::translate("SettingDetail", "\345\217\230\346\233\264\346\226\207\344\273\266\345\244\271", 0));
        defaultpath->setText(QApplication::translate("SettingDetail", "\346\201\242\345\244\215\351\273\230\350\256\244", 0));
        label_17->setText(QApplication::translate("SettingDetail", "\346\226\207\344\273\266\345\217\246\345\255\230\344\270\272\345\210\235\345\247\213\347\233\256\345\275\225", 0));
        defaultSavepath->setText(QApplication::translate("SettingDetail", "\346\201\242\345\244\215\351\273\230\350\256\244", 0));
        openuserSavepath->setText(QApplication::translate("SettingDetail", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", 0));
        changeuserSavepath->setText(QApplication::translate("SettingDetail", "\345\217\230\346\233\264\346\226\207\344\273\266\345\244\271", 0));
        ReplyWelcome_enabled->setText(QApplication::translate("SettingDetail", "\351\234\200\350\246\201\344\275\277\347\224\250\346\254\242\350\277\216\350\257\255\344\277\241\346\201\257", 0));
        lineEdit_Rewelcome->setText(QApplication::translate("SettingDetail", "\344\275\240\345\245\275\346\210\221\346\230\257\345\234\250\347\272\277\345\256\242\346\234\215\357\274\214\345\276\210\351\253\230\345\205\264\344\270\272\344\275\240\346\234\215\345\212\241", 0));
        ResetRadio->setText(QApplication::translate("SettingDetail", "\351\242\204\350\256\276", 0));
        selfsetRadio->setText(QApplication::translate("SettingDetail", "\350\207\252\345\256\232\344\271\211", 0));
        friendsMode->clear();
        friendsMode->insertItems(0, QStringList()
         << QApplication::translate("SettingDetail", "\345\205\250\351\203\250\346\213\222\347\273\235", 0)
         << QApplication::translate("SettingDetail", "\344\272\272\345\267\245\350\256\244\350\257\201", 0)
         << QApplication::translate("SettingDetail", "\347\255\224\346\241\210\350\256\244\350\257\201", 0)
         << QApplication::translate("SettingDetail", "\345\205\250\351\203\250\346\216\245\345\217\227", 0)
        );
        friendquest_label->setText(QApplication::translate("SettingDetail", "\351\227\256\351\242\230", 0));
        friendanswer_label->setText(QApplication::translate("SettingDetail", "\347\255\224\346\241\210", 0));
        pb_friendset->setText(QApplication::translate("SettingDetail", "\347\241\256\350\256\244", 0));
        friendquest_label_2->setText(QApplication::translate("SettingDetail", "\346\235\203\351\231\220\347\261\273\345\236\213", 0));
        label_23->setText(QApplication::translate("SettingDetail", "\345\255\227\345\217\267\350\256\276\347\275\256", 0));
        checkBox_fontSize->setText(QApplication::translate("SettingDetail", "\345\220\257\347\224\250\345\255\227\345\217\267\350\256\276\347\275\256", 0));
        label_11->setText(QApplication::translate("SettingDetail", "\346\234\200\350\277\221\344\274\232\350\257\235\345\210\227\350\241\250\346\241\206\344\270\255\346\217\217\350\277\260\346\226\207\346\234\254\351\242\234\350\211\262\347\232\204\350\256\276\347\275\256\357\274\210\351\207\215\345\220\257\345\256\242\346\210\267\347\253\257\346\225\210\346\236\234\346\233\264\344\275\263\357\274\211:", 0));
        label_12->setText(QApplication::translate("SettingDetail", "\344\270\273\351\242\230Dark\344\270\213\351\242\234\350\211\262\357\274\232", 0));
        pbt_darkclr->setText(QString());
        label_13->setText(QApplication::translate("SettingDetail", "\344\270\273\351\242\230Light\344\270\213\351\242\234\350\211\262\357\274\232", 0));
        pbt_lightclr->setText(QString());
        label_10->setText(QApplication::translate("SettingDetail", "\347\211\210\346\234\254\344\277\241\346\201\257", 0));
        version->setText(QApplication::translate("SettingDetail", "qTalk 0.8", 0));
        gengxin->setText(QApplication::translate("SettingDetail", "\346\243\200\346\237\245\346\233\264\346\226\260", 0));
        collectInfo->setText(QApplication::translate("SettingDetail", "\346\224\266\351\233\206\346\227\245\345\277\227", 0));
        clearCache->setText(QApplication::translate("SettingDetail", "\346\270\205\347\220\206\347\274\223\345\255\230", 0));
        label_25->setText(QApplication::translate("SettingDetail", "\344\276\277\346\215\267\347\273\264\346\212\244", 0));
        newversion->setText(QString());
        version_3->setText(QApplication::translate("SettingDetail", "\346\234\254\350\275\257\344\273\266\344\275\277\347\224\250\344\272\206EmojiOne\350\241\250\346\203\205\345\214\205\343\200\202", 0));
        logcoll_label->setText(QString());
        cbAutoStartup->setText(QApplication::translate("SettingDetail", "\345\274\200\346\234\272\350\207\252\345\220\257\345\212\250", 0));
        cbQuitOnClose->setText(QApplication::translate("SettingDetail", "\345\205\263\351\227\255\344\274\232\350\257\235\346\241\206\357\274\214\351\200\200\345\207\272\347\250\213\345\272\217", 0));
        label->setText(QApplication::translate("SettingDetail", "\351\202\256\344\273\266\345\210\206\351\232\224\347\254\246\357\274\232", 0));
        cbNoticeGroupDestroy->setText(QApplication::translate("SettingDetail", "\347\276\244\347\273\204\350\242\253\351\224\200\346\257\201\346\227\266\357\274\214\345\274\271\345\207\272\351\200\232\347\237\245\347\252\227\345\217\243", 0));
        tbMailSplitDefault->setText(QApplication::translate("SettingDetail", "\345\210\206\345\217\267", 0));
        tbMailSplitComma->setText(QApplication::translate("SettingDetail", "\351\200\227\345\217\267", 0));
        label_2->setText(QApplication::translate("SettingDetail", "\345\276\252\347\216\257\350\257\267\346\261\202\346\254\241\346\225\260", 0));
        cbAutoShake->setText(QApplication::translate("SettingDetail", "\350\207\252\345\212\250\346\222\255\346\224\276\345\257\271\346\226\271\345\217\221\346\235\245\347\232\204\351\234\207\345\212\250", 0));
        cbHttpLog->setText(QApplication::translate("SettingDetail", "\350\256\260\345\275\225http\350\257\267\346\261\202\346\227\245\345\277\227", 0));
        cbEsc_hideChat->setText(QApplication::translate("SettingDetail", "ESC\351\224\256\345\205\263\351\227\255\350\201\212\345\244\251\346\241\206", 0));
        cbGroupChatMember_ShowOrHide->setText(QApplication::translate("SettingDetail", "\345\261\225\347\244\272\347\276\244\346\210\220\345\221\230\345\210\227\350\241\250", 0));
        cbScrollbarOnblew->setText(QApplication::translate("SettingDetail", "\345\210\207\346\215\242\350\201\212\345\244\251\346\241\206\346\273\232\345\212\250\346\235\241\344\270\215\347\275\256\345\272\225", 0));
        label_text->setText(QApplication::translate("SettingDetail", "\347\212\266\346\200\201\346\240\217\344\270\212\346\234\252\350\257\273\346\225\260\346\226\207\346\234\254\351\242\234\350\211\262:", 0));
        pbt_tasktextclr->setText(QString());
        ar_enabled->setText(QApplication::translate("SettingDetail", "\347\246\273\345\274\200\347\224\265\350\204\221", 0));
        label_15->setText(QApplication::translate("SettingDetail", "push\346\266\210\346\201\257\345\210\260\346\211\213\346\234\272\347\253\257\357\274\214\345\271\266\350\207\252\345\212\250\345\233\236\345\244\215", 0));
        ar_message->clear();
        ar_message->insertItems(0, QStringList()
         << QApplication::translate("SettingDetail", "\351\251\254\344\270\212\345\233\236\346\235\245", 0)
         << QApplication::translate("SettingDetail", "\347\216\260\345\234\250\345\277\231", 0)
         << QApplication::translate("SettingDetail", "\346\255\243\345\234\250\344\274\232\350\256\256\344\270\255", 0)
         << QApplication::translate("SettingDetail", "\345\244\226\345\207\272\345\260\261\351\244\220", 0)
         << QApplication::translate("SettingDetail", "\344\270\215\345\234\250\345\212\236\345\205\254\345\256\244", 0)
        );
        ar_systemmsg->setText(QApplication::translate("SettingDetail", "\351\242\204\350\256\276", 0));
        ar_usermsg->setText(QApplication::translate("SettingDetail", "\350\207\252\345\256\232\344\271\211", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingDetail: public Ui_SettingDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDETAIL_H

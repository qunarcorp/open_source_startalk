/********************************************************************************
** Form generated from reading UI file 'MenuRobotDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUROBOTDIALOG_H
#define UI_MENUROBOTDIALOG_H

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
#include "TextEdit.h"
#include "chattoolbar.h"
#include "draggablewebview.h"

QT_BEGIN_NAMESPACE

class Ui_MenuRobotDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wb;
    QVBoxLayout *verticalLayout_2;
    QWidget *titlebarWidget;
    QWidget *infopannel;
    QHBoxLayout *horizontalLayout_7;
    QWidget *widget_7;
    QPushButton *headerimage;
    QLabel *headericon;
    QWidget *undbclicked;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *name;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *noticy;
    QWidget *funtionpannel;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnfilter;
    QWidget *webviewFrame;
    DraggableWebView *webView;
    QWidget *dealingpanel;
    QHBoxLayout *horizontalLayout_13;
    QLabel *dealing;
    QWidget *spider_0;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_5;
    QWidget *editPanel;
    QVBoxLayout *verticalLayout_6;
    QWidget *toolbar_1;
    QHBoxLayout *horizontalLayout_3;
    ChatToolBar *toolbar;
    QPushButton *down;
    QWidget *frametextedit;
    QVBoxLayout *verticalLayout_4;
    TextEdit *textEdit;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *sendbtn;
    QWidget *menupanel;
    QHBoxLayout *horizontalLayout;
    QWidget *robotMenu;
    QHBoxLayout *robotMenuHlayout;
    QPushButton *up;

    void setupUi(QWidget *MenuRobotDialog)
    {
        if (MenuRobotDialog->objectName().isEmpty())
            MenuRobotDialog->setObjectName(QStringLiteral("MenuRobotDialog"));
        MenuRobotDialog->resize(631, 535);
        MenuRobotDialog->setStyleSheet(QString::fromUtf8("\n"
"QWidget{\n"
"    font-family:'\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"}\n"
"QWidget#MenuRobotDialog\n"
"{\n"
"    border:none;\n"
"    background:#00000000;\n"
"}\n"
"\n"
"\n"
"QWidget#widgetBorder{\n"
"    border: none;\n"
"    border-radius: 0px;\n"
"    \n"
"}\n"
"\n"
"QWidget#webView\n"
"{\n"
"    background:#00000000;\n"
"}\n"
"QWidget#webviewFrame\n"
"{\n"
"    background:#FFFFFF;\n"
"    border:none;\n"
"}\n"
" \n"
"QWidget#spider_0{\n"
"    background-color: #00000000;\n"
"}\n"
"QWidget#border{\n"
"    background-color: #FFFFFF;\n"
"}\n"
"QWidget#border_3{\n"
"    background-color: #FFFFFF;\n"
"}\n"
"QWidget#fontpage{\n"
"    background-color: #FFFFFF;\n"
"}\n"
"QWidget#toolbar_1{\n"
"    background-color: #FFFFFF;\n"
"}\n"
"QWidget#frametextedit,#menupanel{\n"
"    background-color: #FFFFFF;\n"
"}\n"
"QTextEdit#textEdit{\n"
"    border:none;\n"
"	background-color: #00000000;\n"
"}\n"
"\n"
"/* \345\267\245\345\205\267\346\235\241 */\n"
"QPushButton#btnEmotion{ \n"
"    border:1px so"
                        "lid #00000000;\n"
"	image : url(:/Images/toolbar_emoticon_normal.png);\n"
"} \n"
"QPushButton#btnEmotion:hover{ \n"
"	image : url(:/Images/toolbar_emoticon_hover.png);\n"
"} \n"
"QPushButton#btnEmotion:pressed{ \n"
"	image : url(:/Images/toolbar_emoticon_hover.png);\n"
"} \n"
"\n"
"QPushButton#btnFont{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/font_normal.png);\n"
"} \n"
"QPushButton#btnFont:hover{ \n"
"    image : url(:/Images/font_hover.png);\n"
"} \n"
"QPushButton#btnFont:pressed{ \n"
"    image : url(:/Images/font_hover.png);\n"
"} \n"
"\n"
"QPushButton#btnJietu{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/toolbar_screenCapture_normal.png);\n"
"} \n"
"QPushButton#btnJietu:hover{ \n"
"    image : url(:/Images/toolbar_screenCapture_hover.png);\n"
"} \n"
"QPushButton#btnJietu:pressed{ \n"
"   image : url(:/Images/toolbar_screenCapture_hover.png);\n"
"} \n"
"\n"
"QPushButton#btnSendPic{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/toolbar_sendfile_norma"
                        "l.png);\n"
"} \n"
"QPushButton#btnSendPic:hover{ \n"
"    image : url(:/Images/toolbar_sendfile_hover.png);\n"
"} \n"
"QPushButton#btnSendPic:pressed{ \n"
"    image : url(:/Images/toolbar_sendfile_hover.png);\n"
"} \n"
"\n"
"QPushButton#historyRecord{ \n"
"    border:1px solid #00000000;\n"
"	\n"
"	image : url(:/Images/historyicon.png);\n"
"} \n"
"QPushButton#historyRecord:hover{ \n"
"    image : url(:/Images/historyicon.png);\n"
"} \n"
"QPushButton#historyRecord:pressed{ \n"
"    image : url(:/Images/historyicon.png);\n"
"} \n"
"\n"
"QPushButton#historyRecordWeb{ \n"
"    border:1px solid #00000000;\n"
"	\n"
"	image : url(:/Images/aio_group_search_normal.png);\n"
"} \n"
"QPushButton#historyRecordWeb:hover{ \n"
"    image : url(:/Images/aio_group_search_normal.png);\n"
"} \n"
"QPushButton#historyRecordWeb:pressed{ \n"
"    image : url(:/Images/aio_group_search_normal.png);\n"
"} \n"
"QPushButton#trace{  \n"
"    border:none;\n"
"    image : url(:/Images/icon_go.png);\n"
"}\n"
"\n"
"QPushButton#btnQuickReply{ "
                        "\n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/QReply.png);\n"
"} \n"
"QPushButton#btnQuickReply:hover{ \n"
"    image : url(:/Images/QReply.png);\n"
"} \n"
"QPushButton#btnQuickReply:pressed{ \n"
"    image : url(:/Images/QReply.png);\n"
"} \n"
"\n"
"QPushButton#pushButton_muc{  \n"
"    border:1px solid #00000000;\n"
"    image : url(:/Images/titlebar_function_addMember_normal.png);\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton#pushButton_muc:hover{\n"
"    image : url(:/Images/titlebar_function_addMember_down.png);\n"
"}\n"
"\n"
"QPushButton#pushButton_muc:pressed{\n"
"    image : url(:/Images/titlebar_function_addMember_down.png);\n"
"}\n"
"\n"
"QPushButton#sendmail{  \n"
"    border:1px solid #00000000;\n"
"    margin-right:6px;\n"
"    image : url(:/Images/mailnormal.png);\n"
"}\n"
"\n"
"QPushButton#sendmail:pressed{\n"
"    image : url(:/Images/mailpress.png);\n"
"}\n"
"\n"
"QPushButton#sendbtn{\n"
"    border-radius: 0px;\n"
"    color:#666666;\n"
"    border:1px solid #E5E5E5;\n"
"    backgroun"
                        "d-color:#FFFFFF;\n"
"}\n"
"\n"
"QPushButton#sendbtn:hover{\n"
"    color:#FFFFFF;\n"
"    background-color:#38C738;\n"
"}\n"
"QPushButton#sendbtn:pressed{\n"
"    color:#FFFFFF;\n"
"    background-color:#2FB82F;\n"
"}\n"
"\n"
"\n"
"QPushButton#btnTransfer{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/transfer_normal.png);\n"
"} \n"
"QPushButton#btnTransfer:hover{ \n"
"    image : url(:/Images/transfer_hover.png);\n"
"} \n"
"QPushButton#btnTransfer:pressed{ \n"
"    image : url(:/Images/transfer_hover.png);\n"
"} \n"
"\n"
"\n"
"QPushButton#btnShake{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/toolbar_shake_normal.png);\n"
"} \n"
"QPushButton#btnShake:hover{ \n"
"    image : url(:/Images/toolbar_shake_hover.png);\n"
"} \n"
"QPushButton#btnShake:pressed{ \n"
"   image : url(:/Images/toolbar_shake_hover.png);\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"QWidget#robotMenu\n"
"{\n"
"    background:#E5E5E5;\n"
"    border:none;\n"
"}\n"
"\n"
"\n"
"QPushButton#up\n"
"{ \n"
"    border:none;\n"
" "
                        "  image : url(:/Images/robotInput.png);\n"
"}\n"
"\n"
"QPushButton#down\n"
"{\n"
"     border:none;\n"
"   image : url(:/Images/robotMenu.png);\n"
"}\n"
"\n"
"QPushButton#btnJietusetting{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/jietu_normal.png);\n"
"} \n"
"QPushButton#btnJietusetting:hover{ \n"
"    image : url(:/Images/jietu_hover.png);\n"
"} \n"
"QPushButton#btnJietusetting:pressed{ \n"
"   image : url(:/Images/jietu_hover.png);\n"
"} \n"
"\n"
"QPushButton#btnfilter{ \n"
"    border:1px solid #00000000;\n"
"	image : url(:/Images/filter.png);\n"
"} \n"
"QPushButton#btnfilter:hover{ \n"
"    image : url(:/Images/filter.png);\n"
"} \n"
"QPushButton#btnfilter:pressed{ \n"
"   image : url(:/Images/filter.png);\n"
"} \n"
"\n"
"QWidget#dealingpanel\n"
"{\n"
"	background:#00000000;\n"
"	border:none;\n"
"}\n"
"QLabel#dealing\n"
"{\n"
"	background:#A0000000;\n"
"	border:none;\n"
"	color:#ECEDEF;\n"
"	border-radius:3px;\n"
"}"));
        verticalLayout = new QVBoxLayout(MenuRobotDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wb = new QWidget(MenuRobotDialog);
        wb->setObjectName(QStringLiteral("wb"));
        wb->setStyleSheet(QStringLiteral(""));
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
        infopannel = new QWidget(titlebarWidget);
        infopannel->setObjectName(QStringLiteral("infopannel"));
        infopannel->setGeometry(QRect(0, 0, 591, 60));
        infopannel->setMinimumSize(QSize(0, 60));
        infopannel->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_7 = new QHBoxLayout(infopannel);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(8, 0, 200, 0);
        widget_7 = new QWidget(infopannel);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setMinimumSize(QSize(50, 50));
        widget_7->setMaximumSize(QSize(50, 50));
        headerimage = new QPushButton(widget_7);
        headerimage->setObjectName(QStringLiteral("headerimage"));
        headerimage->setGeometry(QRect(0, 0, 50, 50));
        headerimage->setMinimumSize(QSize(50, 50));
        headerimage->setMaximumSize(QSize(50, 50));
        headerimage->setFlat(true);
        headericon = new QLabel(widget_7);
        headericon->setObjectName(QStringLiteral("headericon"));
        headericon->setGeometry(QRect(40, 40, 10, 10));
        headericon->setMinimumSize(QSize(10, 10));
        headericon->setMaximumSize(QSize(10, 10));

        horizontalLayout_7->addWidget(widget_7);

        undbclicked = new QWidget(infopannel);
        undbclicked->setObjectName(QStringLiteral("undbclicked"));
        verticalLayout_3 = new QVBoxLayout(undbclicked);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 6, 20, 6);
        widget_6 = new QWidget(undbclicked);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_10 = new QHBoxLayout(widget_6);
        horizontalLayout_10->setSpacing(6);
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

        widget_5 = new QWidget(undbclicked);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_9 = new QHBoxLayout(widget_5);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        noticy = new QLabel(widget_5);
        noticy->setObjectName(QStringLiteral("noticy"));
        noticy->setMaximumSize(QSize(16777215, 16777215));
        noticy->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_9->addWidget(noticy);


        verticalLayout_3->addWidget(widget_5);


        horizontalLayout_7->addWidget(undbclicked);

        funtionpannel = new QWidget(titlebarWidget);
        funtionpannel->setObjectName(QStringLiteral("funtionpannel"));
        funtionpannel->setGeometry(QRect(10, 10, 30, 27));
        funtionpannel->setMinimumSize(QSize(0, 27));
        funtionpannel->setMaximumSize(QSize(16777215, 27));
        horizontalLayout_4 = new QHBoxLayout(funtionpannel);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btnfilter = new QPushButton(funtionpannel);
        btnfilter->setObjectName(QStringLiteral("btnfilter"));
        btnfilter->setMinimumSize(QSize(27, 27));
        btnfilter->setMaximumSize(QSize(27, 27));
        btnfilter->setIconSize(QSize(27, 27));
        btnfilter->setFlat(true);

        horizontalLayout_4->addWidget(btnfilter);


        verticalLayout_2->addWidget(titlebarWidget);

        webviewFrame = new QWidget(wb);
        webviewFrame->setObjectName(QStringLiteral("webviewFrame"));
        webView = new DraggableWebView(webviewFrame);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setGeometry(QRect(0, 0, 650, 346));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
        webView->setSizePolicy(sizePolicy1);
        webView->setMaximumSize(QSize(16777215, 16777215));
        dealingpanel = new QWidget(webviewFrame);
        dealingpanel->setObjectName(QStringLiteral("dealingpanel"));
        dealingpanel->setGeometry(QRect(10, 10, 391, 211));
        dealingpanel->setStyleSheet(QStringLiteral(""));
        horizontalLayout_13 = new QHBoxLayout(dealingpanel);
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        dealing = new QLabel(dealingpanel);
        dealing->setObjectName(QStringLiteral("dealing"));
        dealing->setMinimumSize(QSize(220, 100));
        dealing->setMaximumSize(QSize(220, 100));
        dealing->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(dealing);


        verticalLayout_2->addWidget(webviewFrame);

        spider_0 = new QWidget(wb);
        spider_0->setObjectName(QStringLiteral("spider_0"));
        spider_0->setMinimumSize(QSize(0, 1));
        spider_0->setMaximumSize(QSize(16777215, 1));
        spider_0->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(spider_0);

        widget_8 = new QWidget(wb);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMinimumSize(QSize(0, 0));
        verticalLayout_5 = new QVBoxLayout(widget_8);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        editPanel = new QWidget(widget_8);
        editPanel->setObjectName(QStringLiteral("editPanel"));
        sizePolicy.setHeightForWidth(editPanel->sizePolicy().hasHeightForWidth());
        editPanel->setSizePolicy(sizePolicy);
        editPanel->setMinimumSize(QSize(100, 0));
        editPanel->setStyleSheet(QStringLiteral(""));
        verticalLayout_6 = new QVBoxLayout(editPanel);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        toolbar_1 = new QWidget(editPanel);
        toolbar_1->setObjectName(QStringLiteral("toolbar_1"));
        sizePolicy.setHeightForWidth(toolbar_1->sizePolicy().hasHeightForWidth());
        toolbar_1->setSizePolicy(sizePolicy);
        toolbar_1->setMinimumSize(QSize(0, 32));
        toolbar_1->setMaximumSize(QSize(16777215, 32));
        toolbar_1->setStyleSheet(QStringLiteral(""));
        horizontalLayout_3 = new QHBoxLayout(toolbar_1);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(2, 0, 2, 0);
        toolbar = new ChatToolBar(toolbar_1);
        toolbar->setObjectName(QStringLiteral("toolbar"));

        horizontalLayout_3->addWidget(toolbar);

        down = new QPushButton(toolbar_1);
        down->setObjectName(QStringLiteral("down"));
        down->setMinimumSize(QSize(30, 30));
        down->setMaximumSize(QSize(30, 30));
        down->setFlat(true);

        horizontalLayout_3->addWidget(down);


        verticalLayout_6->addWidget(toolbar_1);

        frametextedit = new QWidget(editPanel);
        frametextedit->setObjectName(QStringLiteral("frametextedit"));
        frametextedit->setMaximumSize(QSize(16777215, 16777215));
        frametextedit->setStyleSheet(QStringLiteral(""));
        verticalLayout_4 = new QVBoxLayout(frametextedit);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        textEdit = new TextEdit(frametextedit);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy2);
        textEdit->setMinimumSize(QSize(0, 100));
        textEdit->setMaximumSize(QSize(16777215, 100));
        textEdit->setStyleSheet(QStringLiteral(""));
        textEdit->setFrameShape(QFrame::NoFrame);

        verticalLayout_4->addWidget(textEdit);

        widget_4 = new QWidget(frametextedit);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(0, 0));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 10, 10);
        horizontalSpacer_7 = new QSpacerItem(593, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        sendbtn = new QPushButton(widget_4);
        sendbtn->setObjectName(QStringLiteral("sendbtn"));
        sendbtn->setMinimumSize(QSize(68, 26));
        sendbtn->setMaximumSize(QSize(68, 26));
        sendbtn->setFlat(true);

        horizontalLayout_2->addWidget(sendbtn);


        verticalLayout_4->addWidget(widget_4);


        verticalLayout_6->addWidget(frametextedit);


        verticalLayout_5->addWidget(editPanel);

        menupanel = new QWidget(widget_8);
        menupanel->setObjectName(QStringLiteral("menupanel"));
        menupanel->setMinimumSize(QSize(0, 48));
        menupanel->setMaximumSize(QSize(16777215, 48));
        horizontalLayout = new QHBoxLayout(menupanel);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        robotMenu = new QWidget(menupanel);
        robotMenu->setObjectName(QStringLiteral("robotMenu"));
        robotMenuHlayout = new QHBoxLayout(robotMenu);
        robotMenuHlayout->setSpacing(1);
        robotMenuHlayout->setContentsMargins(11, 11, 11, 11);
        robotMenuHlayout->setObjectName(QStringLiteral("robotMenuHlayout"));
        robotMenuHlayout->setContentsMargins(1, 1, 1, 1);

        horizontalLayout->addWidget(robotMenu);

        up = new QPushButton(menupanel);
        up->setObjectName(QStringLiteral("up"));
        up->setMinimumSize(QSize(46, 46));
        up->setMaximumSize(QSize(46, 46));
        up->setFlat(true);

        horizontalLayout->addWidget(up);


        verticalLayout_5->addWidget(menupanel);


        verticalLayout_2->addWidget(widget_8);


        verticalLayout->addWidget(wb);


        retranslateUi(MenuRobotDialog);

        QMetaObject::connectSlotsByName(MenuRobotDialog);
    } // setupUi

    void retranslateUi(QWidget *MenuRobotDialog)
    {
        MenuRobotDialog->setWindowTitle(QApplication::translate("MenuRobotDialog", "MenuRobotDialog", 0));
        headericon->setText(QString());
        name->setText(QString());
        noticy->setText(QString());
        btnfilter->setText(QString());
        dealing->setText(QApplication::translate("MenuRobotDialog", "<html><head/><body><p>\345\244\232\344\275\215\345\257\274\346\270\270\345\220\214\346\227\266\346\212\242\347\255\224<br>\347\255\233\351\200\211\344\270\255...</p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        down->setToolTip(QApplication::translate("MenuRobotDialog", "\350\277\234\347\250\213\346\266\210\346\201\257\346\220\234\347\264\242", 0));
#endif // QT_NO_TOOLTIP
        down->setText(QString());
        sendbtn->setText(QApplication::translate("MenuRobotDialog", "\345\217\221\351\200\201(S)", 0));
        up->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MenuRobotDialog: public Ui_MenuRobotDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUROBOTDIALOG_H

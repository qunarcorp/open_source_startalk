/********************************************************************************
** Form generated from reading UI file 'GroupChatDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPCHATDIALOG_H
#define UI_GROUPCHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TextEdit.h"
#include "chattoolbar.h"
#include "draggablewebview.h"
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_GroupChatDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *translatebg;
    QVBoxLayout *verticalLayout_2;
    QWidget *chatbar;
    QHBoxLayout *horizontalLayout_13;
    QWidget *titleview;
    QHBoxLayout *horizontalLayout_8;
    StaticLabel *headerimage;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *name;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *noticy;
    QSpacerItem *horizontalSpacer_6;
    QWidget *functions;
    QVBoxLayout *verticalLayout_10;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *sendmail;
    QPushButton *leaveButton;
    QPushButton *addGroupItem;
    QSpacerItem *verticalSpacer_2;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *leftPanel;
    QVBoxLayout *verticalLayout_4;
    QWidget *webviewPanel;
    QPushButton *externBtn;
    QWidget *externWidget;
    DraggableWebView *webView;
    QWidget *spider_0;
    QWidget *widget_tool;
    QHBoxLayout *horizontalLayout_4;
    QWidget *toolbar2;
    QHBoxLayout *horizontalLayout_10;
    ChatToolBar *toolbar;
    QWidget *borderinput;
    QHBoxLayout *horizontalLayout_2;
    QWidget *frametextedit;
    QVBoxLayout *verticalLayout_5;
    TextEdit *textEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *productbtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *sendbtn;
    QWidget *rightPanel;
    QVBoxLayout *verticalLayout_8;
    QWidget *groupfilepanel;
    QVBoxLayout *verticalLayout_7;
    QWidget *grouptitlepanel;
    QHBoxLayout *horizontalLayout_7;
    QLabel *groupfiletitle;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnMore;
    QStackedWidget *groupfilestackview;
    QWidget *emptypage;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label;
    QWidget *listpage;
    QVBoxLayout *groupfilelayout;
    QSpacerItem *verticalSpacer;
    QWidget *groupLstPanel;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout_12;
    QLabel *groupListTitle;
    QPushButton *pbRefresh;
    QVBoxLayout *verticalLayout_9;
    QListView *listView;

    void setupUi(QWidget *GroupChatDialog)
    {
        if (GroupChatDialog->objectName().isEmpty())
            GroupChatDialog->setObjectName(QStringLiteral("GroupChatDialog"));
        GroupChatDialog->resize(797, 726);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GroupChatDialog->sizePolicy().hasHeightForWidth());
        GroupChatDialog->setSizePolicy(sizePolicy);
        GroupChatDialog->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(GroupChatDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        translatebg = new QWidget(GroupChatDialog);
        translatebg->setObjectName(QStringLiteral("translatebg"));
        translatebg->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(translatebg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        chatbar = new QWidget(translatebg);
        chatbar->setObjectName(QStringLiteral("chatbar"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(chatbar->sizePolicy().hasHeightForWidth());
        chatbar->setSizePolicy(sizePolicy1);
        chatbar->setMinimumSize(QSize(0, 60));
        chatbar->setMaximumSize(QSize(16777215, 60));
        chatbar->setStyleSheet(QStringLiteral(""));
        horizontalLayout_13 = new QHBoxLayout(chatbar);
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 130, 0);
        titleview = new QWidget(chatbar);
        titleview->setObjectName(QStringLiteral("titleview"));
        titleview->setMinimumSize(QSize(0, 60));
        titleview->setMaximumSize(QSize(16777215, 60));
        titleview->setStyleSheet(QStringLiteral(""));
        horizontalLayout_8 = new QHBoxLayout(titleview);
        horizontalLayout_8->setSpacing(10);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(8, 5, 0, 5);
        headerimage = new StaticLabel(titleview);
        headerimage->setObjectName(QStringLiteral("headerimage"));
        headerimage->setMinimumSize(QSize(50, 50));
        headerimage->setMaximumSize(QSize(50, 50));
        headerimage->setProperty("flat", QVariant(false));

        horizontalLayout_8->addWidget(headerimage);

        widget_4 = new QWidget(titleview);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        name = new QLabel(widget_6);
        name->setObjectName(QStringLiteral("name"));
        name->setMinimumSize(QSize(0, 25));
        name->setStyleSheet(QStringLiteral("font: bold 14px;"));
        name->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_6->addWidget(name);

        horizontalSpacer_5 = new QSpacerItem(20, 22, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        verticalLayout_3->addWidget(widget_6);

        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(0, 25));
        widget_5->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_9 = new QHBoxLayout(widget_5);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 5, 0, 0);
        noticy = new QLabel(widget_5);
        noticy->setObjectName(QStringLiteral("noticy"));
        sizePolicy1.setHeightForWidth(noticy->sizePolicy().hasHeightForWidth());
        noticy->setSizePolicy(sizePolicy1);
        noticy->setMinimumSize(QSize(0, 25));
        noticy->setMaximumSize(QSize(16777215, 25));
        noticy->setStyleSheet(QStringLiteral(""));
        noticy->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        noticy->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        noticy->setProperty("dragEnabled", QVariant(false));
        noticy->setProperty("readOnly", QVariant(false));

        horizontalLayout_9->addWidget(noticy);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);


        verticalLayout_3->addWidget(widget_5);


        horizontalLayout_8->addWidget(widget_4);


        horizontalLayout_13->addWidget(titleview);

        functions = new QWidget(chatbar);
        functions->setObjectName(QStringLiteral("functions"));
        functions->setMinimumSize(QSize(150, 60));
        functions->setMaximumSize(QSize(150, 60));
        functions->setStyleSheet(QStringLiteral(""));
        verticalLayout_10 = new QVBoxLayout(functions);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 2, 0, 0);
        widget_2 = new QWidget(functions);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(150, 27));
        widget_2->setMaximumSize(QSize(150, 27));
        horizontalLayout_5 = new QHBoxLayout(widget_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(48, 6, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        sendmail = new QPushButton(widget_2);
        sendmail->setObjectName(QStringLiteral("sendmail"));
        sendmail->setMinimumSize(QSize(27, 27));
        sendmail->setMaximumSize(QSize(27, 27));
        sendmail->setIconSize(QSize(27, 27));
        sendmail->setFlat(true);

        horizontalLayout_5->addWidget(sendmail);

        leaveButton = new QPushButton(widget_2);
        leaveButton->setObjectName(QStringLiteral("leaveButton"));
        leaveButton->setMinimumSize(QSize(27, 27));
        leaveButton->setMaximumSize(QSize(27, 27));
        leaveButton->setIconSize(QSize(27, 27));
        leaveButton->setFlat(true);

        horizontalLayout_5->addWidget(leaveButton);

        addGroupItem = new QPushButton(widget_2);
        addGroupItem->setObjectName(QStringLiteral("addGroupItem"));
        addGroupItem->setMinimumSize(QSize(27, 27));
        addGroupItem->setMaximumSize(QSize(27, 27));
        addGroupItem->setIconSize(QSize(27, 27));
        addGroupItem->setFlat(true);

        horizontalLayout_5->addWidget(addGroupItem);


        verticalLayout_10->addWidget(widget_2);

        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_2);


        horizontalLayout_13->addWidget(functions);


        verticalLayout_2->addWidget(chatbar);

        horizontalWidget = new QWidget(translatebg);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        sizePolicy.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy);
        horizontalWidget->setMinimumSize(QSize(0, 0));
        horizontalWidget->setMaximumSize(QSize(16777215, 16777215));
        horizontalWidget->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        leftPanel = new QWidget(horizontalWidget);
        leftPanel->setObjectName(QStringLiteral("leftPanel"));
        sizePolicy.setHeightForWidth(leftPanel->sizePolicy().hasHeightForWidth());
        leftPanel->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(leftPanel);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        webviewPanel = new QWidget(leftPanel);
        webviewPanel->setObjectName(QStringLiteral("webviewPanel"));
        externBtn = new QPushButton(webviewPanel);
        externBtn->setObjectName(QStringLiteral("externBtn"));
        externBtn->setGeometry(QRect(580, 32, 20, 411));
        externBtn->setMinimumSize(QSize(20, 0));
        externBtn->setMaximumSize(QSize(20, 16777215));
        externWidget = new QWidget(webviewPanel);
        externWidget->setObjectName(QStringLiteral("externWidget"));
        externWidget->setGeometry(QRect(550, 310, 3, 80));
        externWidget->setMinimumSize(QSize(3, 0));
        externWidget->setMaximumSize(QSize(3, 16777215));
        webView = new DraggableWebView(webviewPanel);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setGeometry(QRect(280, 190, 120, 80));

        verticalLayout_4->addWidget(webviewPanel);

        spider_0 = new QWidget(leftPanel);
        spider_0->setObjectName(QStringLiteral("spider_0"));
        spider_0->setMinimumSize(QSize(0, 1));
        spider_0->setMaximumSize(QSize(16777215, 1));
        spider_0->setStyleSheet(QStringLiteral(""));

        verticalLayout_4->addWidget(spider_0);

        widget_tool = new QWidget(leftPanel);
        widget_tool->setObjectName(QStringLiteral("widget_tool"));
        sizePolicy1.setHeightForWidth(widget_tool->sizePolicy().hasHeightForWidth());
        widget_tool->setSizePolicy(sizePolicy1);
        widget_tool->setMinimumSize(QSize(0, 32));
        widget_tool->setMaximumSize(QSize(16777215, 32));
        widget_tool->setAcceptDrops(false);
        widget_tool->setStyleSheet(QStringLiteral(""));
        horizontalLayout_4 = new QHBoxLayout(widget_tool);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        toolbar2 = new QWidget(widget_tool);
        toolbar2->setObjectName(QStringLiteral("toolbar2"));
        toolbar2->setStyleSheet(QStringLiteral(""));
        horizontalLayout_10 = new QHBoxLayout(toolbar2);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        toolbar = new ChatToolBar(toolbar2);
        toolbar->setObjectName(QStringLiteral("toolbar"));

        horizontalLayout_10->addWidget(toolbar);


        horizontalLayout_4->addWidget(toolbar2);


        verticalLayout_4->addWidget(widget_tool);

        borderinput = new QWidget(leftPanel);
        borderinput->setObjectName(QStringLiteral("borderinput"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(borderinput->sizePolicy().hasHeightForWidth());
        borderinput->setSizePolicy(sizePolicy2);
        borderinput->setMinimumSize(QSize(100, 0));
        borderinput->setMaximumSize(QSize(16777215, 136));
        borderinput->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(borderinput);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        frametextedit = new QWidget(borderinput);
        frametextedit->setObjectName(QStringLiteral("frametextedit"));
        frametextedit->setMaximumSize(QSize(16777215, 16777215));
        frametextedit->setStyleSheet(QStringLiteral(""));
        verticalLayout_5 = new QVBoxLayout(frametextedit);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        textEdit = new TextEdit(frametextedit);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy3);
        textEdit->setMinimumSize(QSize(0, 100));
        textEdit->setMaximumSize(QSize(16777215, 100));
        textEdit->setAutoFillBackground(false);
        textEdit->setStyleSheet(QStringLiteral(""));
        textEdit->setFrameShape(QFrame::NoFrame);

        verticalLayout_5->addWidget(textEdit);

        widget = new QWidget(frametextedit);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(16777215, 36));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(18, 0, 10, 10);
        productbtn = new QPushButton(widget);
        productbtn->setObjectName(QStringLiteral("productbtn"));
        productbtn->setMinimumSize(QSize(68, 26));
        productbtn->setMaximumSize(QSize(68, 26));
        productbtn->setFlat(true);

        horizontalLayout_3->addWidget(productbtn);

        horizontalSpacer_2 = new QSpacerItem(566, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        sendbtn = new QPushButton(widget);
        sendbtn->setObjectName(QStringLiteral("sendbtn"));
        sendbtn->setMinimumSize(QSize(68, 26));
        sendbtn->setMaximumSize(QSize(68, 26));
        sendbtn->setFlat(true);

        horizontalLayout_3->addWidget(sendbtn);


        verticalLayout_5->addWidget(widget);


        horizontalLayout_2->addWidget(frametextedit);


        verticalLayout_4->addWidget(borderinput);


        horizontalLayout->addWidget(leftPanel);

        rightPanel = new QWidget(horizontalWidget);
        rightPanel->setObjectName(QStringLiteral("rightPanel"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(rightPanel->sizePolicy().hasHeightForWidth());
        rightPanel->setSizePolicy(sizePolicy4);
        rightPanel->setMinimumSize(QSize(150, 0));
        rightPanel->setMaximumSize(QSize(150, 16777215));
        verticalLayout_8 = new QVBoxLayout(rightPanel);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(1, 0, 0, 0);
        groupfilepanel = new QWidget(rightPanel);
        groupfilepanel->setObjectName(QStringLiteral("groupfilepanel"));
        groupfilepanel->setMinimumSize(QSize(0, 119));
        groupfilepanel->setMaximumSize(QSize(16777215, 119));
        verticalLayout_7 = new QVBoxLayout(groupfilepanel);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        grouptitlepanel = new QWidget(groupfilepanel);
        grouptitlepanel->setObjectName(QStringLiteral("grouptitlepanel"));
        grouptitlepanel->setMinimumSize(QSize(0, 20));
        grouptitlepanel->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_7 = new QHBoxLayout(grouptitlepanel);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 5, 0);
        groupfiletitle = new QLabel(grouptitlepanel);
        groupfiletitle->setObjectName(QStringLiteral("groupfiletitle"));
        groupfiletitle->setMinimumSize(QSize(0, 20));
        groupfiletitle->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_7->addWidget(groupfiletitle);

        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        btnMore = new QPushButton(grouptitlepanel);
        btnMore->setObjectName(QStringLiteral("btnMore"));
        btnMore->setMinimumSize(QSize(40, 20));
        btnMore->setMaximumSize(QSize(40, 20));
        btnMore->setSizeIncrement(QSize(0, 0));
        btnMore->setFlat(true);

        horizontalLayout_7->addWidget(btnMore);


        verticalLayout_7->addWidget(grouptitlepanel);

        groupfilestackview = new QStackedWidget(groupfilepanel);
        groupfilestackview->setObjectName(QStringLiteral("groupfilestackview"));
        emptypage = new QWidget();
        emptypage->setObjectName(QStringLiteral("emptypage"));
        horizontalLayout_11 = new QHBoxLayout(emptypage);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label = new QLabel(emptypage);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(80, 80));
        label->setMaximumSize(QSize(80, 80));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Images/icon/commen/empty.png")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label);

        groupfilestackview->addWidget(emptypage);
        listpage = new QWidget();
        listpage->setObjectName(QStringLiteral("listpage"));
        groupfilelayout = new QVBoxLayout(listpage);
        groupfilelayout->setSpacing(0);
        groupfilelayout->setContentsMargins(11, 11, 11, 11);
        groupfilelayout->setObjectName(QStringLiteral("groupfilelayout"));
        groupfilelayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        groupfilelayout->addItem(verticalSpacer);

        groupfilestackview->addWidget(listpage);

        verticalLayout_7->addWidget(groupfilestackview);


        verticalLayout_8->addWidget(groupfilepanel);

        groupLstPanel = new QWidget(rightPanel);
        groupLstPanel->setObjectName(QStringLiteral("groupLstPanel"));
        groupLstPanel->setStyleSheet(QStringLiteral(""));
        verticalLayout_6 = new QVBoxLayout(groupLstPanel);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget_title = new QWidget(groupLstPanel);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        widget_title->setMinimumSize(QSize(0, 20));
        widget_title->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_12 = new QHBoxLayout(widget_title);
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 4, 0);
        groupListTitle = new QLabel(widget_title);
        groupListTitle->setObjectName(QStringLiteral("groupListTitle"));
        sizePolicy1.setHeightForWidth(groupListTitle->sizePolicy().hasHeightForWidth());
        groupListTitle->setSizePolicy(sizePolicy1);
        groupListTitle->setMinimumSize(QSize(0, 20));
        groupListTitle->setMaximumSize(QSize(16777215, 20));
        groupListTitle->setMargin(0);

        horizontalLayout_12->addWidget(groupListTitle);

        pbRefresh = new QPushButton(widget_title);
        pbRefresh->setObjectName(QStringLiteral("pbRefresh"));
        pbRefresh->setMinimumSize(QSize(0, 20));
        pbRefresh->setMaximumSize(QSize(40, 20));
        pbRefresh->setFlat(true);

        horizontalLayout_12->addWidget(pbRefresh);


        verticalLayout_6->addWidget(widget_title);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        listView = new QListView(groupLstPanel);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_9->addWidget(listView);


        verticalLayout_6->addLayout(verticalLayout_9);


        verticalLayout_8->addWidget(groupLstPanel);


        horizontalLayout->addWidget(rightPanel);


        verticalLayout_2->addWidget(horizontalWidget);


        verticalLayout->addWidget(translatebg);


        retranslateUi(GroupChatDialog);

        QMetaObject::connectSlotsByName(GroupChatDialog);
    } // setupUi

    void retranslateUi(QWidget *GroupChatDialog)
    {
        GroupChatDialog->setWindowTitle(QApplication::translate("GroupChatDialog", "GroupChatDialog", 0));
        name->setText(QString());
        noticy->setText(QString());
#ifndef QT_NO_TOOLTIP
        sendmail->setToolTip(QApplication::translate("GroupChatDialog", "\345\217\221\351\200\201\351\202\256\344\273\266", 0));
#endif // QT_NO_TOOLTIP
        sendmail->setText(QString());
#ifndef QT_NO_TOOLTIP
        leaveButton->setToolTip(QApplication::translate("GroupChatDialog", "\351\200\200\345\207\272\347\276\244", 0));
#endif // QT_NO_TOOLTIP
        leaveButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        addGroupItem->setToolTip(QApplication::translate("GroupChatDialog", "\351\202\200\350\257\267\346\210\220\345\221\230", 0));
#endif // QT_NO_TOOLTIP
        addGroupItem->setText(QString());
        externBtn->setText(QString());
        productbtn->setText(QApplication::translate("GroupChatDialog", "\344\272\247\345\223\201\346\216\250\350\215\220", 0));
        sendbtn->setText(QApplication::translate("GroupChatDialog", "\345\217\221\351\200\201(S)", 0));
        groupfiletitle->setText(QApplication::translate("GroupChatDialog", "\347\276\244\346\226\207\344\273\266", 0));
        btnMore->setText(QApplication::translate("GroupChatDialog", "\346\233\264\345\244\232>", 0));
        label->setText(QString());
        groupListTitle->setText(QString());
        pbRefresh->setText(QApplication::translate("GroupChatDialog", "\345\210\267\346\226\260", 0));
    } // retranslateUi

};

namespace Ui {
    class GroupChatDialog: public Ui_GroupChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPCHATDIALOG_H

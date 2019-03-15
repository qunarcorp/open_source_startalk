/********************************************************************************
** Form generated from reading UI file 'ChatDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDIALOG_H
#define UI_CHATDIALOG_H

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
#include "mylabel.h"
#include "rightextendpanel.h"

QT_BEGIN_NAMESPACE

class Ui_ChatDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wb;
    QVBoxLayout *verticalLayout_9;
    QWidget *chattitle;
    QWidget *infopannel;
    QHBoxLayout *horizontalLayout_7;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_3;
    StaticLabel *headerimage;
    QWidget *undbclicked;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_Icon;
    QVBoxLayout *verticalLayout_11;
    QLabel *platformIcon;
    QLabel *name;
    QLabel *status;
    QLabel *typing;
    QSpacerItem *horizontalSpacer_2;
    QLabel *leJid;
    QLabel *leNotice;
    QWidget *funtionpanel;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnfilter;
    QPushButton *sendmail;
    QPushButton *pushButton_muc;
    QPushButton *trace;
    QPushButton *showProduct;
    QWidget *resourceinfo;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_resource;
    QWidget *body;
    QHBoxLayout *horizontalLayout_6;
    QWidget *leftwidget;
    QVBoxLayout *verticalLayout_8;
    QWidget *webviewFrame;
    DraggableWebView *webView;
    QWidget *dealingpanel;
    QHBoxLayout *horizontalLayout_13;
    QLabel *dealing;
    QWidget *spider_0;
    QWidget *border;
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
    QPushButton *productbtn;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *sendbtn;
    QWidget *menupanel;
    QHBoxLayout *horizontalLayout;
    QWidget *robotMenu;
    QHBoxLayout *robotMenuHlayout;
    QPushButton *up;
    RightExtendPanel *rightwidget;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *ChatDialog)
    {
        if (ChatDialog->objectName().isEmpty())
            ChatDialog->setObjectName(QStringLiteral("ChatDialog"));
        ChatDialog->resize(682, 520);
        ChatDialog->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(ChatDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wb = new QWidget(ChatDialog);
        wb->setObjectName(QStringLiteral("wb"));
        wb->setStyleSheet(QStringLiteral(""));
        verticalLayout_9 = new QVBoxLayout(wb);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 2);
        chattitle = new QWidget(wb);
        chattitle->setObjectName(QStringLiteral("chattitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chattitle->sizePolicy().hasHeightForWidth());
        chattitle->setSizePolicy(sizePolicy);
        chattitle->setMinimumSize(QSize(0, 60));
        chattitle->setMaximumSize(QSize(16777215, 60));
        chattitle->setStyleSheet(QStringLiteral(""));
        infopannel = new QWidget(chattitle);
        infopannel->setObjectName(QStringLiteral("infopannel"));
        infopannel->setGeometry(QRect(0, 0, 401, 60));
        infopannel->setMinimumSize(QSize(0, 60));
        infopannel->setMaximumSize(QSize(16777215, 60));
        infopannel->setStyleSheet(QStringLiteral(""));
        horizontalLayout_7 = new QHBoxLayout(infopannel);
        horizontalLayout_7->setSpacing(10);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(8, 0, 200, 0);
        widget_7 = new QWidget(infopannel);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setMinimumSize(QSize(50, 50));
        widget_7->setMaximumSize(QSize(50, 50));
        verticalLayout_3 = new QVBoxLayout(widget_7);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        headerimage = new StaticLabel(widget_7);
        headerimage->setObjectName(QStringLiteral("headerimage"));
        headerimage->setMinimumSize(QSize(50, 50));
        headerimage->setMaximumSize(QSize(50, 50));
        headerimage->setProperty("flat", QVariant(true));

        verticalLayout_3->addWidget(headerimage);


        horizontalLayout_7->addWidget(widget_7);

        undbclicked = new QWidget(infopannel);
        undbclicked->setObjectName(QStringLiteral("undbclicked"));
        verticalLayout_7 = new QVBoxLayout(undbclicked);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget_6 = new QWidget(undbclicked);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(6, 24));
        widget_6->setMaximumSize(QSize(16777215, 24));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_Icon = new QWidget(widget_6);
        widget_Icon->setObjectName(QStringLiteral("widget_Icon"));
        widget_Icon->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_11 = new QVBoxLayout(widget_Icon);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 8, 0, 0);
        platformIcon = new QLabel(widget_Icon);
        platformIcon->setObjectName(QStringLiteral("platformIcon"));
        platformIcon->setMinimumSize(QSize(0, 0));
        platformIcon->setMaximumSize(QSize(16777215, 15));
        platformIcon->setStyleSheet(QStringLiteral(""));
        platformIcon->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        platformIcon->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_11->addWidget(platformIcon);


        horizontalLayout_4->addWidget(widget_Icon);

        name = new QLabel(widget_6);
        name->setObjectName(QStringLiteral("name"));
        name->setMinimumSize(QSize(0, 24));
        name->setMaximumSize(QSize(16777215, 24));
        name->setStyleSheet(QStringLiteral("font: bold 14px;"));
        name->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        name->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_4->addWidget(name);

        status = new QLabel(widget_6);
        status->setObjectName(QStringLiteral("status"));
        status->setMinimumSize(QSize(0, 0));
        status->setMaximumSize(QSize(16777215, 16777215));
        status->setStyleSheet(QStringLiteral("font: 11px;"));
        status->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_4->addWidget(status);

        typing = new QLabel(widget_6);
        typing->setObjectName(QStringLiteral("typing"));
        typing->setMinimumSize(QSize(0, 24));
        typing->setMaximumSize(QSize(16777215, 24));
        typing->setStyleSheet(QStringLiteral("font: 11px;"));
        typing->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_4->addWidget(typing);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_7->addWidget(widget_6);

        leJid = new QLabel(undbclicked);
        leJid->setObjectName(QStringLiteral("leJid"));
        leJid->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leJid->sizePolicy().hasHeightForWidth());
        leJid->setSizePolicy(sizePolicy1);
        leJid->setMaximumSize(QSize(16777215, 18));
        leJid->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        leJid->setProperty("readOnly", QVariant(true));

        verticalLayout_7->addWidget(leJid);

        leNotice = new QLabel(undbclicked);
        leNotice->setObjectName(QStringLiteral("leNotice"));
        leNotice->setEnabled(true);
        leNotice->setMaximumSize(QSize(16777215, 18));
        leNotice->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        leNotice->setProperty("readOnly", QVariant(true));

        verticalLayout_7->addWidget(leNotice);


        horizontalLayout_7->addWidget(undbclicked);

        funtionpanel = new QWidget(chattitle);
        funtionpanel->setObjectName(QStringLiteral("funtionpanel"));
        funtionpanel->setGeometry(QRect(539, 10, 120, 27));
        funtionpanel->setMinimumSize(QSize(120, 27));
        funtionpanel->setMaximumSize(QSize(120, 27));
        horizontalLayout_5 = new QHBoxLayout(funtionpanel);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(15, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        btnfilter = new QPushButton(funtionpanel);
        btnfilter->setObjectName(QStringLiteral("btnfilter"));
        btnfilter->setFlat(true);

        horizontalLayout_5->addWidget(btnfilter);

        sendmail = new QPushButton(funtionpanel);
        sendmail->setObjectName(QStringLiteral("sendmail"));
        sendmail->setMinimumSize(QSize(27, 27));
        sendmail->setMaximumSize(QSize(27, 27));
        sendmail->setIconSize(QSize(27, 27));
        sendmail->setFlat(true);

        horizontalLayout_5->addWidget(sendmail);

        pushButton_muc = new QPushButton(funtionpanel);
        pushButton_muc->setObjectName(QStringLiteral("pushButton_muc"));
        pushButton_muc->setMinimumSize(QSize(27, 27));
        pushButton_muc->setMaximumSize(QSize(27, 27));
        pushButton_muc->setStyleSheet(QStringLiteral(""));
        pushButton_muc->setIconSize(QSize(27, 27));
        pushButton_muc->setFlat(true);

        horizontalLayout_5->addWidget(pushButton_muc);

        trace = new QPushButton(funtionpanel);
        trace->setObjectName(QStringLiteral("trace"));
        trace->setMinimumSize(QSize(27, 27));
        trace->setMaximumSize(QSize(27, 27));
        trace->setIconSize(QSize(27, 27));
        trace->setFlat(true);

        horizontalLayout_5->addWidget(trace);

        showProduct = new QPushButton(funtionpanel);
        showProduct->setObjectName(QStringLiteral("showProduct"));
        showProduct->setMinimumSize(QSize(27, 27));
        showProduct->setMaximumSize(QSize(27, 27));
        showProduct->setIconSize(QSize(27, 27));
        showProduct->setCheckable(true);
        showProduct->setFlat(true);

        horizontalLayout_5->addWidget(showProduct);

        resourceinfo = new QWidget(chattitle);
        resourceinfo->setObjectName(QStringLiteral("resourceinfo"));
        resourceinfo->setGeometry(QRect(450, 20, 140, 27));
        resourceinfo->setMinimumSize(QSize(140, 27));
        resourceinfo->setMaximumSize(QSize(16777215, 27));
        resourceinfo->setStyleSheet(QStringLiteral(""));
        verticalLayout_10 = new QVBoxLayout(resourceinfo);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_resource = new QLabel(resourceinfo);
        label_resource->setObjectName(QStringLiteral("label_resource"));
        label_resource->setMinimumSize(QSize(140, 27));
        label_resource->setMaximumSize(QSize(16777215, 27));

        verticalLayout_10->addWidget(label_resource);


        verticalLayout_9->addWidget(chattitle);

        body = new QWidget(wb);
        body->setObjectName(QStringLiteral("body"));
        body->setMinimumSize(QSize(0, 0));
        horizontalLayout_6 = new QHBoxLayout(body);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        leftwidget = new QWidget(body);
        leftwidget->setObjectName(QStringLiteral("leftwidget"));
        leftwidget->setMinimumSize(QSize(0, 0));
        leftwidget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_8 = new QVBoxLayout(leftwidget);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        webviewFrame = new QWidget(leftwidget);
        webviewFrame->setObjectName(QStringLiteral("webviewFrame"));
        webView = new DraggableWebView(webviewFrame);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setGeometry(QRect(0, 0, 362, 232));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
        webView->setSizePolicy(sizePolicy2);
        webView->setMaximumSize(QSize(16777215, 16777215));
        dealingpanel = new QWidget(webviewFrame);
        dealingpanel->setObjectName(QStringLiteral("dealingpanel"));
        dealingpanel->setGeometry(QRect(10, 10, 342, 212));
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


        verticalLayout_8->addWidget(webviewFrame);

        spider_0 = new QWidget(leftwidget);
        spider_0->setObjectName(QStringLiteral("spider_0"));
        spider_0->setMinimumSize(QSize(0, 1));
        spider_0->setMaximumSize(QSize(16777215, 1));
        spider_0->setStyleSheet(QStringLiteral(""));

        verticalLayout_8->addWidget(spider_0);

        border = new QWidget(leftwidget);
        border->setObjectName(QStringLiteral("border"));
        border->setMinimumSize(QSize(0, 0));
        border->setStyleSheet(QStringLiteral(""));
        verticalLayout_5 = new QVBoxLayout(border);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        editPanel = new QWidget(border);
        editPanel->setObjectName(QStringLiteral("editPanel"));
        sizePolicy.setHeightForWidth(editPanel->sizePolicy().hasHeightForWidth());
        editPanel->setSizePolicy(sizePolicy);
        editPanel->setMinimumSize(QSize(0, 0));
        editPanel->setMaximumSize(QSize(16777215, 16777215));
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
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        toolbar = new ChatToolBar(toolbar_1);
        toolbar->setObjectName(QStringLiteral("toolbar"));
        toolbar->setMinimumSize(QSize(0, 32));

        horizontalLayout_3->addWidget(toolbar);

        down = new QPushButton(toolbar_1);
        down->setObjectName(QStringLiteral("down"));
        down->setMinimumSize(QSize(0, 30));
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
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
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
        productbtn = new QPushButton(widget_4);
        productbtn->setObjectName(QStringLiteral("productbtn"));
        productbtn->setFlat(true);

        horizontalLayout_2->addWidget(productbtn);

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

        menupanel = new QWidget(border);
        menupanel->setObjectName(QStringLiteral("menupanel"));
        menupanel->setMinimumSize(QSize(0, 54));
        menupanel->setMaximumSize(QSize(16777215, 53));
        horizontalLayout = new QHBoxLayout(menupanel);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        robotMenu = new QWidget(menupanel);
        robotMenu->setObjectName(QStringLiteral("robotMenu"));
        robotMenu->setMinimumSize(QSize(0, 48));
        robotMenu->setMaximumSize(QSize(16777215, 48));
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


        verticalLayout_8->addWidget(border);


        horizontalLayout_6->addWidget(leftwidget);

        rightwidget = new RightExtendPanel(body);
        rightwidget->setObjectName(QStringLiteral("rightwidget"));
        rightwidget->setMinimumSize(QSize(320, 0));
        rightwidget->setMaximumSize(QSize(320, 16777215));
        verticalLayout_2 = new QVBoxLayout(rightwidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_6->addWidget(rightwidget);


        verticalLayout_9->addWidget(body);


        verticalLayout->addWidget(wb);


        retranslateUi(ChatDialog);

        QMetaObject::connectSlotsByName(ChatDialog);
    } // setupUi

    void retranslateUi(QWidget *ChatDialog)
    {
        ChatDialog->setWindowTitle(QApplication::translate("ChatDialog", "ChatDialog", 0));
        platformIcon->setText(QString());
        name->setText(QString());
        status->setText(QString());
        typing->setText(QApplication::translate("ChatDialog", "\346\255\243\345\234\250\350\276\223\345\205\245...", 0));
        leJid->setText(QString());
        leNotice->setText(QString());
        btnfilter->setText(QString());
#ifndef QT_NO_TOOLTIP
        sendmail->setToolTip(QApplication::translate("ChatDialog", "\345\217\221\351\200\201\351\202\256\344\273\266", 0));
#endif // QT_NO_TOOLTIP
        sendmail->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_muc->setToolTip(QApplication::translate("ChatDialog", "\345\210\233\345\273\272\347\276\244", 0));
#endif // QT_NO_TOOLTIP
        pushButton_muc->setText(QString());
#ifndef QT_NO_TOOLTIP
        trace->setToolTip(QApplication::translate("ChatDialog", "\346\237\245\347\234\213\347\273\204\347\273\207\346\236\266\346\236\204", 0));
#endif // QT_NO_TOOLTIP
        trace->setText(QString());
#ifndef QT_NO_TOOLTIP
        showProduct->setToolTip(QApplication::translate("ChatDialog", "\346\211\223\345\274\200\346\210\226\345\205\263\351\227\255\346\211\200\346\234\211\347\252\227\345\217\243\347\232\204\346\211\251\345\261\225\344\277\241\346\201\257\351\235\242\346\235\277", 0));
#endif // QT_NO_TOOLTIP
        showProduct->setText(QString());
        label_resource->setText(QString());
        dealing->setText(QApplication::translate("ChatDialog", "<html><head/><body><p>\345\244\232\344\275\215\345\257\274\346\270\270\345\220\214\346\227\266\346\212\242\347\255\224<br>\347\255\233\351\200\211\344\270\255...</p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        down->setToolTip(QApplication::translate("ChatDialog", "\350\277\234\347\250\213\346\266\210\346\201\257\346\220\234\347\264\242", 0));
#endif // QT_NO_TOOLTIP
        down->setText(QString());
        productbtn->setText(QApplication::translate("ChatDialog", "\344\272\247\345\223\201\346\216\250\350\215\220", 0));
        sendbtn->setText(QApplication::translate("ChatDialog", "\345\217\221\351\200\201(S)", 0));
        up->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatDialog: public Ui_ChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'MultiDialogContainer.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIDIALOGCONTAINER_H
#define UI_MULTIDIALOGCONTAINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <statictext.h>
#include "LineEdit.h"
#include "advtoolbar.h"
#include "slidingstackedwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MultiDialogContainer
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *tbk1;
    QWidget *tbk2;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_5;
    QSplitter *splitter;
    QWidget *spitter_left;
    QHBoxLayout *horizontalLayout_6;
    QWidget *rightpanel;
    QVBoxLayout *verticalLayout_3;
    QWidget *lineEditPanel;
    QSlider *loadmsgprogress;
    QWidget *linesubpanel;
    QHBoxLayout *horizontalLayout_7;
    LineEdit *lineEdit;
    QPushButton *createnewgroup;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QStackedWidget *levelStacked;
    QWidget *sessionListPanel;
    QWidget *menupanel;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_17;
    QHBoxLayout *horizontalLayout_4;
    QLabel *couversationCount;
    QLabel *label_4;
    QPushButton *loadUnread;
    QPushButton *loadAll;
    QWidget *advedSessionPanel;
    QVBoxLayout *verticalLayout_6;
    QWidget *advtool;
    QHBoxLayout *horizontalLayout_22;
    AdvToolbar *widget_18;
    SlidingStackedWidget *extendListStacked;
    QWidget *combinationPanel;
    QVBoxLayout *verticalLayout_4;
    SlidingStackedWidget *combinationstacked;
    QWidget *spitter_right;
    QWidget *custemwidgets;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *custemstack;
    QWidget *emptysessionpage;
    QWidget *staffgroup;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_2;
    StaticText *grouppath;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_3;
    StaticText *groupdata;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *openchat;
    QSpacerItem *verticalSpacer;
    QWidget *noteInfor;
    QVBoxLayout *verticalLayout_15;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_note_title;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pbtn_addNote;
    QScrollArea *scrollArea;
    QWidget *notegroup;
    QHBoxLayout *notegroupLayout;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_19;
    QVBoxLayout *verticalLayout_14;
    QWidget *widget_20;
    QVBoxLayout *verticalLayout_13;
    QWidget *widget_21;
    QVBoxLayout *verticalLayout_12;
    QLineEdit *lineEdit_2;
    QWidget *widget_22;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_title;
    QListWidget *listWidget;
    QWidget *widget_23;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_7;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pbtn_addSubNote;
    QSpacerItem *horizontalSpacer_2;
    QWidget *staffuser;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_15;
    QLabel *user_headimage;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_5;
    StaticText *user_id;
    QWidget *widget_13;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_6;
    StaticText *staffusersgroup;
    QWidget *widget_15;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_9;
    StaticText *user_name;
    QWidget *widget_16;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_email;
    StaticText *user_email;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *openchat_simple;
    QSpacerItem *verticalSpacer_2;
    QWidget *webwidgets;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *webwidgetstack;

    void setupUi(QWidget *MultiDialogContainer)
    {
        if (MultiDialogContainer->objectName().isEmpty())
            MultiDialogContainer->setObjectName(QStringLiteral("MultiDialogContainer"));
        MultiDialogContainer->resize(902, 585);
        MultiDialogContainer->setMinimumSize(QSize(0, 0));
        MultiDialogContainer->setMaximumSize(QSize(16777215, 16777215));
        MultiDialogContainer->setStyleSheet(QLatin1String("QLabel#label_note_title {font-size:16px;font-weight:bold;border:none;background:#E4E5EA;}\n"
"\n"
"QScrollArea#scrollArea\n"
"{\n"
"	border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton#pbtn_addNote\n"
"{\n"
"	border:1px solid #515151;\n"
"	image:url(:/Images/addButton.png);\n"
"	background:#9DE69D;;\n"
"}\n"
"\n"
"QPushButton#pbtn_addNote:hover\n"
"{\n"
"	background:#38C738;\n"
"}\n"
"\n"
"QWidget#widget_20\n"
"{\n"
"	background-color:#CFCFCF;\n"
"}\n"
"\n"
"QListWidget#listWidget\n"
"{\n"
"	border:none;background-color:#00000000;\n"
"}\n"
"QPushButton#pbtn_addSubNote\n"
"{\n"
"	border:1px solid #515151;\n"
"	image:url(:/Images/addButton.png);\n"
"	background:#9DE69D;;\n"
"}\n"
"\n"
"QPushButton#pbtn_addSubNote:hover\n"
"{\n"
"	background:#38C738;\n"
"}\n"
"\n"
"QWidget#widget_10\n"
"{\n"
"	border:none;\n"
"	border-top:1px solid #515151;\n"
"}\n"
"\n"
"QWidget#widget_23\n"
"{\n"
"	border:none;\n"
"	border-left:1px solid #515151;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(MultiDialogContainer);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        tbk1 = new QWidget(MultiDialogContainer);
        tbk1->setObjectName(QStringLiteral("tbk1"));
        tbk1->setStyleSheet(QLatin1String("QLabel#label_note_title {font-size:16px;font-weight:bold;border:none;background:#E4E5EA;}\n"
"\n"
"QScrollArea#scrollArea\n"
"{\n"
"	border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton#pbtn_addNote\n"
"{\n"
"	border:1 px solid #FF0000;\n"
"	image:url(:/Images/addButton.png);\n"
"}"));
        tbk2 = new QWidget(tbk1);
        tbk2->setObjectName(QStringLiteral("tbk2"));
        tbk2->setGeometry(QRect(0, 0, 841, 585));
        tbk2->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(tbk2);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 2, 0);
        widget_3 = new QWidget(tbk2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout_5 = new QVBoxLayout(widget_3);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(widget_3);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setFrameShadow(QFrame::Plain);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setOpaqueResize(true);
        splitter->setHandleWidth(1);
        splitter->setChildrenCollapsible(false);
        spitter_left = new QWidget(splitter);
        spitter_left->setObjectName(QStringLiteral("spitter_left"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spitter_left->sizePolicy().hasHeightForWidth());
        spitter_left->setSizePolicy(sizePolicy);
        spitter_left->setMinimumSize(QSize(200, 0));
        spitter_left->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_6 = new QHBoxLayout(spitter_left);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        rightpanel = new QWidget(spitter_left);
        rightpanel->setObjectName(QStringLiteral("rightpanel"));
        sizePolicy.setHeightForWidth(rightpanel->sizePolicy().hasHeightForWidth());
        rightpanel->setSizePolicy(sizePolicy);
        rightpanel->setMinimumSize(QSize(0, 0));
        rightpanel->setMaximumSize(QSize(16777215, 16777215));
        rightpanel->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(rightpanel);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 2);
        lineEditPanel = new QWidget(rightpanel);
        lineEditPanel->setObjectName(QStringLiteral("lineEditPanel"));
        lineEditPanel->setMinimumSize(QSize(0, 60));
        lineEditPanel->setMaximumSize(QSize(16777215, 60));
        lineEditPanel->setStyleSheet(QStringLiteral(""));
        loadmsgprogress = new QSlider(lineEditPanel);
        loadmsgprogress->setObjectName(QStringLiteral("loadmsgprogress"));
        loadmsgprogress->setGeometry(QRect(0, 58, 200, 2));
        loadmsgprogress->setMinimumSize(QSize(0, 2));
        loadmsgprogress->setMaximumSize(QSize(16777215, 2));
        loadmsgprogress->setOrientation(Qt::Horizontal);
        linesubpanel = new QWidget(lineEditPanel);
        linesubpanel->setObjectName(QStringLiteral("linesubpanel"));
        linesubpanel->setGeometry(QRect(0, 0, 181, 28));
        horizontalLayout_7 = new QHBoxLayout(linesubpanel);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(10, 0, 10, 0);
        lineEdit = new LineEdit(linesubpanel);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 28));
        lineEdit->setMaximumSize(QSize(16777215, 28));
        lineEdit->setStyleSheet(QStringLiteral(""));

        horizontalLayout_7->addWidget(lineEdit);

        createnewgroup = new QPushButton(linesubpanel);
        createnewgroup->setObjectName(QStringLiteral("createnewgroup"));
        createnewgroup->setMinimumSize(QSize(28, 28));
        createnewgroup->setMaximumSize(QSize(28, 28));
        createnewgroup->setStyleSheet(QStringLiteral(""));
        createnewgroup->setFlat(true);

        horizontalLayout_7->addWidget(createnewgroup);


        verticalLayout_3->addWidget(lineEditPanel);

        widget = new QWidget(rightpanel);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        levelStacked = new QStackedWidget(widget);
        levelStacked->setObjectName(QStringLiteral("levelStacked"));
        sessionListPanel = new QWidget();
        sessionListPanel->setObjectName(QStringLiteral("sessionListPanel"));
        sessionListPanel->setStyleSheet(QStringLiteral(""));
        menupanel = new QWidget(sessionListPanel);
        menupanel->setObjectName(QStringLiteral("menupanel"));
        menupanel->setGeometry(QRect(0, 510, 440, 78));
        menupanel->setMinimumSize(QSize(0, 78));
        menupanel->setMaximumSize(QSize(16777215, 78));
        menupanel->setStyleSheet(QStringLiteral(""));
        verticalLayout_7 = new QVBoxLayout(menupanel);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget_17 = new QWidget(menupanel);
        widget_17->setObjectName(QStringLiteral("widget_17"));
        widget_17->setMinimumSize(QSize(0, 14));
        widget_17->setMaximumSize(QSize(16777215, 14));
        horizontalLayout_4 = new QHBoxLayout(widget_17);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 10, 0);
        couversationCount = new QLabel(widget_17);
        couversationCount->setObjectName(QStringLiteral("couversationCount"));
        couversationCount->setMinimumSize(QSize(0, 14));
        couversationCount->setMaximumSize(QSize(16777215, 14));
        couversationCount->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(couversationCount);

        label_4 = new QLabel(widget_17);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(14, 14));
        label_4->setMaximumSize(QSize(14, 14));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/Images/Setting_Hover.png")));
        label_4->setScaledContents(true);

        horizontalLayout_4->addWidget(label_4);


        verticalLayout_7->addWidget(widget_17);

        loadUnread = new QPushButton(menupanel);
        loadUnread->setObjectName(QStringLiteral("loadUnread"));
        loadUnread->setMinimumSize(QSize(0, 32));
        loadUnread->setMaximumSize(QSize(16777215, 32));
        loadUnread->setFlat(true);

        verticalLayout_7->addWidget(loadUnread);

        loadAll = new QPushButton(menupanel);
        loadAll->setObjectName(QStringLiteral("loadAll"));
        loadAll->setMinimumSize(QSize(0, 32));
        loadAll->setMaximumSize(QSize(16777215, 32));
        loadAll->setFlat(true);

        verticalLayout_7->addWidget(loadAll);

        advedSessionPanel = new QWidget(sessionListPanel);
        advedSessionPanel->setObjectName(QStringLiteral("advedSessionPanel"));
        advedSessionPanel->setGeometry(QRect(0, 0, 28, 84));
        verticalLayout_6 = new QVBoxLayout(advedSessionPanel);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        advtool = new QWidget(advedSessionPanel);
        advtool->setObjectName(QStringLiteral("advtool"));
        advtool->setMinimumSize(QSize(0, 60));
        advtool->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_22 = new QHBoxLayout(advtool);
        horizontalLayout_22->setSpacing(0);
        horizontalLayout_22->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        widget_18 = new AdvToolbar(advtool);
        widget_18->setObjectName(QStringLiteral("widget_18"));

        horizontalLayout_22->addWidget(widget_18);


        verticalLayout_6->addWidget(advtool);

        extendListStacked = new SlidingStackedWidget(advedSessionPanel);
        extendListStacked->setObjectName(QStringLiteral("extendListStacked"));
        extendListStacked->setStyleSheet(QStringLiteral(""));

        verticalLayout_6->addWidget(extendListStacked);

        levelStacked->addWidget(sessionListPanel);
        combinationPanel = new QWidget();
        combinationPanel->setObjectName(QStringLiteral("combinationPanel"));
        verticalLayout_4 = new QVBoxLayout(combinationPanel);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        combinationstacked = new SlidingStackedWidget(combinationPanel);
        combinationstacked->setObjectName(QStringLiteral("combinationstacked"));

        verticalLayout_4->addWidget(combinationstacked);

        levelStacked->addWidget(combinationPanel);

        horizontalLayout_5->addWidget(levelStacked);


        verticalLayout_3->addWidget(widget);


        horizontalLayout_6->addWidget(rightpanel);

        splitter->addWidget(spitter_left);
        spitter_right = new QWidget(splitter);
        spitter_right->setObjectName(QStringLiteral("spitter_right"));
        spitter_right->setMinimumSize(QSize(500, 0));
        spitter_right->setStyleSheet(QStringLiteral(""));
        custemwidgets = new QWidget(spitter_right);
        custemwidgets->setObjectName(QStringLiteral("custemwidgets"));
        custemwidgets->setGeometry(QRect(0, 0, 654, 896));
        verticalLayout_2 = new QVBoxLayout(custemwidgets);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        custemstack = new QStackedWidget(custemwidgets);
        custemstack->setObjectName(QStringLiteral("custemstack"));
        custemstack->setMinimumSize(QSize(300, 1));
        emptysessionpage = new QWidget();
        emptysessionpage->setObjectName(QStringLiteral("emptysessionpage"));
        emptysessionpage->setStyleSheet(QStringLiteral(""));
        custemstack->addWidget(emptysessionpage);
        staffgroup = new QWidget();
        staffgroup->setObjectName(QStringLiteral("staffgroup"));
        staffgroup->setStyleSheet(QStringLiteral(""));
        verticalLayout_8 = new QVBoxLayout(staffgroup);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 100, 0, 0);
        widget_6 = new QWidget(staffgroup);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_11 = new QHBoxLayout(widget_6);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(-1, -1, -1, 20);
        label = new QLabel(widget_6);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(200, 200));
        label->setMaximumSize(QSize(200, 200));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Images/im_default_header.png")));
        label->setScaledContents(true);

        horizontalLayout_11->addWidget(label);


        verticalLayout_8->addWidget(widget_6);

        widget_7 = new QWidget(staffgroup);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        horizontalLayout_12 = new QHBoxLayout(widget_7);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(150, -1, -1, -1);
        label_2 = new QLabel(widget_7);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setMaximumSize(QSize(60, 16777215));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_12->addWidget(label_2);

        grouppath = new StaticText(widget_7);
        grouppath->setObjectName(QStringLiteral("grouppath"));
        grouppath->setReadOnly(true);

        horizontalLayout_12->addWidget(grouppath);


        verticalLayout_8->addWidget(widget_7);

        widget_8 = new QWidget(staffgroup);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        horizontalLayout_13 = new QHBoxLayout(widget_8);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(150, -1, -1, -1);
        label_3 = new QLabel(widget_8);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(60, 0));
        label_3->setMaximumSize(QSize(60, 16777215));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_13->addWidget(label_3);

        groupdata = new StaticText(widget_8);
        groupdata->setObjectName(QStringLiteral("groupdata"));
        groupdata->setReadOnly(true);

        horizontalLayout_13->addWidget(groupdata);


        verticalLayout_8->addWidget(widget_8);

        widget_9 = new QWidget(staffgroup);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        horizontalLayout_14 = new QHBoxLayout(widget_9);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(-1, 20, -1, -1);
        openchat = new QPushButton(widget_9);
        openchat->setObjectName(QStringLiteral("openchat"));
        openchat->setEnabled(true);
        openchat->setMinimumSize(QSize(200, 32));
        openchat->setMaximumSize(QSize(200, 32));
        openchat->setFlat(true);

        horizontalLayout_14->addWidget(openchat);


        verticalLayout_8->addWidget(widget_9);

        verticalSpacer = new QSpacerItem(20, 430, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        custemstack->addWidget(staffgroup);
        noteInfor = new QWidget();
        noteInfor->setObjectName(QStringLiteral("noteInfor"));
        verticalLayout_15 = new QVBoxLayout(noteInfor);
        verticalLayout_15->setSpacing(0);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(5, 0, 5, 0);
        widget_2 = new QWidget(noteInfor);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_16 = new QVBoxLayout(widget_2);
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_note_title = new QLabel(widget_2);
        label_note_title->setObjectName(QStringLiteral("label_note_title"));
        label_note_title->setMinimumSize(QSize(0, 35));
        label_note_title->setMaximumSize(QSize(16777215, 35));
        label_note_title->setScaledContents(true);
        label_note_title->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_note_title);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(0, 80));
        widget_4->setMaximumSize(QSize(16777215, 80));
        horizontalLayout_9 = new QHBoxLayout(widget_4);
        horizontalLayout_9->setSpacing(20);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(10, 0, 0, 0);
        pbtn_addNote = new QPushButton(widget_4);
        pbtn_addNote->setObjectName(QStringLiteral("pbtn_addNote"));
        pbtn_addNote->setMinimumSize(QSize(50, 25));
        pbtn_addNote->setMaximumSize(QSize(30, 23));
        pbtn_addNote->setFlat(false);

        horizontalLayout_9->addWidget(pbtn_addNote);

        scrollArea = new QScrollArea(widget_4);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        notegroup = new QWidget();
        notegroup->setObjectName(QStringLiteral("notegroup"));
        notegroup->setGeometry(QRect(0, 0, 564, 80));
        notegroupLayout = new QHBoxLayout(notegroup);
        notegroupLayout->setSpacing(10);
        notegroupLayout->setContentsMargins(11, 11, 11, 11);
        notegroupLayout->setObjectName(QStringLiteral("notegroupLayout"));
        notegroupLayout->setContentsMargins(20, 5, -1, 5);
        scrollArea->setWidget(notegroup);

        horizontalLayout_9->addWidget(scrollArea);


        verticalLayout_16->addWidget(widget_4);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_19 = new QWidget(widget_5);
        widget_19->setObjectName(QStringLiteral("widget_19"));
        verticalLayout_14 = new QVBoxLayout(widget_19);
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        widget_20 = new QWidget(widget_19);
        widget_20->setObjectName(QStringLiteral("widget_20"));
        verticalLayout_13 = new QVBoxLayout(widget_20);
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        widget_21 = new QWidget(widget_20);
        widget_21->setObjectName(QStringLiteral("widget_21"));
        verticalLayout_12 = new QVBoxLayout(widget_21);
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(10, 10, 10, 10);
        lineEdit_2 = new QLineEdit(widget_21);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 30));
        lineEdit_2->setMaximumSize(QSize(16777215, 30));

        verticalLayout_12->addWidget(lineEdit_2);


        verticalLayout_13->addWidget(widget_21);

        widget_22 = new QWidget(widget_20);
        widget_22->setObjectName(QStringLiteral("widget_22"));
        widget_22->setMinimumSize(QSize(0, 40));
        widget_22->setMaximumSize(QSize(16777215, 40));
        verticalLayout_11 = new QVBoxLayout(widget_22);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_title = new QLabel(widget_22);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_title);


        verticalLayout_13->addWidget(widget_22);


        verticalLayout_14->addWidget(widget_20);

        listWidget = new QListWidget(widget_19);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_14->addWidget(listWidget);


        horizontalLayout->addWidget(widget_19);

        widget_23 = new QWidget(widget_5);
        widget_23->setObjectName(QStringLiteral("widget_23"));
        verticalLayout_10 = new QVBoxLayout(widget_23);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget_23);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/Images/icon/commen/empty.png")));

        verticalLayout_10->addWidget(label_7);

        widget_10 = new QWidget(widget_23);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        widget_10->setMinimumSize(QSize(0, 40));
        widget_10->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_8 = new QHBoxLayout(widget_10);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(5, 0, 0, 0);
        pbtn_addSubNote = new QPushButton(widget_10);
        pbtn_addSubNote->setObjectName(QStringLiteral("pbtn_addSubNote"));
        pbtn_addSubNote->setMinimumSize(QSize(30, 23));
        pbtn_addSubNote->setMaximumSize(QSize(30, 23));
        pbtn_addSubNote->setFlat(true);

        horizontalLayout_8->addWidget(pbtn_addSubNote);

        horizontalSpacer_2 = new QSpacerItem(345, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);


        verticalLayout_10->addWidget(widget_10);


        horizontalLayout->addWidget(widget_23);


        verticalLayout_16->addWidget(widget_5);


        verticalLayout_15->addWidget(widget_2);

        custemstack->addWidget(noteInfor);
        staffuser = new QWidget();
        staffuser->setObjectName(QStringLiteral("staffuser"));
        staffuser->setStyleSheet(QStringLiteral(""));
        verticalLayout_9 = new QVBoxLayout(staffuser);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 100, 0, 0);
        widget_11 = new QWidget(staffuser);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        horizontalLayout_15 = new QHBoxLayout(widget_11);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(-1, -1, -1, 20);
        user_headimage = new QLabel(widget_11);
        user_headimage->setObjectName(QStringLiteral("user_headimage"));
        user_headimage->setMinimumSize(QSize(200, 200));
        user_headimage->setMaximumSize(QSize(200, 200));
        user_headimage->setPixmap(QPixmap(QString::fromUtf8(":/Images/no_session_selected_background.png")));
        user_headimage->setScaledContents(true);

        horizontalLayout_15->addWidget(user_headimage);


        verticalLayout_9->addWidget(widget_11);

        widget_12 = new QWidget(staffuser);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        horizontalLayout_16 = new QHBoxLayout(widget_12);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(150, -1, -1, -1);
        label_5 = new QLabel(widget_12);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(60, 0));
        label_5->setMaximumSize(QSize(60, 16777215));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_16->addWidget(label_5);

        user_id = new StaticText(widget_12);
        user_id->setObjectName(QStringLiteral("user_id"));
        user_id->setReadOnly(true);

        horizontalLayout_16->addWidget(user_id);


        verticalLayout_9->addWidget(widget_12);

        widget_13 = new QWidget(staffuser);
        widget_13->setObjectName(QStringLiteral("widget_13"));
        horizontalLayout_17 = new QHBoxLayout(widget_13);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(150, -1, -1, -1);
        label_6 = new QLabel(widget_13);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(60, 0));
        label_6->setMaximumSize(QSize(60, 16777215));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_17->addWidget(label_6);

        staffusersgroup = new StaticText(widget_13);
        staffusersgroup->setObjectName(QStringLiteral("staffusersgroup"));
        staffusersgroup->setReadOnly(true);

        horizontalLayout_17->addWidget(staffusersgroup);


        verticalLayout_9->addWidget(widget_13);

        widget_15 = new QWidget(staffuser);
        widget_15->setObjectName(QStringLiteral("widget_15"));
        horizontalLayout_20 = new QHBoxLayout(widget_15);
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalLayout_20->setContentsMargins(150, -1, -1, -1);
        label_9 = new QLabel(widget_15);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(60, 0));
        label_9->setMaximumSize(QSize(60, 16777215));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_20->addWidget(label_9);

        user_name = new StaticText(widget_15);
        user_name->setObjectName(QStringLiteral("user_name"));
        user_name->setReadOnly(true);

        horizontalLayout_20->addWidget(user_name);


        verticalLayout_9->addWidget(widget_15);

        widget_16 = new QWidget(staffuser);
        widget_16->setObjectName(QStringLiteral("widget_16"));
        horizontalLayout_21 = new QHBoxLayout(widget_16);
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        horizontalLayout_21->setContentsMargins(150, 9, -1, -1);
        label_email = new QLabel(widget_16);
        label_email->setObjectName(QStringLiteral("label_email"));
        label_email->setMinimumSize(QSize(60, 0));
        label_email->setMaximumSize(QSize(60, 16777215));
        label_email->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_21->addWidget(label_email);

        user_email = new StaticText(widget_16);
        user_email->setObjectName(QStringLiteral("user_email"));
        user_email->setReadOnly(true);

        horizontalLayout_21->addWidget(user_email);


        verticalLayout_9->addWidget(widget_16);

        widget_14 = new QWidget(staffuser);
        widget_14->setObjectName(QStringLiteral("widget_14"));
        horizontalLayout_18 = new QHBoxLayout(widget_14);
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(-1, 20, -1, -1);
        openchat_simple = new QPushButton(widget_14);
        openchat_simple->setObjectName(QStringLiteral("openchat_simple"));
        openchat_simple->setMinimumSize(QSize(200, 32));
        openchat_simple->setMaximumSize(QSize(200, 32));
        openchat_simple->setStyleSheet(QStringLiteral(""));
        openchat_simple->setFlat(true);

        horizontalLayout_18->addWidget(openchat_simple);


        verticalLayout_9->addWidget(widget_14);

        verticalSpacer_2 = new QSpacerItem(20, 348, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);

        custemstack->addWidget(staffuser);

        verticalLayout_2->addWidget(custemstack);

        webwidgets = new QWidget(spitter_right);
        webwidgets->setObjectName(QStringLiteral("webwidgets"));
        webwidgets->setGeometry(QRect(0, 0, 34, 34));
        horizontalLayout_2 = new QHBoxLayout(webwidgets);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        webwidgetstack = new QStackedWidget(webwidgets);
        webwidgetstack->setObjectName(QStringLiteral("webwidgetstack"));

        horizontalLayout_2->addWidget(webwidgetstack);

        splitter->addWidget(spitter_right);

        verticalLayout_5->addWidget(splitter);


        verticalLayout->addWidget(widget_3);


        horizontalLayout_3->addWidget(tbk1);


        retranslateUi(MultiDialogContainer);

        extendListStacked->setCurrentIndex(-1);
        custemstack->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MultiDialogContainer);
    } // setupUi

    void retranslateUi(QWidget *MultiDialogContainer)
    {
        MultiDialogContainer->setWindowTitle(QApplication::translate("MultiDialogContainer", "TitlebarWidget", 0));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("MultiDialogContainer", "shift+alt+o \346\220\234\347\264\242\350\201\224\347\263\273\344\272\272\346\210\226\347\276\244", 0));
#ifndef QT_NO_TOOLTIP
        createnewgroup->setToolTip(QApplication::translate("MultiDialogContainer", "\346\226\260\345\273\272\347\276\244", 0));
#endif // QT_NO_TOOLTIP
        createnewgroup->setText(QString());
        couversationCount->setText(QApplication::translate("MultiDialogContainer", "x/y", 0));
        label_4->setText(QString());
        loadUnread->setText(QApplication::translate("MultiDialogContainer", "\345\217\252\346\230\276\347\244\272\346\234\252\350\257\273\345\222\214\347\275\256\351\241\266\344\274\232\350\257\235", 0));
        loadAll->setText(QApplication::translate("MultiDialogContainer", "\345\212\240\350\275\275\346\211\200\346\234\211\344\274\232\350\257\235", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("MultiDialogContainer", "\351\203\250\351\227\250\357\274\232", 0));
        grouppath->setText(QApplication::translate("MultiDialogContainer", "NULL", 0));
        label_3->setText(QApplication::translate("MultiDialogContainer", "\347\273\237\350\256\241\357\274\232", 0));
        groupdata->setText(QApplication::translate("MultiDialogContainer", "NULL", 0));
        openchat->setText(QApplication::translate("MultiDialogContainer", "\345\210\233\345\273\272\347\276\244\344\274\232\350\257\235", 0));
        label_note_title->setText(QApplication::translate("MultiDialogContainer", "\347\254\224\350\256\260\344\277\241\346\201\257", 0));
#ifndef QT_NO_TOOLTIP
        pbtn_addNote->setToolTip(QApplication::translate("MultiDialogContainer", "\346\267\273\345\212\240\350\256\260\344\272\213\346\234\254", 0));
#endif // QT_NO_TOOLTIP
        pbtn_addNote->setText(QString());
        lineEdit_2->setPlaceholderText(QApplication::translate("MultiDialogContainer", "\346\220\234\347\264\242", 0));
        label_title->setText(QApplication::translate("MultiDialogContainer", "\346\211\200\346\234\211", 0));
        label_7->setText(QString());
        pbtn_addSubNote->setText(QString());
        user_headimage->setText(QString());
        label_5->setText(QApplication::translate("MultiDialogContainer", "ID\357\274\232", 0));
        user_id->setText(QApplication::translate("MultiDialogContainer", "NULL", 0));
        label_6->setText(QApplication::translate("MultiDialogContainer", "\351\203\250\351\227\250\357\274\232", 0));
        staffusersgroup->setText(QApplication::translate("MultiDialogContainer", "NULL", 0));
        label_9->setText(QApplication::translate("MultiDialogContainer", "\345\247\223\345\220\215\357\274\232", 0));
        user_name->setText(QApplication::translate("MultiDialogContainer", "NULL", 0));
        label_email->setText(QApplication::translate("MultiDialogContainer", "\351\202\256\347\256\261\357\274\232", 0));
        user_email->setText(QApplication::translate("MultiDialogContainer", "NULL", 0));
        openchat_simple->setText(QApplication::translate("MultiDialogContainer", "\345\217\221\350\265\267\344\274\232\350\257\235", 0));
    } // retranslateUi

};

namespace Ui {
    class MultiDialogContainer: public Ui_MultiDialogContainer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIDIALOGCONTAINER_H

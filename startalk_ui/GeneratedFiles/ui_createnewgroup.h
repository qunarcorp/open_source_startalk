/********************************************************************************
** Form generated from reading UI file 'createnewgroup.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWGROUP_H
#define UI_CREATENEWGROUP_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "slidingstackedwidget.h"

QT_BEGIN_NAMESPACE

class Ui_CreateNewGroup
{
public:
    QVBoxLayout *verticalLayout_9;
    QWidget *shadowbg;
    QHBoxLayout *horizontalLayout_4;
    QWidget *shadowinnerbg;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QWidget *leftPanel;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *searchEdit;
    QWidget *tabhodler;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *tabDeps;
    QPushButton *tabFriend;
    QStackedWidget *stackedWidget;
    QWidget *memberpage;
    QVBoxLayout *verticalLayout_6;
    SlidingStackedWidget *memberstack;
    QWidget *jiagoupage;
    QVBoxLayout *verticalLayout_8;
    QTreeWidget *jiagouTreeWidget;
    QWidget *friendPage;
    QVBoxLayout *verticalLayout_7;
    QTreeWidget *friendList;
    QWidget *searchpage;
    QVBoxLayout *verticalLayout;
    QTreeWidget *searchTreeWidget;
    QWidget *rightPanel;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *headcount;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *close;
    QSpacerItem *verticalSpacer;
    QListWidget *listWidget;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *edit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancle;
    QPushButton *pushButton_creategroup;
    QPushButton *ok;

    void setupUi(QWidget *CreateNewGroup)
    {
        if (CreateNewGroup->objectName().isEmpty())
            CreateNewGroup->setObjectName(QStringLiteral("CreateNewGroup"));
        CreateNewGroup->resize(718, 568);
        CreateNewGroup->setStyleSheet(QString::fromUtf8("QWidget{\n"
"    font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"}\n"
"QWidget#leftPanel{\n"
"    background-color:#EAEBED;\n"
"	border-bottom-left-radius: 4px;\n"
"	border-top-left-radius: 4px;\n"
"}\n"
"QWidget#rightPanel{\n"
"	border-bottom-right-radius: 4px;\n"
"	border-top-right-radius: 4px;	\n"
"    background-color:#FFFFFF;\n"
"}\n"
"QTreeWidget,QListWidget{\n"
"    border:none;\n"
"    background-color:#00000000;\n"
"}\n"
"QTreeWidget::branch{\n"
"	border-image:none;\n"
"	image:none;\n"
"}\n"
"\n"
"QLineEdit#searchEdit{\n"
"    padding-left:20px;\n"
"    border:1px solid #FFFFFF;\n"
"    border-radius: 13px;\n"
"}\n"
"\n"
"QLabel{\n"
"    color:#666666;\n"
"}\n"
"\n"
"QPushButton#ok,#next,#pushButton_creategroup{\n"
"	 border-radius: 0px;\n"
"    color:#FFFFFF;\n"
"    background-color:#3DCE3D;\n"
"}\n"
"QPushButton#ok:disabled,#next:disabled,#pushButton_creategroup:disabled{\n"
"    background-color:#9DE69D;\n"
"}\n"
"QPushButton#ok:hover,#next:hover,#pushButton_creategroup:hover{\n"
""
                        "    background-color:#38C738;\n"
"}\n"
"QPushButton#ok:pressed,#next:pressed,#pushButton_creategroup:pressed{\n"
"    background-color:#2FB82F;\n"
"}\n"
"\n"
"QPushButton#cancle,#edit{\n"
"    color:#666666;\n"
"    border:1px solid #E5E5E5;\n"
"}\n"
"QPushButton#cancle:hover,#edit:hover{\n"
"    background-color:#f5f5f5;\n"
"}\n"
"QPushButton#cancle:pressed,#edit:pressed{\n"
"    background-color:#EBEBEB;\n"
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
"\n"
"\n"
"QPushButton#tabFriend,#tabDeps{\n"
"	height:27px;\n"
"	background:#00000000;\n"
"	border:none;\n"
"	color:#666666;\n"
"}\n"
"\n"
"QPushButton#tabFriend:checked,#tabDeps:checked{\n"
"	border:none;\n"
"	color:#FFFFFF;\n"
""
                        "    background-color:#3DCE3D;\n"
"}"));
        verticalLayout_9 = new QVBoxLayout(CreateNewGroup);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(CreateNewGroup);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        horizontalLayout_4 = new QHBoxLayout(shadowbg);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        horizontalLayout = new QHBoxLayout(shadowinnerbg);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        splitter = new QSplitter(shadowinnerbg);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setMinimumSize(QSize(700, 550));
        splitter->setMaximumSize(QSize(16777215, 16777215));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(0);
        splitter->setChildrenCollapsible(false);
        leftPanel = new QWidget(splitter);
        leftPanel->setObjectName(QStringLiteral("leftPanel"));
        leftPanel->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_3 = new QVBoxLayout(leftPanel);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(leftPanel);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(0, 48));
        widget_5->setMaximumSize(QSize(16777215, 48));
        verticalLayout_5 = new QVBoxLayout(widget_5);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(16, 0, 16, 0);
        searchEdit = new QLineEdit(widget_5);
        searchEdit->setObjectName(QStringLiteral("searchEdit"));
        searchEdit->setMinimumSize(QSize(0, 26));

        verticalLayout_5->addWidget(searchEdit);


        verticalLayout_3->addWidget(widget_5);

        tabhodler = new QWidget(leftPanel);
        tabhodler->setObjectName(QStringLiteral("tabhodler"));
        horizontalLayout_5 = new QHBoxLayout(tabhodler);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        tabDeps = new QPushButton(tabhodler);
        tabDeps->setObjectName(QStringLiteral("tabDeps"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/icon_go_hover.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabDeps->setIcon(icon);
        tabDeps->setCheckable(true);
        tabDeps->setChecked(true);
        tabDeps->setAutoExclusive(true);
        tabDeps->setFlat(true);

        horizontalLayout_5->addWidget(tabDeps);

        tabFriend = new QPushButton(tabhodler);
        tabFriend->setObjectName(QStringLiteral("tabFriend"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/mainpanel_group_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabFriend->setIcon(icon1);
        tabFriend->setCheckable(true);
        tabFriend->setAutoExclusive(true);
        tabFriend->setFlat(true);

        horizontalLayout_5->addWidget(tabFriend);


        verticalLayout_3->addWidget(tabhodler);

        stackedWidget = new QStackedWidget(leftPanel);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        memberpage = new QWidget();
        memberpage->setObjectName(QStringLiteral("memberpage"));
        verticalLayout_6 = new QVBoxLayout(memberpage);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        memberstack = new SlidingStackedWidget(memberpage);
        memberstack->setObjectName(QStringLiteral("memberstack"));
        jiagoupage = new QWidget();
        jiagoupage->setObjectName(QStringLiteral("jiagoupage"));
        verticalLayout_8 = new QVBoxLayout(jiagoupage);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        jiagouTreeWidget = new QTreeWidget(jiagoupage);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        jiagouTreeWidget->setHeaderItem(__qtreewidgetitem);
        jiagouTreeWidget->setObjectName(QStringLiteral("jiagouTreeWidget"));
        jiagouTreeWidget->setMinimumSize(QSize(10, 10));

        verticalLayout_8->addWidget(jiagouTreeWidget);

        memberstack->addWidget(jiagoupage);
        friendPage = new QWidget();
        friendPage->setObjectName(QStringLiteral("friendPage"));
        verticalLayout_7 = new QVBoxLayout(friendPage);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        friendList = new QTreeWidget(friendPage);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        friendList->setHeaderItem(__qtreewidgetitem1);
        friendList->setObjectName(QStringLiteral("friendList"));

        verticalLayout_7->addWidget(friendList);

        memberstack->addWidget(friendPage);

        verticalLayout_6->addWidget(memberstack);

        stackedWidget->addWidget(memberpage);
        searchpage = new QWidget();
        searchpage->setObjectName(QStringLiteral("searchpage"));
        verticalLayout = new QVBoxLayout(searchpage);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        searchTreeWidget = new QTreeWidget(searchpage);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setText(0, QStringLiteral("1"));
        searchTreeWidget->setHeaderItem(__qtreewidgetitem2);
        searchTreeWidget->setObjectName(QStringLiteral("searchTreeWidget"));

        verticalLayout->addWidget(searchTreeWidget);

        stackedWidget->addWidget(searchpage);

        verticalLayout_3->addWidget(stackedWidget);

        splitter->addWidget(leftPanel);
        rightPanel = new QWidget(splitter);
        rightPanel->setObjectName(QStringLiteral("rightPanel"));
        rightPanel->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_4 = new QVBoxLayout(rightPanel);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_6 = new QWidget(rightPanel);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(0, 48));
        widget_6->setMaximumSize(QSize(16777215, 48));
        horizontalLayout_2 = new QHBoxLayout(widget_6);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(20, 0, 0, 0);
        headcount = new QLabel(widget_6);
        headcount->setObjectName(QStringLiteral("headcount"));
        headcount->setMinimumSize(QSize(0, 0));
        headcount->setMaximumSize(QSize(16777215, 16777215));
        headcount->setWordWrap(false);

        horizontalLayout_2->addWidget(headcount);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widget_2 = new QWidget(widget_6);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        close = new QPushButton(widget_2);
        close->setObjectName(QStringLiteral("close"));
        close->setFlat(true);

        verticalLayout_2->addWidget(close);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(widget_2);


        verticalLayout_4->addWidget(widget_6);

        listWidget = new QListWidget(rightPanel);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_4->addWidget(listWidget);

        widget_3 = new QWidget(rightPanel);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QStringLiteral(""));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(10, 0, 20, 20);
        edit = new QPushButton(widget_3);
        edit->setObjectName(QStringLiteral("edit"));
        edit->setMinimumSize(QSize(70, 26));
        edit->setMaximumSize(QSize(70, 16777215));
        edit->setFlat(true);

        horizontalLayout_3->addWidget(edit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        cancle = new QPushButton(widget_3);
        cancle->setObjectName(QStringLiteral("cancle"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cancle->sizePolicy().hasHeightForWidth());
        cancle->setSizePolicy(sizePolicy);
        cancle->setMinimumSize(QSize(70, 26));
        cancle->setMaximumSize(QSize(70, 16777215));
        cancle->setFlat(true);

        horizontalLayout_3->addWidget(cancle);

        pushButton_creategroup = new QPushButton(widget_3);
        pushButton_creategroup->setObjectName(QStringLiteral("pushButton_creategroup"));
        pushButton_creategroup->setMinimumSize(QSize(70, 26));
        pushButton_creategroup->setMaximumSize(QSize(70, 26));

        horizontalLayout_3->addWidget(pushButton_creategroup);

        ok = new QPushButton(widget_3);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setMinimumSize(QSize(70, 26));
        ok->setMaximumSize(QSize(70, 60));
        ok->setFlat(true);

        horizontalLayout_3->addWidget(ok);


        verticalLayout_4->addWidget(widget_3);

        splitter->addWidget(rightPanel);

        horizontalLayout->addWidget(splitter);


        horizontalLayout_4->addWidget(shadowinnerbg);


        verticalLayout_9->addWidget(shadowbg);


        retranslateUi(CreateNewGroup);

        stackedWidget->setCurrentIndex(0);
        memberstack->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CreateNewGroup);
    } // setupUi

    void retranslateUi(QWidget *CreateNewGroup)
    {
        CreateNewGroup->setWindowTitle(QApplication::translate("CreateNewGroup", "CreateNewGroup", 0));
        searchEdit->setText(QString());
        searchEdit->setPlaceholderText(QApplication::translate("CreateNewGroup", "\346\220\234\347\264\242\350\201\224\347\263\273\344\272\272", 0));
        tabDeps->setText(QApplication::translate("CreateNewGroup", "\347\273\204\347\273\207\346\236\266\346\236\204", 0));
        tabFriend->setText(QApplication::translate("CreateNewGroup", "\345\245\275\345\217\213", 0));
        headcount->setText(QApplication::translate("CreateNewGroup", "\350\257\267\345\213\276\351\200\211\351\234\200\350\246\201\346\267\273\345\212\240\347\232\204\350\201\224\347\263\273\344\272\272", 0));
        close->setText(QString());
        edit->setText(QApplication::translate("CreateNewGroup", "\350\276\223\345\205\245", 0));
        cancle->setText(QApplication::translate("CreateNewGroup", "\345\217\226\346\266\210", 0));
        pushButton_creategroup->setText(QApplication::translate("CreateNewGroup", "\345\210\233\345\273\272", 0));
        ok->setText(QApplication::translate("CreateNewGroup", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateNewGroup: public Ui_CreateNewGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWGROUP_H

/********************************************************************************
** Form generated from reading UI file 'selgroupmember.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELGROUPMEMBER_H
#define UI_SELGROUPMEMBER_H

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

class Ui_SelGroupMember
{
public:
    QVBoxLayout *verticalLayout_10;
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
    QVBoxLayout *verticalLayout_9;
    QPushButton *tabDeps;
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
    QWidget *widget;
    QLabel *label;
    QLineEdit *lineEdit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancle;
    QPushButton *ok;

    void setupUi(QWidget *SelGroupMember)
    {
        if (SelGroupMember->objectName().isEmpty())
            SelGroupMember->setObjectName(QStringLiteral("SelGroupMember"));
        SelGroupMember->resize(718, 568);
        SelGroupMember->setStyleSheet(QString::fromUtf8("QWidget{\n"
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
"QPushButton#ok{\n"
"	 border-radius: 0px;\n"
"    color:#FFFFFF;\n"
"    background-color:#3DCE3D;\n"
"}\n"
"QPushButton#ok:disabled{\n"
"    background-color:#9DE69D;\n"
"}\n"
"QPushButton#ok:hover{\n"
"    background-color:#38C738;\n"
"}\n"
"QPushButton#ok:pressed{\n"
"    background-color:#2FB82F;\n"
"}\n"
"\n"
"QPush"
                        "Button#cancle{\n"
"    color:#666666;\n"
"    border:1px solid #E5E5E5;\n"
"}\n"
"QPushButton#cancle:hover{\n"
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
"    background-color:#3DCE3D;\n"
"}\n"
"QWidget#widget,QWidget#widget_3\n"
"{\n"
"	border:none;\n"
"	color:#FFFFFF;\n"
"    background-color:#EAEBED;\n"
"}"));
        verticalLayout_10 = new QVBoxLayout(SelGroupMember);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(SelGroupMember);
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
        splitter->setEnabled(true);
        splitter->setMinimumSize(QSize(700, 550));
        splitter->setMaximumSize(QSize(16777215, 16777215));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setOpaqueResize(false);
        splitter->setHandleWidth(0);
        splitter->setChildrenCollapsible(false);
        leftPanel = new QWidget(splitter);
        leftPanel->setObjectName(QStringLiteral("leftPanel"));
        leftPanel->setEnabled(true);
        leftPanel->setMinimumSize(QSize(261, 0));
        leftPanel->setMaximumSize(QSize(261, 16777215));
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
        verticalLayout_9 = new QVBoxLayout(tabhodler);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        tabDeps = new QPushButton(tabhodler);
        tabDeps->setObjectName(QStringLiteral("tabDeps"));
        tabDeps->setCheckable(false);
        tabDeps->setChecked(false);
        tabDeps->setAutoExclusive(false);
        tabDeps->setFlat(true);

        verticalLayout_9->addWidget(tabDeps);


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

        widget = new QWidget(rightPanel);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 86));
        widget->setMaximumSize(QSize(16777215, 86));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 161, 16));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(40, 40, 341, 31));

        verticalLayout_4->addWidget(widget);

        widget_3 = new QWidget(rightPanel);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QStringLiteral(""));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(10, 0, 20, 20);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        cancle = new QPushButton(widget_3);
        cancle->setObjectName(QStringLiteral("cancle"));
        cancle->setMinimumSize(QSize(70, 26));
        cancle->setMaximumSize(QSize(70, 60));
        cancle->setFlat(true);

        horizontalLayout_3->addWidget(cancle);

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


        verticalLayout_10->addWidget(shadowbg);


        retranslateUi(SelGroupMember);

        stackedWidget->setCurrentIndex(0);
        memberstack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SelGroupMember);
    } // setupUi

    void retranslateUi(QWidget *SelGroupMember)
    {
        SelGroupMember->setWindowTitle(QApplication::translate("SelGroupMember", "SelGroupMember", 0));
        searchEdit->setText(QString());
        searchEdit->setPlaceholderText(QApplication::translate("SelGroupMember", "\346\220\234\347\264\242\350\201\224\347\263\273\344\272\272", 0));
        tabDeps->setText(QApplication::translate("SelGroupMember", "\347\276\244\347\273\204\346\210\220\345\221\230", 0));
        headcount->setText(QApplication::translate("SelGroupMember", "\350\257\267\345\213\276\351\200\211\351\234\200\350\246\201\350\201\212\345\244\251\347\232\204\347\276\244\346\210\220\345\221\230:", 0));
        close->setText(QString());
        label->setText(QApplication::translate("SelGroupMember", "\350\257\267\350\276\223\345\205\245\351\237\263\350\247\206\351\242\221\350\201\212\345\244\251\345\256\244\347\232\204\345\220\215\347\247\260:", 0));
        cancle->setText(QApplication::translate("SelGroupMember", "\345\217\226\346\266\210", 0));
        ok->setText(QApplication::translate("SelGroupMember", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class SelGroupMember: public Ui_SelGroupMember {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELGROUPMEMBER_H

/********************************************************************************
** Form generated from reading UI file 'RobotSearchView.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTSEARCHVIEW_H
#define UI_ROBOTSEARCHVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_RobotSearchView
{
public:
    QVBoxLayout *verticalLayout_4;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout_5;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout;
    TitlebarWidget *titilebar;
    QWidget *groupbtns;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *myrobot;
    QPushButton *searchrobot;
    QSpacerItem *horizontalSpacer_2;
    QStackedWidget *stackedWidget;
    QWidget *myRobotListPage;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *myRobotList;
    QWidget *robotSearchPage;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit;
    QListWidget *searchRobotList;

    void setupUi(QWidget *RobotSearchView)
    {
        if (RobotSearchView->objectName().isEmpty())
            RobotSearchView->setObjectName(QStringLiteral("RobotSearchView"));
        RobotSearchView->resize(280, 461);
        RobotSearchView->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"\n"
"QPushButton{\n"
"	color:#1ba9ba;\n"
"	border:1px solid #1ba9ba;\n"
"	background:#FFFFFF;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked{\n"
"	background:#1ba9ba;\n"
"	color:#FFFFFF;\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton#myrobot{\n"
"	border-top-left-radius:3px;\n"
"	border-bottom-left-radius:3px;\n"
"}\n"
"QPushButton#searchrobot{\n"
"	border-top-right-radius:3px;\n"
"	border-bottom-right-radius:3px;\n"
"}\n"
"\n"
"QListWidget{\n"
"	border:none;\n"
"	background:#00000000;\n"
"}\n"
"\n"
"QLineEdit#lineEdit{\n"
"    font-size: 15px;\n"
"    font-family:'\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"    color:#A7A6AA;\n"
"    border-radius: 14px;\n"
"    background-color: #ffffff;\n"
"    border:1px solid #1ba9ba;\n"
"	padding-left:10px;\n"
"}\n"
"QLineEdit#lineEdit:focus{\n"
"    background-color: #e5e5e5;\n"
"    color:#464545;\n"
"}\n"
"QStackedWidget#stackedWidget{\n"
"	border:none;\n"
"	background:#00"
                        "000000;\n"
"}\n"
""));
        verticalLayout_4 = new QVBoxLayout(RobotSearchView);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(RobotSearchView);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        verticalLayout_5 = new QVBoxLayout(shadowbg);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        verticalLayout = new QVBoxLayout(shadowinnerbg);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        titilebar = new TitlebarWidget(shadowinnerbg);
        titilebar->setObjectName(QStringLiteral("titilebar"));
        titilebar->setMinimumSize(QSize(0, 32));
        titilebar->setMaximumSize(QSize(16777215, 32));

        verticalLayout->addWidget(titilebar);

        groupbtns = new QWidget(shadowinnerbg);
        groupbtns->setObjectName(QStringLiteral("groupbtns"));
        groupbtns->setMinimumSize(QSize(0, 32));
        groupbtns->setMaximumSize(QSize(16777215, 32));
        horizontalLayout = new QHBoxLayout(groupbtns);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(105, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        myrobot = new QPushButton(groupbtns);
        myrobot->setObjectName(QStringLiteral("myrobot"));
        myrobot->setMinimumSize(QSize(72, 24));
        myrobot->setMaximumSize(QSize(72, 24));
        myrobot->setCheckable(true);
        myrobot->setAutoExclusive(true);
        myrobot->setFlat(true);

        horizontalLayout->addWidget(myrobot);

        searchrobot = new QPushButton(groupbtns);
        searchrobot->setObjectName(QStringLiteral("searchrobot"));
        searchrobot->setMinimumSize(QSize(72, 24));
        searchrobot->setMaximumSize(QSize(72, 24));
        searchrobot->setCheckable(true);
        searchrobot->setChecked(true);
        searchrobot->setAutoExclusive(true);
        searchrobot->setFlat(true);

        horizontalLayout->addWidget(searchrobot);

        horizontalSpacer_2 = new QSpacerItem(105, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(groupbtns);

        stackedWidget = new QStackedWidget(shadowinnerbg);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        myRobotListPage = new QWidget();
        myRobotListPage->setObjectName(QStringLiteral("myRobotListPage"));
        horizontalLayout_2 = new QHBoxLayout(myRobotListPage);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 1, 0);
        myRobotList = new QListWidget(myRobotListPage);
        myRobotList->setObjectName(QStringLiteral("myRobotList"));
        myRobotList->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(myRobotList);

        stackedWidget->addWidget(myRobotListPage);
        robotSearchPage = new QWidget();
        robotSearchPage->setObjectName(QStringLiteral("robotSearchPage"));
        verticalLayout_2 = new QVBoxLayout(robotSearchPage);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 1, 0);
        widget = new QWidget(robotSearchPage);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(10, 2, 10, 2);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 28));
        lineEdit->setMaximumSize(QSize(16777215, 28));

        verticalLayout_3->addWidget(lineEdit);


        verticalLayout_2->addWidget(widget);

        searchRobotList = new QListWidget(robotSearchPage);
        searchRobotList->setObjectName(QStringLiteral("searchRobotList"));

        verticalLayout_2->addWidget(searchRobotList);

        stackedWidget->addWidget(robotSearchPage);

        verticalLayout->addWidget(stackedWidget);


        verticalLayout_5->addWidget(shadowinnerbg);


        verticalLayout_4->addWidget(shadowbg);


        retranslateUi(RobotSearchView);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(RobotSearchView);
    } // setupUi

    void retranslateUi(QWidget *RobotSearchView)
    {
        RobotSearchView->setWindowTitle(QApplication::translate("RobotSearchView", "RobotSearchView", 0));
        myrobot->setText(QApplication::translate("RobotSearchView", "\346\210\221\345\205\263\346\263\250\347\232\204", 0));
        searchrobot->setText(QApplication::translate("RobotSearchView", "\346\220\234\347\264\242", 0));
    } // retranslateUi

};

namespace Ui {
    class RobotSearchView: public Ui_RobotSearchView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTSEARCHVIEW_H

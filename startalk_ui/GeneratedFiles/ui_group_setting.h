/********************************************************************************
** Form generated from reading UI file 'group_setting.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUP_SETTING_H
#define UI_GROUP_SETTING_H

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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <statictext.h>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_GroupSetting
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *shadowbg;
    QHBoxLayout *horizontalLayout_4;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout_3;
    QWidget *bks;
    QWidget *bg1;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_3;
    QWidget *page_sub1;
    QVBoxLayout *verticalLayout_2;
    QWidget *vcardpanel;
    QLabel *avatar;
    QLineEdit *gname;
    QLabel *label_2;
    StaticText *gid;
    QPushButton *ok_change;
    QLabel *label_3;
    QWidget *gonggaopannel;
    QPushButton *pushButton;
    QTextEdit *gsubject;
    QLabel *label_6;
    QWidget *mypanel;
    QWidget *personInfo;
    QLabel *label;
    QLabel *nickname;
    QCheckBox *autojoin;
    QCheckBox *menberChangeNotify;
    QLabel *label1;
    QWidget *page_2;
    QWidget *page2_sub1;
    QWidget *page2_sub2;
    QTableView *tableView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *distroy;
    QPushButton *exit;
    QPushButton *cancle;
    TitlebarWidget *titlebarWidget;
    QWidget *navbar;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *baseinfo;
    QPushButton *list;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *GroupSetting)
    {
        if (GroupSetting->objectName().isEmpty())
            GroupSetting->setObjectName(QStringLiteral("GroupSetting"));
        GroupSetting->resize(518, 448);
        GroupSetting->setMinimumSize(QSize(518, 448));
        GroupSetting->setMaximumSize(QSize(518, 448));
        GroupSetting->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QWidget#GroupSetting{\n"
"    background-color: #ECECEC;\n"
"}\n"
"\n"
"QWidget#page_sub1,#page2_sub1,#page3_sub1{\n"
"    border-radius: 10px;\n"
"    background-color: #E2E2E2;\n"
"	margin: 20px 10px 0px 10px\n"
"}\n"
"QWidget#page_sub2{\n"
"    border-radius: 10px;\n"
"	margin: 35px 80px 15px 80px;\n"
"}\n"
"\n"
"\n"
"QWidget#page2_sub2{\n"
"    border-radius: 10px;\n"
"	margin: 35px 80px 15px 80px;\n"
"}\n"
"\n"
"QWidget#page3_sub2{\n"
"    border-radius: 10px;\n"
"	margin: 35px 80px 15px 80px;\n"
"}\n"
"\n"
"QPushButton{\n"
"    color: #666666;\n"
"	background-color: #FFFFFF;\n"
"	border:none;\n"
"}\n"
"QPushButton#baseinfo,#list,#setting\n"
"{\n"
"	border-left:1px solid #1ba9ba;\n"
"	border-top:1px solid #1ba9ba;\n"
"	border-bottom:1px solid #1ba9ba;\n"
"}\n"
"QPushButton#list\n"
"{\n"
"	border-right:1px solid #1ba9ba;\n"
"}\n"
"QPushButton:hover {\n"
"    color: #FFFFFF;\n"
"	background-color: #3dbbca;\n"
"}\n"
""
                        "QPushButton:pressed{\n"
"\n"
"    color: #FFFFFF;\n"
"	background-color: #1194a4;\n"
"}\n"
"QPushButton:checked{\n"
"\n"
"    color: #FFFFFF;\n"
"	background-color: #1ba9ba;\n"
"}\n"
"QWidget#personInfo {\n"
"	background-color:#D9D9D9;\n"
" 	border-radius: 10px;\n"
"}\n"
"\n"
"\n"
"QLabel{\n"
"	color:#333333;\n"
"	font:bold 12px;\n"
"}\n"
"QPushButton{\n"
"	color:#333333;\n"
"	font:bold 12px;\n"
"}\n"
"\n"
"QCheckBox{\n"
"	color:#333333;\n"
"	font:bold 12px;\n"
"}\n"
"QLineEdit{\n"
"    background-color: #00000000;\n"
"    border:none;\n"
"}\n"
"QLineEdit:hover{\n"
"    border:1px solid #999999;\n"
"}\n"
"QLineEdit:focus{\n"
"    background-color: #FFFFFF;\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"    border-color: #1BA9BA;\n"
"}\n"
"\n"
"QLineEdit:disabled{\n"
"    background-color: #ECECEC;\n"
"    border:none;\n"
"}\n"
"\n"
"QTextEdit{\n"
"    background: #FFFFFF;\n"
"    border:none;\n"
"}\n"
"\n"
"QTextEdit:focus{\n"
"    background-color: #FFFFFF;\n"
"    border-width: 1px;\n"
"    bord"
                        "er-style: solid;\n"
"    border-color: #1BA9BA;\n"
"}\n"
"\n"
"QLineEdit#gid\n"
"{\n"
"	border:none;\n"
"	background:#00000000;\n"
"	color:#333333;\n"
"	font:bold 12px;\n"
"}\n"
"\n"
"QLabel#nickname\n"
"{\n"
"    background-color:#FFFFFF; \n"
"    border:1px solid;\n"
"}\n"
"QLabel#avatar\n"
"{\n"
"	border:1px solid #ECECEC;\n"
"}"));
        horizontalLayout = new QHBoxLayout(GroupSetting);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(GroupSetting);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        horizontalLayout_4 = new QHBoxLayout(shadowbg);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        verticalLayout_3 = new QVBoxLayout(shadowinnerbg);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(1, 1, 1, 1);
        bks = new QWidget(shadowinnerbg);
        bks->setObjectName(QStringLiteral("bks"));
        bg1 = new QWidget(bks);
        bg1->setObjectName(QStringLiteral("bg1"));
        bg1->setGeometry(QRect(0, 0, 500, 400));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(bg1->sizePolicy().hasHeightForWidth());
        bg1->setSizePolicy(sizePolicy);
        bg1->setMinimumSize(QSize(500, 400));
        bg1->setMaximumSize(QSize(500, 400));
        bg1->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(bg1);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(bg1);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setMaximumSize(QSize(540, 400));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setStyleSheet(QStringLiteral(""));
        horizontalLayout_3 = new QHBoxLayout(page);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        page_sub1 = new QWidget(page);
        page_sub1->setObjectName(QStringLiteral("page_sub1"));
        page_sub1->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(page_sub1);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(45, 45, 45, 0);
        vcardpanel = new QWidget(page_sub1);
        vcardpanel->setObjectName(QStringLiteral("vcardpanel"));
        avatar = new QLabel(vcardpanel);
        avatar->setObjectName(QStringLiteral("avatar"));
        avatar->setGeometry(QRect(10, 15, 100, 100));
        avatar->setMinimumSize(QSize(100, 100));
        avatar->setMaximumSize(QSize(100, 100));
        avatar->setStyleSheet(QStringLiteral(""));
        gname = new QLineEdit(vcardpanel);
        gname->setObjectName(QStringLiteral("gname"));
        gname->setGeometry(QRect(160, 25, 241, 22));
        label_2 = new QLabel(vcardpanel);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 25, 40, 22));
        gid = new StaticText(vcardpanel);
        gid->setObjectName(QStringLiteral("gid"));
        gid->setGeometry(QRect(160, 80, 241, 22));
        gid->setStyleSheet(QStringLiteral(""));
        gid->setFrame(false);
        gid->setReadOnly(true);
        ok_change = new QPushButton(vcardpanel);
        ok_change->setObjectName(QStringLiteral("ok_change"));
        ok_change->setGeometry(QRect(330, 50, 70, 22));
        label_3 = new QLabel(vcardpanel);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 80, 40, 22));

        verticalLayout_2->addWidget(vcardpanel);

        gonggaopannel = new QWidget(page_sub1);
        gonggaopannel->setObjectName(QStringLiteral("gonggaopannel"));
        pushButton = new QPushButton(gonggaopannel);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(329, 80, 70, 22));
        gsubject = new QTextEdit(gonggaopannel);
        gsubject->setObjectName(QStringLiteral("gsubject"));
        gsubject->setGeometry(QRect(10, 20, 391, 55));
        label_6 = new QLabel(gonggaopannel);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, -1, 54, 22));

        verticalLayout_2->addWidget(gonggaopannel);

        mypanel = new QWidget(page_sub1);
        mypanel->setObjectName(QStringLiteral("mypanel"));
        mypanel->setMaximumSize(QSize(0, 0));
        personInfo = new QWidget(mypanel);
        personInfo->setObjectName(QStringLiteral("personInfo"));
        personInfo->setGeometry(QRect(0, 0, 360, 96));
        personInfo->setMinimumSize(QSize(360, 96));
        personInfo->setMaximumSize(QSize(360, 96));
        personInfo->setStyleSheet(QStringLiteral(""));
        label = new QLabel(personInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(15, 23, 40, 14));
        nickname = new QLabel(personInfo);
        nickname->setObjectName(QStringLiteral("nickname"));
        nickname->setGeometry(QRect(60, 20, 201, 20));
        nickname->setMaximumSize(QSize(16777215, 20));
        nickname->setStyleSheet(QStringLiteral(""));
        autojoin = new QCheckBox(personInfo);
        autojoin->setObjectName(QStringLiteral("autojoin"));
        autojoin->setGeometry(QRect(15, 50, 0, 0));
        autojoin->setChecked(true);
        menberChangeNotify = new QCheckBox(personInfo);
        menberChangeNotify->setObjectName(QStringLiteral("menberChangeNotify"));
        menberChangeNotify->setGeometry(QRect(15, 60, 141, 16));
        label1 = new QLabel(mypanel);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(0, 0, 81, 16));

        verticalLayout_2->addWidget(mypanel);


        horizontalLayout_3->addWidget(page_sub1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page2_sub1 = new QWidget(page_2);
        page2_sub1->setObjectName(QStringLiteral("page2_sub1"));
        page2_sub1->setGeometry(QRect(0, 0, 520, 360));
        page2_sub2 = new QWidget(page2_sub1);
        page2_sub2->setObjectName(QStringLiteral("page2_sub2"));
        page2_sub2->setGeometry(QRect(0, 0, 520, 360));
        tableView = new QTableView(page2_sub2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(30, 45, 460, 305));
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        widget = new QWidget(bg1);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(40, 40));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 20, -1);
        horizontalSpacer_3 = new QSpacerItem(356, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        distroy = new QPushButton(widget);
        distroy->setObjectName(QStringLiteral("distroy"));
        distroy->setMinimumSize(QSize(70, 28));
        distroy->setMaximumSize(QSize(70, 28));

        horizontalLayout_2->addWidget(distroy);

        exit = new QPushButton(widget);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setMinimumSize(QSize(70, 28));
        exit->setMaximumSize(QSize(70, 28));

        horizontalLayout_2->addWidget(exit);

        cancle = new QPushButton(widget);
        cancle->setObjectName(QStringLiteral("cancle"));
        cancle->setMinimumSize(QSize(70, 28));
        cancle->setMaximumSize(QSize(70, 28));

        horizontalLayout_2->addWidget(cancle);


        verticalLayout->addWidget(widget);

        titlebarWidget = new TitlebarWidget(bks);
        titlebarWidget->setObjectName(QStringLiteral("titlebarWidget"));
        titlebarWidget->setGeometry(QRect(246, 186, 16, 28));
        titlebarWidget->setMinimumSize(QSize(0, 28));
        titlebarWidget->setMaximumSize(QSize(16777215, 28));
        navbar = new QWidget(bks);
        navbar->setObjectName(QStringLiteral("navbar"));
        navbar->setGeometry(QRect(0, 0, 520, 40));
        navbar->setMinimumSize(QSize(520, 40));
        navbar->setMaximumSize(QSize(520, 40));
        horizontalLayout_5 = new QHBoxLayout(navbar);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        baseinfo = new QPushButton(navbar);
        baseinfo->setObjectName(QStringLiteral("baseinfo"));
        baseinfo->setMinimumSize(QSize(70, 28));
        baseinfo->setMaximumSize(QSize(70, 28));
        baseinfo->setStyleSheet(QStringLiteral(""));
        baseinfo->setCheckable(true);
        baseinfo->setChecked(true);
        baseinfo->setAutoExclusive(true);
        baseinfo->setFlat(true);

        horizontalLayout_5->addWidget(baseinfo);

        list = new QPushButton(navbar);
        list->setObjectName(QStringLiteral("list"));
        list->setMinimumSize(QSize(70, 28));
        list->setMaximumSize(QSize(70, 28));
        list->setCheckable(true);
        list->setAutoExclusive(true);
        list->setFlat(false);

        horizontalLayout_5->addWidget(list);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_3->addWidget(bks);


        horizontalLayout_4->addWidget(shadowinnerbg);


        horizontalLayout->addWidget(shadowbg);


        retranslateUi(GroupSetting);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GroupSetting);
    } // setupUi

    void retranslateUi(QWidget *GroupSetting)
    {
        GroupSetting->setWindowTitle(QApplication::translate("GroupSetting", "GroupSetting", 0));
        avatar->setText(QString());
        label_2->setText(QApplication::translate("GroupSetting", "\345\220\215\347\247\260\357\274\232", 0));
        gid->setText(QString());
        ok_change->setText(QApplication::translate("GroupSetting", "\346\233\264\346\226\260", 0));
        label_3->setText(QApplication::translate("GroupSetting", "\347\276\244\345\217\267\357\274\232", 0));
        pushButton->setText(QApplication::translate("GroupSetting", "\346\233\264\346\226\260\345\205\254\345\221\212", 0));
        label_6->setText(QApplication::translate("GroupSetting", "\347\276\244\345\205\254\345\221\212\357\274\232", 0));
        label->setText(QApplication::translate("GroupSetting", "\346\230\265\347\247\260\357\274\232", 0));
        nickname->setText(QString());
        autojoin->setText(QApplication::translate("GroupSetting", "\350\264\246\345\217\267\344\270\212\347\272\277\346\227\266\350\207\252\345\212\250\345\212\240\345\205\245", 0));
        menberChangeNotify->setText(QApplication::translate("GroupSetting", "\347\276\244\346\210\220\345\221\230\345\217\230\346\233\264\351\200\232\347\237\245", 0));
        label1->setText(QApplication::translate("GroupSetting", "\344\270\252\344\272\272\350\256\276\347\275\256", 0));
        distroy->setText(QApplication::translate("GroupSetting", "\351\224\200\346\257\201\347\276\244\347\273\204", 0));
        exit->setText(QApplication::translate("GroupSetting", "\351\200\200\345\207\272\347\276\244\347\273\204", 0));
        cancle->setText(QApplication::translate("GroupSetting", "\344\277\235\345\255\230\345\271\266\345\205\263\351\227\255", 0));
        baseinfo->setText(QApplication::translate("GroupSetting", "\347\276\244\350\265\204\346\226\231", 0));
        list->setText(QApplication::translate("GroupSetting", "\347\276\244\346\210\220\345\221\230", 0));
    } // retranslateUi

};

namespace Ui {
    class GroupSetting: public Ui_GroupSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUP_SETTING_H

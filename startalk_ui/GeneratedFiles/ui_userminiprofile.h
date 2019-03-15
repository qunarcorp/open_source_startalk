/********************************************************************************
** Form generated from reading UI file 'userminiprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMINIPROFILE_H
#define UI_USERMINIPROFILE_H

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

QT_BEGIN_NAMESPACE

class Ui_UserMiniProfile
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *dialogbg;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QLabel *header;
    QWidget *namepanel;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *username;
    QLabel *sex;
    QSpacerItem *horizontalSpacer;
    QLabel *moodInfo;
    QLabel *downloadheadpercent;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_5;
    QWidget *jidp;
    QHBoxLayout *horizontalLayout_5;
    QLabel *id_label;
    QLabel *jid;
    QWidget *nickpn;
    QHBoxLayout *horizontalLayout_4;
    QLabel *nicklabel;
    QLabel *nickName;
    QWidget *webpn;
    QHBoxLayout *horizontalLayout;
    QLabel *weblabel;
    QLabel *webname;
    QWidget *pathpn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *pathlabel;
    QLabel *path;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *sendmessage;
    QPushButton *addfriend;
    QPushButton *pbsetting;

    void setupUi(QWidget *UserMiniProfile)
    {
        if (UserMiniProfile->objectName().isEmpty())
            UserMiniProfile->setObjectName(QStringLiteral("UserMiniProfile"));
        UserMiniProfile->resize(220, 351);
        UserMiniProfile->setMaximumSize(QSize(220, 16777215));
        UserMiniProfile->setMouseTracking(false);
        UserMiniProfile->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"    font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QWidget#dialogbg{\n"
"    border-radius: 4px;\n"
"    border:1px solid #DADADA80;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #edeeef, stop: 1.0 #d4d7da);\n"
"}\n"
"QLabel#header\n"
"{\n"
"   background-color:#36CAD8;\n"
"}\n"
"QWidget#namepanel\n"
"{\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, \n"
"                     stop: 0 #00000000,\n"
"					 stop: 1.0 #D0333333); \n"
"}\n"
"QLabel#username{  \n"
"  font-weight:bold;\n"
"    font-size:20px;\n"
"    color:#FFFFFF;\n"
"    }\n"
"QLabel#moodInfo{  \n"
"  font-weight:bold;\n"
"    font-size:10px;\n"
"    color:#E5E5E5;\n"
"    }\n"
"	QScrollArea\n"
"	{\n"
"		border:none;\n"
"		background-color:#00000000;\n"
"	}\n"
"QLabel#id_label,#cplabel,#weblabel,#nicklabel,#pathlabel\n"
"{\n"
"    color:#666666;\n"
"}\n"
"\n"
"QLabel#cp,#jid,#nickName,#path,#webname\n"
"{\n"
"    color:#111"
                        "111;\n"
"}\n"
"QLabel#downloadheadpercent\n"
"{\n"
"	font-size:15px;\n"
"	border:1pxsolid#d7d8d9;\n"
"	border-radius:4px;\n"
"	background-color:rgb(255,255,255);\n"
"}\n"
"QPushButton \n"
"{\n"
"	font-size:14px;\n"
"    border-radius: 2px;\n"
"    color:#FFFFFF;\n"
"	padding:5px;\n"
"    background-color:#3DCE3D;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"    background-color:#9DE69D;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color:#38C738;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    background-color:#2FB82F;\n"
"}\n"
"QPushButton#pbsetting{\n"
"	border-image: url(:/Images/backward.png);\n"
"}\n"
"QPushButton#pbsetting:hover{\n"
"	border-image: url(:/Images/backward_hover.png);\n"
"}\n"
"QPushButton#pbsetting:pressed{\n"
"	border-image: url(:/Images/backward.png);\n"
"}"));
        verticalLayout = new QVBoxLayout(UserMiniProfile);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        dialogbg = new QWidget(UserMiniProfile);
        dialogbg->setObjectName(QStringLiteral("dialogbg"));
        dialogbg->setMinimumSize(QSize(220, 0));
        dialogbg->setMaximumSize(QSize(220, 16777215));
        verticalLayout_3 = new QVBoxLayout(dialogbg);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(dialogbg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(220, 220));
        widget_2->setMaximumSize(QSize(220, 220));
        header = new QLabel(widget_2);
        header->setObjectName(QStringLiteral("header"));
        header->setGeometry(QRect(0, 0, 220, 220));
        header->setMinimumSize(QSize(220, 220));
        header->setMaximumSize(QSize(220, 220));
        namepanel = new QWidget(widget_2);
        namepanel->setObjectName(QStringLiteral("namepanel"));
        namepanel->setGeometry(QRect(0, 170, 220, 50));
        namepanel->setMinimumSize(QSize(220, 50));
        namepanel->setMaximumSize(QSize(220, 50));
        verticalLayout_2 = new QVBoxLayout(namepanel);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(12, 0, 12, 0);
        widget = new QWidget(namepanel);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        username = new QLabel(widget);
        username->setObjectName(QStringLiteral("username"));
        username->setMinimumSize(QSize(0, 27));
        username->setMaximumSize(QSize(16777215, 27));
        username->setStyleSheet(QStringLiteral(""));
        username->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_6->addWidget(username);

        sex = new QLabel(widget);
        sex->setObjectName(QStringLiteral("sex"));
        sex->setMinimumSize(QSize(27, 27));
        sex->setMaximumSize(QSize(27, 27));

        horizontalLayout_6->addWidget(sex);

        horizontalSpacer = new QSpacerItem(126, 9, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(widget);

        moodInfo = new QLabel(namepanel);
        moodInfo->setObjectName(QStringLiteral("moodInfo"));
        moodInfo->setMinimumSize(QSize(0, 20));
        moodInfo->setMaximumSize(QSize(16777215, 20));
        moodInfo->setStyleSheet(QStringLiteral("font-size:10px;"));
        moodInfo->setWordWrap(false);

        verticalLayout_2->addWidget(moodInfo);

        downloadheadpercent = new QLabel(widget_2);
        downloadheadpercent->setObjectName(QStringLiteral("downloadheadpercent"));
        downloadheadpercent->setGeometry(QRect(80, 90, 30, 18));

        verticalLayout_3->addWidget(widget_2);

        widget_3 = new QWidget(dialogbg);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout_4 = new QVBoxLayout(widget_3);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 5);
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(0, 0));
        widget_4->setMaximumSize(QSize(16777215, 96));
        verticalLayout_5 = new QVBoxLayout(widget_4);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        jidp = new QWidget(widget_4);
        jidp->setObjectName(QStringLiteral("jidp"));
        jidp->setMinimumSize(QSize(0, 24));
        jidp->setMaximumSize(QSize(16777215, 24));
        horizontalLayout_5 = new QHBoxLayout(jidp);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        id_label = new QLabel(jidp);
        id_label->setObjectName(QStringLiteral("id_label"));
        id_label->setMinimumSize(QSize(72, 0));
        id_label->setMaximumSize(QSize(72, 16777215));
        id_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(id_label);

        jid = new QLabel(jidp);
        jid->setObjectName(QStringLiteral("jid"));
        jid->setMouseTracking(true);
        jid->setContextMenuPolicy(Qt::DefaultContextMenu);
        jid->setAcceptDrops(true);
        jid->setScaledContents(true);
        jid->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        jid->setProperty("readOnly", QVariant(true));

        horizontalLayout_5->addWidget(jid);


        verticalLayout_5->addWidget(jidp);

        nickpn = new QWidget(widget_4);
        nickpn->setObjectName(QStringLiteral("nickpn"));
        nickpn->setMinimumSize(QSize(0, 24));
        nickpn->setMaximumSize(QSize(16777215, 24));
        horizontalLayout_4 = new QHBoxLayout(nickpn);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        nicklabel = new QLabel(nickpn);
        nicklabel->setObjectName(QStringLiteral("nicklabel"));
        nicklabel->setMinimumSize(QSize(72, 0));
        nicklabel->setMaximumSize(QSize(72, 16777215));
        nicklabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        nicklabel->setWordWrap(true);
        nicklabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_4->addWidget(nicklabel);

        nickName = new QLabel(nickpn);
        nickName->setObjectName(QStringLiteral("nickName"));
        nickName->setContextMenuPolicy(Qt::DefaultContextMenu);
        nickName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        nickName->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_4->addWidget(nickName);


        verticalLayout_5->addWidget(nickpn);

        webpn = new QWidget(widget_4);
        webpn->setObjectName(QStringLiteral("webpn"));
        webpn->setMinimumSize(QSize(0, 24));
        webpn->setMaximumSize(QSize(16777215, 24));
        horizontalLayout = new QHBoxLayout(webpn);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        weblabel = new QLabel(webpn);
        weblabel->setObjectName(QStringLiteral("weblabel"));
        weblabel->setMinimumSize(QSize(72, 0));
        weblabel->setMaximumSize(QSize(72, 16777215));
        weblabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(weblabel);

        webname = new QLabel(webpn);
        webname->setObjectName(QStringLiteral("webname"));
        webname->setContextMenuPolicy(Qt::DefaultContextMenu);
        webname->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        webname->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(webname);


        verticalLayout_5->addWidget(webpn);

        pathpn = new QWidget(widget_4);
        pathpn->setObjectName(QStringLiteral("pathpn"));
        pathpn->setMinimumSize(QSize(0, 24));
        pathpn->setMaximumSize(QSize(16777215, 24));
        horizontalLayout_2 = new QHBoxLayout(pathpn);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pathlabel = new QLabel(pathpn);
        pathlabel->setObjectName(QStringLiteral("pathlabel"));
        pathlabel->setMinimumSize(QSize(72, 0));
        pathlabel->setMaximumSize(QSize(72, 16777215));
        pathlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pathlabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(pathlabel);

        path = new QLabel(pathpn);
        path->setObjectName(QStringLiteral("path"));
        path->setContextMenuPolicy(Qt::DefaultContextMenu);
        path->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        path->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(path);


        verticalLayout_5->addWidget(pathpn);


        verticalLayout_4->addWidget(widget_4);

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setStyleSheet(QStringLiteral(""));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(2, 0, 2, 0);
        sendmessage = new QPushButton(widget_5);
        sendmessage->setObjectName(QStringLiteral("sendmessage"));
        sendmessage->setFlat(true);

        horizontalLayout_3->addWidget(sendmessage);

        addfriend = new QPushButton(widget_5);
        addfriend->setObjectName(QStringLiteral("addfriend"));

        horizontalLayout_3->addWidget(addfriend);

        pbsetting = new QPushButton(widget_5);
        pbsetting->setObjectName(QStringLiteral("pbsetting"));
        pbsetting->setMinimumSize(QSize(0, 20));
        pbsetting->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_3->addWidget(pbsetting);


        verticalLayout_4->addWidget(widget_5);


        verticalLayout_3->addWidget(widget_3);


        verticalLayout->addWidget(dialogbg);


        retranslateUi(UserMiniProfile);

        QMetaObject::connectSlotsByName(UserMiniProfile);
    } // setupUi

    void retranslateUi(QWidget *UserMiniProfile)
    {
        UserMiniProfile->setWindowTitle(QApplication::translate("UserMiniProfile", "UserMiniProfile", 0));
        header->setText(QString());
        username->setText(QString());
        sex->setText(QString());
        moodInfo->setText(QString());
        downloadheadpercent->setText(QString());
        id_label->setText(QApplication::translate("UserMiniProfile", "ID\357\274\232", 0));
        jid->setText(QString());
        nicklabel->setText(QApplication::translate("UserMiniProfile", "\346\230\265\347\247\260\357\274\232", 0));
        nickName->setText(QString());
        weblabel->setText(QApplication::translate("UserMiniProfile", "\347\275\221\351\241\265\350\212\261\345\220\215\357\274\232", 0));
        webname->setText(QString());
        pathlabel->setText(QApplication::translate("UserMiniProfile", "\347\273\204\347\273\207\346\236\266\346\236\204\357\274\232", 0));
        path->setText(QString());
        sendmessage->setText(QApplication::translate("UserMiniProfile", "\345\217\221\351\200\201\346\266\210\346\201\257", 0));
        addfriend->setText(QApplication::translate("UserMiniProfile", "\345\212\240\344\270\272\345\245\275\345\217\213", 0));
        pbsetting->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserMiniProfile: public Ui_UserMiniProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMINIPROFILE_H

/********************************************************************************
** Form generated from reading UI file 'userprofilewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPROFILEWIDGET_H
#define UI_USERPROFILEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_UserProfileWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *shadowbg;
    QHBoxLayout *horizontalLayout;
    QWidget *shadowinnerbg2;
    QVBoxLayout *verticalLayout_2;
    TitlebarWidget *titlebar;
    QWidget *baseinfo;
    QLabel *btnAvatar;
    QLabel *id;
    QLabel *dep;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *name;
    QLabel *sex;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QStackedWidget *detailinfos;
    QWidget *basepage;
    QVBoxLayout *verticalLayout_3;
    QWidget *infopanel;
    QLabel *lbBoom;
    QLabel *lbLeader;
    QLabel *lbMobile;
    QLabel *lbMark;
    QLineEdit *leBoom;
    QLabel *lbLeaderLink;
    QLabel *lbMobileLink;
    QLineEdit *leMark;
    QLineEdit *leEmpty;
    QWidget *morepage;
    QWidget *infonav;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnBasic;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *UserProfileWidget)
    {
        if (UserProfileWidget->objectName().isEmpty())
            UserProfileWidget->setObjectName(QStringLiteral("UserProfileWidget"));
        UserProfileWidget->resize(550, 450);
        UserProfileWidget->setMinimumSize(QSize(550, 450));
        UserProfileWidget->setMaximumSize(QSize(550, 450));
        UserProfileWidget->setStyleSheet(QLatin1String("QLabel#name{ font-size:22px;color:#111111; font-weight: bold;}\n"
"QLabel#id{ font-size:12px;color:#333333;}\n"
"QLabel#dep{ font-size:12px;color:#333333;}\n"
"QLabel#btnAvatar{border:2px solid #A0FFFFFF;}\n"
"QLabel#btnAvatar:hover{border:2px solid #1194a4;}\n"
"\n"
"QPushButton#btnBasic,#btnMore{height:27px;width:70px;color: #666666; background-color: #FFFFFF; border:none;}\n"
"QPushButton#btnBasic:hover,#btnMore:hover {color: #FFFFFF;background-color: #3dbbca;}\n"
"QPushButton#btnBasic:pressed,#btnMore:pressed{color: #FFFFFF; background-color: #1194a4;}\n"
"QPushButton#btnBasic:checked,#btnMore:checked{color: #FFFFFF; background-color: #1ba9ba;}\n"
"\n"
"QPushButton#btnBasic,#btnMore{ border-left:1px solid #1ba9ba; border-top:1px solid #1ba9ba; border-bottom:1px solid #1ba9ba;}\n"
"QPushButton#btnBasic{ border-right:1px solid #1ba9ba;}\n"
"\n"
"\n"
"QWidget#infopanel{border-radius: 10px;background-color: #E2E2E2;margin: 20px 10px 20px 10px}\n"
"\n"
"\n"
"QLineEdit{ background-color: #00000000; border:none;p"
                        "adding-left:-2px;}\n"
"QLineEdit:hover{ border:1px solid #999999;}\n"
"QLineEdit:focus{ background-color: #FFFFFF; border-width: 1px; border-style: solid; border-color: #1BA9BA;}\n"
"QLineEdit:disabled{ background-color: #ECECEC; border:none;}"));
        verticalLayout = new QVBoxLayout(UserProfileWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(UserProfileWidget);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        horizontalLayout = new QHBoxLayout(shadowbg);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg2 = new QWidget(shadowbg);
        shadowinnerbg2->setObjectName(QStringLiteral("shadowinnerbg2"));
        shadowinnerbg2->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(shadowinnerbg2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        titlebar = new TitlebarWidget(shadowinnerbg2);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 27));
        titlebar->setMaximumSize(QSize(16777215, 27));

        verticalLayout_2->addWidget(titlebar);

        baseinfo = new QWidget(shadowinnerbg2);
        baseinfo->setObjectName(QStringLiteral("baseinfo"));
        baseinfo->setMinimumSize(QSize(0, 150));
        baseinfo->setMaximumSize(QSize(16777215, 150));
        btnAvatar = new QLabel(baseinfo);
        btnAvatar->setObjectName(QStringLiteral("btnAvatar"));
        btnAvatar->setGeometry(QRect(30, 30, 100, 100));
        btnAvatar->setMinimumSize(QSize(100, 100));
        btnAvatar->setMaximumSize(QSize(100, 100));
        btnAvatar->setCursor(QCursor(Qt::ArrowCursor));
        btnAvatar->setProperty("iconSize", QVariant(QSize(96, 96)));
        btnAvatar->setProperty("flat", QVariant(true));
        id = new QLabel(baseinfo);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(150, 61, 341, 22));
        id->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        dep = new QLabel(baseinfo);
        dep->setObjectName(QStringLiteral("dep"));
        dep->setGeometry(QRect(150, 85, 231, 61));
        dep->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        dep->setWordWrap(true);
        dep->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        widget_2 = new QWidget(baseinfo);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(150, 31, 331, 28));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        name = new QLabel(widget_2);
        name->setObjectName(QStringLiteral("name"));
        name->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_3->addWidget(name);

        sex = new QLabel(widget_2);
        sex->setObjectName(QStringLiteral("sex"));
        sex->setMinimumSize(QSize(27, 27));
        sex->setMaximumSize(QSize(27, 27));

        horizontalLayout_3->addWidget(sex);

        horizontalSpacer_2 = new QSpacerItem(219, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(baseinfo);

        widget = new QWidget(shadowinnerbg2);
        widget->setObjectName(QStringLiteral("widget"));
        detailinfos = new QStackedWidget(widget);
        detailinfos->setObjectName(QStringLiteral("detailinfos"));
        detailinfos->setGeometry(QRect(0, 0, 532, 255));
        basepage = new QWidget();
        basepage->setObjectName(QStringLiteral("basepage"));
        verticalLayout_3 = new QVBoxLayout(basepage);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        infopanel = new QWidget(basepage);
        infopanel->setObjectName(QStringLiteral("infopanel"));
        lbBoom = new QLabel(infopanel);
        lbBoom->setObjectName(QStringLiteral("lbBoom"));
        lbBoom->setGeometry(QRect(60, 70, 70, 28));
        lbBoom->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbLeader = new QLabel(infopanel);
        lbLeader->setObjectName(QStringLiteral("lbLeader"));
        lbLeader->setGeometry(QRect(60, 100, 70, 28));
        lbLeader->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbMobile = new QLabel(infopanel);
        lbMobile->setObjectName(QStringLiteral("lbMobile"));
        lbMobile->setGeometry(QRect(60, 130, 70, 28));
        lbMobile->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbMark = new QLabel(infopanel);
        lbMark->setObjectName(QStringLiteral("lbMark"));
        lbMark->setGeometry(QRect(60, 160, 70, 28));
        lbMark->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        leBoom = new QLineEdit(infopanel);
        leBoom->setObjectName(QStringLiteral("leBoom"));
        leBoom->setGeometry(QRect(140, 70, 361, 28));
        leBoom->setStyleSheet(QStringLiteral(""));
        lbLeaderLink = new QLabel(infopanel);
        lbLeaderLink->setObjectName(QStringLiteral("lbLeaderLink"));
        lbLeaderLink->setGeometry(QRect(140, 100, 361, 28));
        lbLeaderLink->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);
        lbMobileLink = new QLabel(infopanel);
        lbMobileLink->setObjectName(QStringLiteral("lbMobileLink"));
        lbMobileLink->setGeometry(QRect(140, 130, 361, 28));
        lbMobileLink->setOpenExternalLinks(false);
        lbMobileLink->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);
        leMark = new QLineEdit(infopanel);
        leMark->setObjectName(QStringLiteral("leMark"));
        leMark->setGeometry(QRect(140, 160, 361, 28));
        leEmpty = new QLineEdit(infopanel);
        leEmpty->setObjectName(QStringLiteral("leEmpty"));
        leEmpty->setGeometry(QRect(0, 0, 0, 0));

        verticalLayout_3->addWidget(infopanel);

        detailinfos->addWidget(basepage);
        morepage = new QWidget();
        morepage->setObjectName(QStringLiteral("morepage"));
        detailinfos->addWidget(morepage);
        infonav = new QWidget(widget);
        infonav->setObjectName(QStringLiteral("infonav"));
        infonav->setGeometry(QRect(0, 0, 532, 40));
        infonav->setMinimumSize(QSize(0, 40));
        infonav->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_2 = new QHBoxLayout(infonav);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btnBasic = new QPushButton(infonav);
        btnBasic->setObjectName(QStringLiteral("btnBasic"));
        btnBasic->setEnabled(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/aio_startsession_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBasic->setIcon(icon);
        btnBasic->setCheckable(true);
        btnBasic->setChecked(true);
        btnBasic->setAutoExclusive(true);

        horizontalLayout_2->addWidget(btnBasic);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(widget);


        horizontalLayout->addWidget(shadowinnerbg2);


        verticalLayout->addWidget(shadowbg);


        retranslateUi(UserProfileWidget);

        QMetaObject::connectSlotsByName(UserProfileWidget);
    } // setupUi

    void retranslateUi(QWidget *UserProfileWidget)
    {
        UserProfileWidget->setWindowTitle(QApplication::translate("UserProfileWidget", "UserProfileWidget", 0));
#ifndef QT_NO_TOOLTIP
        btnAvatar->setToolTip(QApplication::translate("UserProfileWidget", "\346\233\264\346\215\242\345\244\264\345\203\217", 0));
#endif // QT_NO_TOOLTIP
        btnAvatar->setText(QString());
        id->setText(QApplication::translate("UserProfileWidget", "wz.wang", 0));
        dep->setText(QApplication::translate("UserProfileWidget", "QunarStaff/\346\227\205\346\270\270\345\272\246\345\201\207\344\272\213\344\270\232\351\203\250/\346\212\200\346\234\257/\345\275\223\345\234\260\344\272\272\345\256\242\346\210\267\347\253\257\345\274\200\345\217\221/", 0));
        name->setText(QApplication::translate("UserProfileWidget", "\347\216\213\345\276\201wz", 0));
        sex->setText(QString());
        lbBoom->setText(QApplication::translate("UserProfileWidget", "\344\270\252\346\200\247\347\255\276\345\220\215\357\274\232", 0));
        lbLeader->setText(QApplication::translate("UserProfileWidget", "\347\233\264\345\261\236\351\242\206\345\257\274\357\274\232", 0));
        lbMobile->setText(QApplication::translate("UserProfileWidget", "\346\211\213\346\234\272\345\217\267\357\274\232", 0));
        lbMark->setText(QApplication::translate("UserProfileWidget", "\345\244\207\346\263\250\357\274\232", 0));
        leBoom->setPlaceholderText(QApplication::translate("UserProfileWidget", "\347\202\271\345\207\273\347\274\226\350\276\221\344\270\252\346\200\247\347\255\276\345\220\215", 0));
        lbLeaderLink->setText(QApplication::translate("UserProfileWidget", "TextLabel", 0));
        lbMobileLink->setText(QApplication::translate("UserProfileWidget", "<html><head/><body><p><a><span style=\" text-decoration: underline; color:#0000ff;\">\347\202\271\345\207\273\346\237\245\347\234\213</span></a></p></body></html>", 0));
        leMark->setPlaceholderText(QApplication::translate("UserProfileWidget", "\347\202\271\345\207\273\347\274\226\350\276\221\345\244\207\346\263\250", 0));
        btnBasic->setText(QApplication::translate("UserProfileWidget", "\350\265\204\346\226\231", 0));
    } // retranslateUi

};

namespace Ui {
    class UserProfileWidget: public Ui_UserProfileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPROFILEWIDGET_H

/********************************************************************************
** Form generated from reading UI file 'NavManagerDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVMANAGERDIALOG_H
#define UI_NAVMANAGERDIALOG_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_NavManagerDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout_3;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout_2;
    TitlebarWidget *titlebar;
    QWidget *widget_8;
    QRadioButton *radbtn_xmpp;
    QRadioButton *radbtn_pb;
    QWidget *widget;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_erCode;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_title;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_yu;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QTextEdit *textEdit_nav;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbt_addNav;
    QPushButton *pbt_deleteNav;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbt_applyNav;
    QPushButton *pbt_adver;
    QPushButton *pbt_selectnone;

    void setupUi(QWidget *NavManagerDialog)
    {
        if (NavManagerDialog->objectName().isEmpty())
            NavManagerDialog->setObjectName(QStringLiteral("NavManagerDialog"));
        NavManagerDialog->resize(529, 450);
        NavManagerDialog->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QWidget#widget_4\n"
"{\n"
"	border-left:1px solid #919191; \n"
"	border-bottom:1px solid #919191 ;\n"
"    border-right:1px solid #919191;\n"
"}\n"
"\n"
"QPushButton#pbt_addNav\n"
"{\n"
"	border-top:1px ;\n"
"    border-bottom:1px ;\n"
"	border-right:1px solid #919191;\n"
"	image: url(:/Images/icon/nav_add.png);    \n"
"}\n"
"\n"
"QPushButton#pbt_addNav:hover\n"
"{\n"
"	image: url(:/Images/icon/nav_add_hover.png); \n"
"}\n"
"\n"
"QPushButton#pbt_deleteNav\n"
"{\n"
"	border-top:1px ;\n"
"    border-bottom:1px ;\n"
"	border-right:1px solid #919191;\n"
"	image: url(:/Images/icon/nav_sub.png); \n"
"}\n"
"QPushButton#pbt_deleteNav:hover\n"
"{\n"
"	image: url(:/Images/icon/nav_sub_hover.png); \n"
"}\n"
"\n"
"QPushButton#pbt_applyNav,QPushButton#pbt_selectnone\n"
"{\n"
"	background:#1ba9ba;\n"
"	color:#efefef;\n"
"	border:none;\n"
"}\n"
"QPushButton#pbt_applyNav:hover,QPushButton#pbt_selectnone:hover\n"
"{\n"
"	backgro"
                        "und:#3dbbca;\n"
"}\n"
"\n"
"QPushButton#pbt_adver\n"
"{\n"
"	color: #666666;\n"
"	background-color: #FFFFFF;\n"
"	border:none;\n"
"}\n"
"QPushButton#pbt_adver:hover\n"
"{\n"
"	color: #FFFFFF;\n"
"	background-color: #3dbbca;\n"
"}\n"
"QRadioButton#radbtn_pb,QRadioButton#radbtn_xmpp\n"
"{\n"
"	 font-size: 12px;\n"
"	font-weight:bold;\n"
"}\n"
"QLabel#label_yu\n"
"{\n"
"	font-size: 12px;\n"
"	font-weight:bold;\n"
"}\n"
"QWidget#widget_2\n"
"{\n"
"	background-color: #E2E2E2;\n"
"}\n"
"QLineEdit{\n"
"	font-size: 12px;\n"
"	font-weight:bold;\n"
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
"	font-size: 12px;\n"
"	font-weight:bold;\n"
"    background: #FFFFFF;\n"
"    border:none;\n"
""
                        "}\n"
"\n"
"QTextEdit:focus{\n"
"    background-color: #FFFFFF;\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"    border-color: #1BA9BA;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(NavManagerDialog);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(NavManagerDialog);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        verticalLayout_3 = new QVBoxLayout(shadowbg);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        verticalLayout_2 = new QVBoxLayout(shadowinnerbg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        titlebar = new TitlebarWidget(shadowinnerbg);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 30));
        titlebar->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(titlebar);

        widget_8 = new QWidget(shadowinnerbg);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMinimumSize(QSize(0, 30));
        widget_8->setMaximumSize(QSize(16777215, 30));
        radbtn_xmpp = new QRadioButton(widget_8);
        radbtn_xmpp->setObjectName(QStringLiteral("radbtn_xmpp"));
        radbtn_xmpp->setGeometry(QRect(140, 10, 89, 16));
        radbtn_pb = new QRadioButton(widget_8);
        radbtn_pb->setObjectName(QStringLiteral("radbtn_pb"));
        radbtn_pb->setGeometry(QRect(290, 10, 89, 16));

        verticalLayout_2->addWidget(widget_8);

        widget = new QWidget(shadowinnerbg);
        widget->setObjectName(QStringLiteral("widget"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(210, 10, 300, 313));
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 5, 0);
        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(73, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        label_erCode = new QLabel(widget_6);
        label_erCode->setObjectName(QStringLiteral("label_erCode"));
        label_erCode->setMinimumSize(QSize(120, 120));
        label_erCode->setMaximumSize(QSize(120, 120));

        horizontalLayout_5->addWidget(label_erCode);

        horizontalSpacer_3 = new QSpacerItem(72, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_5->addWidget(widget_6);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(0, 31));
        widget_5->setMaximumSize(QSize(16777215, 31));
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(30, 0, 5, 0);
        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(31, 0));
        label_2->setMaximumSize(QSize(31, 16777215));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_title = new QLineEdit(widget_5);
        lineEdit_title->setObjectName(QStringLiteral("lineEdit_title"));
        lineEdit_title->setMinimumSize(QSize(0, 0));
        lineEdit_title->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(lineEdit_title);

        lineEdit_title->raise();
        label_2->raise();

        verticalLayout_5->addWidget(widget_5);

        widget_9 = new QWidget(widget_2);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setMinimumSize(QSize(0, 31));
        widget_9->setMaximumSize(QSize(16777215, 31));
        horizontalLayout_3 = new QHBoxLayout(widget_9);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(30, 0, 5, 0);
        label = new QLabel(widget_9);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(31, 0));
        label->setMaximumSize(QSize(31, 16777215));

        horizontalLayout_3->addWidget(label);

        label_yu = new QLabel(widget_9);
        label_yu->setObjectName(QStringLiteral("label_yu"));

        horizontalLayout_3->addWidget(label_yu);


        verticalLayout_5->addWidget(widget_9);

        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setMinimumSize(QSize(0, 91));
        widget_7->setMaximumSize(QSize(16777215, 91));
        horizontalLayout_4 = new QHBoxLayout(widget_7);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, 3, 5, 0);
        label_4 = new QLabel(widget_7);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(54, 30));
        label_4->setMaximumSize(QSize(54, 16777215));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_4->addWidget(label_4);

        textEdit_nav = new QTextEdit(widget_7);
        textEdit_nav->setObjectName(QStringLiteral("textEdit_nav"));
        textEdit_nav->setMinimumSize(QSize(0, 80));
        textEdit_nav->setMaximumSize(QSize(16777215, 80));

        horizontalLayout_4->addWidget(textEdit_nav);


        verticalLayout_5->addWidget(widget_7);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(0, 10, 201, 371));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 0, 0, 20);
        listWidget = new QListWidget(widget_3);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 0, 0, 0);
        pbt_addNav = new QPushButton(widget_4);
        pbt_addNav->setObjectName(QStringLiteral("pbt_addNav"));
        pbt_addNav->setMinimumSize(QSize(23, 23));
        pbt_addNav->setMaximumSize(QSize(23, 23));
        pbt_addNav->setFlat(true);

        horizontalLayout->addWidget(pbt_addNav);

        pbt_deleteNav = new QPushButton(widget_4);
        pbt_deleteNav->setObjectName(QStringLiteral("pbt_deleteNav"));
        pbt_deleteNav->setMinimumSize(QSize(23, 23));
        pbt_deleteNav->setMaximumSize(QSize(23, 23));
        pbt_deleteNav->setFlat(true);

        horizontalLayout->addWidget(pbt_deleteNav);

        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget_4);

        pbt_applyNav = new QPushButton(widget);
        pbt_applyNav->setObjectName(QStringLiteral("pbt_applyNav"));
        pbt_applyNav->setGeometry(QRect(407, 338, 75, 23));
        pbt_applyNav->setFlat(true);
        pbt_adver = new QPushButton(widget);
        pbt_adver->setObjectName(QStringLiteral("pbt_adver"));
        pbt_adver->setGeometry(QRect(230, 338, 75, 23));
        pbt_adver->setFlat(true);
        pbt_selectnone = new QPushButton(widget);
        pbt_selectnone->setObjectName(QStringLiteral("pbt_selectnone"));
        pbt_selectnone->setGeometry(QRect(320, 340, 75, 23));
        pbt_selectnone->setFlat(true);

        verticalLayout_2->addWidget(widget);


        verticalLayout_3->addWidget(shadowinnerbg);


        verticalLayout_4->addWidget(shadowbg);


        retranslateUi(NavManagerDialog);

        QMetaObject::connectSlotsByName(NavManagerDialog);
    } // setupUi

    void retranslateUi(QWidget *NavManagerDialog)
    {
        NavManagerDialog->setWindowTitle(QApplication::translate("NavManagerDialog", "Dialog", 0));
        radbtn_xmpp->setText(QApplication::translate("NavManagerDialog", "xmpp\345\215\217\350\256\256", 0));
        radbtn_pb->setText(QApplication::translate("NavManagerDialog", "pb\345\215\217\350\256\256", 0));
        label_erCode->setText(QString());
        label_2->setText(QApplication::translate("NavManagerDialog", "\345\220\215\347\247\260:", 0));
        label->setText(QApplication::translate("NavManagerDialog", "\345\237\237\345\220\215:", 0));
        label_yu->setText(QString());
        label_4->setText(QApplication::translate("NavManagerDialog", "\345\257\274\350\210\252\345\234\260\345\235\200:", 0));
#ifndef QT_NO_TOOLTIP
        pbt_addNav->setToolTip(QApplication::translate("NavManagerDialog", "\346\226\260\346\267\273\345\212\240", 0));
#endif // QT_NO_TOOLTIP
        pbt_addNav->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbt_deleteNav->setToolTip(QApplication::translate("NavManagerDialog", "\345\210\240\351\231\244\351\241\271", 0));
#endif // QT_NO_TOOLTIP
        pbt_deleteNav->setText(QString());
        pbt_applyNav->setText(QApplication::translate("NavManagerDialog", "\345\272\224\347\224\250", 0));
        pbt_adver->setText(QApplication::translate("NavManagerDialog", "\351\253\230\347\272\247", 0));
        pbt_selectnone->setText(QApplication::translate("NavManagerDialog", "\346\270\205\351\231\244\346\211\200\346\234\211", 0));
    } // retranslateUi

};

namespace Ui {
    class NavManagerDialog: public Ui_NavManagerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVMANAGERDIALOG_H

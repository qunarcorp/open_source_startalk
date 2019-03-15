/********************************************************************************
** Form generated from reading UI file 'MainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

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
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QWidget *maintablist;
    QVBoxLayout *verticalLayout_7;
    QWidget *portraitWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *portraitpanel;
    StaticLabel *portrait;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *precencebtn;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *combinationPannel;
    QPushButton *combinationbtn;
    QLabel *unreadworksIcon;
    QWidget *chatbtnpannel;
    QPushButton *chatsbtn;
    QLabel *unreadcount;
    QWidget *unreadpromot;
    QSpacerItem *verticalSpacer;
    QWidget *bottomWidget;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pbDingdan;
    QPushButton *questionBtn;
    QPushButton *mainMenuBtn;
    QPushButton *setting;
    QWidget *multicontainer;
    QHBoxLayout *multicontainer_layout;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(902, 522);
        MainWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(MainWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(MainWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(900, 520));
        widget_4->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        maintablist = new QWidget(widget_4);
        maintablist->setObjectName(QStringLiteral("maintablist"));
        maintablist->setMaximumSize(QSize(48, 16777215));
        verticalLayout_7 = new QVBoxLayout(maintablist);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        portraitWidget = new QWidget(maintablist);
        portraitWidget->setObjectName(QStringLiteral("portraitWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(portraitWidget->sizePolicy().hasHeightForWidth());
        portraitWidget->setSizePolicy(sizePolicy);
        portraitWidget->setMinimumSize(QSize(0, 60));
        verticalLayout_2 = new QVBoxLayout(portraitWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(portraitWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 10, 0, 10);
        portraitpanel = new QWidget(widget_2);
        portraitpanel->setObjectName(QStringLiteral("portraitpanel"));
        portraitpanel->setMinimumSize(QSize(28, 28));
        portraitpanel->setMaximumSize(QSize(28, 28));
        portrait = new StaticLabel(portraitpanel);
        portrait->setObjectName(QStringLiteral("portrait"));
        portrait->setGeometry(QRect(0, 0, 28, 28));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(portrait->sizePolicy().hasHeightForWidth());
        portrait->setSizePolicy(sizePolicy1);
        portrait->setMinimumSize(QSize(28, 28));
        portrait->setMaximumSize(QSize(28, 28));
        portrait->setCursor(QCursor(Qt::PointingHandCursor));
        portrait->setStyleSheet(QStringLiteral(""));
        portrait->setProperty("flat", QVariant(true));

        horizontalLayout_2->addWidget(portraitpanel);


        verticalLayout_2->addWidget(widget_2);

        widget_5 = new QWidget(portraitWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        precencebtn = new QPushButton(widget_5);
        precencebtn->setObjectName(QStringLiteral("precencebtn"));
        precencebtn->setMinimumSize(QSize(12, 12));
        precencebtn->setMaximumSize(QSize(12, 12));
        precencebtn->setText(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/presence_online.png"), QSize(), QIcon::Normal, QIcon::Off);
        precencebtn->setIcon(icon);
        precencebtn->setAutoDefault(false);
        precencebtn->setFlat(true);

        horizontalLayout_4->addWidget(precencebtn);


        verticalLayout_2->addWidget(widget_5);


        verticalLayout_7->addWidget(portraitWidget);

        widget = new QWidget(maintablist);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(16777215, 86));
        widget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 10, 0, 10);
        combinationPannel = new QWidget(widget);
        combinationPannel->setObjectName(QStringLiteral("combinationPannel"));
        combinationPannel->setMinimumSize(QSize(0, 28));
        combinationPannel->setMaximumSize(QSize(16777215, 28));
        combinationbtn = new QPushButton(combinationPannel);
        combinationbtn->setObjectName(QStringLiteral("combinationbtn"));
        combinationbtn->setGeometry(QRect(0, 0, 48, 28));
        combinationbtn->setMinimumSize(QSize(0, 28));
        combinationbtn->setMaximumSize(QSize(16777215, 28));
        combinationbtn->setStyleSheet(QStringLiteral(""));
        combinationbtn->setCheckable(true);
        combinationbtn->setFlat(true);
        unreadworksIcon = new QLabel(combinationPannel);
        unreadworksIcon->setObjectName(QStringLiteral("unreadworksIcon"));
        unreadworksIcon->setGeometry(QRect(20, 10, 12, 12));
        unreadworksIcon->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(combinationPannel);

        chatbtnpannel = new QWidget(widget);
        chatbtnpannel->setObjectName(QStringLiteral("chatbtnpannel"));
        chatbtnpannel->setMinimumSize(QSize(0, 28));
        chatbtnpannel->setMaximumSize(QSize(16777215, 28));
        chatbtnpannel->setSizeIncrement(QSize(0, 28));
        chatbtnpannel->setStyleSheet(QLatin1String("QLabel#unreadcount{\n"
"	font-size:11px;\n"
"    min-width:15px;\n"
"	min-height:15px;\n"
"	max-height:15px;\n"
"    color: #FFFFFF;\n"
"    background:#F55F56;\n"
"    border-radius:7px;\n"
"    padding-left:4px;\n"
"    padding-right:4px;\n"
"}\n"
"\n"
"QWidget#unreadpromot{\n"
"    min-width:8px;\n"
"	min-height:8px;\n"
"	max-height:8px;\n"
"    max-width:8px;\n"
"    background:#F55F56;\n"
"    border-radius:4px;\n"
"}\n"
"\n"
"\n"
""));
        chatsbtn = new QPushButton(chatbtnpannel);
        chatsbtn->setObjectName(QStringLiteral("chatsbtn"));
        chatsbtn->setGeometry(QRect(0, 0, 48, 28));
        chatsbtn->setCheckable(true);
        chatsbtn->setFlat(true);
        unreadcount = new QLabel(chatbtnpannel);
        unreadcount->setObjectName(QStringLiteral("unreadcount"));
        unreadcount->setEnabled(true);
        unreadcount->setGeometry(QRect(20, 10, 23, 15));
        unreadcount->setMinimumSize(QSize(23, 15));
        unreadcount->setMaximumSize(QSize(12, 15));
        unreadcount->setSizeIncrement(QSize(0, 0));
        unreadcount->setStyleSheet(QStringLiteral(""));
        unreadcount->setTextFormat(Qt::PlainText);
        unreadcount->setScaledContents(false);
        unreadcount->setAlignment(Qt::AlignCenter);
        unreadcount->setTextInteractionFlags(Qt::NoTextInteraction);
        unreadpromot = new QWidget(chatbtnpannel);
        unreadpromot->setObjectName(QStringLiteral("unreadpromot"));
        unreadpromot->setGeometry(QRect(0, 0, 8, 8));
        unreadpromot->setMinimumSize(QSize(8, 8));
        unreadpromot->setMaximumSize(QSize(8, 8));
        unreadpromot->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(chatbtnpannel);


        verticalLayout_7->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        bottomWidget = new QWidget(maintablist);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(0, 210));
        bottomWidget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_4 = new QVBoxLayout(bottomWidget);
        verticalLayout_4->setSpacing(32);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(10, 0, 10, 32);
        pbDingdan = new QPushButton(bottomWidget);
        pbDingdan->setObjectName(QStringLiteral("pbDingdan"));
        pbDingdan->setMinimumSize(QSize(30, 30));
        pbDingdan->setMaximumSize(QSize(30, 30));
        pbDingdan->setFlat(true);

        verticalLayout_4->addWidget(pbDingdan);

        questionBtn = new QPushButton(bottomWidget);
        questionBtn->setObjectName(QStringLiteral("questionBtn"));
        sizePolicy1.setHeightForWidth(questionBtn->sizePolicy().hasHeightForWidth());
        questionBtn->setSizePolicy(sizePolicy1);
        questionBtn->setMinimumSize(QSize(28, 28));
        questionBtn->setMaximumSize(QSize(28, 28));
        questionBtn->setFlat(true);

        verticalLayout_4->addWidget(questionBtn);

        mainMenuBtn = new QPushButton(bottomWidget);
        mainMenuBtn->setObjectName(QStringLiteral("mainMenuBtn"));
        sizePolicy1.setHeightForWidth(mainMenuBtn->sizePolicy().hasHeightForWidth());
        mainMenuBtn->setSizePolicy(sizePolicy1);
        mainMenuBtn->setMinimumSize(QSize(28, 28));
        mainMenuBtn->setMaximumSize(QSize(28, 28));
        mainMenuBtn->setFlat(true);

        verticalLayout_4->addWidget(mainMenuBtn);

        setting = new QPushButton(bottomWidget);
        setting->setObjectName(QStringLiteral("setting"));
        setting->setMinimumSize(QSize(28, 28));
        setting->setMaximumSize(QSize(28, 28));
        setting->setFlat(true);

        verticalLayout_4->addWidget(setting);


        verticalLayout_7->addWidget(bottomWidget);


        horizontalLayout->addWidget(maintablist);

        multicontainer = new QWidget(widget_4);
        multicontainer->setObjectName(QStringLiteral("multicontainer"));
        multicontainer->setStyleSheet(QStringLiteral(""));
        multicontainer_layout = new QHBoxLayout(multicontainer);
        multicontainer_layout->setSpacing(0);
        multicontainer_layout->setObjectName(QStringLiteral("multicontainer_layout"));
        multicontainer_layout->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(multicontainer);


        verticalLayout_3->addWidget(widget_4);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "Form", 0));
        portrait->setText(QString());
        combinationbtn->setText(QString());
        unreadworksIcon->setText(QString());
        chatsbtn->setText(QString());
        unreadcount->setText(QString());
        pbDingdan->setText(QString());
        questionBtn->setText(QString());
        mainMenuBtn->setText(QString());
        setting->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H

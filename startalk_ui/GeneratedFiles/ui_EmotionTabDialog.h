/********************************************************************************
** Form generated from reading UI file 'EmotionTabDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMOTIONTABDIALOG_H
#define UI_EMOTIONTABDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmotionTabDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *contentpanel;
    QStackedWidget *stackedWidget;
    QWidget *emotListPanel;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea_2;
    QWidget *emotcionpanel;
    QVBoxLayout *verticalLayout_2;
    QWidget *emotcionShop;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QWidget *btnpanel;
    QHBoxLayout *horizontalLayout;
    QToolButton *leftpage;
    QScrollArea *scrollArea;
    QWidget *btngroup;
    QHBoxLayout *btngroup_layout;
    QPushButton *emotList;
    QToolButton *rightpage;
    QWidget *widget_setting;
    QVBoxLayout *verticalLayout_5;
    QPushButton *setting;

    void setupUi(QWidget *EmotionTabDialog)
    {
        if (EmotionTabDialog->objectName().isEmpty())
            EmotionTabDialog->setObjectName(QStringLiteral("EmotionTabDialog"));
        EmotionTabDialog->resize(459, 299);
        EmotionTabDialog->setMinimumSize(QSize(459, 299));
        EmotionTabDialog->setMaximumSize(QSize(459, 299));
        EmotionTabDialog->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"    font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"\n"
"QWidget#widget\n"
"{\n"
"	background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #edeeef, stop: 1.0 #d4d7da);\n"
"}\n"
"\n"
"#btnpanel QPushButton\n"
"{\n"
"	border:1px solid #00000000;\n"
"    font-size:14px;\n"
"    color:#FFFFFF;\n"
"    padding:5px;\n"
"    background-color:#3DCE3D;\n"
"}\n"
"\n"
"#btnpanel QPushButton:hover\n"
"{\n"
"    background-color:#38C738;\n"
"}\n"
"#btnpanel QPushButton:presse\n"
"{\n"
"    background-color:#2FB82F;\n"
"}\n"
"#btnpanel QPushButton:checked\n"
"{\n"
"    background-color:#FFFFFF;\n"
"	color:#666666;\n"
"}\n"
"#btnpanel QPushButton:disabled\n"
"{\n"
"    background-color:#9DE69D;\n"
"}\n"
"\n"
"QPushButton#setting {\n"
"    border : 1px solid #00000000;\n"
"    image: url(:/Images/mainpanel_setting_normal.png);\n"
"}\n"
"\n"
"QPushButton#setting:hover {\n"
"    image: url(:/Images/mainpanel_setting_hover.png);\n"
"}"
                        "\n"
"QPushButton#setting:pressed {\n"
"    image: url(:/Images/mainpanel_setting_pressed.png);\n"
"}\n"
"\n"
"QWidget#scrollArea,#btngroup\n"
"{\n"
"	border:none;\n"
"	background-color:#00000000;\n"
"}\n"
"QToolButton#leftpage,QToolButton#rightpage{  \n"
"\n"
"background: #3DCE3D;\n"
" color: rgb(0, 0, 0);\n"
"border-style:flat;  \n"
" \n"
"}  \n"
""));
        horizontalLayout_2 = new QHBoxLayout(EmotionTabDialog);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(EmotionTabDialog);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        contentpanel = new QWidget(widget);
        contentpanel->setObjectName(QStringLiteral("contentpanel"));
        stackedWidget = new QStackedWidget(contentpanel);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 152, 269));
        stackedWidget->setMinimumSize(QSize(0, 239));
        emotListPanel = new QWidget(contentpanel);
        emotListPanel->setObjectName(QStringLiteral("emotListPanel"));
        emotListPanel->setGeometry(QRect(80, 80, 87, 87));
        emotListPanel->setStyleSheet(QLatin1String("QWidget#emotcionpanel\n"
"{\n"
"    background-color:#E2E4E6;\n"
"	border:none;\n"
"}\n"
"\n"
"QWidget#emotListPanel\n"
"{\n"
"    background-color:#AA000000;\n"
"	border:none;\n"
"}\n"
"\n"
"QWidget#scrollArea_2\n"
"{\n"
"	border:none;\n"
"}\n"
"\n"
"\n"
""));
        verticalLayout_4 = new QVBoxLayout(emotListPanel);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(20, 20, 20, 20);
        scrollArea_2 = new QScrollArea(emotListPanel);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setStyleSheet(QStringLiteral(""));
        scrollArea_2->setWidgetResizable(true);
        emotcionpanel = new QWidget();
        emotcionpanel->setObjectName(QStringLiteral("emotcionpanel"));
        emotcionpanel->setGeometry(QRect(0, 0, 47, 47));
        emotcionpanel->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QWidget\n"
"{\n"
"    font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"    color:#333333;\n"
"}\n"
"#emotcionShop QPushButton\n"
"{\n"
"	border:1px solid #00000000;\n"
"    font-size:14px;\n"
"    color:#FFFFFF;\n"
"    padding:5px;\n"
"    background-color:#3DCE3D;\n"
"}\n"
"\n"
"#emotcionShop QPushButton:hover\n"
"{\n"
"    background-color:#38C738;\n"
"}\n"
"#emotcionShop QPushButton:presse\n"
"{\n"
"    background-color:#2FB82F;\n"
"}\n"
"#emotcionShop QPushButton:checked\n"
"{\n"
"    background-color:#FFFFFF;\n"
"	color:#666666;\n"
"}\n"
"#emotcionShop QPushButton:disabled\n"
"{\n"
"    background-color:#9DE69D;\n"
"}\n"
""));
        verticalLayout_2 = new QVBoxLayout(emotcionpanel);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 0, 10, 0);
        emotcionShop = new QWidget(emotcionpanel);
        emotcionShop->setObjectName(QStringLiteral("emotcionShop"));
        verticalLayout_3 = new QVBoxLayout(emotcionShop);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

        verticalLayout_2->addWidget(emotcionShop);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        scrollArea_2->setWidget(emotcionpanel);

        verticalLayout_4->addWidget(scrollArea_2);


        verticalLayout->addWidget(contentpanel);

        btnpanel = new QWidget(widget);
        btnpanel->setObjectName(QStringLiteral("btnpanel"));
        btnpanel->setMinimumSize(QSize(0, 30));
        btnpanel->setMaximumSize(QSize(16777215, 30));
        horizontalLayout = new QHBoxLayout(btnpanel);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        leftpage = new QToolButton(btnpanel);
        leftpage->setObjectName(QStringLiteral("leftpage"));
        leftpage->setMinimumSize(QSize(22, 30));
        leftpage->setMaximumSize(QSize(22, 30));
        leftpage->setStyleSheet(QStringLiteral(""));
        leftpage->setCheckable(false);
        leftpage->setPopupMode(QToolButton::DelayedPopup);
        leftpage->setArrowType(Qt::LeftArrow);

        horizontalLayout->addWidget(leftpage);

        scrollArea = new QScrollArea(btnpanel);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(0, 30));
        scrollArea->setMaximumSize(QSize(16777215, 30));
        scrollArea->setStyleSheet(QStringLiteral(""));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        btngroup = new QWidget();
        btngroup->setObjectName(QStringLiteral("btngroup"));
        btngroup->setGeometry(QRect(0, 0, 360, 30));
        btngroup->setMinimumSize(QSize(0, 30));
        btngroup->setMaximumSize(QSize(16777215, 30));
        btngroup_layout = new QHBoxLayout(btngroup);
        btngroup_layout->setSpacing(2);
        btngroup_layout->setObjectName(QStringLiteral("btngroup_layout"));
        btngroup_layout->setContentsMargins(0, 0, 0, 0);
        emotList = new QPushButton(btngroup);
        emotList->setObjectName(QStringLiteral("emotList"));
        emotList->setMaximumSize(QSize(70, 16777215));
        emotList->setCheckable(true);

        btngroup_layout->addWidget(emotList);

        scrollArea->setWidget(btngroup);

        horizontalLayout->addWidget(scrollArea);

        rightpage = new QToolButton(btnpanel);
        rightpage->setObjectName(QStringLiteral("rightpage"));
        rightpage->setMinimumSize(QSize(22, 30));
        rightpage->setMaximumSize(QSize(22, 30));
        rightpage->setCheckable(false);
        rightpage->setPopupMode(QToolButton::DelayedPopup);
        rightpage->setArrowType(Qt::RightArrow);

        horizontalLayout->addWidget(rightpage);

        widget_setting = new QWidget(btnpanel);
        widget_setting->setObjectName(QStringLiteral("widget_setting"));
        widget_setting->setMinimumSize(QSize(55, 30));
        widget_setting->setMaximumSize(QSize(55, 30));
        verticalLayout_5 = new QVBoxLayout(widget_setting);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(22, 0, 3, 0);
        setting = new QPushButton(widget_setting);
        setting->setObjectName(QStringLiteral("setting"));
        setting->setMinimumSize(QSize(30, 30));
        setting->setMaximumSize(QSize(30, 30));

        verticalLayout_5->addWidget(setting);


        horizontalLayout->addWidget(widget_setting);


        verticalLayout->addWidget(btnpanel);


        horizontalLayout_2->addWidget(widget);


        retranslateUi(EmotionTabDialog);

        QMetaObject::connectSlotsByName(EmotionTabDialog);
    } // setupUi

    void retranslateUi(QWidget *EmotionTabDialog)
    {
        EmotionTabDialog->setWindowTitle(QApplication::translate("EmotionTabDialog", "Dialog", 0));
        leftpage->setText(QString());
        emotList->setText(QApplication::translate("EmotionTabDialog", "\344\270\213\350\275\275\350\241\250\346\203\205", 0));
        rightpage->setText(QString());
        setting->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EmotionTabDialog: public Ui_EmotionTabDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMOTIONTABDIALOG_H

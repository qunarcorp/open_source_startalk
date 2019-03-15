/********************************************************************************
** Form generated from reading UI file 'EmotionManagerDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMOTIONMANAGERDIALOG_H
#define UI_EMOTIONMANAGERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_EmotionManagerDialog
{
public:
    QWidget *shadowbg;
    QWidget *shadowinnerbg;
    QWidget *bk;
    TitlebarWidget *titlebar;
    QWidget *widget;
    QTabWidget *tabWidget;
    QWidget *tab_local;
    QListWidget *listWidget_local;
    QWidget *tab_server;
    QListWidget *listWidget_server;
    QStackedWidget *stackedWidget;
    QWidget *page_local;
    QWidget *widget_3;
    QWidget *widget_4;
    QPushButton *deleteSaveEmotionBtn;
    QPushButton *addSaveEmotionBtn;
    QWidget *widget_6;
    QStackedWidget *stackedWidget_local;
    QWidget *page_server;
    QWidget *widget_5;
    QLabel *label_icon;
    QLabel *label_name;
    QLabel *label_showName;
    QLabel *label_showmiaoshu;
    QLabel *label_name_2;
    QLabel *label_showSize;
    QLabel *label_name_3;
    QPushButton *downloadBtn;
    QWidget *widget_2;

    void setupUi(QDialog *EmotionManagerDialog)
    {
        if (EmotionManagerDialog->objectName().isEmpty())
            EmotionManagerDialog->setObjectName(QStringLiteral("EmotionManagerDialog"));
        EmotionManagerDialog->resize(520, 450);
        EmotionManagerDialog->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QTabWidget\n"
"{\n"
"	border:none;\n"
"}\n"
"QListWidget\n"
"{\n"
"	border:none;\n"
"}\n"
"QWidget::gridwidget\n"
"{\n"
"	border:none;\n"
"}\n"
"QScrollArea\n"
"{\n"
"	border:none;\n"
"}\n"
"QWidget#page_local,#page_server{\n"
"    border-radius: 10px;\n"
"    background-color: #E2E2E2;\n"
"	margin: 0px 10px 0px 10px\n"
"}\n"
"\n"
"QPushButton{\n"
"    color: #666666;\n"
"	background-color: #FFFFFF;\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: #FFFFFF;\n"
"	background-color: #3dbbca;\n"
"}\n"
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
"QListWidget::listWidget_LocalEmotion\n"
"{\n"
"	border:none;\n"
"}\n"
"QTabBar::tab\n"
"{\n"
"	width:65;\n"
"	height:23;\n"
"	font:14px ;\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
""
                        "QTabBar::tab {\n"
"  	background: #666666;\n"
"	background-color: #FFFFFF;\n"
" 	padding: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"    background: #FFFFFF;\n"
"background-color: #3dbbca;\n"
"}\n"
"\n"
"\n"
""));
        shadowbg = new QWidget(EmotionManagerDialog);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        shadowbg->setGeometry(QRect(0, 0, 520, 450));
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        shadowinnerbg->setGeometry(QRect(8, 8, 504, 434));
        bk = new QWidget(shadowinnerbg);
        bk->setObjectName(QStringLiteral("bk"));
        bk->setGeometry(QRect(1, 1, 502, 432));
        titlebar = new TitlebarWidget(bk);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setGeometry(QRect(0, 0, 502, 28));
        widget = new QWidget(bk);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 28, 502, 405));
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(13, 10, 140, 385));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setTabPosition(QTabWidget::South);
        tab_local = new QWidget();
        tab_local->setObjectName(QStringLiteral("tab_local"));
        listWidget_local = new QListWidget(tab_local);
        listWidget_local->setObjectName(QStringLiteral("listWidget_local"));
        listWidget_local->setGeometry(QRect(0, 0, 138, 355));
        tabWidget->addTab(tab_local, QString());
        tab_server = new QWidget();
        tab_server->setObjectName(QStringLiteral("tab_server"));
        listWidget_server = new QListWidget(tab_server);
        listWidget_server->setObjectName(QStringLiteral("listWidget_server"));
        listWidget_server->setGeometry(QRect(0, 0, 138, 355));
        tabWidget->addTab(tab_server, QString());
        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(159, 0, 340, 401));
        page_local = new QWidget();
        page_local->setObjectName(QStringLiteral("page_local"));
        widget_3 = new QWidget(page_local);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(0, 0, 340, 411));
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(10, 360, 320, 40));
        deleteSaveEmotionBtn = new QPushButton(widget_4);
        deleteSaveEmotionBtn->setObjectName(QStringLiteral("deleteSaveEmotionBtn"));
        deleteSaveEmotionBtn->setGeometry(QRect(216, 10, 75, 23));
        deleteSaveEmotionBtn->setFlat(true);
        addSaveEmotionBtn = new QPushButton(widget_4);
        addSaveEmotionBtn->setObjectName(QStringLiteral("addSaveEmotionBtn"));
        addSaveEmotionBtn->setGeometry(QRect(18, 10, 75, 23));
        addSaveEmotionBtn->setFlat(true);
        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(10, 2, 320, 360));
        widget_6->setMinimumSize(QSize(320, 360));
        widget_6->setMaximumSize(QSize(320, 360));
        stackedWidget_local = new QStackedWidget(widget_6);
        stackedWidget_local->setObjectName(QStringLiteral("stackedWidget_local"));
        stackedWidget_local->setGeometry(QRect(2, 0, 320, 360));
        stackedWidget_local->setMinimumSize(QSize(320, 360));
        stackedWidget_local->setMaximumSize(QSize(320, 360));
        stackedWidget->addWidget(page_local);
        page_server = new QWidget();
        page_server->setObjectName(QStringLiteral("page_server"));
        widget_5 = new QWidget(page_server);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(0, 0, 340, 400));
        label_icon = new QLabel(widget_5);
        label_icon->setObjectName(QStringLiteral("label_icon"));
        label_icon->setGeometry(QRect(130, 70, 91, 91));
        label_name = new QLabel(widget_5);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setGeometry(QRect(80, 200, 41, 16));
        label_showName = new QLabel(widget_5);
        label_showName->setObjectName(QStringLiteral("label_showName"));
        label_showName->setGeometry(QRect(130, 200, 111, 16));
        label_showmiaoshu = new QLabel(widget_5);
        label_showmiaoshu->setObjectName(QStringLiteral("label_showmiaoshu"));
        label_showmiaoshu->setGeometry(QRect(130, 240, 111, 16));
        label_name_2 = new QLabel(widget_5);
        label_name_2->setObjectName(QStringLiteral("label_name_2"));
        label_name_2->setGeometry(QRect(80, 240, 41, 16));
        label_showSize = new QLabel(widget_5);
        label_showSize->setObjectName(QStringLiteral("label_showSize"));
        label_showSize->setGeometry(QRect(130, 280, 111, 16));
        label_name_3 = new QLabel(widget_5);
        label_name_3->setObjectName(QStringLiteral("label_name_3"));
        label_name_3->setGeometry(QRect(80, 280, 41, 16));
        downloadBtn = new QPushButton(widget_5);
        downloadBtn->setObjectName(QStringLiteral("downloadBtn"));
        downloadBtn->setGeometry(QRect(120, 320, 75, 23));
        stackedWidget->addWidget(page_server);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(153, 0, 10, 401));

        retranslateUi(EmotionManagerDialog);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EmotionManagerDialog);
    } // setupUi

    void retranslateUi(QDialog *EmotionManagerDialog)
    {
        EmotionManagerDialog->setWindowTitle(QApplication::translate("EmotionManagerDialog", "Dialog", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_local), QApplication::translate("EmotionManagerDialog", "\346\234\254\345\234\260", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_server), QApplication::translate("EmotionManagerDialog", "\346\234\215\345\212\241\345\231\250", 0));
        deleteSaveEmotionBtn->setText(QApplication::translate("EmotionManagerDialog", "Delete", 0));
        addSaveEmotionBtn->setText(QApplication::translate("EmotionManagerDialog", "Add...", 0));
        label_icon->setText(QApplication::translate("EmotionManagerDialog", "TextLabel", 0));
        label_name->setText(QApplication::translate("EmotionManagerDialog", "\345\220\215\345\255\227:", 0));
        label_showName->setText(QString());
        label_showmiaoshu->setText(QString());
        label_name_2->setText(QApplication::translate("EmotionManagerDialog", "\346\217\217\350\277\260:", 0));
        label_showSize->setText(QString());
        label_name_3->setText(QApplication::translate("EmotionManagerDialog", "\345\244\247\345\260\217:", 0));
        downloadBtn->setText(QApplication::translate("EmotionManagerDialog", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class EmotionManagerDialog: public Ui_EmotionManagerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMOTIONMANAGERDIALOG_H

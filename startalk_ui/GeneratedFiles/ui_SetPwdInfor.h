/********************************************************************************
** Form generated from reading UI file 'SetPwdInfor.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPWDINFOR_H
#define UI_SETPWDINFOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_setPwdInfor
{
public:
    QVBoxLayout *verticalLayout_5;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout_4;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout_3;
    TitlebarWidget *titlebar;
    QWidget *widget_infor;
    QVBoxLayout *verticalLayout_10;
    QWidget *widget;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_titlewidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_title;
    QWidget *widget_desc;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_desc;
    QWidget *widget_pwd;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEdit_Pwd;
    QWidget *widget_pwd_second;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *lineEdit_Pwd_second;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_9;
    QLabel *label;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *Btn_Cancel;
    QPushButton *Btn_OK;

    void setupUi(QWidget *setPwdInfor)
    {
        if (setPwdInfor->objectName().isEmpty())
            setPwdInfor->setObjectName(QStringLiteral("setPwdInfor"));
        setPwdInfor->resize(550, 350);
        setPwdInfor->setStyleSheet(QString::fromUtf8("QWidget#shadowbg{\n"
"    background-color:#FFFFFF;\n"
"    border-radius: 4px;\n"
"	    font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"	border:1px solid #DADADA80\n"
"}\n"
"\n"
"QLabel#label_title,QLabel#label_desc,QLabel#label_pwd{\n"
"    font-size:12px;\n"
"	font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"    color:#000000;\n"
"}\n"
"QPushButton{\n"
"	color:#333333;\n"
"	font:bold 12px;\n"
"}\n"
"QPushButton#Btn_Cancel{\n"
"   color: #666666;\n"
"	background-color: #FFFFFF;\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton#Btn_Cancel:hover{\n"
"    border:1px solid #EBEBEB;\n"
"    background-color:#EBEBEB;\n"
"}\n"
"\n"
"\n"
"QPushButton#Btn_Cancel:pressed{\n"
"    border:1px solid #D6D6D6;\n"
"    background-color:#D6D6D6;\n"
"}\n"
"\n"
"\n"
"QPushButton#Btn_OK{\n"
"    color: #666666;\n"
"	background-color: #FFFFFF;\n"
"	border:none;\n"
"}\n"
"QPushButton#Btn_OK:hover {\n"
"    color: #FFFFFF;\n"
"	background-color: #3dbbca;\n"
"}\n"
"QPushButton#Btn_OK:pressed{\n"
"\n"
""
                        "    color: #FFFFFF;\n"
"	background-color: #1194a4;\n"
"}\n"
"\n"
"QTextEdit:focus{\n"
"    background-color: #FFFFFF;\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"    border-color: #1BA9BA;\n"
"}\n"
"\n"
"QLineEdit#lineEdit_title,#lineEdit_Pwd,#lineEdit_desc,#lineEdit_Pwd_second\n"
"{\n"
"	background:#FFFFFF;\n"
"	color:#333333;\n"
"	font:bold 12px;\n"
"}\n"
"QLineEdit#lineEdit_title:hover,#lineEdit_Pwd:hover,#lineEdit_desc:hover,#lineEdit_Pwd_second:hover\n"
"{\n"
"    border:1px solid #999999;\n"
"}\n"
"QLineEdit#lineEdit_title:focus,#lineEdit_Pwd:focus,#lineEdit_desc:focus,#lineEdit_Pwd_second:focus\n"
"{\n"
"    background-color: #FFFFFF;\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"    border-color: #1BA9BA;\n"
"}\n"
"\n"
"QLabel#label\n"
"{\n"
"	border:none;\n"
"	color:#FF0000;\n"
"	font-size:13px;\n"
"	font-weight:bold;\n"
"}\n"
"\n"
""));
        verticalLayout_5 = new QVBoxLayout(setPwdInfor);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(setPwdInfor);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        verticalLayout_4 = new QVBoxLayout(shadowbg);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        verticalLayout_3 = new QVBoxLayout(shadowinnerbg);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(1, 1, 1, 1);
        titlebar = new TitlebarWidget(shadowinnerbg);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 28));
        titlebar->setMaximumSize(QSize(16777215, 28));

        verticalLayout_3->addWidget(titlebar);

        widget_infor = new QWidget(shadowinnerbg);
        widget_infor->setObjectName(QStringLiteral("widget_infor"));
        verticalLayout_10 = new QVBoxLayout(widget_infor);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 20, 0, 0);
        widget = new QWidget(widget_infor);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_8 = new QVBoxLayout(widget);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        widget_titlewidget = new QWidget(widget);
        widget_titlewidget->setObjectName(QStringLiteral("widget_titlewidget"));
        widget_titlewidget->setMaximumSize(QSize(16777215, 80));
        verticalLayout = new QVBoxLayout(widget_titlewidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(80, 0, 80, 0);
        lineEdit_title = new QLineEdit(widget_titlewidget);
        lineEdit_title->setObjectName(QStringLiteral("lineEdit_title"));
        lineEdit_title->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(lineEdit_title);


        verticalLayout_8->addWidget(widget_titlewidget);

        widget_desc = new QWidget(widget);
        widget_desc->setObjectName(QStringLiteral("widget_desc"));
        widget_desc->setMaximumSize(QSize(16777215, 40));
        verticalLayout_2 = new QVBoxLayout(widget_desc);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(80, 0, 80, 0);
        lineEdit_desc = new QLineEdit(widget_desc);
        lineEdit_desc->setObjectName(QStringLiteral("lineEdit_desc"));
        lineEdit_desc->setMaximumSize(QSize(16777215, 25));
        lineEdit_desc->setInputMethodHints(Qt::ImhNone);
        lineEdit_desc->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(lineEdit_desc);


        verticalLayout_8->addWidget(widget_desc);

        widget_pwd = new QWidget(widget);
        widget_pwd->setObjectName(QStringLiteral("widget_pwd"));
        widget_pwd->setMaximumSize(QSize(16777215, 80));
        verticalLayout_6 = new QVBoxLayout(widget_pwd);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(80, 0, 80, 0);
        lineEdit_Pwd = new QLineEdit(widget_pwd);
        lineEdit_Pwd->setObjectName(QStringLiteral("lineEdit_Pwd"));
        lineEdit_Pwd->setMaximumSize(QSize(16777215, 25));
        lineEdit_Pwd->setEchoMode(QLineEdit::Password);

        verticalLayout_6->addWidget(lineEdit_Pwd);


        verticalLayout_8->addWidget(widget_pwd);

        widget_pwd_second = new QWidget(widget);
        widget_pwd_second->setObjectName(QStringLiteral("widget_pwd_second"));
        widget_pwd_second->setMaximumSize(QSize(16777215, 40));
        verticalLayout_7 = new QVBoxLayout(widget_pwd_second);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(80, 0, 80, 0);
        lineEdit_Pwd_second = new QLineEdit(widget_pwd_second);
        lineEdit_Pwd_second->setObjectName(QStringLiteral("lineEdit_Pwd_second"));
        lineEdit_Pwd_second->setMaximumSize(QSize(16777215, 25));
        lineEdit_Pwd_second->setEchoMode(QLineEdit::Password);

        verticalLayout_7->addWidget(lineEdit_Pwd_second);


        verticalLayout_8->addWidget(widget_pwd_second);


        verticalLayout_10->addWidget(widget);

        widget_3 = new QWidget(widget_infor);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 85));
        widget_3->setMaximumSize(QSize(16777215, 85));
        verticalLayout_9 = new QVBoxLayout(widget_3);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(40, 0, 80, 0);
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 60));
        label->setMaximumSize(QSize(16777215, 60));
        label->setTextFormat(Qt::RichText);

        verticalLayout_9->addWidget(label);


        verticalLayout_10->addWidget(widget_3);

        widget_2 = new QWidget(widget_infor);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMaximumSize(QSize(16777215, 60));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(50);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(200, 0, 60, 10);
        Btn_Cancel = new QPushButton(widget_2);
        Btn_Cancel->setObjectName(QStringLiteral("Btn_Cancel"));
        Btn_Cancel->setMinimumSize(QSize(0, 30));
        Btn_Cancel->setMaximumSize(QSize(16777215, 30));
        Btn_Cancel->setFlat(true);

        horizontalLayout->addWidget(Btn_Cancel);

        Btn_OK = new QPushButton(widget_2);
        Btn_OK->setObjectName(QStringLiteral("Btn_OK"));
        Btn_OK->setMinimumSize(QSize(0, 30));
        Btn_OK->setMaximumSize(QSize(16777215, 30));
        Btn_OK->setFlat(true);

        horizontalLayout->addWidget(Btn_OK);


        verticalLayout_10->addWidget(widget_2);


        verticalLayout_3->addWidget(widget_infor);


        verticalLayout_4->addWidget(shadowinnerbg);


        verticalLayout_5->addWidget(shadowbg);


        retranslateUi(setPwdInfor);

        QMetaObject::connectSlotsByName(setPwdInfor);
    } // setupUi

    void retranslateUi(QWidget *setPwdInfor)
    {
        setPwdInfor->setWindowTitle(QApplication::translate("setPwdInfor", "Form", 0));
        lineEdit_title->setPlaceholderText(QApplication::translate("setPwdInfor", "\345\257\206\347\240\201\347\256\261\345\220\215\347\247\260", 0));
        lineEdit_desc->setPlaceholderText(QApplication::translate("setPwdInfor", "\345\257\206\347\240\201\347\256\261\347\232\204\346\217\217\345\217\231", 0));
        lineEdit_Pwd->setPlaceholderText(QApplication::translate("setPwdInfor", "\350\276\223\345\205\245\344\270\273\345\257\206\347\240\201", 0));
        lineEdit_Pwd_second->setPlaceholderText(QApplication::translate("setPwdInfor", "\351\252\214\350\257\201\344\270\273\345\257\206\347\240\201", 0));
        label->setText(QString());
        Btn_Cancel->setText(QApplication::translate("setPwdInfor", "\345\217\226\346\266\210", 0));
        Btn_OK->setText(QApplication::translate("setPwdInfor", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class setPwdInfor: public Ui_setPwdInfor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPWDINFOR_H

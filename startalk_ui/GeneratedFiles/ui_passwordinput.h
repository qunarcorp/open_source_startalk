/********************************************************************************
** Form generated from reading UI file 'passwordinput.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDINPUT_H
#define UI_PASSWORDINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PasswordInput
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *dialogbg;
    QVBoxLayout *verticalLayout_2;
    TitlebarWidget *widget;
    QWidget *widget_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *join;

    void setupUi(QWidget *PasswordInput)
    {
        if (PasswordInput->objectName().isEmpty())
            PasswordInput->setObjectName(QStringLiteral("PasswordInput"));
        PasswordInput->resize(326, 182);
        verticalLayout = new QVBoxLayout(PasswordInput);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        dialogbg = new QWidget(PasswordInput);
        dialogbg->setObjectName(QStringLiteral("dialogbg"));
        verticalLayout_2 = new QVBoxLayout(dialogbg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new TitlebarWidget(dialogbg);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 27));
        widget->setMaximumSize(QSize(16777215, 27));

        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(dialogbg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"    color: #666666;\n"
"	background-color: #FFFFFF;\n"
"	border:none;\n"
"}\n"
"QPushButton:hover {\n"
"   color: #FFFFFF;\n"
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
"	background-color: #FFB03f;\n"
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
"    background-color: #FFFFFF;\n"
"    border:none;\n"
"}\n"
"QLineEdit:focus{\n"
"    background-color: #33000000;\n"
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
"    background-color: #FFF"
                        "FFF;\n"
"    border:none;\n"
"}\n"
"QTextEdit:focus{\n"
"    background-color: #FFFFFF;\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"    border-color: #1BA9BA;\n"
"}\n"
""));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 50, 50));
        label->setMinimumSize(QSize(50, 50));
        label->setMaximumSize(QSize(50, 50));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 30, 191, 16));
        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 58, 190, 31));
        lineEdit->setEchoMode(QLineEdit::Password);
        join = new QPushButton(widget_2);
        join->setObjectName(QStringLiteral("join"));
        join->setGeometry(QRect(225, 108, 75, 31));
        join->setFlat(true);

        verticalLayout_2->addWidget(widget_2);


        verticalLayout->addWidget(dialogbg);


        retranslateUi(PasswordInput);

        QMetaObject::connectSlotsByName(PasswordInput);
    } // setupUi

    void retranslateUi(QWidget *PasswordInput)
    {
        PasswordInput->setWindowTitle(QApplication::translate("PasswordInput", "PasswordInput", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("PasswordInput", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        join->setText(QApplication::translate("PasswordInput", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class PasswordInput: public Ui_PasswordInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDINPUT_H

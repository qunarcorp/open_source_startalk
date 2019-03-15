/********************************************************************************
** Form generated from reading UI file 'groupmemberinput.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPMEMBERINPUT_H
#define UI_GROUPMEMBERINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_GroupMemberInput
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widgetbk;
    QVBoxLayout *verticalLayout;
    TitlebarWidget *titlebar;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *textEdit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok;

    void setupUi(QWidget *GroupMemberInput)
    {
        if (GroupMemberInput->objectName().isEmpty())
            GroupMemberInput->setObjectName(QStringLiteral("GroupMemberInput"));
        GroupMemberInput->resize(400, 300);
        GroupMemberInput->setStyleSheet(QString::fromUtf8("QWidget{\n"
"    font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"}\n"
"QWidget#titlebar{\n"
"    background-color:#EAEBED;\n"
"}\n"
"QWidget#widgetbk{\n"
"    background-color:#FFFFFF;\n"
"    border:#000000 1px solid;\n"
"}\n"
"\n"
"\n"
"QPushButton#ok,#next,#pushButton_creategroup{\n"
"	 border-radius: 0px;\n"
"    color:#FFFFFF;\n"
"    background-color:#3DCE3D;\n"
"}\n"
"QPushButton#ok:disabled,#next:disabled,#pushButton_creategroup:disabled{\n"
"    background-color:#9DE69D;\n"
"}\n"
"QPushButton#ok:hover,#next:hover,#pushButton_creategroup:hover{\n"
"    background-color:#38C738;\n"
"}\n"
"QPushButton#ok:pressed,#next:pressed,#pushButton_creategroup:pressed{\n"
"    background-color:#2FB82F;\n"
"}\n"
"QTextEdit#textEdit\n"
"{\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(GroupMemberInput);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widgetbk = new QWidget(GroupMemberInput);
        widgetbk->setObjectName(QStringLiteral("widgetbk"));
        widgetbk->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(widgetbk);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titlebar = new TitlebarWidget(widgetbk);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        verticalLayout_2 = new QVBoxLayout(titlebar);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        verticalLayout->addWidget(titlebar);

        widget_5 = new QWidget(widgetbk);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        verticalLayout_4 = new QVBoxLayout(widget_5);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(10, 10, 10, 10);
        textEdit = new QTextEdit(widget_5);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout_4->addWidget(textEdit);


        verticalLayout->addWidget(widget_5);

        widget_3 = new QWidget(widgetbk);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 10, 10);
        horizontalSpacer = new QSpacerItem(317, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ok = new QPushButton(widget_3);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setMinimumSize(QSize(70, 26));
        ok->setMaximumSize(QSize(70, 16777215));
        ok->setFlat(true);

        horizontalLayout_2->addWidget(ok);


        verticalLayout->addWidget(widget_3);


        horizontalLayout->addWidget(widgetbk);


        retranslateUi(GroupMemberInput);

        QMetaObject::connectSlotsByName(GroupMemberInput);
    } // setupUi

    void retranslateUi(QWidget *GroupMemberInput)
    {
        GroupMemberInput->setWindowTitle(QApplication::translate("GroupMemberInput", "GroupMemberInput", 0));
        ok->setText(QApplication::translate("GroupMemberInput", "\347\241\256\350\256\244", 0));
    } // retranslateUi

};

namespace Ui {
    class GroupMemberInput: public Ui_GroupMemberInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPMEMBERINPUT_H

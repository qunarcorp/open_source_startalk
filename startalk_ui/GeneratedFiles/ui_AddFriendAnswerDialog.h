/********************************************************************************
** Form generated from reading UI file 'AddFriendAnswerDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIENDANSWERDIALOG_H
#define UI_ADDFRIENDANSWERDIALOG_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_AddFriendAnswerDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout_3;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout_2;
    TitlebarWidget *titlebar;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_answer;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_answer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_cancel;
    QPushButton *pb_ok;

    void setupUi(QWidget *AddFriendAnswerDialog)
    {
        if (AddFriendAnswerDialog->objectName().isEmpty())
            AddFriendAnswerDialog->setObjectName(QStringLiteral("AddFriendAnswerDialog"));
        AddFriendAnswerDialog->resize(316, 186);
        AddFriendAnswerDialog->setStyleSheet(QLatin1String("\n"
"#AddFriendAnswerDialog QPushButton#pb_cancel{border-radius:3px;border:1px solid #1BA9BA;background:#00000000;color:#1BA9BA;}\n"
"\n"
"#AddFriendAnswerDialog QPushButton#pb_ok{border-radius:3px;border:none;background:#1BA9BA;color:#FFFFFF;}\n"
"\n"
"\n"
"#AddFriendAnswerDialog QLabel#label_answer {color:#1BA9BA;}"));
        verticalLayout_4 = new QVBoxLayout(AddFriendAnswerDialog);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(AddFriendAnswerDialog);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        verticalLayout_3 = new QVBoxLayout(shadowbg);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        shadowinnerbg->setMinimumSize(QSize(300, 170));
        shadowinnerbg->setMaximumSize(QSize(300, 170));
        shadowinnerbg->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(shadowinnerbg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        titlebar = new TitlebarWidget(shadowinnerbg);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 30));
        titlebar->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_3 = new QHBoxLayout(titlebar);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(15, 0, 0, 0);

        verticalLayout_2->addWidget(titlebar);

        widget = new QWidget(shadowinnerbg);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(24, 0, 24, 0);
        label_answer = new QLabel(widget);
        label_answer->setObjectName(QStringLiteral("label_answer"));
        label_answer->setMinimumSize(QSize(0, 30));
        label_answer->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label_answer);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(8);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 28));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_answer = new QLineEdit(widget_3);
        lineEdit_answer->setObjectName(QStringLiteral("lineEdit_answer"));
        lineEdit_answer->setMinimumSize(QSize(0, 28));

        horizontalLayout_2->addWidget(lineEdit_answer);


        verticalLayout->addWidget(widget_3);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(shadowinnerbg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 24, 25);
        horizontalSpacer = new QSpacerItem(319, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pb_cancel = new QPushButton(widget_2);
        pb_cancel->setObjectName(QStringLiteral("pb_cancel"));
        pb_cancel->setMinimumSize(QSize(48, 22));
        pb_cancel->setMaximumSize(QSize(48, 22));
        pb_cancel->setFlat(true);

        horizontalLayout->addWidget(pb_cancel);

        pb_ok = new QPushButton(widget_2);
        pb_ok->setObjectName(QStringLiteral("pb_ok"));
        pb_ok->setMinimumSize(QSize(48, 22));
        pb_ok->setMaximumSize(QSize(48, 22));
        pb_ok->setFlat(true);

        horizontalLayout->addWidget(pb_ok);


        verticalLayout_2->addWidget(widget_2);


        verticalLayout_3->addWidget(shadowinnerbg);


        verticalLayout_4->addWidget(shadowbg);


        retranslateUi(AddFriendAnswerDialog);

        QMetaObject::connectSlotsByName(AddFriendAnswerDialog);
    } // setupUi

    void retranslateUi(QWidget *AddFriendAnswerDialog)
    {
        AddFriendAnswerDialog->setWindowTitle(QApplication::translate("AddFriendAnswerDialog", "Dialog", 0));
        shadowbg->setStyleSheet(QApplication::translate("AddFriendAnswerDialog", "\n"
"#AddFriendAnswerDialog QPushButton#pb_cancel{border-radius:3px;border:1px solid #1BA9BA;background:#00000000;color:#1BA9BA;}\n"
"\n"
"#AddFriendAnswerDialog QPushButton#pb_ok{border-radius:3px;border:none;background:#1BA9BA;color:#FFFFFF;}\n"
"\n"
"#AddFriendAnswerDialog QPushButton#pb_ok,#pb_cancel{    font-size:14px;    border: 2px solid #1ba9ba;	background-color: rgb(27, 169, 186);	color: #efefef;}\n"
"\n"
"", 0));
        label_answer->setText(QApplication::translate("AddFriendAnswerDialog", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\351\252\214\350\257\201\344\277\241\346\201\257", 0));
        label_2->setText(QApplication::translate("AddFriendAnswerDialog", "\351\252\214\350\257\201\344\277\241\346\201\257\357\274\232", 0));
        pb_cancel->setText(QApplication::translate("AddFriendAnswerDialog", "\345\217\226\346\266\210", 0));
        pb_ok->setText(QApplication::translate("AddFriendAnswerDialog", "\350\257\267\346\261\202", 0));
    } // retranslateUi

};

namespace Ui {
    class AddFriendAnswerDialog: public Ui_AddFriendAnswerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIENDANSWERDIALOG_H

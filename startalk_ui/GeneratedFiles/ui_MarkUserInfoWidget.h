/********************************************************************************
** Form generated from reading UI file 'MarkUserInfoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARKUSERINFOWIDGET_H
#define UI_MARKUSERINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MarkUserInfoWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *dialogborderback;
    QVBoxLayout *verticalLayout;
    TitlebarWidget *titlebar;
    QWidget *widget;
    QLabel *label_2;
    QTextEdit *lbMarkInfo;
    QLabel *label;
    QLabel *lbConversationId;
    QLabel *label_3;
    QLineEdit *lbMarkTitle;
    QPushButton *btnOk;

    void setupUi(QWidget *MarkUserInfoWidget)
    {
        if (MarkUserInfoWidget->objectName().isEmpty())
            MarkUserInfoWidget->setObjectName(QStringLiteral("MarkUserInfoWidget"));
        MarkUserInfoWidget->resize(306, 255);
        MarkUserInfoWidget->setStyleSheet(QString::fromUtf8("\n"
"QWidget\n"
"{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"\n"
"QLineEdit{\n"
"    background-color: #FFFFFF;\n"
"    border:none;\n"
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
"    background-color: #FFFFFF;\n"
"    border:none;\n"
"}\n"
"QTextEdit:focus{\n"
"    background-color: #FFFFFF;\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"    border-color: #1BA9BA;\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(MarkUserInfoWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        dialogborderback = new QWidget(MarkUserInfoWidget);
        dialogborderback->setObjectName(QStringLiteral("dialogborderback"));
        verticalLayout = new QVBoxLayout(dialogborderback);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titlebar = new TitlebarWidget(dialogborderback);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 28));
        titlebar->setMaximumSize(QSize(16777215, 28));

        verticalLayout->addWidget(titlebar);

        widget = new QWidget(dialogborderback);
        widget->setObjectName(QStringLiteral("widget"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 54, 12));
        lbMarkInfo = new QTextEdit(widget);
        lbMarkInfo->setObjectName(QStringLiteral("lbMarkInfo"));
        lbMarkInfo->setGeometry(QRect(80, 70, 201, 121));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(12, 10, 54, 12));
        lbConversationId = new QLabel(widget);
        lbConversationId->setObjectName(QStringLiteral("lbConversationId"));
        lbConversationId->setGeometry(QRect(80, 10, 201, 16));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 70, 54, 12));
        lbMarkTitle = new QLineEdit(widget);
        lbMarkTitle->setObjectName(QStringLiteral("lbMarkTitle"));
        lbMarkTitle->setGeometry(QRect(80, 40, 201, 20));
        lbMarkTitle->setClearButtonEnabled(true);
        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QStringLiteral("btnOk"));
        btnOk->setGeometry(QRect(210, 200, 75, 23));

        verticalLayout->addWidget(widget);


        horizontalLayout->addWidget(dialogborderback);


        retranslateUi(MarkUserInfoWidget);

        QMetaObject::connectSlotsByName(MarkUserInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *MarkUserInfoWidget)
    {
        MarkUserInfoWidget->setWindowTitle(QApplication::translate("MarkUserInfoWidget", "MarkUserInfoWidget", 0));
        label_2->setText(QApplication::translate("MarkUserInfoWidget", "\345\244\207\346\263\250\345\220\215\347\247\260", 0));
        lbMarkInfo->setPlaceholderText(QApplication::translate("MarkUserInfoWidget", "\345\244\207\346\263\250\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("MarkUserInfoWidget", "\347\224\250\346\210\267ID", 0));
        lbConversationId->setText(QString());
        label_3->setText(QApplication::translate("MarkUserInfoWidget", "\345\244\207\346\263\250\344\277\241\346\201\257", 0));
        lbMarkTitle->setPlaceholderText(QApplication::translate("MarkUserInfoWidget", "\345\244\207\346\263\250\345\220\215", 0));
        btnOk->setText(QApplication::translate("MarkUserInfoWidget", "\345\245\275", 0));
    } // retranslateUi

};

namespace Ui {
    class MarkUserInfoWidget: public Ui_MarkUserInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKUSERINFOWIDGET_H

/********************************************************************************
** Form generated from reading UI file 'EncryptChatDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENCRYPTCHATDIALOG_H
#define UI_ENCRYPTCHATDIALOG_H

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
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_EncryptChatDialog
{
public:
    QVBoxLayout *verticalLayout_8;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout_7;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout_6;
    TitlebarWidget *titlebarWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_icon;
    QSpacerItem *verticalSpacer;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_title;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout;
    QLabel *label_infor;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pB_Cancel;
    QPushButton *pB_Decrypt;
    QPushButton *pB_Encrypt;

    void setupUi(QWidget *EncryptChatDialog)
    {
        if (EncryptChatDialog->objectName().isEmpty())
            EncryptChatDialog->setObjectName(QStringLiteral("EncryptChatDialog"));
        EncryptChatDialog->resize(534, 232);
        EncryptChatDialog->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QWidget#shadowinnerbg{\n"
"    background-color: #ECECEC;\n"
"}\n"
"\n"
"QLabel#label_title\n"
"{\n"
"	font-size:16px;\n"
"	font:bold 14px;\n"
"}\n"
"\n"
"QPushButton#pB_Cancel,#pB_Decrypt,#pB_Encrypt{\n"
"	color: #FFFFFF;\n"
"    background-color: #3dbbca;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QLabel#label_icon\n"
"{\n"
"	border:none;\n"
"	border-image: url(:/Images/close_hover.png);  \n"
"}\n"
"\n"
"QPushButton#pB_Cancel:hover,#pB_Decrypt:hover,#pB_Encrypt:hover{\n"
"    color: #FFFFFF;\n"
"	background-color: #1194a4;\n"
"}"));
        verticalLayout_8 = new QVBoxLayout(EncryptChatDialog);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(EncryptChatDialog);
        shadowbg->setObjectName(QStringLiteral("shadowbg"));
        verticalLayout_7 = new QVBoxLayout(shadowbg);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(8, 8, 8, 8);
        shadowinnerbg = new QWidget(shadowbg);
        shadowinnerbg->setObjectName(QStringLiteral("shadowinnerbg"));
        verticalLayout_6 = new QVBoxLayout(shadowinnerbg);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        titlebarWidget = new TitlebarWidget(shadowinnerbg);
        titlebarWidget->setObjectName(QStringLiteral("titlebarWidget"));
        titlebarWidget->setMinimumSize(QSize(0, 27));
        titlebarWidget->setMaximumSize(QSize(16777215, 27));

        verticalLayout_6->addWidget(titlebarWidget);

        widget = new QWidget(shadowinnerbg);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(110, 0));
        widget_4->setMaximumSize(QSize(110, 16777215));
        verticalLayout_5 = new QVBoxLayout(widget_4);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(10, 10, 10, 0);
        label_icon = new QLabel(widget_4);
        label_icon->setObjectName(QStringLiteral("label_icon"));
        label_icon->setMinimumSize(QSize(90, 90));
        label_icon->setMaximumSize(QSize(90, 90));
        label_icon->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_icon);

        verticalSpacer = new QSpacerItem(20, 86, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(widget_4);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        verticalLayout_4 = new QVBoxLayout(widget_5);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(18, 0, 0, 0);
        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        verticalLayout_2 = new QVBoxLayout(widget_6);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 20, 0, 0);
        label_title = new QLabel(widget_6);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setMinimumSize(QSize(0, 30));
        label_title->setMaximumSize(QSize(16777215, 30));
        label_title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_title);


        verticalLayout_3->addWidget(widget_6);

        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        verticalLayout = new QVBoxLayout(widget_7);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_infor = new QLabel(widget_7);
        label_infor->setObjectName(QStringLiteral("label_infor"));
        label_infor->setMinimumSize(QSize(0, 30));
        label_infor->setMaximumSize(QSize(16777215, 30));
        label_infor->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(label_infor);


        verticalLayout_3->addWidget(widget_7);


        verticalLayout_4->addWidget(widget_2);

        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(35);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 10, 25, 20);
        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pB_Cancel = new QPushButton(widget_3);
        pB_Cancel->setObjectName(QStringLiteral("pB_Cancel"));
        pB_Cancel->setMinimumSize(QSize(65, 0));
        pB_Cancel->setMaximumSize(QSize(65, 25));
        pB_Cancel->setFlat(true);

        horizontalLayout->addWidget(pB_Cancel);

        pB_Decrypt = new QPushButton(widget_3);
        pB_Decrypt->setObjectName(QStringLiteral("pB_Decrypt"));
        pB_Decrypt->setMinimumSize(QSize(80, 0));
        pB_Decrypt->setMaximumSize(QSize(80, 25));
        pB_Decrypt->setFlat(true);

        horizontalLayout->addWidget(pB_Decrypt);

        pB_Encrypt = new QPushButton(widget_3);
        pB_Encrypt->setObjectName(QStringLiteral("pB_Encrypt"));
        pB_Encrypt->setMinimumSize(QSize(80, 25));
        pB_Encrypt->setMaximumSize(QSize(80, 25));
        pB_Encrypt->setFlat(true);

        horizontalLayout->addWidget(pB_Encrypt);


        verticalLayout_4->addWidget(widget_3);


        horizontalLayout_2->addWidget(widget_5);


        verticalLayout_6->addWidget(widget);


        verticalLayout_7->addWidget(shadowinnerbg);


        verticalLayout_8->addWidget(shadowbg);


        retranslateUi(EncryptChatDialog);

        QMetaObject::connectSlotsByName(EncryptChatDialog);
    } // setupUi

    void retranslateUi(QWidget *EncryptChatDialog)
    {
        EncryptChatDialog->setWindowTitle(QApplication::translate("EncryptChatDialog", "Form", 0));
        label_icon->setText(QString());
        label_title->setText(QApplication::translate("EncryptChatDialog", "\346\217\220\347\244\272", 0));
        label_infor->setText(QApplication::translate("EncryptChatDialog", "\344\274\232\350\257\235\345\212\240\345\257\206", 0));
        pB_Cancel->setText(QApplication::translate("EncryptChatDialog", "\345\217\226\346\266\210", 0));
        pB_Decrypt->setText(QApplication::translate("EncryptChatDialog", "\350\247\243\345\257\206\344\274\232\350\257\235", 0));
        pB_Encrypt->setText(QApplication::translate("EncryptChatDialog", "\345\212\240\345\257\206\344\274\232\350\257\235", 0));
    } // retranslateUi

};

namespace Ui {
    class EncryptChatDialog: public Ui_EncryptChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCRYPTCHATDIALOG_H

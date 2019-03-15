/********************************************************************************
** Form generated from reading UI file 'ChatDisplayOptionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDISPLAYOPTIONWIDGET_H
#define UI_CHATDISPLAYOPTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TitlebarWidget.h>

QT_BEGIN_NAMESPACE

class Ui_ChatDisplayOptionWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *dialogbg;
    QVBoxLayout *verticalLayout_3;
    TitlebarWidget *titlebar;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QFontComboBox *cbFontFamily;
    QComboBox *cbFontSize;
    QPushButton *btnFontColor;
    QPushButton *btnMyColor;
    QPushButton *btnOtherColor;
    QLabel *label_8;
    QPushButton *btnOtherFontColor;

    void setupUi(QWidget *ChatDisplayOptionWidget)
    {
        if (ChatDisplayOptionWidget->objectName().isEmpty())
            ChatDisplayOptionWidget->setObjectName(QStringLiteral("ChatDisplayOptionWidget"));
        ChatDisplayOptionWidget->resize(382, 242);
        ChatDisplayOptionWidget->setStyleSheet(QString::fromUtf8("QLabel,QCheckBox,QComboBox\n"
"{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#666666;\n"
"}\n"
"QPushButton\n"
"{\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"	background:#666666;\n"
"}\n"
"\n"
"QComboBox {\n"
"    border: 1px solid #EBEBEB;\n"
"    border-radius: 0px;\n"
"    padding: 1px 18px 1px 3px;\n"
"}\n"
"\n"
"QComboBox:!editable, QComboBox::drop-down:editable {\n"
"     background: #AAFFFFFF;\n"
"}\n"
"\n"
"QComboBox:on { /* shift the text when the popup opens */\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"	border-left-width: 1px;\n"
"    border-left-color: #EBEBEB;\n"
"    border-left-style: solid; /* just a single line */\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/Images/jietu_normal.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    to"
                        "p: 1px;\n"
"    left: 1px;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(ChatDisplayOptionWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        dialogbg = new QWidget(ChatDisplayOptionWidget);
        dialogbg->setObjectName(QStringLiteral("dialogbg"));
        dialogbg->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(dialogbg);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        titlebar = new TitlebarWidget(dialogbg);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 28));
        titlebar->setMaximumSize(QSize(16777215, 28));

        verticalLayout_3->addWidget(titlebar);

        widget_2 = new QWidget(dialogbg);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 60, 22));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 140, 60, 22));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 20, 40, 22));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 50, 40, 22));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(79, 80, 61, 22));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(79, 150, 61, 22));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(79, 180, 61, 22));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cbFontFamily = new QFontComboBox(widget);
        cbFontFamily->setObjectName(QStringLiteral("cbFontFamily"));
        cbFontFamily->setGeometry(QRect(160, 20, 200, 22));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setStyleStrategy(QFont::PreferAntialias);
        cbFontFamily->setCurrentFont(font);
        cbFontSize = new QComboBox(widget);
        cbFontSize->setObjectName(QStringLiteral("cbFontSize"));
        cbFontSize->setGeometry(QRect(160, 50, 200, 22));
        btnFontColor = new QPushButton(widget);
        btnFontColor->setObjectName(QStringLiteral("btnFontColor"));
        btnFontColor->setGeometry(QRect(160, 80, 200, 22));
        btnFontColor->setFlat(true);
        btnMyColor = new QPushButton(widget);
        btnMyColor->setObjectName(QStringLiteral("btnMyColor"));
        btnMyColor->setGeometry(QRect(160, 150, 201, 22));
        btnMyColor->setFlat(true);
        btnOtherColor = new QPushButton(widget);
        btnOtherColor->setObjectName(QStringLiteral("btnOtherColor"));
        btnOtherColor->setGeometry(QRect(160, 180, 201, 22));
        btnOtherColor->setFlat(true);
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(79, 110, 61, 22));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        btnOtherFontColor = new QPushButton(widget);
        btnOtherFontColor->setObjectName(QStringLiteral("btnOtherFontColor"));
        btnOtherFontColor->setGeometry(QRect(160, 110, 200, 22));
        btnOtherFontColor->setFlat(true);

        verticalLayout_2->addWidget(widget);


        verticalLayout_3->addWidget(widget_2);


        verticalLayout->addWidget(dialogbg);


        retranslateUi(ChatDisplayOptionWidget);

        QMetaObject::connectSlotsByName(ChatDisplayOptionWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatDisplayOptionWidget)
    {
        ChatDisplayOptionWidget->setWindowTitle(QApplication::translate("ChatDisplayOptionWidget", "ChatDisplayOptionWidget", 0));
        label->setText(QApplication::translate("ChatDisplayOptionWidget", "\346\226\207\345\255\227\350\256\276\347\275\256", 0));
        label_2->setText(QApplication::translate("ChatDisplayOptionWidget", "\346\260\224\346\263\241\350\256\276\347\275\256", 0));
        label_3->setText(QApplication::translate("ChatDisplayOptionWidget", "\345\255\227\344\275\223", 0));
        label_4->setText(QApplication::translate("ChatDisplayOptionWidget", "\345\255\227\345\217\267", 0));
        label_5->setText(QApplication::translate("ChatDisplayOptionWidget", "\346\210\221\347\232\204\345\255\227\344\275\223", 0));
        label_6->setText(QApplication::translate("ChatDisplayOptionWidget", "\346\210\221\347\232\204\351\242\234\350\211\262", 0));
        label_7->setText(QApplication::translate("ChatDisplayOptionWidget", "\345\257\271\346\226\271\351\242\234\350\211\262", 0));
        cbFontSize->clear();
        cbFontSize->insertItems(0, QStringList()
         << QApplication::translate("ChatDisplayOptionWidget", "8", 0)
         << QApplication::translate("ChatDisplayOptionWidget", "10", 0)
         << QApplication::translate("ChatDisplayOptionWidget", "12", 0)
         << QApplication::translate("ChatDisplayOptionWidget", "14", 0)
         << QApplication::translate("ChatDisplayOptionWidget", "16", 0)
         << QApplication::translate("ChatDisplayOptionWidget", "18", 0)
         << QApplication::translate("ChatDisplayOptionWidget", "20", 0)
         << QApplication::translate("ChatDisplayOptionWidget", "22", 0)
         << QApplication::translate("ChatDisplayOptionWidget", "24", 0)
        );
        btnFontColor->setText(QString());
        btnMyColor->setText(QString());
        btnOtherColor->setText(QString());
        label_8->setText(QApplication::translate("ChatDisplayOptionWidget", "\345\257\271\346\226\271\345\255\227\344\275\223", 0));
        btnOtherFontColor->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatDisplayOptionWidget: public Ui_ChatDisplayOptionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDISPLAYOPTIONWIDGET_H

/********************************************************************************
** Form generated from reading UI file 'ErCodeLoginWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERCODELOGINWIDGET_H
#define UI_ERCODELOGINWIDGET_H

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

class Ui_ErCodeLoginWidget
{
public:
    QVBoxLayout *verticalLayout_5;
    QWidget *shadowbg;
    QVBoxLayout *verticalLayout_4;
    QWidget *shadowinnerbg;
    QVBoxLayout *verticalLayout_3;
    TitlebarWidget *titlebarWidget;
    QWidget *widget_bk;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QLabel *title_label;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *nickname_label;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *ercode_label;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbtn_return;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ErCodeLoginWidget)
    {
        if (ErCodeLoginWidget->objectName().isEmpty())
            ErCodeLoginWidget->setObjectName(QStringLiteral("ErCodeLoginWidget"));
        ErCodeLoginWidget->resize(434, 332);
        ErCodeLoginWidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QWidget#shadowinnerbg{\n"
"    background-color: #ECECEC;\n"
"}\n"
"\n"
"QPushButton#pbtn_return{\n"
"	color: #FFFFFF;\n"
"    background-color: #3dbbca;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"\n"
"QPushButton#pbtn_return:hover{\n"
"    color: #FFFFFF;\n"
"	background-color: #1194a4;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(ErCodeLoginWidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        shadowbg = new QWidget(ErCodeLoginWidget);
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
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        titlebarWidget = new TitlebarWidget(shadowinnerbg);
        titlebarWidget->setObjectName(QStringLiteral("titlebarWidget"));
        titlebarWidget->setMinimumSize(QSize(0, 27));
        titlebarWidget->setMaximumSize(QSize(16777215, 27));

        verticalLayout_3->addWidget(titlebarWidget);

        widget_bk = new QWidget(shadowinnerbg);
        widget_bk->setObjectName(QStringLiteral("widget_bk"));
        verticalLayout_2 = new QVBoxLayout(widget_bk);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(widget_bk);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 80));
        widget_3->setMaximumSize(QSize(16777215, 80));
        verticalLayout_6 = new QVBoxLayout(widget_3);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        title_label = new QLabel(widget_5);
        title_label->setObjectName(QStringLiteral("title_label"));
        title_label->setMinimumSize(QSize(320, 30));
        title_label->setMaximumSize(QSize(320, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        title_label->setFont(font);
        title_label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(title_label);


        verticalLayout_6->addWidget(widget_5);

        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        nickname_label = new QLabel(widget_6);
        nickname_label->setObjectName(QStringLiteral("nickname_label"));
        nickname_label->setMinimumSize(QSize(160, 30));
        nickname_label->setMaximumSize(QSize(160, 30));
        nickname_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(nickname_label);


        verticalLayout_6->addWidget(widget_6);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 20, 0, 20);
        horizontalSpacer_3 = new QSpacerItem(146, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        ercode_label = new QLabel(widget_4);
        ercode_label->setObjectName(QStringLiteral("ercode_label"));
        ercode_label->setMinimumSize(QSize(120, 120));
        ercode_label->setMaximumSize(QSize(120, 120));

        horizontalLayout_2->addWidget(ercode_label);

        horizontalSpacer_4 = new QSpacerItem(146, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_4);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(widget_bk);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 15);
        horizontalSpacer = new QSpacerItem(126, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pbtn_return = new QPushButton(widget_2);
        pbtn_return->setObjectName(QStringLiteral("pbtn_return"));
        pbtn_return->setMinimumSize(QSize(160, 30));
        pbtn_return->setMaximumSize(QSize(160, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        pbtn_return->setFont(font1);
        pbtn_return->setFlat(true);

        horizontalLayout_3->addWidget(pbtn_return);

        horizontalSpacer_2 = new QSpacerItem(126, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget_2);


        verticalLayout_3->addWidget(widget_bk);


        verticalLayout_4->addWidget(shadowinnerbg);


        verticalLayout_5->addWidget(shadowbg);


        retranslateUi(ErCodeLoginWidget);

        QMetaObject::connectSlotsByName(ErCodeLoginWidget);
    } // setupUi

    void retranslateUi(QWidget *ErCodeLoginWidget)
    {
        ErCodeLoginWidget->setWindowTitle(QApplication::translate("ErCodeLoginWidget", "Form", 0));
        title_label->setText(QApplication::translate("ErCodeLoginWidget", "\350\257\267\347\224\250\347\247\273\345\212\250\347\253\257\347\232\204qtalk\350\277\233\350\241\214\346\211\253\346\217\217\344\272\214\347\273\264\347\240\201\350\277\233\350\241\214\347\231\273\345\275\225", 0));
        nickname_label->setText(QString());
        ercode_label->setText(QString());
        pbtn_return->setText(QApplication::translate("ErCodeLoginWidget", "\350\277\224      \345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class ErCodeLoginWidget: public Ui_ErCodeLoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERCODELOGINWIDGET_H

/********************************************************************************
** Form generated from reading UI file 'UpdateInforNewDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEINFORNEWDIALOG_H
#define UI_UPDATEINFORNEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TitlebarWidget.h>

QT_BEGIN_NAMESPACE

class Ui_UpdateInforNewDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *dialogbg;
    QVBoxLayout *verticalLayout_2;
    TitlebarWidget *Title_bar;
    QWidget *widget_Content;
    QVBoxLayout *verticalLayout;
    QLabel *label_msg;
    QLabel *label_Infor;
    QWidget *widget_btn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_later;
    QPushButton *pushButton_once;

    void setupUi(QDialog *UpdateInforNewDialog)
    {
        if (UpdateInforNewDialog->objectName().isEmpty())
            UpdateInforNewDialog->setObjectName(QStringLiteral("UpdateInforNewDialog"));
        UpdateInforNewDialog->resize(650, 400);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        UpdateInforNewDialog->setFont(font);
        UpdateInforNewDialog->setStyleSheet(QString::fromUtf8("QDialog#UpdateInforNewDialog{\n"
"	border-radius: 4px;\n"
"	background-color: rgb(255, 255, 255, 254);\n"
"	background-position: top left right bottom;\n"
"	background-clip: padding;\n"
"	border: 1px solid #d7d8d9;\n"
"}\n"
"\n"
"QWidget\n"
"{\n"
"	font-family:'\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"}\n"
"\n"
"QPushButton#pushButton_once{\n"
"	border-radius: 0px;\n"
"    color:#FFFFFF;\n"
"    background-color:#3DCE3D;\n"
"}\n"
"QPushButton#pushButton_once:hover{\n"
"background-color:#38C738;\n"
"}\n"
"\n"
"QPushButton#pushButton_once:pressed{\n"
"	background-color:#2FB82F;\n"
"}\n"
"\n"
"QPushButton#pushButton_later{\n"
"    color:#666666;\n"
"    border:1px solid #E5E5E5;\n"
"}\n"
"QPushButton#pushButton_later:hover{\n"
"    background-color:#f5f5f5;\n"
"}\n"
"QPushButton#pushButton_later:pressed{\n"
"    background-color:#EBEBEB;\n"
"}\n"
"\n"
"QLabel#label_Infor\n"
"{\n"
"	color: #7A7A7A;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(UpdateInforNewDialog);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        dialogbg = new QWidget(UpdateInforNewDialog);
        dialogbg->setObjectName(QStringLiteral("dialogbg"));
        verticalLayout_2 = new QVBoxLayout(dialogbg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Title_bar = new TitlebarWidget(dialogbg);
        Title_bar->setObjectName(QStringLiteral("Title_bar"));
        Title_bar->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(Title_bar);

        widget_Content = new QWidget(dialogbg);
        widget_Content->setObjectName(QStringLiteral("widget_Content"));
        verticalLayout = new QVBoxLayout(widget_Content);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(50, 0, 50, 0);
        label_msg = new QLabel(widget_Content);
        label_msg->setObjectName(QStringLiteral("label_msg"));

        verticalLayout->addWidget(label_msg);

        label_Infor = new QLabel(widget_Content);
        label_Infor->setObjectName(QStringLiteral("label_Infor"));
        label_Infor->setMinimumSize(QSize(500, 40));
        label_Infor->setMaximumSize(QSize(500, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        label_Infor->setFont(font1);

        verticalLayout->addWidget(label_Infor);

        widget_btn = new QWidget(widget_Content);
        widget_btn->setObjectName(QStringLiteral("widget_btn"));
        widget_btn->setMinimumSize(QSize(550, 60));
        widget_btn->setMaximumSize(QSize(550, 60));
        horizontalLayout = new QHBoxLayout(widget_btn);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 15, 0);
        horizontalSpacer = new QSpacerItem(412, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_later = new QPushButton(widget_btn);
        pushButton_later->setObjectName(QStringLiteral("pushButton_later"));
        pushButton_later->setMinimumSize(QSize(115, 0));
        pushButton_later->setMaximumSize(QSize(140, 25));
        pushButton_later->setFlat(true);

        horizontalLayout->addWidget(pushButton_later);

        pushButton_once = new QPushButton(widget_btn);
        pushButton_once->setObjectName(QStringLiteral("pushButton_once"));
        pushButton_once->setMinimumSize(QSize(60, 25));
        pushButton_once->setMaximumSize(QSize(16777215, 25));
        pushButton_once->setFlat(true);

        horizontalLayout->addWidget(pushButton_once);


        verticalLayout->addWidget(widget_btn);


        verticalLayout_2->addWidget(widget_Content);


        verticalLayout_3->addWidget(dialogbg);


        retranslateUi(UpdateInforNewDialog);

        QMetaObject::connectSlotsByName(UpdateInforNewDialog);
    } // setupUi

    void retranslateUi(QDialog *UpdateInforNewDialog)
    {
        UpdateInforNewDialog->setWindowTitle(QApplication::translate("UpdateInforNewDialog", "Dialog", 0));
        label_msg->setText(QApplication::translate("UpdateInforNewDialog", "TextLabel", 0));
        label_Infor->setText(QApplication::translate("UpdateInforNewDialog", "\344\270\272\344\272\206\344\270\215\345\275\261\345\223\215\346\202\250\347\232\204\344\270\232\345\212\241\345\222\250\350\257\242\357\274\214\345\274\272\347\203\210\350\246\201\346\261\202\346\202\250\345\215\207\347\272\247\345\220\216\347\273\247\347\273\255\344\275\277\347\224\250\357\274\214\345\220\246\345\210\231\345\275\261\345\223\215\345\220\216\347\273\255\344\275\277\347\224\250", 0));
        pushButton_later->setText(QApplication::translate("UpdateInforNewDialog", "\346\232\202\344\270\215\345\215\207\347\272\247,\347\273\247\347\273\255\344\275\277\347\224\250", 0));
        pushButton_once->setText(QApplication::translate("UpdateInforNewDialog", "\345\215\207\347\272\247\344\275\277\347\224\250", 0));
    } // retranslateUi

};

namespace Ui {
    class UpdateInforNewDialog: public Ui_UpdateInforNewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEINFORNEWDIALOG_H

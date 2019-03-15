/********************************************************************************
** Form generated from reading UI file 'PersonInforDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONINFORDIALOG_H
#define UI_PERSONINFORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonInforDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget_bkg;
    QVBoxLayout *verticalLayout;
    QWidget *TitleBar;
    QHBoxLayout *horizontalLayout_2;
    QLabel *title_label;
    QPushButton *pbclose;
    QWidget *vline;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *widget;
    QLabel *label_2;
    QLineEdit *MaxNumEdit;
    QLabel *label_3;
    QLabel *sp_1;
    QLabel *label_4;
    QLineEdit *realNameEdit;
    QLabel *uin_label;
    QLabel *label_6;
    QLabel *Loginname_label;
    QLabel *label_7;
    QLabel *label_9;
    QLineEdit *WebNameEdit;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_10;
    QLabel *DepatrM_label;
    QLabel *sp_2;
    QLabel *sp_3;
    QLabel *sp_4;
    QLabel *sp_5;
    QLabel *sp_6;
    QPushButton *pbSave;
    QPushButton *pbCancle;
    QLabel *label_SaveResult;
    QLabel *Image_label;
    QLabel *realNameLabel;
    QLabel *WebNameLabel;

    void setupUi(QDialog *PersonInforDialog)
    {
        if (PersonInforDialog->objectName().isEmpty())
            PersonInforDialog->setObjectName(QStringLiteral("PersonInforDialog"));
        PersonInforDialog->resize(498, 605);
        PersonInforDialog->setStyleSheet(QString::fromUtf8("QWidget#widget_bkg{\n"
"    background-color:#D3D3D3;\n"
"    border-radius: 4px;\n"
"	border:1px solid #000000;\n"
"	\n"
"	\n"
"}\n"
"QWidget\n"
"{\n"
"	font-size:12px;\n"
"    color:#333333;\n"
"	font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QLabel{\n"
"    font-size:12px;\n"
"    color:#333333;\n"
"	font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QWidget#widget\n"
"{\n"
"	background-color:#EAEAEA;\n"
"}\n"
"\n"
"QLabel#title_label{\n"
"    font: bold 14px;\n"
"}\n"
"\n"
"QLabel#sp_1,#sp_2,#sp_3,#sp_4,#sp_5,#sp_6,#sp_7,#sp_8,#sp_9{\n"
"    border:1px solid #D6D6D6;\n"
"}\n"
"QLabel#label_3,#label_12,#label_11,#label_SaveResult\n"
"{\n"
"	color:#FF4500;\n"
"}\n"
"\n"
"QPushButton#pbCancle,#pbSave\n"
"{\n"
"    border-radius: 2px;\n"
"    border:1px solid #EBEBEB;\n"
"    background-color:#FFFFFF;\n"
"}\n"
"\n"
"QPushButton#pbCancle:hover,#pbSave:hover{\n"
"    border-radius: 2px;\n"
"    border:1px solid #EBEBEB;\n"
"    background-color:#EBEBEB;\n"
""
                        "}\n"
"\n"
"\n"
"QPushButton#pbCancle:pressed,#pbSave:pressed{\n"
"    border-radius: 2px;\n"
"    border:1px solid #D6D6D6;\n"
"    background-color:#D6D6D6;\n"
"}\n"
"QPushButton#pbclose{\n"
"	border-top-right-radius: 4px;\n"
"    border:1px solid #00000000;\n"
"    background-color:#FFFFFF;\n"
"}\n"
"\n"
"QPushButton#pbclose:hover{\n"
"    background-color:#FF0000;\n"
"}\n"
"QPushButton#pbclose:pressed{\n"
"    background-color:#A30707;\n"
"}\n"
"QScrollArea#scrollArea{\n"
"	border:none;\n"
"}\n"
"\n"
"QWidget#scrollAreaWidgetContents{\n"
"	background-color:#FFFFFFFF;\n"
"}\n"
"QWidget#vline{\n"
"	background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0,  \n"
"                                 stop: 0 #00000000, stop: 0.1 #A3A6A9,  \n"
"                                 stop: 0.9 #A3A6A9, stop: 1.0 #00000000); \n"
"}\n"
"\n"
"\n"
"QLineEdit\n"
"{\n"
"border:1px solid #D6D6D6;\n"
"    background-color:#FFFFFF;\n"
"}\n"
"QLineEdit:hover{\n"
"    border-radius: 2px;\n"
"    border:1px solid #EBEBEB;\n"
"    backgro"
                        "und-color:#EBEBEB;\n"
"}\n"
"\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"    border:1px solid #4F9AD4;\n"
"    background-color:#FFFFFF;\n"
"}\n"
"\n"
"QLabel#label_SaveResult\n"
"{\n"
"	font-size:18px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(PersonInforDialog);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_bkg = new QWidget(PersonInforDialog);
        widget_bkg->setObjectName(QStringLiteral("widget_bkg"));
        verticalLayout = new QVBoxLayout(widget_bkg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        TitleBar = new QWidget(widget_bkg);
        TitleBar->setObjectName(QStringLiteral("TitleBar"));
        TitleBar->setMinimumSize(QSize(0, 30));
        horizontalLayout_2 = new QHBoxLayout(TitleBar);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        title_label = new QLabel(TitleBar);
        title_label->setObjectName(QStringLiteral("title_label"));
        title_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(title_label);

        pbclose = new QPushButton(TitleBar);
        pbclose->setObjectName(QStringLiteral("pbclose"));
        pbclose->setMinimumSize(QSize(28, 28));
        pbclose->setMaximumSize(QSize(28, 28));
        pbclose->setFlat(true);

        horizontalLayout_2->addWidget(pbclose);


        verticalLayout->addWidget(TitleBar);

        vline = new QWidget(widget_bkg);
        vline->setObjectName(QStringLiteral("vline"));

        verticalLayout->addWidget(vline);

        scrollArea = new QScrollArea(widget_bkg);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(496, 458));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 479, 563));
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 481, 561));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 20, 91, 16));
        MaxNumEdit = new QLineEdit(widget);
        MaxNumEdit->setObjectName(QStringLiteral("MaxNumEdit"));
        MaxNumEdit->setGeometry(QRect(120, 17, 191, 24));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 40, 201, 16));
        sp_1 = new QLabel(widget);
        sp_1->setObjectName(QStringLiteral("sp_1"));
        sp_1->setGeometry(QRect(0, 70, 500, 1));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 90, 110, 20));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        realNameEdit = new QLineEdit(widget);
        realNameEdit->setObjectName(QStringLiteral("realNameEdit"));
        realNameEdit->setGeometry(QRect(440, 190, 21, 24));
        uin_label = new QLabel(widget);
        uin_label->setObjectName(QStringLiteral("uin_label"));
        uin_label->setGeometry(QRect(120, 90, 151, 16));
        uin_label->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 140, 110, 16));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Loginname_label = new QLabel(widget);
        Loginname_label->setObjectName(QStringLiteral("Loginname_label"));
        Loginname_label->setGeometry(QRect(120, 130, 121, 31));
        Loginname_label->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 190, 110, 20));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(0, 270, 110, 20));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        WebNameEdit = new QLineEdit(widget);
        WebNameEdit->setObjectName(QStringLiteral("WebNameEdit"));
        WebNameEdit->setGeometry(QRect(430, 270, 20, 24));
        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(120, 290, 361, 20));
        label_12 = new QLabel(widget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(120, 210, 301, 20));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(0, 340, 110, 20));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        DepatrM_label = new QLabel(widget);
        DepatrM_label->setObjectName(QStringLiteral("DepatrM_label"));
        DepatrM_label->setGeometry(QRect(130, 340, 111, 20));
        DepatrM_label->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        sp_2 = new QLabel(widget);
        sp_2->setObjectName(QStringLiteral("sp_2"));
        sp_2->setGeometry(QRect(0, 120, 541, 1));
        sp_3 = new QLabel(widget);
        sp_3->setObjectName(QStringLiteral("sp_3"));
        sp_3->setGeometry(QRect(0, 170, 541, 1));
        sp_4 = new QLabel(widget);
        sp_4->setObjectName(QStringLiteral("sp_4"));
        sp_4->setGeometry(QRect(0, 250, 500, 1));
        sp_5 = new QLabel(widget);
        sp_5->setObjectName(QStringLiteral("sp_5"));
        sp_5->setGeometry(QRect(0, 320, 500, 1));
        sp_6 = new QLabel(widget);
        sp_6->setObjectName(QStringLiteral("sp_6"));
        sp_6->setGeometry(QRect(0, 380, 500, 1));
        pbSave = new QPushButton(widget);
        pbSave->setObjectName(QStringLiteral("pbSave"));
        pbSave->setGeometry(QRect(384, 510, 70, 28));
        pbSave->setFlat(true);
        pbCancle = new QPushButton(widget);
        pbCancle->setObjectName(QStringLiteral("pbCancle"));
        pbCancle->setGeometry(QRect(310, 510, 70, 28));
        pbCancle->setFlat(true);
        label_SaveResult = new QLabel(widget);
        label_SaveResult->setObjectName(QStringLiteral("label_SaveResult"));
        label_SaveResult->setGeometry(QRect(40, 510, 241, 31));
        Image_label = new QLabel(widget);
        Image_label->setObjectName(QStringLiteral("Image_label"));
        Image_label->setGeometry(QRect(40, 390, 181, 111));
        realNameLabel = new QLabel(widget);
        realNameLabel->setObjectName(QStringLiteral("realNameLabel"));
        realNameLabel->setGeometry(QRect(120, 190, 191, 21));
        realNameLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        WebNameLabel = new QLabel(widget);
        WebNameLabel->setObjectName(QStringLiteral("WebNameLabel"));
        WebNameLabel->setGeometry(QRect(120, 270, 201, 21));
        WebNameLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        horizontalLayout->addWidget(widget_bkg);


        retranslateUi(PersonInforDialog);

        QMetaObject::connectSlotsByName(PersonInforDialog);
    } // setupUi

    void retranslateUi(QDialog *PersonInforDialog)
    {
        PersonInforDialog->setWindowTitle(QApplication::translate("PersonInforDialog", "Dialog", 0));
        title_label->setText(QApplication::translate("PersonInforDialog", "\345\237\272\346\234\254\344\277\241\346\201\257\350\256\276\347\275\256", 0));
        pbclose->setText(QApplication::translate("PersonInforDialog", "X", 0));
        label_2->setText(QApplication::translate("PersonInforDialog", "\346\234\200\345\244\247\345\220\214\346\227\266\346\216\245\345\276\205\346\225\260:", 0));
        label_3->setText(QApplication::translate("PersonInforDialog", "*\345\234\250\347\272\277\347\251\272\351\227\262\346\227\266\345\220\214\346\227\266\346\216\245\345\276\205\350\256\277\345\256\242\346\234\200\345\244\247\346\225\260\343\200\202", 0));
        sp_1->setText(QString());
        label_4->setText(QApplication::translate("PersonInforDialog", "\346\211\213\346\234\272\345\217\267:", 0));
        uin_label->setText(QApplication::translate("PersonInforDialog", "TextLabel", 0));
        label_6->setText(QApplication::translate("PersonInforDialog", "\347\231\273\345\275\225\345\220\215:", 0));
        Loginname_label->setText(QApplication::translate("PersonInforDialog", "TextLabel", 0));
        label_7->setText(QApplication::translate("PersonInforDialog", "\347\234\237\345\256\236\345\247\223\345\220\215:", 0));
        label_9->setText(QApplication::translate("PersonInforDialog", "\347\275\221\351\241\265\346\230\276\347\244\272\345\220\215:", 0));
        label_11->setText(QApplication::translate("PersonInforDialog", "*\345\257\271\350\256\277\345\256\242\346\230\276\347\244\272\345\234\250\347\272\277\345\235\220\345\270\255\344\277\256\346\224\271\345\220\216\345\217\212\346\227\266\347\224\237\346\225\210/\347\246\273\347\272\277\345\235\220\345\270\255\344\277\256\346\224\271\345\220\21624\345\260\217\346\227\266\347\224\237\346\225\210\343\200\202", 0));
        label_12->setText(QApplication::translate("PersonInforDialog", "*\344\270\215\350\266\205\350\277\20725\344\270\252\345\255\227\347\254\246\357\274\210\346\261\211\345\255\227\357\274\214\346\225\260\345\255\227\357\274\214\345\255\227\346\257\215\345\222\214\344\270\213\345\210\222\347\272\277\357\274\211\343\200\202", 0));
        label_10->setText(QApplication::translate("PersonInforDialog", "\346\211\200\345\234\250\351\203\250\351\227\250:", 0));
        DepatrM_label->setText(QString());
        sp_2->setText(QString());
        sp_3->setText(QString());
        sp_4->setText(QString());
        sp_5->setText(QString());
        sp_6->setText(QString());
        pbSave->setText(QApplication::translate("PersonInforDialog", "\344\277\235\345\255\230", 0));
        pbCancle->setText(QApplication::translate("PersonInforDialog", "\346\224\276\345\274\203", 0));
        label_SaveResult->setText(QString());
        Image_label->setText(QApplication::translate("PersonInforDialog", "TextLabel", 0));
        realNameLabel->setText(QApplication::translate("PersonInforDialog", "TextLabel", 0));
        WebNameLabel->setText(QApplication::translate("PersonInforDialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class PersonInforDialog: public Ui_PersonInforDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONINFORDIALOG_H

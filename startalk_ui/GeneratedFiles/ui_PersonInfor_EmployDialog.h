/********************************************************************************
** Form generated from reading UI file 'PersonInfor_EmployDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONINFOR_EMPLOYDIALOG_H
#define UI_PERSONINFOR_EMPLOYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonInfor_employDialog
{
public:
    QWidget *widget_bkg;
    QWidget *TitleBar;
    QPushButton *pbclose;
    QLabel *title_label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *widget;
    QLabel *label;
    QLabel *loginName_label;
    QLabel *sp_1;
    QLabel *label_2;
    QLabel *mobil_label;
    QLabel *sp_2;
    QLabel *Emaillabel;
    QLabel *Email_label;
    QLabel *sp_3;
    QLabel *Image_Label;
    QPushButton *ButtonOK;
    QWidget *vline;

    void setupUi(QDialog *PersonInfor_employDialog)
    {
        if (PersonInfor_employDialog->objectName().isEmpty())
            PersonInfor_employDialog->setObjectName(QStringLiteral("PersonInfor_employDialog"));
        PersonInfor_employDialog->resize(498, 532);
        PersonInfor_employDialog->setStyleSheet(QLatin1String("QWidget#widget_bkg{\n"
"    background-color:#D3D3D3;\n"
"    border-radius: 4px;\n"
"	border:1px solid #000000;\n"
"}\n"
"QLabel{\n"
"    font-size:12px;\n"
"    color:#000000;\n"
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
"QLabel#sp_1,#sp_2,#sp_3{\n"
"    border:1px solid #D6D6D6;\n"
"}\n"
"\n"
"\n"
"QPushButton#ButtonOK\n"
"{\n"
"    border-radius: 2px;\n"
"    border:1px solid #EBEBEB;\n"
"    background-color:#FFFFFF;\n"
"}\n"
"\n"
"QPushButton#ButtonOK:hover{\n"
"    border-radius: 2px;\n"
"    border:1px solid #EBEBEB;\n"
"    background-color:#EBEBEB;\n"
"}\n"
"\n"
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
"QWidget"
                        "#scrollAreaWidgetContents{\n"
"	background-color:#FFFFFFFF;\n"
"}\n"
"QWidget#vline{\n"
"	background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0,  \n"
"                                 stop: 0 #00000000, stop: 0.1 #A3A6A9,  \n"
"                                 stop: 0.9 #A3A6A9, stop: 1.0 #00000000); \n"
"}\n"
"\n"
"\n"
"QLabel#label_SaveResult\n"
"{\n"
"	font-size:18px;\n"
"}"));
        widget_bkg = new QWidget(PersonInfor_employDialog);
        widget_bkg->setObjectName(QStringLiteral("widget_bkg"));
        widget_bkg->setGeometry(QRect(0, 0, 498, 532));
        TitleBar = new QWidget(widget_bkg);
        TitleBar->setObjectName(QStringLiteral("TitleBar"));
        TitleBar->setGeometry(QRect(1, 1, 498, 30));
        pbclose = new QPushButton(TitleBar);
        pbclose->setObjectName(QStringLiteral("pbclose"));
        pbclose->setGeometry(QRect(450, 2, 30, 25));
        pbclose->setFlat(true);
        title_label = new QLabel(TitleBar);
        title_label->setObjectName(QStringLiteral("title_label"));
        title_label->setGeometry(QRect(210, 5, 80, 20));
        scrollArea = new QScrollArea(widget_bkg);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(1, 41, 496, 490));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 496, 490));
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 481, 491));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 40, 54, 12));
        loginName_label = new QLabel(widget);
        loginName_label->setObjectName(QStringLiteral("loginName_label"));
        loginName_label->setGeometry(QRect(130, 40, 141, 16));
        loginName_label->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        sp_1 = new QLabel(widget);
        sp_1->setObjectName(QStringLiteral("sp_1"));
        sp_1->setGeometry(QRect(0, 90, 500, 1));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 130, 54, 12));
        mobil_label = new QLabel(widget);
        mobil_label->setObjectName(QStringLiteral("mobil_label"));
        mobil_label->setGeometry(QRect(120, 130, 141, 16));
        mobil_label->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        sp_2 = new QLabel(widget);
        sp_2->setObjectName(QStringLiteral("sp_2"));
        sp_2->setGeometry(QRect(-10, 180, 500, 1));
        Emaillabel = new QLabel(widget);
        Emaillabel->setObjectName(QStringLiteral("Emaillabel"));
        Emaillabel->setGeometry(QRect(50, 230, 54, 12));
        Email_label = new QLabel(widget);
        Email_label->setObjectName(QStringLiteral("Email_label"));
        Email_label->setGeometry(QRect(120, 230, 141, 16));
        Email_label->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        sp_3 = new QLabel(widget);
        sp_3->setObjectName(QStringLiteral("sp_3"));
        sp_3->setGeometry(QRect(0, 280, 500, 1));
        Image_Label = new QLabel(widget);
        Image_Label->setObjectName(QStringLiteral("Image_Label"));
        Image_Label->setGeometry(QRect(50, 320, 141, 81));
        ButtonOK = new QPushButton(widget);
        ButtonOK->setObjectName(QStringLiteral("ButtonOK"));
        ButtonOK->setGeometry(QRect(360, 440, 75, 21));
        ButtonOK->setFlat(true);
        scrollArea->setWidget(scrollAreaWidgetContents);
        vline = new QWidget(widget_bkg);
        vline->setObjectName(QStringLiteral("vline"));
        vline->setGeometry(QRect(1, 31, 496, 10));

        retranslateUi(PersonInfor_employDialog);

        QMetaObject::connectSlotsByName(PersonInfor_employDialog);
    } // setupUi

    void retranslateUi(QDialog *PersonInfor_employDialog)
    {
        PersonInfor_employDialog->setWindowTitle(QApplication::translate("PersonInfor_employDialog", "Dialog", 0));
        pbclose->setText(QApplication::translate("PersonInfor_employDialog", "X", 0));
        title_label->setText(QApplication::translate("PersonInfor_employDialog", "\345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("PersonInfor_employDialog", "\347\231\273\345\275\225\345\220\215:", 0));
        loginName_label->setText(QApplication::translate("PersonInfor_employDialog", "TextLoginNameLabel", 0));
        sp_1->setText(QString());
        label_2->setText(QApplication::translate("PersonInfor_employDialog", "\347\224\265\350\257\235:", 0));
        mobil_label->setText(QApplication::translate("PersonInfor_employDialog", "TextPhoneLabel", 0));
        sp_2->setText(QString());
        Emaillabel->setText(QApplication::translate("PersonInfor_employDialog", "\351\202\256\347\256\261:", 0));
        Email_label->setText(QApplication::translate("PersonInfor_employDialog", "TextPhoneLabel", 0));
        sp_3->setText(QString());
        Image_Label->setText(QApplication::translate("PersonInfor_employDialog", "TextLabel", 0));
        ButtonOK->setText(QApplication::translate("PersonInfor_employDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class PersonInfor_employDialog: public Ui_PersonInfor_employDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONINFOR_EMPLOYDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'TransferChatDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFERCHATDIALOG_H
#define UI_TRANSFERCHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransferChatDialog
{
public:
    QWidget *widget_bkg;
    QWidget *TitleBar;
    QPushButton *btnClose;
    QLabel *label_title;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QLineEdit *lineEdit_id;
    QLabel *label_2;
    QTextEdit *textEdit_resons;
    QWidget *page_3;
    QListWidget *listWidget_relation;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *textEdit_resonscollage;
    QWidget *page_2;
    QLabel *label_5;
    QTextEdit *textEdit_page2;
    QTreeWidget *treeWidget;
    QWidget *widget_2;
    QPushButton *btnCancle;
    QPushButton *btnOk;

    void setupUi(QDialog *TransferChatDialog)
    {
        if (TransferChatDialog->objectName().isEmpty())
            TransferChatDialog->setObjectName(QStringLiteral("TransferChatDialog"));
        TransferChatDialog->resize(352, 440);
        TransferChatDialog->setStyleSheet(QLatin1String("QWidget#widget_bkg{\n"
"    background-color:#D3D3D3;\n"
"    border-radius: 4px;\n"
"	border:1px solid #000000;\n"
"}\n"
"\n"
"QWidget#widget_3{\n"
"    background-color:#EAEAEA;\n"
"\n"
"}\n"
"\n"
"QLabel{\n"
"    font-size:12px;\n"
"    color:#000000;\n"
"}\n"
"QLabel#label_title{\n"
"    font: bold 14px;\n"
"}\n"
"\n"
"QPushButton#btnOk,#btnCancle\n"
"{\n"
"    border-radius: 2px;\n"
"    border:1px solid #EBEBEB;\n"
"    background-color:#FFFFFF;\n"
"}\n"
"\n"
"QPushButton#btnOk:hover,#btnCancle:hover{\n"
"    border-radius: 2px;\n"
"    border:1px solid #EBEBEB;\n"
"    background-color:#EBEBEB;\n"
"}\n"
"\n"
"\n"
"QPushButton#ptnOk:pressed,#btnCancle:pressed{\n"
"    border-radius: 2px;\n"
"    border:1px solid #D6D6D6;\n"
"    background-color:#D6D6D6;\n"
"}\n"
"QPushButton#btnClose{\n"
"	border-top-right-radius: 4px;\n"
"    border:1px solid #00000000;\n"
"    background-color:#FFFFFF;\n"
"}\n"
"\n"
"QPushButton#btnClose:hover{\n"
"    background-color:#FF0000;\n"
"}\n"
"QPushButton#btnClose:pressed{\n"
""
                        "    background-color:#A30707;\n"
"}\n"
"\n"
"QWidget#page,#page_2,#page_3\n"
"{\n"
"	background-color:#EAEAEA;\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"border:1px solid #D6D6D6;\n"
"    background-color:#FFFFFF;\n"
"}\n"
"QLineEdit:hover{\n"
"    border-radius: 2px;\n"
"    border:1px solid #EBEBEB;\n"
"     background-color:#FFFFFF;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
""));
        widget_bkg = new QWidget(TransferChatDialog);
        widget_bkg->setObjectName(QStringLiteral("widget_bkg"));
        widget_bkg->setGeometry(QRect(0, 0, 350, 440));
        TitleBar = new QWidget(widget_bkg);
        TitleBar->setObjectName(QStringLiteral("TitleBar"));
        TitleBar->setGeometry(QRect(0, 0, 350, 30));
        btnClose = new QPushButton(TitleBar);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setGeometry(QRect(300, 5, 30, 20));
        btnClose->setFlat(true);
        label_title = new QLabel(TitleBar);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(70, 0, 201, 30));
        label_title->setAlignment(Qt::AlignCenter);
        widget = new QWidget(widget_bkg);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 30, 364, 410));
        widget->setMinimumSize(QSize(350, 410));
        widget->setMaximumSize(QSize(16777215, 410));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 0, 1, 0);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(348, 40));
        widget_3->setMaximumSize(QSize(348, 40));
        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 12, 71, 20));
        lineEdit = new QLineEdit(widget_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 5, 241, 30));

        verticalLayout->addWidget(widget_3);

        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(348, 340));
        stackedWidget->setMaximumSize(QSize(348, 340));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 44, 101, 21));
        lineEdit_id = new QLineEdit(page);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(150, 40, 141, 31));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 110, 91, 16));
        textEdit_resons = new QTextEdit(page);
        textEdit_resons->setObjectName(QStringLiteral("textEdit_resons"));
        textEdit_resons->setGeometry(QRect(40, 130, 251, 131));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        listWidget_relation = new QListWidget(page_3);
        listWidget_relation->setObjectName(QStringLiteral("listWidget_relation"));
        listWidget_relation->setGeometry(QRect(60, 30, 221, 121));
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 10, 121, 16));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 160, 81, 16));
        textEdit_resonscollage = new QTextEdit(page_3);
        textEdit_resonscollage->setObjectName(QStringLiteral("textEdit_resonscollage"));
        textEdit_resonscollage->setGeometry(QRect(60, 180, 221, 141));
        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 160, 91, 16));
        textEdit_page2 = new QTextEdit(page_2);
        textEdit_page2->setObjectName(QStringLiteral("textEdit_page2"));
        textEdit_page2->setGeometry(QRect(20, 180, 311, 121));
        treeWidget = new QTreeWidget(page_2);
        treeWidget->headerItem()->setText(0, QString());
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(20, 10, 311, 141));
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        btnCancle = new QPushButton(widget_2);
        btnCancle->setObjectName(QStringLiteral("btnCancle"));
        btnCancle->setGeometry(QRect(170, 2, 45, 25));
        btnCancle->setFlat(true);
        btnOk = new QPushButton(widget_2);
        btnOk->setObjectName(QStringLiteral("btnOk"));
        btnOk->setGeometry(QRect(270, 2, 45, 25));
        btnOk->setFlat(true);

        verticalLayout->addWidget(widget_2);


        retranslateUi(TransferChatDialog);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(TransferChatDialog);
    } // setupUi

    void retranslateUi(QDialog *TransferChatDialog)
    {
        TransferChatDialog->setWindowTitle(QApplication::translate("TransferChatDialog", "Dialog", 0));
        btnClose->setText(QApplication::translate("TransferChatDialog", "X", 0));
        label_title->setText(QString());
        label_6->setText(QApplication::translate("TransferChatDialog", "\346\243\200\347\264\242\345\205\263\351\224\256\345\255\227:", 0));
        label->setText(QApplication::translate("TransferChatDialog", "\350\276\223\345\205\245\350\246\201\350\275\254\347\247\273\345\210\260\347\232\204id\357\274\232", 0));
        label_2->setText(QApplication::translate("TransferChatDialog", "\350\275\254\347\247\273\347\232\204\345\216\237\345\233\240\357\274\232", 0));
        label_3->setText(QApplication::translate("TransferChatDialog", "\351\200\211\346\213\251\350\246\201\350\275\254\347\247\273\347\232\204\350\201\224\347\263\273\344\272\272\357\274\232", 0));
        label_4->setText(QApplication::translate("TransferChatDialog", "\350\275\254\347\247\273\347\232\204\345\216\237\345\233\240\357\274\232", 0));
        label_5->setText(QApplication::translate("TransferChatDialog", "\350\275\254\347\247\273\345\216\237\345\233\240(\345\277\205\345\241\253)\357\274\232", 0));
        btnCancle->setText(QApplication::translate("TransferChatDialog", "\346\224\276\345\274\203", 0));
        btnOk->setText(QApplication::translate("TransferChatDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class TransferChatDialog: public Ui_TransferChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFERCHATDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'NoteInfor.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEINFOR_H
#define UI_NOTEINFOR_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_NoteInfor
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    TitlebarWidget *titlebar;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit_notetitle;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTextEdit *textEdit_notedesc;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbtn_cancel;
    QPushButton *pbtn_ok;

    void setupUi(QWidget *NoteInfor)
    {
        if (NoteInfor->objectName().isEmpty())
            NoteInfor->setObjectName(QStringLiteral("NoteInfor"));
        NoteInfor->resize(400, 300);
        NoteInfor->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QWidget#widget\n"
"{\n"
"	border:1px solid #D1D1D1;\n"
"  	background: #ECECEC;\n"
"	\n"
"}\n"
"\n"
"\n"
"QPushButton#pbtn_cancel{\n"
"    color: #666666;\n"
"	background-color: #FFFFFF;\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton#pbtn_ok\n"
"{\n"
"	color: #666666;\n"
"	border:none;\n"
"	background-color: #3dbbca;\n"
"}\n"
"\n"
"QPushButton#pbtn_cancel:hover,QPushButton#pbtn_ok:hover {\n"
"    color: #FFFFFF;\n"
"	background-color: #3dbbca;\n"
"}\n"
"QPushButton#pbtn_cancel:pressed, QPushButton#pbtn_ok:press{\n"
"\n"
"    color: #FFFFFF;\n"
"	background-color: #1194a4;\n"
"}\n"
"QPushButton#pbtn_cancel:checked,QPushButton#pbtn_ok:checked{\n"
"\n"
"    color: #FFFFFF;\n"
"	background-color: #1ba9ba;\n"
"}\n"
"QLineEdit{\n"
"	color:  #333333;\n"
"	background:#AAffffff;	\n"
"	font: 14px;\n"
"	border: 1px solid #FFFFFF;\n"
"}\n"
"\n"
"QLineEdit:hover{\n"
"	border: 1px solid #65e1f6;\n"
"}\n"
"QLineEdit:focus{\n"
"	"
                        "border: 1px solid #65e1f6;\n"
"}\n"
"\n"
"QTextEdit\n"
"{\n"
"	color:  #333333;\n"
"	background:#AAffffff;	\n"
"	font: 14px;\n"
"	border: 1px solid #FFFFFF;\n"
"}\n"
"\n"
"QTextEdit:hover\n"
"{\n"
"	border: 1px solid #65e1f6;\n"
"}\n"
"QTextEdit:focus\n"
"{\n"
"	border: 1px solid #65e1f6;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(NoteInfor);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(NoteInfor);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        titlebar = new TitlebarWidget(widget);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 30));
        titlebar->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(titlebar);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 200));
        widget_3->setMaximumSize(QSize(16777215, 200));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(20, -1, 20, -1);
        label = new QLabel(widget_4);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(30, 50));

        horizontalLayout_3->addWidget(label);

        lineEdit_notetitle = new QLineEdit(widget_4);
        lineEdit_notetitle->setObjectName(QStringLiteral("lineEdit_notetitle"));

        horizontalLayout_3->addWidget(lineEdit_notetitle);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(20, 0, 20, 0);
        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 50));
        label_2->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_2->addWidget(label_2);

        textEdit_notedesc = new QTextEdit(widget_5);
        textEdit_notedesc->setObjectName(QStringLiteral("textEdit_notedesc"));
        textEdit_notedesc->setMinimumSize(QSize(0, 0));
        textEdit_notedesc->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(textEdit_notedesc);


        verticalLayout->addWidget(widget_5);


        verticalLayout_2->addWidget(widget_3);

        widget_6 = new QWidget(widget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout = new QHBoxLayout(widget_6);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 20, 10);
        horizontalSpacer = new QSpacerItem(257, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbtn_cancel = new QPushButton(widget_6);
        pbtn_cancel->setObjectName(QStringLiteral("pbtn_cancel"));
        pbtn_cancel->setMinimumSize(QSize(40, 23));
        pbtn_cancel->setMaximumSize(QSize(40, 23));
        pbtn_cancel->setFlat(true);

        horizontalLayout->addWidget(pbtn_cancel);

        pbtn_ok = new QPushButton(widget_6);
        pbtn_ok->setObjectName(QStringLiteral("pbtn_ok"));
        pbtn_ok->setMinimumSize(QSize(40, 23));
        pbtn_ok->setMaximumSize(QSize(40, 23));
        pbtn_ok->setFlat(true);

        horizontalLayout->addWidget(pbtn_ok);


        verticalLayout_2->addWidget(widget_6);


        verticalLayout_3->addWidget(widget);


        retranslateUi(NoteInfor);

        QMetaObject::connectSlotsByName(NoteInfor);
    } // setupUi

    void retranslateUi(QWidget *NoteInfor)
    {
        NoteInfor->setWindowTitle(QApplication::translate("NoteInfor", "Form", 0));
        label->setText(QApplication::translate("NoteInfor", "\346\240\207\351\242\230:", 0));
        label_2->setText(QApplication::translate("NoteInfor", "\346\217\217\350\277\260:", 0));
        pbtn_cancel->setText(QApplication::translate("NoteInfor", "\345\217\226\346\266\210", 0));
        pbtn_ok->setText(QApplication::translate("NoteInfor", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class NoteInfor: public Ui_NoteInfor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEINFOR_H

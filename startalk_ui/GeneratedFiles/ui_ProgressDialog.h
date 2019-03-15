/********************************************************************************
** Form generated from reading UI file 'ProgressDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSDIALOG_H
#define UI_PROGRESSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgressDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_border;
    QProgressBar *progressBar;
    QPushButton *pushButtonOK;
    QLabel *label_infor;

    void setupUi(QWidget *ProgressDialog)
    {
        if (ProgressDialog->objectName().isEmpty())
            ProgressDialog->setObjectName(QStringLiteral("ProgressDialog"));
        ProgressDialog->resize(400, 187);
        ProgressDialog->setStyleSheet(QString::fromUtf8("QWidget#widget_border{\n"
"    background-color:#FFFFFF;\n"
"    border-radius: 4px;\n"
"	font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"	border:1px solid #DADADA80\n"
"}\n"
"QLabel#label_infor\n"
"{\n"
"     font: bold 15px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"     color: red;\n"
"}"));
        verticalLayout = new QVBoxLayout(ProgressDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_border = new QWidget(ProgressDialog);
        widget_border->setObjectName(QStringLiteral("widget_border"));
        progressBar = new QProgressBar(widget_border);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(40, 40, 331, 23));
        progressBar->setValue(0);
        pushButtonOK = new QPushButton(widget_border);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(260, 140, 75, 23));
        label_infor = new QLabel(widget_border);
        label_infor->setObjectName(QStringLiteral("label_infor"));
        label_infor->setGeometry(QRect(10, 70, 371, 51));

        verticalLayout->addWidget(widget_border);


        retranslateUi(ProgressDialog);

        QMetaObject::connectSlotsByName(ProgressDialog);
    } // setupUi

    void retranslateUi(QWidget *ProgressDialog)
    {
        ProgressDialog->setWindowTitle(QApplication::translate("ProgressDialog", "Form", 0));
        pushButtonOK->setText(QApplication::translate("ProgressDialog", "PushButton", 0));
        label_infor->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProgressDialog: public Ui_ProgressDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSDIALOG_H

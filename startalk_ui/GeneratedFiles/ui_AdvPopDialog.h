/********************************************************************************
** Form generated from reading UI file 'AdvPopDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVPOPDIALOG_H
#define UI_ADVPOPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "advtoolbar.h"

QT_BEGIN_NAMESPACE

class Ui_AdvPopDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_bk;
    QVBoxLayout *verticalLayout_2;
    AdvToolbar *advwidget;

    void setupUi(QWidget *AdvPopDialog)
    {
        if (AdvPopDialog->objectName().isEmpty())
            AdvPopDialog->setObjectName(QStringLiteral("AdvPopDialog"));
        AdvPopDialog->resize(300, 170);
        verticalLayout = new QVBoxLayout(AdvPopDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_bk = new QWidget(AdvPopDialog);
        widget_bk->setObjectName(QStringLiteral("widget_bk"));
        verticalLayout_2 = new QVBoxLayout(widget_bk);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        advwidget = new AdvToolbar(widget_bk);
        advwidget->setObjectName(QStringLiteral("advwidget"));

        verticalLayout_2->addWidget(advwidget);


        verticalLayout->addWidget(widget_bk);


        retranslateUi(AdvPopDialog);

        QMetaObject::connectSlotsByName(AdvPopDialog);
    } // setupUi

    void retranslateUi(QWidget *AdvPopDialog)
    {
        AdvPopDialog->setWindowTitle(QApplication::translate("AdvPopDialog", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class AdvPopDialog: public Ui_AdvPopDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVPOPDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'SelectContactDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTCONTACTDIALOG_H
#define UI_SELECTCONTACTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <rostertreeview.h>
#include "TitlebarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SelectContactDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widgetBorder;
    QVBoxLayout *verticalLayout;
    TitlebarWidget *titlebarWidget;
    QWidget *border;
    QPushButton *addBtn;
    QPushButton *delBtn;
    QListWidget *rightWidget;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QLineEdit *lineEdit;
    RosterTreeView *leftTreeView;

    void setupUi(QDialog *SelectContactDialog)
    {
        if (SelectContactDialog->objectName().isEmpty())
            SelectContactDialog->setObjectName(QStringLiteral("SelectContactDialog"));
        SelectContactDialog->resize(593, 408);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SelectContactDialog->sizePolicy().hasHeightForWidth());
        SelectContactDialog->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(SelectContactDialog);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widgetBorder = new QWidget(SelectContactDialog);
        widgetBorder->setObjectName(QStringLiteral("widgetBorder"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widgetBorder->sizePolicy().hasHeightForWidth());
        widgetBorder->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(widgetBorder);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titlebarWidget = new TitlebarWidget(widgetBorder);
        titlebarWidget->setObjectName(QStringLiteral("titlebarWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(titlebarWidget->sizePolicy().hasHeightForWidth());
        titlebarWidget->setSizePolicy(sizePolicy2);
        titlebarWidget->setMinimumSize(QSize(0, 27));
        titlebarWidget->setMaximumSize(QSize(16777215, 27));

        verticalLayout->addWidget(titlebarWidget);

        border = new QWidget(widgetBorder);
        border->setObjectName(QStringLiteral("border"));
        addBtn = new QPushButton(border);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setGeometry(QRect(280, 100, 75, 31));
        delBtn = new QPushButton(border);
        delBtn->setObjectName(QStringLiteral("delBtn"));
        delBtn->setGeometry(QRect(280, 160, 75, 31));
        rightWidget = new QListWidget(border);
        rightWidget->setObjectName(QStringLiteral("rightWidget"));
        rightWidget->setGeometry(QRect(360, 10, 221, 301));
        btnOK = new QPushButton(border);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        btnOK->setGeometry(QRect(430, 320, 75, 31));
        btnCancel = new QPushButton(border);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(510, 320, 75, 31));
        lineEdit = new QLineEdit(border);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 261, 25));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        leftTreeView = new RosterTreeView(border);
        leftTreeView->setObjectName(QStringLiteral("leftTreeView"));
        leftTreeView->setGeometry(QRect(10, 50, 261, 261));

        verticalLayout->addWidget(border);


        horizontalLayout->addWidget(widgetBorder);


        retranslateUi(SelectContactDialog);

        QMetaObject::connectSlotsByName(SelectContactDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectContactDialog)
    {
        SelectContactDialog->setWindowTitle(QApplication::translate("SelectContactDialog", "SelectContactDialog", 0));
        addBtn->setText(QApplication::translate("SelectContactDialog", "-->", 0));
        delBtn->setText(QApplication::translate("SelectContactDialog", "<--", 0));
        btnOK->setText(QString());
        btnCancel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SelectContactDialog: public Ui_SelectContactDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTCONTACTDIALOG_H
